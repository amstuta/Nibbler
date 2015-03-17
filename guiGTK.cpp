//
// guiGTK.cpp for guiGTK in /home/amstuta/rendu/cpp_nibbler
//
// Made by arthur
// Login   <amstuta@epitech.net>
//
// Started on  Tue Mar 17 18:39:50 2015 arthur
// Last update Tue Mar 17 18:39:51 2015 arthur
//

#include <iostream>
#include "guiGTK.hpp"

GuiGTK::GuiGTK():
  IGui::IGui()
{
}

GuiGTK::~GuiGTK()
{
}

void GuiGTK::sayWassUp() const
{
  std::cout << "YOOOO" << std::endl;
}

extern "C"
{
  IGui	*create_gui()
  {
    return new GuiGTK;
  }
}
