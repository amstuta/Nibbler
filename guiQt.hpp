#ifndef GUIQT_HPP_
# define GUIQT_HPP_

#include "IGui.hpp"

class GuiQt: public IGui
{
public:
  GuiQt();
  ~GuiQt();

  void	sayWassUp() const;
};

#endif
