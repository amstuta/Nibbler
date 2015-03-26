//
// main.cpp for main in /home/amstuta/rendu/cpp_nibbler
//
// Made by arthur
// Login   <amstuta@epitech.net>
//
// Started on  Tue Mar 17 18:40:41 2015 arthur
// Last update Thu Mar 26 14:43:56 2015 raphael elkaim
//

#include <iostream>
#include <sstream>
#include "board.hpp"
#include "coord.hpp"
#include "loader.hpp"
#include "snake.hpp"

int		main(int ac, char **av)
{
  IGui		*gui;
  std::string	libName;
  
  if (ac != 4)
    {
      std::cout << "Usage: ./nibbler width height library" << std::endl;
      return -1;
    }
  libName = "./";
  libName += av[3];
  Loader l(libName);
  gui = l.getGui();
  Coord	axis(av[1], av[2]);
  if (axis[0] == 0 || axis[1] == 0)
    {
      std::cerr << "error: invalid map size" << std::endl;
      return 1;
    }
  Board game(axis[0], axis[1], gui);
  game.launch();
  return 0;
}
