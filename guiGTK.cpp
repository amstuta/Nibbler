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
