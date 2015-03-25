//
// coord.cpp for nibbler in /home/elkaim_r/projects/cpp/cpp_nibbler
// 
// Made by raphael elkaim
// Login   <elkaim_r@epitech.net>
// 
// Started on  Wed Mar 25 12:13:24 2015 raphael elkaim
// Last update Wed Mar 25 14:26:31 2015 raphael elkaim
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
