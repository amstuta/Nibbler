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

void Loader::initGui()
{
  IGui	*obj;
  IGui*	(*creator)();

  creator = reinterpret_cast<IGui* (*)()>(dlsym(handler, "create_gui"));
  if (creator == NULL)
    return;
  obj = creator();
  obj->sayWassUp();
}
