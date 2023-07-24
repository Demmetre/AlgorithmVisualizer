# Compiler
CXX := g++

SHELL := /bin/bash

# Compiler Flags
CXXFLAGS := -std=c++17 -Wall -Wextra

# SFML Directories
SFML_INCLUDE := -I./SFML-2.6.0/include
SFML_LIBS := -L./SFML-2.6.0/lib -lsfml-graphics -lsfml-window -lsfml-system

# Targets
TARGETS := main    # Add more targets if needed

# Default Target
all: $(TARGETS)

# Rules for Targets
main: main.cpp
	export LD_LIBRARY_PATH=./SFML-2.6.0/lib:$$LD_LIBRARY_PATH;
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) $< -o $@ $(SFML_LIBS)

# Clean
.PHONY: clean
clean:
	rm -f $(TARGETS)

.PHONY: all clean
