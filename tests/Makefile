# Usage:
#   make run TARGET=C03            # tests dans ../C03 et exos dans ../../C03/ex*
#   make run TARGET=C03 MODE=eval  # tests dans ../C03 et exos dans ../../ex*
#   make build | make valgrind | make norm | make list | make clean

SHELL          := /bin/bash

R  		       ?= 
MODE           ?= default
CC             ?= cc
CFLAGS         := -Wall -Wextra -Werror
NAME           := test

# ---- Détection fichiers (évaluée à l'appel de make) -------------------------
EX_GLOB        := $(shell [ "$(MODE)" = "eval" ] && echo "../../ex*/*.c" || echo "../../$(R)/ex*/*.c")
EX_FILES       := $(shell find $(EX_GLOB) -type f -name "*.c" 2>/dev/null)
TEST_DIR       := ../$(R)
TEST_FILES     := $(shell find "$(TEST_DIR)" -maxdepth 1 -type f \( -name "main.c" -o -name "assert.c" -o -name "test_*.c" \) | sort)

# ---- Raccourcis jolis --------------------------------------------------------
define PRINT_HEADER
	@echo "📂 Cible:                $(R)  (mode: $(MODE))"
	@echo "🧪 Dossier tests:        $(TEST_DIR)"
	@echo "📦 Dossiers exos:        $(EX_GLOB)"
	@echo "📄 Fichiers exos:" ; \
	if [ -n "$(EX_FILES)" ]; then printf '  - %s\n' $(EX_FILES); else echo "  (aucun)"; fi
	@echo "🧪 Fichiers tests:" ; \
	if [ -n "$(TEST_FILES)" ]; then printf '  - %s\n' $(TEST_FILES); else echo "  (aucun)"; fi
endef

# ---- Vérifs ------------------------------------------------------------------
define CHECKS
	@if ! [[ "$(R)" =~ ^C[0-9]{2}$$ ]]; then \
		echo "❌ Usage: make run R=CXX [MODE=eval]"; \
		exit 1; \
	fi
	@if [ -z "$(EX_FILES)" ]; then \
		echo "❌ Aucun fichier .c d'exercice trouvé dans: $(EX_GLOB)"; \
		exit 1; \
	fi
	@if [ -z "$(TEST_FILES)" ]; then \
		echo "❌ Aucun fichier de tests trouvé dans $(TEST_DIR) (main.c/assert.c/test_*.c)"; \
		exit 1; \
	fi
endef

# ---- Règles ------------------------------------------------------------------
.PHONY: run build valgrind norm list clean help

run: build
	@echo "🚀 Exécution..."
	@if command -v valgrind >/dev/null 2>&1; then \
		echo "🧠 Exécution avec Valgrind..."; \
		valgrind --leak-check=full --errors-for-leak-kinds=all --error-exitcode=42 ./$(NAME) || code=$$?; \
		if [ "$$code" = "42" ]; then echo "💥 Memory leak detected!"; exit 42; fi; \
		exit $${code:-0}; \
	else \
		echo "⚠️  Valgrind indisponible, exécution simple."; \
		./$(NAME); \
	fi

build:
	$(PRINT_HEADER)
	$(CHECKS)
	@echo "📝 Lancement norminette..."
	@norminette $(EX_FILES) || true
	@echo "⚙️  Compilation..."
	@$(CC) $(CFLAGS) $(TEST_FILES) $(EX_FILES) -o $(NAME)
	@echo "✅ Binaire prêt: ./$(NAME)"

valgrind: build
	@echo "🧠 Exécution avec Valgrind..."
	@valgrind --leak-check=full --errors-for-leak-kinds=all --error-exitcode=42 ./$(NAME)

norm:
	$(PRINT_HEADER)
	$(CHECKS)
	@echo "📝 Lancement norminette..."
	@norminette $(EX_FILES) || true

list:
	$(PRINT_HEADER)

clean:
	@rm -f $(NAME)
	@echo "🧹 Nettoyage terminé."

help:
	@echo "Cibles disponibles:"
	@echo "  make run R=C03 [MODE=eval]   -> compile + exécute (Valgrind si présent)"
	@echo "  make build R=C03 [MODE=eval] -> compile uniquement"
	@echo "  make valgrind R=C03 [...]    -> force exécution sous Valgrind"
	@echo "  make norm R=C03 [...]        -> lance norminette sur les exos"
	@echo "  make list R=C03 [...]        -> affiche les fichiers détectés"
	@echo "  make clean                        -> supprime le binaire"
