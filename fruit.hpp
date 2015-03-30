//
// fruit.hpp for nibbler in /home/elkaim_r/projects/cpp/cpp_nibbler
// 
// Made by raphael elkaim
// Login   <elkaim_r@epitech.net>
// 
// Started on  Fri Mar 27 14:16:42 2015 raphael elkaim
// Last update Fri Mar 27 14:32:24 2015 raphael elkaim
//

#ifndef FRUIT_HPP_
# define FRUIT_HPP_

#include <vector>

class Fruit
{
  Point pos;
public:
  Fruit(int, int);
  ~Fruit();
  Point getPos();
};

#endif
