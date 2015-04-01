//
// guiSDL.cpp for guiSDL in /home/amstuta/rendu/cpp_nibbler
//
// Made by arthur
// Login   <amstuta@epitech.net>
//
// Started on  Tue Mar 17 18:55:33 2015 arthur
// Last update Wed Apr  1 14:39:05 2015 Lauranne Bruno
//

#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include <iostream>
#include <unistd.h>
#include <utility>
#include "snake.hpp"
#include "guiSFML.hpp"
#include "fruit.hpp"

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
  xs = x;
  ys = y;
  window = new sf::RenderWindow(sf::VideoMode((x + 2)* 20, (y + 2)* 20, 32), "Nibbler", sf::Style::Close);
  borderImage.LoadFromFile("./media/border.png");
  grassImage.LoadFromFile("./media/grass.png");
  fruitImage.LoadFromFile("./media/Mushroom.png");
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
	return LEFT;
      if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Right))
	return RIGHT;
      if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Down))
	return DOWN;
      if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Up))
	return UP;
    }
  return 0;
}

void GuiSFML::showScore(int sc)
{
  std::stringstream ss;
  ss << "score:";
  ss << sc;
  std::string str = ss.str();
  sf::String Scoring(str, sf::Font::GetDefaultFont(), 20);
  Scoring.SetPosition(0, 0);
  window->Draw(Scoring);
}

void GuiSFML::dispFruit(std::map<Point, Fruit> &fruits)
{
  sf::Sprite fruit;
  fruit.SetImage(fruitImage);
  for (std::map<Point, Fruit>::iterator it= fruits.begin();it != fruits.end(); it++)
    {
      fruit.Scale(1, 1);
      fruit.SetPosition(((*it).first.first + 1) * 20, ((*it).first.second + 1) * 20);
      window->Draw(fruit);
    }
}

void GuiSFML::update()
{
  sf::Shape head = sf::Shape::Rectangle(20, 0, 0, 20, sf::Color(0, 255, 0, 255));
  sf::Shape snakou = sf::Shape::Rectangle(20, 0, 0, 20, sf::Color(255, 255, 128, 128));
  sf::Sprite border;
  sf::Sprite grass;
  border.SetImage(borderImage);
  grass.SetImage(grassImage);
  for (int i(0); i < ys + 2; i++)
    {
      border.SetPosition(0, i * 20);
      window->Draw(border);
      border.SetPosition((xs + 1) * 20, i * 20);
      window->Draw(border);
    }
  for (int i(0); i < xs + 2; i++)
    {
      border.SetPosition( i * 20, 0);
      window->Draw(border);
      border.SetPosition(i * 20, (ys + 1) * 20);
      window->Draw(border);
    }
  for (int i(1);i < ys + 1;i++)
    {
      for (int j(1);j < xs + 1;j++)
	{
	  grass.SetPosition(j * 20, i * 20);
	  window->Draw(grass);
	}
    }
  for (unsigned int i(0); i < snak->size(); i++)
    {
      if (!i)
	{
	  snakou.Scale(1, 1);
	  snakou.SetPosition(((*snak)[i]->first + 1) * 20, ((*snak)[i]->second + 1) * 20);
	  window->Draw(snakou);
	}
      else
	{
	  head.Scale(1, 1);
	  head.SetPosition(((*snak)[i]->first + 1) * 20, ((*snak)[i]->second + 1) * 20);
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
