#ifndef GUIGTK_HPP_
# define GUIGTK_HPP_

#include "IGui.hpp"

class GuiGTK: public IGui
{
public:
  GuiGTK();
  ~GuiGTK();

  void	sayWassUp() const;
};

#endif
