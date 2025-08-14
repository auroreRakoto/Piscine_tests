#!/bin/bash
set -e

# Usage: ./run.sh C03 [eval]
TARGET="${1:-}"
MODE="${2:-}"

if [[ -z "$TARGET" || ! "$TARGET" =~ ^C[0-9]{2}$ ]]; then
	echo "❌ Usage: $0 CXX [eval]"
	echo "   ex: $0 C00          # tests dans ../C00 et exos dans ../../C00/ex*"
	echo "       $0 C00 eval     # tests dans ../C00 et exos dans ../../ex*"
	exit 1
fi

# Où chercher les fichiers d'exos (selon le mode)
if [[ "$MODE" == "eval" ]]; then
	EX_GLOB="../../ex*/*.c"
else
	EX_GLOB="../../${TARGET}/ex*/*.c"
fi

# Récupération des fichiers .c d'exos
# (ex: ../../C03/ex*/**/*.c ou ../../ex*/**/*.c)
readarray -t EX_FILES < <(find $EX_GLOB -type f -name "*.c" 2>/dev/null || true)
if [[ ${#EX_FILES[@]} -eq 0 ]]; then
	echo "❌ Aucun fichier .c d'exercice trouvé dans: $EX_GLOB"
	exit 1
fi

# Fichiers de tests dans ../CXX
# On prend: main.c, assert.c, et test_*.c (au premier niveau)
TEST_DIR="../$TARGET"
readarray -t TEST_FILES < <(find "$TEST_DIR" -maxdepth 1 -type f \( -name "main.c" -o -name "assert.c" -o -name "test_*.c" \) | sort || true)

if [[ ${#TEST_FILES[@]} -eq 0 ]]; then
	echo "❌ Aucun fichier de tests trouvé dans le dossier courant."
	echo "   Attendus: main.c, assert.c, et/ou test_*.c"
	exit 1
fi

echo "📂 Cible:                $TARGET  (mode: ${MODE:-default})"
echo "🧪 Dossier tests:        ../${TARGET}"
echo "📦 Dossiers exos:        $EX_GLOB"
echo "📄 Fichiers exos:"
printf '  - %s\n' "${EX_FILES[@]}"
echo "🧪 Fichiers tests:"
printf '  - %s\n' "${TEST_FILES[@]}"

# Norminette (best effort)
echo "📝 Lancement norminette..."
norminette "${EX_FILES[@]}" || true

# Compilation
echo "⚙️  Compilation..."
cc -Wall -Wextra -Werror "${TEST_FILES[@]}" "${EX_FILES[@]}" -o test
#gcc -Wall -Wextra -Werror "${TEST_FILES[@]}" "${EX_FILES[@]}" -o test

# Exécution sous Valgrind si dispo
if command -v valgrind >/dev/null 2>&1; then
	echo "🧠 Exécution avec Valgrind..."
	set +e
	valgrind --leak-check=full --errors-for-leak-kinds=all --error-exitcode=42 ./test
	code=$?
	set -e
	if [[ $code -eq 42 ]]; then
		echo "💥 Memory leak detected!"
		exit 42
	elif [[ $code -ne 0 ]]; then
		exit $code
	else
		echo "✅ No leaks detected."
	fi
else
	echo "⚠️ Valgrind indisponible, exécution simple."
	./test
fi
