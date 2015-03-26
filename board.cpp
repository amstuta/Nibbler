//
// board.cpp for board in /home/elkaim_r/projects/cpp/cpp_nibbler
// 
// Made by raphael elkaim
// Login   <elkaim_r@epitech.net>
// 
// Started on  Mon Mar 23 14:36:37 2015 raphael elkaim
// Last update Thu Mar 26 15:40:34 2015 raphael elkaim
//

#include <iostream>
#include <algorithm>
#include <unistd.h>
#include "snake.hpp"
#include "board.hpp"

void	printf_int(char i)
{
  std::cout << i;
}

Board::Board(int _xSize, int _ySize, IGui * gi):
  plat(_ySize, std::vector<char>(_xSize, '0')),
  ken(_xSize / 2, _ySize / 2, &plat),
  xSize(_xSize),
  ySize(_ySize),
  gui(gi)
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
      gui->update();
      gui->refresh();
      usleep(50000);
    }
  return 0;
}
