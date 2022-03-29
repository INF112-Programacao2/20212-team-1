
# Se qovcê deseja trocar o nome do arquivo de saída do compilador, troque o valor da diretiva abaixo
EXE=capigame # Executable file name

# Source files to compile
SRC=main.cpp Battle.cpp Capimon.cpp Character.cpp Dialog.cpp HomeMenu.cpp Interaction.cpp Map.cpp Npc.cpp Object.cpp Player.cpp Position.cpp Skill.cpp
# Source files directory
SRC_DIR=src
 # Included directories
INCLUDE=-IALLEGRO_DIR
 # Used libraries
LIB=-lallegro -lallegro_image -lallegro_font -lallegro_ttf -lallegro_audio -lallegro_acodec
 # GNU C++ compilers flags
CFLAGS=-lstdc++
# GCC compiler
CXX=gcc


# Directive to generate the executable file. This is default
.PHONY: all
all: $(EXE)

$(EXE): $(SRC)
	@echo "\n'\033[0;32m'Gerando $(SRC_DIR)/$@...'\033[0m'\n"
	cd $(SRC_DIR); $(CXX) $^ -o $@ $(INCLUDE) $(CFLAGS) $(LIB)

%.cpp:
	@touch "$(SRC_DIR)/$@"

# Directive to run the executable file
.PHONY: run
run:
	cd "$(SRC_DIR)"; ./$(EXE)

# Directive to clean the generated files
.PHONY: clean
clean:
	rm -f $(SRC_DIR)/$(EXE)
