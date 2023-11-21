SRC_DIR = src/
INCLUDE_DIR = include/
BIN_DIR = bin/
OUT = $(BIN_DIR)out
CC = cc
CFLAGS = -Wall -lm -O3 -fno-math-errno

SRCS = $(wildcard $(SRC_DIR)*.c)
HEADERS = $(wildcard $(INCLUDE_DIR)*.h)

$(BIN_DIR):
	mkdir $(BIN_DIR)

$(OUT): $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(SRCS) -o $(OUT) -I $(INCLUDE_DIR)

run: $(OUT)
	$(OUT)

all: $(BIN_DIR) $(OUT)
