# cursedLua

This Lua library is a wrapper around the ncurses C API meant to let you use the ncurses library in Lua.

## Content

### Functions

Not all the functions are ported, the list of currentely ported function is the following:
* initscr
* endwin
* curs\_set
* printw
* mvprintw
* move
* getmaxyx
* getch
* echo
* noecho
* has\_colors
* start\_color
* use\_default\_colors
* init\_pair
* nodelay
* refresh
* set\_color

### Other symbols

Some other symbols needed to use ncurses are available, they are the following:
* KEY\_ENTER
* KEY\_BACKSPACE
* KEY\_UP
* KEY\_DOWN
* KEY\_LEFT
* KEY\_RIGHT
* KEY\_HOME
* KEY\_END
* KEY\_NPAGE
* KEY\_PPAGE

## User manual

### Instalation

To install the library, simply do `make && sudo make install` from the root of the repository.

### Use

This library is meant to be required, like any other Lua libraries. To do so, start your program with `local nc = require("cursedLua")`. All the functions are inside the table nc. For example, to print something, you must do `nc.printw("something")`. For a more detailed example, check out the example folder.

When using embedded Lua, don't forget to link the library to your binary with `-lcursedLua`.

For every function, the number of arguments or their types is the same as the one expected by the ncurses C API.

## Further examples

To see this library in actual use, you can check out the programs I made with it. 
* https://github.com/Arkaeriit/snek
* https://github.com/Arkaeriit/evenmorelua
