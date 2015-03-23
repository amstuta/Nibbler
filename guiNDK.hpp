//
// guiGTK.hpp for IGui in /home/amstuta/rendu/cpp_nibbler
//
// Made by arthur
// Login   <amstuta@epitech.net>
//
// Started on  Tue Mar 17 18:39:38 2015 arthur
// Last update Mon Mar 23 14:47:43 2015 raphael elkaim
//

#ifndef GUINDK_HPP_
# define GUINDK_HPP_

#include "IGui.hpp"

class GuiNDK: public IGui
{
public:
  GuiNDK();
  ~GuiNDK();

  void	initGui();
  int	rcv_event();
  void	refresh();
};

#endif
