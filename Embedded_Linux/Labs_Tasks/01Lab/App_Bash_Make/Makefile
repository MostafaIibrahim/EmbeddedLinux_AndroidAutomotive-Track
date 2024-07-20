# Define variables
CC?= gcc
INCS = -I./includes
SRC = src 
BINARY = bin
BUILD = build 
STATIC = slib 
DYNAMIC = dlib
APP = app

SRC_FILES = $(wildcard $(SRC)/*.c)
OBJ_FILES = $(patsubst $(SRC)/%.c, $(BINARY)/%.o, $(SRC_FILES))

TARGET = $(APP)/main
SLIB = $(STATIC)/libmostafas.a
DLIB = $(DYNAMIC)/libmostafad.so

# Default target
all: buildst builddy linkst linkdy

# Rule to compile source files into object files
$(BINARY)/%.o: $(SRC)/%.c
	@if [ ! -d $(BINARY) ]; then mkdir -p $(BINARY); fi
	$(CC) $(INCS) -c $< -o $@

# Rule to build static library
$(SLIB): $(OBJ_FILES)
	@if [ ! -d $(STATIC) ]; then mkdir -p $(STATIC); fi
	@ar rcs $@ $^

# Rule to build dynamic library
$(DLIB): $(OBJ_FILES)
	@if [ ! -d $(DYNAMIC) ]; then mkdir -p $(DYNAMIC); fi
	$(CC) -shared -o $@ $^

# Build static library
buildst: $(SLIB)

# Build dynamic library
builddy: $(DLIB)

# Link the application with the static library
linkst: $(TARGET).st

$(TARGET).st: $(SLIB)
	$(CC) $(INCS) -o $@ $(TARGET).c -L$(STATIC) -lmostafas

# Link the application with the dynamic library
linkdy: $(TARGET).dy

$(TARGET).dy: $(DLIB)
	$(CC) $(INCS) -o $@ $(TARGET).c -L$(DYNAMIC) -lmostafad

# Clean up generated files
clean:
	rm -rf $(BINARY)/*.o $(SLIB) $(DLIB) $(TARGET).st $(TARGET).dy

.PHONY: all clean buildst builddy linkst linkdy
