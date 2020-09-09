#!/usr/local/bin/lua

local nc = require("cursedLua")

function main()
    nc.initscr() --start ncurses
    nc.curs_set(0) --hide the cursor
    local y,x = nc.getmaxyx() --get the size of the terminal
    x = (x - x%2)/2 - 7 --check where to print a text in the center
    y = (y - y%2)/2 
    nc.mvprintw(y,x,"Hello, world!") --print the text in the center
    nc.refresh() --print results
    nc.getch() --wait for user input to end
    nc.endwin() --end ncurses
end

main()

