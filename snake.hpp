//
// snake.hpp for snake in /home/amstuta/rendu/cpp_nibbler
//
// Made by arthur
// Login   <amstuta@epitech.net>
//
// Started on  Tue Mar 17 17:54:19 2015 arthur
// Last update Tue Mar 17 18:30:27 2015 arthur
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

public:
  Snake();
  ~Snake();

  void	addPoint(int x, int y);
  void	printPoints() const;
  void	moveDontEat(int x, int y);
  void	moveEat(int x, int y);
};

#endif
