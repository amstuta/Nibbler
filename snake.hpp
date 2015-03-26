//
// snake.hpp for snake in /home/amstuta/rendu/cpp_nibbler
//
// Made by arthur
// Login   <amstuta@epitech.net>
//
// Started on  Tue Mar 17 17:54:19 2015 arthur
// Last update Thu Mar 26 12:34:49 2015 raphael elkaim
//

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include <vector>

typedef struct
{
  int	x;
  int	y;
} Point;

class Snake
{
  std::vector<Point*>	points;
  std::vector< std::vector<char> > *plat;
  int speedX;
  int speedY;
public:
  Snake(int, int, std::vector< std::vector<char> > *);
  ~Snake();

  void	addPoint(int x, int y);
  void	printPoints() const;
  int	move();
  void	turn(int);
  void	moveEat();
  std::vector<Point*> *getSnake();
};

#endif
