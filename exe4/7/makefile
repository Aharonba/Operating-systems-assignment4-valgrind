# Makefile to compile the program and detect race conditions with Valgrind
CC = gcc
CFLAGS = -g -Wall
TARGET = main
SRC = main.c

# Rule to compile the program
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) -lpthread

# Rule to run Valgrind with Helgrind to detect race conditions
helgrind: $(TARGET)
	valgrind --tool=helgrind ./$(TARGET)

# Rule to clean up the compiled files
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: all clean helgrind
