#!/usr/local/bin/lua

local nc = require("cursedLua")

function main()
    nc.initscr()
    nc.curs_set(0)
    nc.start_color()
    local y,x = nc.getmaxyx()
    x = (x - x%2)/2 - 7
    y = (y - y%2)/2 
    nc.mvprintw(y,x,"Hello, world!")
    nc.refresh()
    os.execute("sleep 5")
    nc.endwin()
end

main()

