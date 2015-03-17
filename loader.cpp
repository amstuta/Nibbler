//
// loader.cpp for loader in /home/amstuta/rendu/cpp_nibbler
//
// Made by arthur
// Login   <amstuta@epitech.net>
//
// Started on  Tue Mar 17 18:40:29 2015 arthur
// Last update Tue Mar 17 18:40:30 2015 arthur
//

#include <dlfcn.h>
#include <cstdlib>
#include <iostream>
#include "loader.hpp"
#include "IGui.hpp"

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

IGui	*Loader::initGui()
{
  IGui	*obj;
  IGui*	(*creator)();

  creator = reinterpret_cast<IGui* (*)()>(dlsym(handler, "create_gui"));
  if (creator == NULL)
    return NULL;
  obj = creator();

  return obj;
}
