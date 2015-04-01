#ifndef GUISFML_HPP_
#define GUISFML_HPP_

#include <SFML/Graphics.hpp>
#include "IGui.hpp"
#include <vector>

class GuiSFML: public IGui
{
  sf::RenderWindow *window;
  std::vector<Point *> *snak;
  int xs;
  int ys;
  sf::Image borderImage;
  sf::Image grassImage;
  sf::Image fruitImage;
public:
  GuiSFML();
  ~GuiSFML();

  void	initGui(int, int, std::vector<Point *> *);
  int	rcv_event();
  void	refresh();
  void	update();
  void	dispFruit(std::map<Point, Fruit> &);
  void	showScore(int);

  class SfmlError : public std::exception
  {
  private:
    const char *msg;
  public:
    SfmlError(const char *);
    virtual ~SfmlError() throw();
    virtual const char *what() throw ();
  };
};

#endif
