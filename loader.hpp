#ifndef LOADER_HPP_
# define LOADER_HPP_

#include <string>

class Loader
{
  void		*handler;
  std::string	fileName;
  
public:
  Loader(const std::string &file);
  ~Loader();

  void	initGui();
};

#endif
