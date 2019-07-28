
#include "cursedLua.h"

int cl_init(lua_State *L){
    initscr();
    return 0;
}

int cl_close(lua_State *L){
    endwin();
    return 0;
}

int cl_cursset(lua_State *L){
    int s = luaL_checknumber(L,1);
    if(s==0 | s==1 | s==2) curs_set(s);
    return 0;
}

int cl_refresh(lua_State *L){
    refresh();
    return 0;
}




int cl_mvprintw(lua_State *L){
    char* str = luaL_checkstring(L,3);
    int x = luaL_checknumber(L,2);
    int y = luaL_checknumber(L,1);
    mvprintw(y,x,"%s",str);
    return 0;
}




void cl_include(lua_State *L){
    lua_pushcfunction(L,cl_init);
    lua_setglobal(L,"initscr");
    lua_pushcfunction(L,cl_close);
    lua_setglobal(L,"endwin");
    lua_pushcfunction(L,cl_cursset);
    lua_setglobal(L,"curs_set");
    lua_pushcfunction(L,cl_mvprintw);
    lua_setglobal(L,"mvprintw");
    lua_pushcfunction(L,cl_refresh);
    lua_setglobal(L,"refresh");
}

