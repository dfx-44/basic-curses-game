//#include <iostream> 

#include <ncurses.h>

#include "game.h"
#include "global.h"

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

  int width = 124;
  int height = 25;
  main_y = 4, main_x = 4;
  win = newwin(height,width,main_y,main_x);

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

void Game::move_player(int in) {

   /*                3. make the boundries to the current map on the window
    *                4. put the map on the screen with for loops
   **/

  // initializes the position of the player 
  // in the window

  if (in == 'l') {

    /* goes to the right */
    mvwaddch(win,y, x, ' ');
    wrefresh(win);
    x++;

    if (x >  width - 3) {
      x--;

    }


  } if (in == 'k') {

    /* goes to the up */
    mvwaddch(win,y, x, ' ');
    wrefresh(win);
    y--;
    if (y < 1) {
      y++;

    }

  }if (in == 'j') {

      /* goes to the down */
      mvwaddch(win,y, x, ' ');
      wrefresh(win);
      y++;
      if (y > height -2) {

        y--;
      }

    } 
    if (in == 'h') {

      /* goes to the left */
      mvwaddch(win,y, x, ' ');
      wrefresh(win);
      x--;
      if (x < 1)
        x++;

    } 
      /* moves to the player 
      * char to the correct place */
      mvwaddch(win,y, x, '@');
      wrefresh(win);

  }
///////////////////////////////////////////////
//
//   Put Map  
///////////////////////////////////////////////

void Game::put_map( *map[]) {

    for(int i = 0; i< ;i++){


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
