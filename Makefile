FLAGS = -Wall -Werror
NC = -lncursesw
LIBLUAPATH_5_4 = /usr/local/lib/lua/5.4
LIBLUAPATH_5_3 = /usr/local/lib/lua/5.3
LIBPATH = /usr/lib64

all : cursedLua.so

cursedLua.o : cursedLua.c
	gcc -c -fPIC cursedLua.c $(FLAGS) -o cursedLua.o

cursedLua.so : cursedLua.o
	gcc -shared cursedLua.o $(NC) -o cursedLua.so

install : 
	mkdir -p $(LIBLUAPATH_5_4) $(LIBLUAPATH_5_3) $(LIBPATH)
	cp -f cursedLua.so $(LIBLUAPATH_5_4)/cursedLua.so
	cp -f cursedLua.so $(LIBLUAPATH_5_4)/cursedLua.so
	cp -f cursedLua.so $(LIBPATH)/libcursedLua.so

uninstall :
	rm -f $(LIBLUAPATH)/cursedLua.so
	rm -f $(LIBPATH)/libcursedLua.so

clean :
	rm -f *.o
	rm -f *.so

