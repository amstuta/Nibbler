//
// guiSDL.hpp for guiSDL in /home/amstuta/rendu/cpp_nibbler
//
// Made by arthur
// Login   <amstuta@epitech.net>
//
// Started on  Tue Mar 17 18:48:25 2015 arthur
// Last update Mon Mar 30 12:11:48 2015 raphael elkaim
//

#ifndef GUISFML_HPP_
#define GUISFML_HPP_

#include <SFML/Graphics.hpp>
#include "IGui.hpp"
#include <vector>

class GuiSFML: public IGui
{
  sf::RenderWindow *window;
  std::vector<Point *> *snak;
public:
  GuiSFML();
  ~GuiSFML();

  void	initGui(int, int, std::vector<Point *> *);
  int	rcv_event();
  void	refresh();
  void	update();
  void	dispFruit(std::map<Point, Fruit> &);
};

#endif
