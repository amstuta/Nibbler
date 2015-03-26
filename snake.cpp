//
// snake.cpp for snake in /home/amstuta/rendu/cpp_nibbler
//
// Made by arthur
// Login   <amstuta@epitech.net>
//
// Started on  Tue Mar 17 17:57:22 2015 arthur
// Last update Thu Mar 26 12:37:27 2015 raphael elkaim
//

#include <iostream>
#include "snake.hpp"

Snake::Snake(int x, int y,  std::vector< std::vector<char> > *p):
  points(),
  plat(p),
  speedX(0),
  speedY(-1)
{
  for (int i(0); i < 4; i++)
    {
      addPoint(x, y + i);
    }
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
  speedX = (speedX == 0) * value;
  speedY = (speedY == 0) * value;
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
