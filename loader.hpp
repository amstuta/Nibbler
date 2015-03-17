//
// loader.hpp for loader in /home/amstuta/rendu/cpp_nibbler
//
// Made by arthur
// Login   <amstuta@epitech.net>
//
// Started on  Tue Mar 17 18:40:35 2015 arthur
// Last update Tue Mar 17 18:40:35 2015 arthur
//

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
