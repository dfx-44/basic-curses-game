#ifndef HEADERFILE_H
#define HEADERFILE_H

#include <iostream>
#include <ncurses.h>
#include "global.h"
#include "map.h"

using namespace std;

class Preparation
{

public:
   void START();
   void REFRESH();

   WINDOW *SET_WINDOW(int _MAIN_WIN_LINES, int _MAIN_WIN_COLS, int start_y, int start_x);
   void WINDOW_REFRESH(WINDOW *win);
   void WINDOW_END();

   void NO_ECHO();
   void RAW();
   void iNIT_PAIR(short color_name, int background, int foreground);
   void START_COLOR();
   void ATTR_ON(int attribute);  //FIXME:
   void ATTR_OFF(int attribute); //FIXME:

   void MOVE(int y,int x,char ch,int MAIN_WIN_LINES,int MAIN_WIN_COLS);               
   void CREATE_MAP_HORI(int MAIN_WIN_LINES, int MAIN_WIN_COLS);
   void CREATE_MAP_VERT(int MAIN_WIN_LINES, int MAIN_WIN_COLS); 
   void SET_INITIAL_MAP(WINDOW *win,char *entry_map[main_win_lines]);
   void MOVE_ENEMY();
   void move_user(char ch, int y,int x);
   //void move_wizard(int y,int x,char ch,char wizard);


   /* FIXME FOR COLOR */
   void IF_HAS_COLOR();

private: //PRIVATES VARIABLES
};


#endif //HEADERFILE_H
