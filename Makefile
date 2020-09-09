FLAGS = -Wall -Werror -g
NC = -lncursesw
LIBLUAPATH = /usr/local/lib/lua/5.3

all : cursedLua.so

cursedLua.o : cursedLua.c
	gcc -c -fPIC cursedLua.c $(FLAGS) -o cursedLua.o

cursedLua.so : cursedLua.o
	gcc -shared cursedLua.o $(NC) -o cursedLua.so

install : 
	cp -f cursedLua.so $(LIBLUAPATH)/cursedLua.so

uninstall :
	rm -f $(LIBLUAPATH)/cursedLua.so

clean :
	rm -f *.o
	rm -f *.so

