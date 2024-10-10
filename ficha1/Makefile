# Variables
CC = gcc              # Compiler
CFLAGS = -Wall -Wuninitialized -Werror -g     # Compiler flags: -Wall enables all warnings, -g includes debug information
LDFLAGS = -lm            # Linker flags (if any)
SRC = $(wildcard *.c) # All .c files in the directory
OBJ = $(SRC:.c=.o)    # Object files corresponding to the .c files
TARGET = my_program   # The name of the final executable

# Default target
all: $(TARGET)

# Linking the object files into the final executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

# Compiling the .c files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(OBJ) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Phony targets that aren't actual files
.PHONY: all clean run
