# Variables
CXX = g++
CXXFLAGS = -Wall -g -pg -fprofile-arcs -ftest-coverage

# Target to compile the entire project
all: demo

# Rule to build the executable from the object file
demo: main.o
	$(CXX) $(CXXFLAGS) -o demo main.o -lgcov

# Rule to compile main.cpp
main.o: main.cpp Graph.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

# Run Valgrind memory check (existing target)
valgrind_check: demo
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./demo -v 10 -e 12 -s 42 > valgrind_report.txt 2>&1

# Run Callgrind and generate a filtered call graph (new target)
callgrind_check: demo
	valgrind --tool=callgrind ./demo -v 10 -e 12 -s 42
	callgrind_annotate callgrind.out.* > callgrind_report.txt
	grep -v "std::\|__gnu_cxx\|allocator\|libc.so\|libstdc++\|ld-linux" callgrind_report.txt > filtered_callgrind_report.txt

# Clean up the object files, executable, and reports
clean:
	rm -f *.o demo *.gcda *.gcno *.gcov valgrind_report.txt *.out callgrind.out.* callgrind_report.txt filtered_callgrind_report.txt

# Phony targets
.PHONY: all clean valgrind_check callgrind_check
