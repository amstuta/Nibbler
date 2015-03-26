//
// guiSDL.hpp for guiSDL in /home/amstuta/rendu/cpp_nibbler
//
// Made by arthur
// Login   <amstuta@epitech.net>
//
// Started on  Tue Mar 17 18:48:25 2015 arthur
// Last update Thu Mar 26 11:27:52 2015 raphael elkaim
//

#ifndef GUISFML_HPP_
#define GUISFML_HPP_

#include <SFML/Graphics.hpp>
#include "IGui.hpp"
#include <vector>

class GuiSFML: public IGui
{
  sf::RenderWindow *window;
  std::vector< std::vector<char> > *board;
public:
  GuiSFML();
  ~GuiSFML();

  void	initGui(int, int, std::vector< std::vector<char> > *);
  int	rcv_event();
  void	refresh();
  void	update();
};

#endif
