#include <iostream>
#include <ncurses.h>

#include "stats.h"
#include "global.h"

void Stats::set_initial(WINDOW *win2, int column, int row, int y, int x)
{
    /*
     * sets the initial layout of the 
     * second window and its colors
     */

    life_bar = "==========";
    mana_bar = "**********";
    health = 10;
    mana_points = 15;
    const char *life = "Life: ";
    const char *mana = "Mana: ";

    attron(COLOR_PAIR(RED));
    mvprintw(y + 8, x + 1, mana);
    attroff(COLOR_PAIR(RED));

    attron(COLOR_PAIR(LIGHT_BLUE));
    mvprintw(y + 8, x + 6, mana_bar);
    attroff(COLOR_PAIR(LIGHT_BLUE));

    attron(COLOR_PAIR(RED));
    mvprintw(y + 3, x + 1, life);
    attroff(COLOR_PAIR(RED));

    attron(COLOR_PAIR(LIGHT_BLUE));
    mvprintw(y + 3, x + 6, life_bar);
    attroff(COLOR_PAIR(LIGHT_BLUE));
}

void Stats::change_health(int y, int x, int amount)
{
    /*
     * lowers the health of the life_bar with a number
     *
     */
    int tmp = health - amount;
    if (tmp <= 0)
    { //  no life
    }
    else
    {
        char buf[1024] = {0}; // room for 1024 chars (or 1023 + a 0 byte for a string)
        char *str = buf;
        char c = '=';
        const char *next_bar;

        /* adds to the amount of numbers */
        for (int i = 0; i < tmp; i++)
        {
            *str++ = c;
        }
        health = tmp;
        life_bar = str;
    }
}
