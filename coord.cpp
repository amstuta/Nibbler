//
// coord.cpp for nibbler in /home/elkaim_r/projects/cpp/cpp_nibbler
// 
// Made by raphael elkaim
// Login   <elkaim_r@epitech.net>
// 
// Started on  Wed Mar 25 12:13:24 2015 raphael elkaim
// Last update Sun Apr  5 17:59:55 2015 elkaim raphael
//

#include <iostream>
#include <sstream>
#include <string>
#include "coord.hpp"

Coord::Coord(char *xa, char *ya)
{
  std::istringstream x_val((std::string(xa)));
  std::istringstream y_val((std::string(ya)));
  x_val >> x;
  y_val >> y;
  if (x > 90)
    x = 90;
  if (y > 50)
    y = 50;
}

Coord::~Coord()
{
}

int	Coord::operator[](int idx)
{
  if (idx == 0)
    return x;
  else
    return y;
}
