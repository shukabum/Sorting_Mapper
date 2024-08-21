# Compiler to use
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# Output executable name
TARGET = Sorting_Project

# Source files
SRCS = main.cpp sorting_algorithms.cpp time_comparison.cpp mystery_sorting.cpp

# Object files (generated from source files)
OBJS = $(SRCS:.cpp=.o)

# Library files
LIBS = libmystery_sorting.a

# Rule to build the executable
$(TARGET): $(OBJS) $(LIBS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) -L. -lmystery_sorting

# Rule to build object files from source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to create the mystery sorting library
$(LIBS): mystery_sorting.o
	ar rcs $(LIBS) mystery_sorting.o

mystery_sorting.o: mystery_sorting.cpp mystery_sorting.h sorting_algorithms.h
	$(CXX) $(CXXFLAGS) -c mystery_sorting.cpp -o mystery_sorting.o

# Clean rule to remove generated files
clean:
	rm -f $(TARGET) $(OBJS) $(LIBS) mystery_sorting.o

# Phony targets (not actual files)
.PHONY: clean
