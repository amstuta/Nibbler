#ifndef LOADER_HPP_
# define LOADER_HPP_

#include <string>

typedef void (*function)(int);

class Loader
{
  void		*handler;
  std::string	fileName;
  
public:
  Loader(const std::string &file);
  ~Loader();

  void	callFunc(const std::string &fctName) const;
};

#endif
