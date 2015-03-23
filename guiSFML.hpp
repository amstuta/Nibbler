//
// guiSDL.hpp for guiSDL in /home/amstuta/rendu/cpp_nibbler
//
// Made by arthur
// Login   <amstuta@epitech.net>
//
// Started on  Tue Mar 17 18:48:25 2015 arthur
// Last update Mon Mar 23 14:11:27 2015 raphael elkaim
//

#ifndef GUISFML_HPP_
#define GUISFML_HPP_

#include <SFML/Graphics.hpp>
#include "IGui.hpp"

class GuiSFML: public IGui
{
  sf::RenderWindow *window;
public:
  GuiSFML();
  ~GuiSFML();

  void	initGui();
  int	rcv_event();
  void	refresh();
};

#endif
