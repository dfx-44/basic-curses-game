#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <cstring>

#include "extra.h"
#include "global.h"
#include "map.h"



// GLOBAL TUPLE ARR AND EXTERN
extern const char entry_map[main_win_lines]; // extern declaration

void Preparation::move_user(char ch,int y,int x) {


}

void Preparation::START()
{
   /**
    * initiates the main screen
    *
    */

   initscr();
   this->IF_HAS_COLOR();
   this->START_COLOR();
   this->NO_ECHO();
   this->RAW();
   keypad(stdscr, true);
   cbreak();
   refresh();

}

void Preparation::REFRESH()
{
   /**
    *  refreshes each element
    */

   refresh();
}

WINDOW *Preparation::SET_WINDOW(int win_lines, int win_cols, int start_y, int start_x)
{
   /**
    * creates a new element window
    */

   WINDOW *win = newwin(win_lines, win_cols, start_y, start_x);
   refresh();
   return win;
}
void Preparation::WINDOW_REFRESH(WINDOW *win)
{

   wrefresh(win);
}

void Preparation::RAW()
{

   raw();
}

void Preparation::NO_ECHO()
{

   noecho();
}
void Preparation::START_COLOR()
{

   start_color();
}
void Preparation::CREATE_MAP_HORI(int MAIN_WIN_LINES, int MAIN_WIN_COLS)
{ //TODO:
   /**
    * inserts part of a map on a horizontal axis 
    * use it just when your char is going down 
    */

   for (int x = 4; x < MAIN_WIN_COLS; x++)
   {
      mvhline(1, x, '#', MAIN_WIN_LINES - 17);
   }
}

void Preparation::CREATE_MAP_VERT(int MAIN_WIN_LINES, int MAIN_WIN_COLS)
{ //FIXME: LATER
   /**
    * inserts  part of a map on a vertical axis
    * use it just when your char is going up
    */

   for (int x = 4; x < MAIN_WIN_COLS; x++)
   {
      mvvline(1, x, '#', MAIN_WIN_LINES - 17);
   }
}

void Preparation::SET_INITIAL_MAP(WINDOW *win, char *entry_map[main_win_lines])
{
   /**
    * this function will go from row to row (lines) and
    * rows will be added
    * TODO: use this int mvwhline(WINDOW *win, int y, int x, chtype ch, int n);
    * OR:  int mvwaddstr(WINDOW *win, int y, int x, const char *str);
    */
   /* initialize variables */
   int ts = 0;
   char char_temp;
   char *str_tmp; 
   int temp_x = 4;
   int tuple_index = 0;
   for (int y = 1; y < 19; y++)
   {                           
      /* current string */
      str_tmp = entry_map[ts]; 

      for (int x = 0; x < strlen(str_tmp); x++)
      { 
         /* chars in the current string */
         char_temp = str_tmp[x];

         if (char_temp == '#')
         {
            attron(COLOR_PAIR(GREEN));
            mvaddch(y, temp_x, char_temp);
            attroff(COLOR_PAIR(GREEN));
            refresh();
            if (temp_x < main_win_x)
               temp_x = 4;

            else
               temp_x++;
         }
         else if (char_temp == 'z')
         { // if char == ','
            attron(COLOR_PAIR(RED));
            mvaddch(y, temp_x, char_temp);
            attroff(COLOR_PAIR(RED));
            refresh();
            if (temp_x < main_win_x)
               temp_x = 4;
            else
               temp_x++;
         }
         else if (char_temp == 'E')
         { // if char == ','

            attron(COLOR_PAIR(RED));
            mvaddch(y, temp_x, char_temp);
            attroff(COLOR_PAIR(RED));
            refresh();
            if (temp_x < main_win_x)
               temp_x = 4;

            else
               temp_x++;
         }
         else
         {
            attron(COLOR_PAIR(YELLOW));
            mvaddch(y, temp_x, char_temp);
            attroff(COLOR_PAIR(YELLOW));
            refresh();
            if (temp_x < main_win_x)
               temp_x = 4;

            else
               temp_x++;
         }
      }
      ts++;
      temp_x = 4;
   }
}

void Preparation::MOVE_ENEMY() {
   /**
    * this will traverse thru the map 
    * and will change all the monsters in the given 
    * position.
    */

   int size_of_tuple_arr = 5; 
   int y,x, top,down;
   char sr;


   /* this is the tuple found inserted in 
      the map creation */

      mvaddch(y, x+4, '.');
      
      down = mvinch(y,x+4);
      refresh();
      mvaddch(y+1,x+4,sr);
      sleep(2);
      refresh();

   
}


void Preparation::IF_HAS_COLOR()
{
   /**
    * should be included before you do colors on 
    * the screen.
    */

   if (has_colors() == FALSE)
   {
      endwin();
      printf("Your terminal does not support color\n");
      exit(1);
   }
}
