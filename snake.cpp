//
// snake.cpp for snake in /home/amstuta/rendu/cpp_nibbler
//
// Made by arthur
// Login   <amstuta@epitech.net>
//
// Started on  Tue Mar 17 17:57:22 2015 arthur
// Last update Mon Mar 30 13:45:04 2015 raphael elkaim
//

#include <iostream>
#include "snake.hpp"

Snake::Snake(int x, int y,  std::vector< std::vector<char> > *p, std::map<Point, Fruit> *stock):
  points(),
  plat(p),
  speedX(0),
  speedY(-1), 
  sto(stock)
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
  
  p->first = x;
  p->second = y;
  if (p->second / plat->size() > 0 || p->first / (*plat)[0].size() > 0)
    return ;
  points.push_back(p);
  (*plat)[y][x] = '#';
}

void	Snake::printPoints() const
{
  /*  for (std::vector<Point*>::const_iterator it = points.begin();
       it != points.end(); ++it)
    {
      std::cout << "X: " << (*it)->x << ", Y: " << (*it)->y << std::endl;
      }*/
}

int	Snake::move()
{
  Point	*p = new Point;
  int	ate = 0;

  p->first = points[0]->first + speedX;
  p->second = points[0]->second + speedY;
  if (p->second / plat->size() > 0 
      || p->first / (*plat)[0].size() > 0
      || (*plat)[p->second][p->first] == '#')
    return 1;
  if ((*plat)[p->second][p->first] == 'f')
    {
      ate = 2;
      sto->erase(*p);
    }
  if (!ate)
    {
      (*plat)[points.back()->second][points.back()->first] = '0';
      delete points.back();
      points.pop_back();
    }
  (*plat)[p->second][p->first] = '#';
  points.insert(points.begin(), p);
  return ate;
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
