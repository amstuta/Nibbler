//
// IGui.hpp for IGui in /home/amstuta/rendu/cpp_nibbler
//
// Made by arthur
// Login   <amstuta@epitech.net>
//
// Started on  Tue Mar 17 18:40:20 2015 arthur
// Last update Thu Mar 26 11:30:06 2015 raphael elkaim
//

#ifndef IGUI_HPP_
# define IGUI_HPP_

#include <vector>

class IGui
{ 
public:
  IGui() {}
  virtual ~IGui() {}


  virtual void	initGui(int, int, std::vector< std::vector<char> > *) = 0;
  virtual int	rcv_event() = 0;
  virtual void	refresh() = 0;
  virtual void	update() = 0;
};

#endif
