//
// guiSDL.hpp for guiSDL in /home/amstuta/rendu/cpp_nibbler
//
// Made by arthur
// Login   <amstuta@epitech.net>
//
// Started on  Tue Mar 17 18:48:25 2015 arthur
// Last update Wed Mar 18 13:19:05 2015 arthur
//

#ifndef GUISFML_HPP_
#define GUISFML_HPP_

#include "IGui.hpp"

class guiSFML: public IGui
{
public:
  guiSFML();
  ~guiSFML();

  void	initGui();
};

#endif
