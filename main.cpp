#include <iostream>
#include <ncurses.h>
#include <curses.h>
#include <stdlib.h>
#include <pthread.h>

#include "extra.h"
#include "global.h"
#include "map.h"                      //MIGHT NEED IT FIXME:
#include "stats.h"


extern char *entry_map[main_win_lines];


int x = 10, y = 10; 

int main() {
  Preparation terminal;
  terminal.START(); 
  init_pair(RED, COLOR_RED,COLOR_BLACK);
  init_pair(YELLOW, COLOR_YELLOW,COLOR_BLACK);
  init_pair(GREEN, COLOR_GREEN,COLOR_BLACK);

  WINDOW *win = terminal.SET_WINDOW(main_win_lines, main_win_cols, 0, 3);
  keypad(win, true);
  refresh();



  box(win, 0, 0); //  draws box on the window 
  refresh();

  terminal.WINDOW_REFRESH(win);

  WINDOW *win_2 = terminal.SET_WINDOW(second_win_lines, second_win_cols, main_win_lines, 3);
  terminal.REFRESH();

  box(win_2, 0, 0);
  terminal.WINDOW_REFRESH(win_2);// should be  refresh

  /* this is the main loop */

  /* TODO: initial map */
  terminal.SET_INITIAL_MAP(win,entry_map);
  terminal.WINDOW_REFRESH(win);

  int ch;
  while (true){
    attron(COLOR_PAIR(RED));
    mvaddch(y, x, '@');
    attroff(COLOR_PAIR(RED));
    refresh();

    ch  = getch();
    refresh();
    if (ch == 'Q' or ch == 'q')
      break;

    if (ch == 'k') {  
      if ( y == 1) {

        /* this gives bounderies */
        attron(COLOR_PAIR(YELLOW));
        mvaddch(y, x, '.');
        attroff(COLOR_PAIR(YELLOW));
        refresh();
        y = 1;

      }
      else {

        attron(COLOR_PAIR(YELLOW));
        mvaddch(y, x, '.');
        attroff(COLOR_PAIR(YELLOW));
        refresh();

        y--;
      }

    }
    if (ch =='h') { 

      /* this gives bounderies */
      if (x == 4) {
        attron(COLOR_PAIR(YELLOW));
        mvaddch(y, x, '.');
        attroff(COLOR_PAIR(YELLOW));
        refresh();
        x = 4;
      }
      else{
        attron(COLOR_PAIR(YELLOW));
        mvaddch(y, x, '.');
        attroff(COLOR_PAIR(YELLOW));
        refresh();
        x--;
      }
    }
    if (ch =='l') { 

      /* this gives bounderies */
      if (x == main_win_cols ) {
        attron(COLOR_PAIR(YELLOW));
        mvaddch(y, x, '.');
        attroff(COLOR_PAIR(YELLOW));
        refresh();
        x = main_win_cols ;
      }
      else {
        attron(COLOR_PAIR(YELLOW));
        mvaddch(y, x, '.');
        attroff(COLOR_PAIR(YELLOW));
        refresh();
        x++;
      }

    }
    if (ch =='j') { 
      /* this gives bounderies */
      if (y == main_win_lines -2) {
        attron(COLOR_PAIR(YELLOW));
        mvaddch(y, x, '.');
        attroff(COLOR_PAIR(YELLOW));
        refresh();
        y = main_win_lines -2;
      }
      else {

        attron(COLOR_PAIR(YELLOW));
        mvaddch(y, x, '.');
        attroff(COLOR_PAIR(YELLOW));
        refresh();
        y++;
      }
    }
  }
  endwin();
  return 0;

}
