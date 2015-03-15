#include <iostream>
#include "guiQt.hpp"

GuiQt::GuiQt():
  IGui::IGui()
{
}

GuiQt::~GuiQt()
{
}

void GuiQt::sayWassUp() const
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
