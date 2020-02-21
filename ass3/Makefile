CXX=clang++
CXXFLAGS = -Og -g

all: problem1

problem1: Reference.o Article.o Book.o TextBook.o ReferenceManager.o
	$(CXX) -o problem1 Reference.o Article.o Book.o TextBook.o ReferenceManager.o

clean:
	rm -f problem1 *.o