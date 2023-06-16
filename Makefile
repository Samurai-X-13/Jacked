# Makefile

# Compiler
CC := g++

# Compiler flags
CFLAGS := -Wall -Wextra -std=c++17

# Source file
SRC := main.cpp

# Output executable name
EXECUTABLE := Jacked

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRC)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(EXECUTABLE)
