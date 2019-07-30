
#include "cursedLua.h"

int cl_init(lua_State *L){
    initscr();
    return 0;
}

int cl_echo(lua_State *L){
    echo();
    return 0;
}

int cl_noecho(lua_State *L){
    noecho();
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

int cl_getxy(lua_State *L){
    int x;
    int y;
    getmaxyx(stdscr,y,x);
    lua_pushnumber(L,y);
    lua_pushnumber(L,x);
    return 2;
}

int cl_getch(lua_State *L){
    int elem = getch();
    switch(elem){
        case KEY_ENTER :
            lua_pushstring(L,"KEY_ENTER");
            break;
        case KEY_BACKSPACE :
            lua_pushstring(L,"KEY_BACKSPACE" );
            break;
        case KEY_UP :
            lua_pushstring(L,"KEY_UP" );
            break;
        case KEY_DOWN :
            lua_pushstring(L,"KEY_DOWN" );
            break;
        case KEY_LEFT :
            lua_pushstring(L,"KEY_LEFT" );
            break;
        case KEY_RIGHT :
            lua_pushstring(L,"KEY_RIGHT" );
            break;
        case KEY_HOME :
            lua_pushstring(L,"KEY_HOME" );
            break;
        case KEY_END :
            lua_pushstring(L,"KEY_END");
            break;
        case KEY_NPAGE :
            lua_pushstring(L,"KEY_END" );
            break;
        case KEY_PPAGE :
            lua_pushstring(L,"KEY_PPAGE" );
            break;
        default :
            lua_pushstring(L,(char*) &elem);
    }
    return 1;
}

int cl_mvprintw(lua_State *L){
    const char* str = luaL_checkstring(L,3);
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
    lua_pushcfunction(L,cl_getxy);
    lua_setglobal(L,"getmaxyx");
    lua_pushcfunction(L,cl_getch);
    lua_setglobal(L,"getch");
    lua_pushcfunction(L,cl_echo);
    lua_setglobal(L,"echo");
    lua_pushcfunction(L,cl_noecho);
    lua_setglobal(L,"noecho");
}

