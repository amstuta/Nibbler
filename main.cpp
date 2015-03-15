#include <iostream>
#include "loader.hpp"

int		main(int ac, char **av)
{
  std::string	libName;
  
  if (ac != 4)
    {
      std::cout << "Usage: ./nibbler width height library" << std::endl;
      return (-1);
    }

  libName = "./";
  libName += av[3];
  Loader l(libName);
  l.initGui();
  return (0);
}
