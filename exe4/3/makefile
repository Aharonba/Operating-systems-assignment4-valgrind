CXX = g++
CXXFLAGS = -Wall -g

# Target to compile the entire project
all: demo

# Rule to build the executable from the object file
demo: main.o
	$(CXX) $(CXXFLAGS) -o demo main.o

# Rule to compile main.cpp
main.o: main.cpp Graph.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

# Clean up the object files and the executable
clean:
	rm -f *.o demo

# Phony targets
.PHONY: all clean
