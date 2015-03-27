//
// guiGTK.cpp for guiGTK in /home/amstuta/rendu/cpp_nibbler
//
// Made by arthur
// Login   <amstuta@epitech.net>
//
// Started on  Tue Mar 17 18:39:50 2015 arthur
// Last update Fri Mar 27 15:01:06 2015 Lauranne Bruno
//

#include <ncurses.h>
#include <iostream>
#include "guiNDK.hpp"

GuiNDK::GuiNDK():
  IGui::IGui()
{}

GuiNDK::~GuiNDK()
{
  delwin(this->window);
  endwin();
}

static void	draw_border(WINDOW *window, int x, int y)
{
  int		i;

  for (i = 0; i < (y - 1); i++)
    {
      mvwprintw(window, i, 0, "*");
      mvwprintw(window, i, x - 1, "*");
    }
  for (i = 0; i < (x - 1); i++)
    {
      mvwprintw(window, 0, i, "*");
      mvwprintw(window, y - 1, i, "*");
    }
  mvwprintw(window, y - 1, i, "*");
}

void		GuiNDK::initGui(int x, int y, std::vector<Point *> *snake)
{
  if (x < 0 && y < 0)
    return;
  this->snk = snake;
  this->win_x = 20;
  this->win_y = 20;
  initscr();
  noecho();
  cbreak();
  curs_set(FALSE);
  this->window = newwin(this->win_y, this->win_x, 0, 0);
  draw_border(this->window, this->win_x, this->win_y);
}

void		GuiNDK::refresh()
{
  wrefresh(this->window);
}

void		GuiNDK::update()
{
  int		x;
  int		y;

  x = 1;
  while (x < this->win_x - 1)
    {
      y = 1;
      while (y < this->win_y - 1)
	{
	  mvwprintw(this->window, y, x, " ");
	  y = y + 1;
	}
      x = x + 1;
    }
  for (std::vector<Point*>::const_iterator it = snk->begin();
       it != snk->end(); ++it)
    mvwprintw(this->window, (*it)->second + 1, (*it)->first + 1, "o");
}

int		GuiNDK::rcv_event()
{
  int		key;

  nodelay(this->window, TRUE);
  keypad(this->window, TRUE);
  key = wgetch(this->window);
  if (key == KEY_LEFT)
    return (-1);
  if (key == KEY_RIGHT)
    return (1);
  if (key == 27)
    return (2);
  return (0);
}

extern "C"
{
  IGui	*create_gui()
  {
    return new GuiNDK;
  }
}
