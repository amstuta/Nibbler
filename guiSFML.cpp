//
// guiSDL.cpp for guiSDL in /home/amstuta/rendu/cpp_nibbler
//
// Made by arthur
// Login   <amstuta@epitech.net>
//
// Started on  Tue Mar 17 18:55:33 2015 arthur
// Last update Mon Mar 30 12:08:39 2015 raphael elkaim
//
#include <SFML/Graphics.hpp>
#include <unistd.h>
#include <utility>
#include "snake.hpp"
#include "guiSFML.hpp"

GuiSFML::GuiSFML():
  IGui::IGui()
{
}

GuiSFML::~GuiSFML()
{
}

void GuiSFML::initGui(int x, int y, std::vector<Point *> *plat)
{
  snak = plat;
  window = new sf::RenderWindow(sf::VideoMode(x * 20, y * 20, 32), "Nibbler", sf::Style::Close);
}

int GuiSFML::rcv_event()
{
  sf::Event Event;

  while (window->GetEvent(Event))
    {
      if (Event.Type == sf::Event::Closed)
	return 2;
      if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Escape))
	return 2;
      if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Left))
	return -1;
      if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Right))
	return 1;
    }
  return 0;
}

void GuiSFML::dispFruit(std::map<Point, Fruit> &fruits)
{
  sf::Shape fruit = sf::Shape::Rectangle(18, 0, 0, 18, sf::Color(255, 0, 0, 255));
  for (std::map<char,int>::iterator it=fruits.begin();it != fruits.end;it++)
    {
      fruit.Scale(1, 1);
      fruit.SetPosition((*it).first * 20, (*it).second * 20);
      window->Draw(fruit);
    }
}

void GuiSFML::update()
{
  sf::Shape head = sf::Shape::Rectangle(18, 0, 0, 18, sf::Color(0, 255, 0, 255));
  sf::Shape snakou = sf::Shape::Rectangle(18, 0, 0, 18, sf::Color(255, 255, 128, 128));
  for (unsigned int i(0); i < snak->size(); i++)
    {
      if (!i)
	{
	  snakou.Scale(1, 1);
	  snakou.SetPosition((*snak)[i]->first * 20, (*snak)[i]->second * 20);
	  window->Draw(snakou);
	}
      else
	{
	  head.Scale(1, 1);
	  head.SetPosition((*snak)[i]->first * 20, (*snak)[i]->second * 20);
	  window->Draw(head);
	}
    }
}

void GuiSFML::refresh()
{
  window->Display();
  window->Clear();
}
  
extern "C"
{
  IGui	*create_gui()
  {
    return new GuiSFML;
  }
}
