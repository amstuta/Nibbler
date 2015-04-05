//
// snake.hpp for snake in /home/amstuta/rendu/cpp_nibbler
//
// Made by arthur
// Login   <amstuta@epitech.net>
//
// Started on  Tue Mar 17 17:54:19 2015 arthur
// Last update Fri Apr  3 15:07:36 2015 elkaim raphael
//

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include <utility>
#include <map>
#include <vector>
#include "fruit.hpp"

# define LEFT 3
# define RIGHT 4
# define UP 5
# define DOWN 6

typedef std::pair<int, int> Point;

class Snake
{
  std::vector<Point *> points;
  std::vector< std::vector<char> > *plat;
  int speedX;
  int speedY;
  std::map<Point, Fruit> *sto;
public:
  Snake(int, int, std::vector< std::vector<char> > *, std::map<Point, Fruit> *);
  ~Snake();

  void	addPoint(int x, int y);
  int	move();
  void	turn(int);
  std::vector<Point*> *getSnake();
};

#endif
