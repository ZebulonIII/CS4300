GCC := g++ -std=c++11
C := -c
O := -o

all: rubik_test

rubik_test: main.o Face.o RubiksCube.o
	$(GCC) $^ $(O) rubiks_test

main.o: main.cpp
	$(GCC) $(C) $<

Face.o: Face.cpp
	$(GCC) $(C) $<

RubiksCube.o: RubiksCube.cpp Face.h
	$(GCC) $(C) $<

clean:
	rm *.o rubiks_test
