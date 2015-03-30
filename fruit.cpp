//
// fruit.cpp for nibbler in /home/elkaim_r/projects/cpp/cpp_nibbler
// 
// Made by raphael elkaim
// Login   <elkaim_r@epitech.net>
// 
// Started on  Fri Mar 27 14:28:46 2015 raphael elkaim
// Last update Mon Mar 30 13:02:37 2015 raphael elkaim
//

#include "snake.hpp"
#include "fruit.hpp"

Fruit::Fruit(int x, int y)
{
  pos.first = x;
  pos.second = y;
}

Fruit::Fruit()
{
  pos.first = 0;
  pos.second = 0;
}


Fruit::~Fruit()
{
}

Point Fruit::getPos()
{
  return pos;
}
