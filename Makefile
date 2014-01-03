FLAGS = -W -g 

all:    utfil.exe

utfil.exe: tree.o program.o
	gcc $(FLAGS) -o utfil.exe tree.o program.o

program.o: program.c
	gcc $(FLAGS) -c program.c

tree.o:	tree.c tree.h
	gcc $(FLAGS) -c tree.c

clean:
	touch dumt.o utfil.exe
	rm *.o utfil.exe
