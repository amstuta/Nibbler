#ifndef LOADER_HPP_
# define LOADER_HPP_

#include <string>
#include "IGui.hpp"

class Loader
{
  void		*handler;
  std::string	fileName;
  
public:
  Loader(const std::string &file);
  ~Loader();

  IGui	*initGui();
};

#endif
