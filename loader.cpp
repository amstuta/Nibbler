#include <dlfcn.h>
#include <cstdlib>
#include <iostream>
#include "loader.hpp"

Loader::Loader(const std::string &file):
  fileName(file)
{
  handler = dlopen(file.c_str(), RTLD_LAZY);
  if (!handler)
    {
      std::cout << "Error: couldn't open dynamic library: " << file << std::endl;
      exit(-1);
    }
}

Loader::~Loader()
{
  dlclose(handler);
}

void Loader::callFunc(const std::string &fctName) const
{
  void	(*fct)(int);

  fct = (function)dlsym(handler, fctName.c_str());
  if (!fct)
    {
      std::cout << "Error: couldn't load function: " << fctName << std::endl;
      return;
    }
  fct(15);
  fct(2);
}

