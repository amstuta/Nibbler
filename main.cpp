//
// main.cpp for main in /home/amstuta/rendu/cpp_nibbler
//
// Made by arthur
// Login   <amstuta@epitech.net>
//
// Started on  Tue Mar 17 18:40:41 2015 arthur
// Last update Mon Mar 23 12:51:28 2015 raphael elkaim
//

#include <iostream>
#include "loader.hpp"
#include "snake.hpp"

void		trySnake()
{
  Snake		s;
  
  s.addPoint(1, 4);
  s.addPoint(7, 9);
  s.addPoint(5, 3);
  s.printPoints();
  s.moveDontEat(2, 2);
  s.printPoints();
}

int		main(int ac, char **av)
{
  IGui		*gui;
  std::string	libName;
  
  if (ac != 4)
    {
      std::cout << "Usage: ./nibbler width height library" << std::endl;
      return (-1);
    }
    
  libName = "./";
  libName += av[3];
  Loader l(libName);
  gui = l.getGui();
  gui->initGui();

  trySnake();
  
  return (0);
}
