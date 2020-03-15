CXX=clang++
CXXFLAGS = -Og -g

all: problem1

problem1: Bed.o Date.o Doctor.o Hospital.o InPatient.o OutPatient.o Person.o problem1.o Time.o
	$(CXX) -o problem1 Bed.o Date.o Doctor.o Hospital.o InPatient.o OutPatient.o Person.o problem1.o Time.o

clean:
	rm -f problem1 *.o