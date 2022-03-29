
INCLUDE=-IALLEGRO_DIR
LIB=-lallegro -lallegro_image -lallegro_font -lallegro_ttf -lallegro_audio -lallegro_acodec
CFLAGS=-W -Wall -lstdc++
CXX=gcc
EXE=capigame
SRC_DIR=src
SRC=main.cpp Battle.cpp Capimon.cpp Character.cpp Dialog.cpp HomeMenu.cpp Interaction.cpp Map.cpp Npc.cpp Object.cpp Player.cpp Position.cpp Skill.cpp

.PHONY: all
all: $(EXE)
	@echo "Building $<"

$(EXE): $(SRC)
	cd $(SRC_DIR); $(CXX) $^ -o $@ $(INCLUDE) $(CFLAGS) $(LIB)

%.cpp:
	@touch "$(SRC_DIR)/$@"

clean:
	rm -f
