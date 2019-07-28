
function main()
    initscr()
    curs_set(0)
    local y,x = getmaxyx()
    x = (x - x%2)/2 - 7
    y = (y - y%2)/2 
    mvprintw(y,x,"Hello, world!")
    refresh()
    wait(50000000)
    endwin()
end

function wait(n)
    for i=1,n do
        local a="lol"
        a= a..a..a
    end
end
