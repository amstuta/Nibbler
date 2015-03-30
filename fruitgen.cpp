//
// fruitgen.cpp for fruit in /home/elkaim_r/projects/cpp/cpp_nibbler
// 
// Made by raphael elkaim
// Login   <elkaim_r@epitech.net>
// 
// Started on  Thu Mar 26 13:49:23 2015 raphael elkaim
// Last update Mon Mar 30 15:37:31 2015 raphael elkaim
//

#include <ctime>
#include "fruitgen.hpp"
#include "fruit.hpp"

FruitGen::FruitGen(int _sizeX, int _sizeY, std::vector< std::vector<char> > *pl):
  sizeX(_sizeX),
  sizeY(_sizeY),
  plat(pl)
{
  srandom(time(0));
}

FruitGen::~FruitGen()
{
}

void FruitGen::popFruit(unsigned int nb)
{
  Point pos;

  if (nb >= stock.size() && stock.size() > 0)
    return ;
  for (unsigned int i(0);i < nb; i++)
    {
      do
	{
	  pos.first = rand() % sizeX;
	  pos.second = rand() % sizeY;
	} while ((*plat)[pos.second][pos.first] != '0');
      stock[pos] = Fruit(pos.first, pos.second);
      (*plat)[pos.second][pos.first] = 'f';
    }
}

std::map<Point, Fruit> &FruitGen::getFruit()
{
  return stock;
}
