# Usage:
#   make run R=C00            # tests in ./C00 and exos in ../C00/ex*
#   make run R=C00 MODE=eval  # tests in ./C00 and exos in ../ex*
#   make build | make valgrind | make norm | make list | make clean

SHELL       := /bin/bash

R           ?= C04
MODE        ?= default
CC          ?= cc
CFLAGS      := -Wall -Wextra -Werror
NAME        := test_$(R)
XF			?= *.out

VERBOSE		?= 1
ASCII		?= 1

# ---------- Where to find exercises ----------
EX_BASE     := $(if $(filter $(MODE),eval),..,../$(R))
EX_FILES    := $(wildcard $(EX_BASE)/ex*/*.c)

# C11 special: ex05 (do-op) is a standalone program → exclude from harness
ifeq ($(R),C11)
  EX_FILES  := $(filter-out $(EX_BASE)/ex05/%,$(EX_FILES))
endif

# ---------- Tests / common / defines ----------
TEST_DIR    := $(R)
# Compile only the aggregator for this module (avoid unresolved refs).
TEST_FILES  := $(wildcard $(R)/tests.c)

COMMON := common/assert.c common/main.c common/data.c common/list_helpers.c
DEFS		:= -DTEST_TARGET=$(R) -DDATA_PATH=\"$(R)/data.txt\"

# Auto-generate -DHAVE_EXNN only for exercises that exist
EX_IDS      := 00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17
EX_DEFS     := $(foreach n,$(EX_IDS),$(if $(wildcard $(EX_BASE)/ex$(n)/*.c),-DHAVE_EX$(n),))
DEFS        += $(EX_DEFS)
# ---------- Toggles ----------
ifeq ($(VERBOSE),1)
DEFS += -DTEST_VERBOSE=1
endif

# (optional) ASCII-only output for Windows consoles
ifeq ($(ASCII),1)
DEFS += -DTEST_ASCII_ONLY=1
endif


# For nicer header print
EX_SHOW     := $(EX_BASE)/ex*/



# ---------- Pretty header ----------
define PRINT_HEADER
	@echo "📂 Cible:                $(R)  (mode: $(MODE))"
	@echo "🧪 Dossier tests:        $(TEST_DIR)"
	@echo "📦 Dossiers exos:        $(EX_SHOW)"
	@echo "📄 Fichiers exos:" ; \
	if [ -n "$(EX_FILES)" ]; then printf '  - %s\n' $(EX_FILES); else echo "  (aucun)"; fi
	@echo "🧪 Fichiers tests:" ; \
	if [ -n "$(TEST_FILES)" ]; then printf '  - %s\n' $(TEST_FILES); else echo "  (aucun)"; fi
endef

# ---------- Checks ----------
define CHECKS
	@if ! [[ "$(R)" =~ ^C[0-9]{2}$$ ]]; then \
		echo "❌ Usage: make run R=CXX [MODE=eval]"; \
		exit 1; \
	fi
	@if [ -z "$(EX_FILES)" ]; then \
		echo "❌ Aucun fichier .c d'exercice trouvé dans: $(EX_SHOW)"; \
		exit 1; \
	fi
	@if [ -z "$(TEST_FILES)" ]; then \
		echo "❌ Aucun fichier de tests trouvé dans $(TEST_DIR) (tests.c)"; \
		exit 1; \
	fi
endef

# ---------- Rules ----------
.PHONY: run build valgrind norm list list-haves lint-tests doop clean help

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
	@$(CC) $(CFLAGS) $(DEFS) $(COMMON) $(TEST_FILES) $(EX_FILES) -o $(NAME)
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

list-haves:
	@echo "HAVE flags: $(EX_DEFS)"

# Spot leftover junk in module folder
lint-tests:
	@bad=$$(ls $(R) 2>/dev/null | grep -E '^(main\.c|assert\.c|.*\.sh)$$' || true); \
	if [ -n "$$bad" ]; then \
		echo "⚠️  Unexpected files in $(R):"; echo "$$bad" | sed 's/^/  - /'; exit 1; \
	else echo "✅ $(R) looks clean."; fi

# Optional: build C11 do-op (ex05) if present
DOOP_SRCS := $(wildcard $(EX_BASE)/ex05/*.c)
doop:
	@if [ -z "$(DOOP_SRCS)" ]; then \
		echo "❌ No ex05 sources found in $(EX_BASE)/ex05"; exit 1; \
	fi
	$(CC) $(CFLAGS) $(DOOP_SRCS) -o do-op
	@echo "✅ Built ./do-op (usage: ./do-op 1 + 41)"

clean:
	@rm -f $(NAME) do-op $(XF)
	@echo "🧹 Nettoyage terminé."

help:
	@echo "Cibles disponibles:"
	@echo "  make run R=C03 [MODE=eval]   -> compile + exécute (Valgrind si présent)"
	@echo "  make build R=C03 [MODE=eval] -> compile uniquement"
	@echo "  make valgrind R=C03 [...]    -> force exécution sous Valgrind"
	@echo "  make norm R=C03 [...]        -> lance norminette sur les exos"
	@echo "  make list R=C03 [...]        -> affiche les fichiers détectés"
	@echo "  make list-haves R=C03 [...]  -> affiche les -DHAVE_EXNN activés"
	@echo "  make doop R=C11              -> (optionnel) build de ex05/do-op"
	@echo "  make clean                   -> supprime les binaires"
