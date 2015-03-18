//
// guiSDL.hpp for guiSDL in /home/amstuta/rendu/cpp_nibbler
//
// Made by arthur
// Login   <amstuta@epitech.net>
//
// Started on  Tue Mar 17 18:48:25 2015 arthur
// Last update Tue Mar 17 18:51:19 2015 arthur
//

#ifndef GUISDL_HPP_
#define GUISDL_HPP_

#include "IGui.hpp"

class guiSDL: public IGui
{
public:
  guiSDL();
  ~guiSDL();

  void	initGui();
};

#endif
