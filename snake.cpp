//
// snake.cpp for snake in /home/amstuta/rendu/cpp_nibbler
//
// Made by arthur
// Login   <amstuta@epitech.net>
//
// Started on  Tue Mar 17 17:57:22 2015 arthur
// Last update Tue Mar 17 18:33:13 2015 arthur
//

#include <iostream>
#include "snake.hpp"

Snake::Snake():
  points()
{
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
}

void	Snake::printPoints() const
{
  for (std::vector<Point*>::const_iterator it = points.begin();
       it != points.end(); ++it)
    {
      std::cout << "X: " << (*it)->x << ", Y: " << (*it)->y << std::endl;
    }
}

void	Snake::moveDontEat(int x, int y)
{
  Point	*p = new Point;

  p->x = x;
  p->y = y;
  points.insert(points.begin(), p);
  points.pop_back();
}

void	Snake::moveEat(int x, int y)
{
  Point	*p = new Point;
    
  p->x = x;
  p->y = y;
  points.insert(points.begin(), p);
}
