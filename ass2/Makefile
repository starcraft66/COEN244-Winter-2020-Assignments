CXX=clang++
CXXFLAGS = -Og -g

all: problem1

problem1: Date.o Passenger.o Person.o ReservationRequest.o ReservationManager.o
	$(CXX) -o problem1 Date.o Passenger.o Person.o ReservationRequest.o ReservationManager.o

clean:
	rm -f problem1 *.o