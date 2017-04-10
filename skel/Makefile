# make all sources under ./src respectively
CC      = g++
CFLAGS  = -g -MMD -MP
LDFLAGS =
LIBS    =
INCLUDE = -I ./include
SRC_DIR = ./src
OBJ_DIR = ./build
BIN_DIR = ./bin
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJS    = $(subst $(SRC_DIR), $(OBJ_DIR), $(SOURCES:.cpp=.o))
TARGET  = $(subst $(SRC_DIR), $(BIN_DIR), $(SOURCES:.cpp=))
BINS    = $(BIN_DIR)/*
DEPENDS = $(OBJS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJS) $(LIBS)

$(BIN_DIR)/%: $(OBJ_DIR)/%.o
	@if [ ! -d $(BIN_DIR) ]; \
		then echo "mkdir -p $(BIN_DIR)"; mkdir -p $(BIN_DIR); \
	fi
	$(CC) -o $@ $< $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@if [ ! -d $(OBJ_DIR) ]; \
		then echo "mkdir -p $(OBJ_DIR)"; mkdir -p $(OBJ_DIR); \
	fi
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

clean:
	$(RM) $(OBJS) $(TARGET) $(DEPENDS)

-include $(DEPENDS)

.PHONY: all clean
