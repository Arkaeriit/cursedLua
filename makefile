all : clean test.bin

cusedLua.o : cursedLua.c cursedLua.h
	gcc -c cursedLua.c -Wall -Werror -o cursedLua.o

main.o : exemple.c cursedLua.h
	gcc -c exemple.c -Wall -Werror -o main.o

test.bin : main.o cursedLua.o 
	gcc main.o cursedLua.o -Wall -Werror -lncursesw -llua -lm -ldl -o test.bin

clean : 
	rm -f *.bin
	rm -f *.o

