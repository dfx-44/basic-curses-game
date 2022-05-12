#ifndef STATS_H
#define STATS_H
#include <iostream>

#include "global.h"

using namespace std;

class Stats
{
public:
    /* members function */
    void set_initial(WINDOW *win2, int column, int row, int y, int x);
    void change_health(int y, int x, int amount);

private:
    /* private variables of the class */
    const char *life_bar;
    const char *mana_bar;
    int health;
    int mana_points;
};
#endif //STATS_H