//
// fruit.cpp for nibbler in /home/elkaim_r/projects/cpp/cpp_nibbler
// 
// Made by raphael elkaim
// Login   <elkaim_r@epitech.net>
// 
// Started on  Fri Mar 27 14:28:46 2015 raphael elkaim
// Last update Fri Mar 27 14:37:00 2015 raphael elkaim
//

Fruit::Fruit(int x, int y)
{
  pos.first = x;
  pos.second = y;
}

Fruit::~Fruit()
{
}

Point Fruit::getPos()
{
  return pos;
}
