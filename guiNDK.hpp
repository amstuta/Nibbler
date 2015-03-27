//
// guiGTK.hpp for IGui in /home/amstuta/rendu/cpp_nibbler
//
// Made by arthur
// Login   <amstuta@epitech.net>
//
// Started on  Tue Mar 17 18:39:38 2015 arthur
// Last update Fri Mar 27 14:33:55 2015 Lauranne Bruno
//

#ifndef GUINDK_HPP_
# define GUINDK_HPP_

#include <ncursesw/ncurses.h>
#include "IGui.hpp"

class GuiNDK: public IGui
{
private:
  int	win_x;
  int	win_y;
  WINDOW *window;
  std::vector<Point *> *snk;

public:
  GuiNDK();
  ~GuiNDK();

  void	initGui(int, int, std::vector<Point *> *);
  int	rcv_event();
  void	refresh();
  void	update();
};

#endif	// !GUINDK_HPP
