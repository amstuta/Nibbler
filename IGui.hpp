//
// IGui.hpp for IGui in /home/amstuta/rendu/cpp_nibbler
//
// Made by arthur
// Login   <amstuta@epitech.net>
//
// Started on  Tue Mar 17 18:40:20 2015 arthur
// Last update Mon Mar 30 12:12:46 2015 raphael elkaim
//

#ifndef IGUI_HPP_
# define IGUI_HPP_

#include <vector>
#include <map>
#include "snake.hpp"
#include "fruit.hpp"

class IGui
{ 
public:
  IGui() {}
  virtual ~IGui() {}


  virtual void	initGui(int, int, std::vector<Point *> *) = 0;
  virtual int	rcv_event() = 0;
  virtual void	refresh() = 0;
  virtual void	update() = 0;
  virtual void	dispFruit(std::map<Point, Fruit> &) = 0;
};

#endif
