/*----------------------------------------------------\
|Ces fonctions ont pour but d'être appelés en lua pour|
|se servir de ncurses en lua.                         |
\----------------------------------------------------*/

#include <ncurses.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

//Foncions qui servent à un crontrole général de l'écrant

int cl_init(lua_State *L); //permet d'initialiser ncurses
int cl_close(lua_State *L); //permet de fermer ncurses
int cl_cursset(lua_State *L); //permet de chisir l'état du curseur
int cl_refresh(lua_State *L);

//Fonctions servant à écrire sur l'écrant

int cl_mvprintw(lua_State *L); //permet d'écrire sur l'écrant


//fonction à appeler en C pour charger la librairie

void cl_include(lua_State *L); //Permet d'inclure dans le lua_State les autres fonctions
