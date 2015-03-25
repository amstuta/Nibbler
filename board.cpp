//
// board.cpp for board in /home/elkaim_r/projects/cpp/cpp_nibbler
// 
// Made by raphael elkaim
// Login   <elkaim_r@epitech.net>
// 
// Started on  Mon Mar 23 14:36:37 2015 raphael elkaim
// Last update Wed Mar 25 16:24:33 2015 raphael elkaim
//

#include <iostream>
#include <algorithm>
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
  gui->initGui();
}

Board::~Board()
{
}

int	Board::launch()
{
  ken.move();
  ken.turn(-1);
  ken.move();
  ken.turn(-1);
  ken.move();
  std::cout << "YOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO" << std::endl;
  for (int i(0); i < ySize; i++)
    {
      for_each(plat[i].begin(), plat[i].end(), printf_int);
      std::cout << std::endl;
    }
  return 0;
}
