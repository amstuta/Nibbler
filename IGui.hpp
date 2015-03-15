#ifndef IGUI_HPP_
# define IGUI_HPP_

class IGui
{ 
public:
  IGui() {}
  virtual ~IGui() {}

  virtual void	sayWassUp() const = 0;
};

#endif
