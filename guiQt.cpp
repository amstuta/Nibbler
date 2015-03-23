//
// guiQt.cpp for guiQt in /home/amstuta/rendu/cpp_nibbler
//
// Made by arthur
// Login   <amstuta@epitech.net>
//
// Started on  Tue Mar 17 18:40:11 2015 arthur
// Last update Mon Mar 23 14:50:22 2015 raphael elkaim
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

int	GuiQt::rcv_event()
{
  std::cout << "WAZZAHHH" << std::endl;
  return 0;
}

extern "C"
{
  IGui	*create_gui()
  {
    return new GuiQt;
  }
}
