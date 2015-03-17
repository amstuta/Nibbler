//
// guiQt.hpp for guiQt in /home/amstuta/rendu/cpp_nibbler
//
// Made by arthur
// Login   <amstuta@epitech.net>
//
// Started on  Tue Mar 17 18:40:04 2015 arthur
// Last update Tue Mar 17 18:50:46 2015 arthur
//

#ifndef GUIQT_HPP_
# define GUIQT_HPP_

#include "IGui.hpp"

class GuiQt: public IGui
{
public:
  GuiQt();
  ~GuiQt();

  void	initGui();
};

#endif
