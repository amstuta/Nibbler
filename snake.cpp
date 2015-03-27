//
// snake.cpp for snake in /home/amstuta/rendu/cpp_nibbler
//
// Made by arthur
// Login   <amstuta@epitech.net>
//
// Started on  Tue Mar 17 17:57:22 2015 arthur
// Last update Fri Mar 27 14:56:04 2015 Lauranne Bruno
//

#include <iostream>
#include "snake.hpp"

Snake::Snake(int x, int y,  std::vector< std::vector<char> > *p):
  points(),
  plat(p),
  speedX(0),
  speedY(-1)
{
  std::cout << "test\n";
  for (int i(0); i < 4; i++)
    {
      addPoint(x, y + i);
    }
  std::cout << "test2\n";
}

Snake::~Snake()
{
  while (!points.empty())
    {
      delete points.back();
      points.pop_back();
    }
}

void	Snake::addPoint(int x, int y)
{
  Point	*p = new Point;
  
  p->x = x;
  p->y = y;
  points.push_back(p);
  (*plat)[y][x] = '#';
}

void	Snake::printPoints() const
{
  for (std::vector<Point*>::const_iterator it = points.begin();
       it != points.end(); ++it)
    {
      std::cout << "X: " << (*it)->x << ", Y: " << (*it)->y << std::endl;
    }
}

int	Snake::move()
{
  Point	*p = new Point;

  p->x = points[0]->x + speedX;
  p->y = points[0]->y + speedY;
  if (p->y / plat->size() > 0 || p->x / (*plat)[0].size() > 0)
    return 1;
  //(*plat)[p->y % plat->size()][] = '#';
  points.insert(points.begin(), p);
  //(*plat)[points.back()->y % plat->size()][points.back()->x % (*plat)[0].size()] = '0';
  delete points.back();
  points.pop_back();
  return 0;
}

void	Snake::turn(int value)
{
  if (speedX == value)
    {
      speedX = 0;
      speedY = 1;
    }
  else if (speedY == value)
    {
      speedX = -1;
      speedY = 0;
    }
  else if ((value == 1 && speedY == -1) || (value == -1 && speedY == 1))
    {
      speedX = 1;
      speedY = 0;
    }
  else
    {
      speedX = 0;
      speedY = -1;
    }
}

  void	Snake::moveEat()
  {
    Point	*p = new Point;
    points.insert(points.begin(), p);
  }

  std::vector<Point*> *Snake::getSnake()
  {
    return &points;
  }
