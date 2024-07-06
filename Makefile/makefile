# Variables
CC = gcc
INCS = -I./include
SRC = src
BIN = bin
BUILD = build
SRC_FILES = $(wildcard $(SRC)/*.c)
OBJ_FILES = $(patsubst $(SRC)/%.c, $(BIN)/%.o, $(SRC_FILES))
TARGET = $(BUILD)/app

# Rules
all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	@mkdir -p $(BUILD)
	$(CC) $(OBJ_FILES) -o $(TARGET)

$(BIN)/%.o: $(SRC)/%.c
	@mkdir -p $(BIN)
	$(CC) $(INCS) -c $< -o $@

clean:
	rm -rf $(BIN)/*.o $(BUILD)/*

.PHONY: all clean
