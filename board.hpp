//
// board.hpp for board in /home/elkaim_r/projects/cpp/cpp_nibbler
// 
// Made by raphael elkaim
// Login   <elkaim_r@epitech.net>
// 
// Started on  Mon Mar 23 14:36:42 2015 raphael elkaim
// Last update Mon Mar 30 11:26:09 2015 raphael elkaim
//

#ifndef BOARD_HPP_
# define BOARD_HPP_

#include <vector>
#include "IGui.hpp"
#include "snake.hpp"
#include "fruitgen.hpp"

class Board
{
  std::vector< std::vector<char> > plat;
  Snake ken;
  int	xSize;
  int	ySize;
  IGui	*gui;
  FruitGen Gene;
public:
  Board(int, int, IGui *);
  ~Board();
  int launch();
};

#endif
