#include <iostream>
#include "loader.hpp"
#include "snake.hpp"

int		main(int ac, char **av)
{
  Snake		s;
  std::string	libName;
  
  if (ac != 4)
    {
      std::cout << "Usage: ./nibbler width height library" << std::endl;
      return (-1);
    }

  s.addPoint(1, 4);
  s.addPoint(7, 9);
  s.addPoint(5, 3);
  s.printPoints();
  s.move(2, 2);
  s.printPoints();
    
  libName = "./";
  libName += av[3];
  Loader l(libName);
  l.initGui();
  return (0);
}
