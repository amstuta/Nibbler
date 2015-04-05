//
// board.cpp for nibbler in /home/elkaim_r/projects/cpp/cpp_nibbler
// 
// Made by elkaim raphael
// Login   <elkaim_r@epitech.net>
// 
// Started on  Sun Apr  5 18:07:55 2015 elkaim raphael
// Last update Sun Apr  5 18:07:56 2015 elkaim raphael
//


#include <iostream>
#include <algorithm>
#include <unistd.h>
#include "snake.hpp"
#include "board.hpp"
#include "fruitgen.hpp"

Board::Board(int _xSize, int _ySize, IGui * gi):
  plat(_ySize, std::vector<char>(_xSize, '0')),
  xSize(_xSize),
  ySize(_ySize),
  gui(gi),
  Gene(xSize, ySize, &plat),
  ken(_xSize / 2, _ySize / 2, &plat, &(Gene.getFruit()))
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
  int	ret;
  int	score(0);

  while ((eve = gui->rcv_event()) != 2)
    {
      if (eve != 0)
      	ken.turn(eve);
      if ((ret = ken.move()) == 1)
	{
	  std::cout << "GAME OVER!" << std::endl;
	  break ;
	}
      score += (ret > 0);
      Gene.popFruit();
      gui->update();
      gui->dispFruit(Gene.getFruit());
      gui->showScore(score);
      gui->refresh();
      usleep(60000);
    }
  std::cout << "score achieved this game: " << score << "!" << std::endl;
  return 0;
}
