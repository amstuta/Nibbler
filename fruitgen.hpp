//
// fruitgen.hpp for fruitgen in /home/elkaim_r/projects/cpp/cpp_nibbler
// 
// Made by raphael elkaim
// Login   <elkaim_r@epitech.net>
// 
// Started on  Thu Mar 26 13:49:29 2015 raphael elkaim
// Last update Mon Mar 30 11:34:46 2015 raphael elkaim
//

#ifndef FRUITGEN_HPP_
# define FRUITGEN_HPP_

#include <map>
#include <cstdlib>
#include "snake.hpp"
#include "fruit.hpp"

class FruitGen
{
  int sizeX;
  int sizeY;
  std::vector< std::vector<char> > plat;
  std::map<Point, Fruit> stock;
public:
  FruitGen(int, int, std::vector< std::vector<char> > *);
  ~FruitGen();
  void popFruit();
  std::map<Point, Fruit> &getFruit();
};

#endif
