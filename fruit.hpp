//
// fruit.hpp for nibbler in /home/elkaim_r/projects/cpp/cpp_nibbler
// 
// Made by raphael elkaim
// Login   <elkaim_r@epitech.net>
// 
// Started on  Fri Mar 27 14:16:42 2015 raphael elkaim
// Last update Mon Mar 30 13:22:53 2015 raphael elkaim
//

#ifndef FRUIT_HPP_
# define FRUIT_HPP_

#include <vector>
typedef std::pair<int, int> Point;

class Fruit
{
  Point pos;
public:
  Fruit(int, int);
  Fruit();
  ~Fruit();
  Point getPos();
};

#endif
