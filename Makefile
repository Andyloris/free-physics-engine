SRC_DIR = src/
INCLUDE_DIR = include/
BIN_DIR = bin/
OBJ_DIR = obj/

OUT = $(BIN_DIR)out
LIB = $(BIN_DIR)free-physics-engine.a

CC = cc
AR = ar rcs

WARNINGS = -Wall -Wextra -Wshadow -Wpointer-arith -Wcast-align -Wwrite-strings -Wredundant-decls -Wnested-externs -Winline -Wconversion -Wstrict-prototypes
CFLAGS = $(WARNINGS) -c -O3 -fno-math-errno
LDFLAGS = -lm 

SRCS = $(wildcard $(SRC_DIR)*.c)
OBJS = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))
HEADERS = $(wildcard $(INCLUDE_DIR)*.h)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(OBJ_DIR) $(HEADERS) Makefile
	 $(CC) $(CFLAGS) $< -o $@ -I $(INCLUDE_DIR)

$(OUT): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(OUT)

$(LIB): $(OBJS)
	$(AR) $(LIB) $(OBJS)

$(BIN_DIR):
	mkdir $(BIN_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

run: $(OUT)
	$(OUT)

clean:
	rm -f $(OBJ_DIR)*
	rmdir $(OBJ_DIR)
	rm -f $(BIN_DIR)*
	rmdir $(BIN_DIR)

all: $(BIN_DIR) $(OBJ_DIR) $(OUT) $(LIB)
lib: $(BIN_DIR) $(OBJ_DIR) $(LIB)
