# Compiler
CXX := g++

# Compiler Flags
CXXFLAGS := -std=c++17 -Wall -Wextra

# SFML Directories
SFML_INCLUDE := -I./SFML-2.6.0/include
SFML_LIBS := -L./SFML-2.6.0/lib -lsfml-graphics -lsfml-window -lsfml-system

# Source Files
SOURCES := $(wildcard *.cpp)

# Object Files
OBJECTS := $(SOURCES:.cpp=.o)

# Targets
TARGET := main    # Add more targets if needed

# Default Target
all: $(TARGET)

# Rules for Targets
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) $^ -o $@ $(SFML_LIBS)

# Rules for Object Files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) -c $< -o $@

# Clean
.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJECTS)

.PHONY: all clean
