FLAGS = -std=c++11 -Wall -pedantic
CC = g++
LIBS = -lGL -lGLU -lGLEW -lglfw

all:
	$(CC) $(FLAGS) -c particle.hpp
	$(CC) $(FLAGS) -c render.cpp 
	$(CC) -o play render.o $(LIBS)

clean:
	rm *.o *.gch

