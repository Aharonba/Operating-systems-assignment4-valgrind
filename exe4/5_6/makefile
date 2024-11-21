# Makefile to compile and run Valgrind with gdb support on the original main.c program

CC = gcc
CFLAGS = -g -Wall
TARGET = main
SRC = main.c

# Rule to compile the program
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Rule to run Valgrind
valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET) arg1 arg2 arg3

# Rule to run Valgrind with gdb support
valgrind-gdb: $(TARGET)
	valgrind --vgdb=yes --vgdb-error=0 ./$(TARGET) hello world this is a test

# Rule to clean up the compiled files
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: all clean valgrind valgrind-gdb
