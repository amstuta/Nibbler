//
// coord.hpp for nibbler in /home/elkaim_r/projects/cpp/cpp_nibbler
// 
// Made by raphael elkaim
// Login   <elkaim_r@epitech.net>
// 
// Started on  Wed Mar 25 12:09:59 2015 raphael elkaim
// Last update Wed Mar 25 12:37:44 2015 raphael elkaim
//

#ifndef COORD_HPP_
# define COORD_HPP_

class Coord
{
private:
  int x;
  int y;
public:
  Coord(char *, char *);
  ~Coord();
  int operator[](int);
};

#endif
