//
// guiGTK.hpp for IGui in /home/amstuta/rendu/cpp_nibbler
//
// Made by arthur
// Login   <amstuta@epitech.net>
//
// Started on  Tue Mar 17 18:39:38 2015 arthur
// Last update Tue Mar 17 18:39:39 2015 arthur
//

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
