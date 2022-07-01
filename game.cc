//#include <iostream> 
#include <ncurses.h>

#include "game.h"

//using namespace std;
///////////////////////////////////////////////
//
//        contructor 
///////////////////////////////////////////////
Game::Game() {

  // this is the contructor that initializes the ncurses screen and 
  // the playing window 
  initscr();
  cbreak();
  noecho();


  width = 124;
  height = 25;
  win = newwin(height,width,4,4);

  x = 10, y=10;

  keypad(win, true);
  box(win,0,0);

  refresh();
  wrefresh(win);

}

///////////////////////////////////////////////
//
//       move player 
///////////////////////////////////////////////

void Game::keep_char_in_screen(int y,int x) {

  if (y >= height) {

    y--;

  }

  if (y <= 12) {

    y++;

  }

  if (x <=12) {

    x++;

  }

  if (x >= width) {

    x--; 

  }

  mvwaddch(win,y, x, '@');
  wrefresh(win);



}
void Game::move_player(int in) {

  /* TODO           1. set all the movements of the player here
   *                2. make boundries on the corners of the screen
   *                3. make the boundries to the current map on the window
   **/

  // initializes the position of the player 
  // in the window

  if (in == 'l') {

    /* goes to the right */
    mvwaddch(win,y, x, ' ');
    wrefresh(win);
    x++;


  } if (in == 'k') {

    /* goes to the up */
    mvwaddch(win,y, x, ' ');
    wrefresh(win);
    y--;


  }if (in == 'j') {

      /* goes to the down */
      mvwaddch(win,y, x, ' ');
      wrefresh(win);
      y++;

    } 
    if (in == 'h') {

      /* goes to the left */
      mvwaddch(win,y, x, ' ');
      wrefresh(win);
      x--;

    } 

  }
///////////////////////////////////////////////
//
//      Game Destructor 
///////////////////////////////////////////////

Game::~Game() {

  // GAME OVER!!!
  getch();
  endwin();

}


