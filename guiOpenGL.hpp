//
// guiOpenGL.hpp for IGui in /home/bruno_a/rendu/cpp_nibbler
// 
// Made by Lauranne Bruno
// Login   <bruno_a@epitech.net>
// 
// Started on  Mon Mar 30 10:38:46 2015 Lauranne Bruno
// Last update Mon Mar 30 17:04:31 2015 Lauranne Bruno
//

#ifndef GUIOPENGL_HPP_
# define GUIOPENGL_HPP_

#include <SDL/SDL.h>
#include "IGui.hpp"

# define BOX 20

class GuiOpenGL : public IGui
{
private:
  int		x;
  int		y;
  double	x_size;
  double	y_size;
  SDL_Surface	*window;
  std::vector<Point *> *snk;

public:
  GuiOpenGL();
  ~GuiOpenGL();

  void	initGui(int, int, std::vector<Point *> *);
  int	rcv_event();
  void	refresh();
  void	update();
  void  dispFruit(std::map<Point, Fruit> &);
  void  showScore(int);
};

#endif	// !GUIOPENGL_HPP_
