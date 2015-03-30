//
// board.cpp for board in /home/elkaim_r/projects/cpp/cpp_nibbler
// 
// Made by raphael elkaim
// Login   <elkaim_r@epitech.net>
// 
// Started on  Mon Mar 23 14:36:37 2015 raphael elkaim
// Last update Mon Mar 30 12:03:34 2015 raphael elkaim
//

#include <iostream>
#include <algorithm>
#include <unistd.h>
#include "snake.hpp"
#include "board.hpp"
#include "fruitgen.hpp"

void	printf_int(char i)
{
  std::cout << i;
}

Board::Board(int _xSize, int _ySize, IGui * gi):
  plat(_ySize, std::vector<char>(_xSize, '0')),
  ken(_xSize / 2, _ySize / 2, &plat),
  xSize(_xSize),
  ySize(_ySize),
  gui(gi),
  Gene(xSize, ySize, &plat)
{
  gui->initGui(xSize, ySize, ken.getSnake());
  gui->refresh();
}

Board::~Board()
{
}

int	Board::launch()
{
  int	eve;
  while ((eve = gui->rcv_event()) != 2)
    {
      if (eve != 0)
      	ken.turn(eve);
      if (ken.move() == 1)
	break ;
      gui->dispFruit(Gene.getFruit());
      gui->update();
      gui->refresh();
      usleep(200000);
    }
  return 0;
}
