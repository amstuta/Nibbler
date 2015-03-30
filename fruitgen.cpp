//
// fruitgen.cpp for fruit in /home/elkaim_r/projects/cpp/cpp_nibbler
// 
// Made by raphael elkaim
// Login   <elkaim_r@epitech.net>
// 
// Started on  Thu Mar 26 13:49:23 2015 raphael elkaim
// Last update Mon Mar 30 11:25:42 2015 raphael elkaim
//

#include "fruitgen.hpp"

FruitGen::FruitGen(int _sizeX, int _sizeY):
  sizeX(_sizeX),
  sizeY(_sizeY)
{
  srandom(time(0));
}

FruitGen::~FruitGen()
{
}

void popFruit()
{
  Point pos;

do
  {
    pos.first = rand() % sizeX;
    pos.second = rand() % sizeY;
  } while ((*plat)[pos.second][pos.first] != '0');
 stock[pos] = Fruit(pos.first, pos.second);
 (*plat)[pos.second][pos.first] = 'f';
}
