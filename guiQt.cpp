//
// guiQt.cpp for guiQt in /home/amstuta/rendu/cpp_nibbler
//
// Made by arthur
// Login   <amstuta@epitech.net>
//
// Started on  Tue Mar 17 18:40:11 2015 arthur
// Last update Tue Mar 17 18:51:06 2015 arthur
//

#include <iostream>
#include "guiQt.hpp"

GuiQt::GuiQt():
  IGui::IGui()
{
}

GuiQt::~GuiQt()
{
}

void	GuiQt::initGui()
{
  std::cout << "WAZZAHHH" << std::endl;
}

extern "C"
{
  IGui	*create_gui()
  {
    return new GuiQt;
  }
}
