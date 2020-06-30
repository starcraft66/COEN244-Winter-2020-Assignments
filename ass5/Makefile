CXX=clang++
CXXFLAGS = -Og -g

all: Q1

Q1: Circle.o Line.o Point.o Shape.o Triangle.o Q1.o
	$(CXX) -o Q1 Circle.o Line.o Point.o Shape.o Triangle.o Q1.o

clean:
	rm -f Q1 Q2 Q3 *.o