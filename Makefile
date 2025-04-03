CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2

all: matrix_output

matrix_output: main.o matrix.o
	$(CXX) $(CXXFLAGS) -o matrix_output main.o matrix.o

main.o: main.cpp matrix.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

matrix.o: matrix.cpp matrix.hpp
	$(CXX) $(CXXFLAGS) -c matrix.cpp

clean:
	rm -f *.o matrix_output
