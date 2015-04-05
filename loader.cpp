#include <dlfcn.h>
#include <cstdlib>
#include <iostream>
#include "loader.hpp"
#include "IGui.hpp"

Loader::Loader(const std::string &file):
  fileName(file)
{
  char *err;

  handler = dlopen(file.c_str(), RTLD_LAZY);
  if (!handler)
    {
      if ((err = dlerror()) != NULL)
	std::cout << "Error:" << err << file << std::endl;
      exit(-1);
    }
}

Loader::~Loader()
{
  dlclose(handler);
}

IGui	*Loader::getGui()
{
  IGui	*obj;
  IGui*	(*creator)();

  creator = reinterpret_cast<IGui* (*)()>(dlsym(handler, "create_gui"));
  if (creator == NULL)
    std::exit(0);
  obj = creator();

  return obj;
}
