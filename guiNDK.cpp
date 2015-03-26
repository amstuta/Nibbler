//
// guiGTK.cpp for guiGTK in /home/amstuta/rendu/cpp_nibbler
//
// Made by arthur
// Login   <amstuta@epitech.net>
//
// Started on  Tue Mar 17 18:39:50 2015 arthur
// Last update Thu Mar 26 15:42:48 2015 raphael elkaim
//

#include <iostream>
#include "guiNDK.hpp"

GuiNDK::GuiNDK():
  IGui::IGui()
{
}

GuiNDK::~GuiNDK()
{
}

void	GuiNDK::initGui()
{
  std::cout << "YOOOO" << std::endl;
}

int	GuiNDK::rcv_event()
{
  std::cout << "YOOOO" << std::endl;
  return 0;
}

void	GuiNDK::refresh()
{
  std::cout << "YOOOO" << std::endl;
}

extern "C"
{
  IGui	*create_gui()
  {
    return new GuiNDK;
  }
}
