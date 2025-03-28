# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g

OPENCV_FLAGS = $(shell pkg-config --cflags --libs opencv4)

# Target executable
TARGET = main

# Source files
SRCS = Main.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default rule to build and run the executable
all: $(TARGET) run

# Rule to link object files into the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET) $(OPENCV_FLAGS)

# Rule to compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(OPENCV_FLAGS) -c $< -o $@

# Rule to run the executable
run: $(TARGET)
	./$(TARGET)

# Clean rule to remove generated files (Fixed for WSL/Linux)
clean:
	rm -f $(TARGET) $(OBJS)
