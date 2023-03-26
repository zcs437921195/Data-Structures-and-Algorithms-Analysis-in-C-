CPP_FLAGS='-std=c++11'

objects = main.o

exercise: $(objects)
	g++ ${CPP_FLAGS} $(objects) -o exercise

main.o: main.cpp Chapter3.h
	g++ ${CPP_FLAGS} -c main.cpp

clean: 
	rm exercise $(objects)