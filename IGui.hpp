//
// IGui.hpp for IGui in /home/amstuta/rendu/cpp_nibbler
//
// Made by arthur
// Login   <amstuta@epitech.net>
//
// Started on  Tue Mar 17 18:40:20 2015 arthur
// Last update Tue Mar 17 18:53:03 2015 arthur
//

#ifndef IGUI_HPP_
# define IGUI_HPP_

class IGui
{ 
public:
  IGui() {}
  virtual ~IGui() {}

  virtual void	initGui() = 0;
};

#endif
