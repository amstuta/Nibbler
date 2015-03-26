//
// guiSDL.cpp for guiSDL in /home/amstuta/rendu/cpp_nibbler
//
// Made by arthur
// Login   <amstuta@epitech.net>
//
// Started on  Tue Mar 17 18:55:33 2015 arthur
// Last update Thu Mar 26 12:06:53 2015 raphael elkaim
//
#include <SFML/Graphics.hpp>
#include <unistd.h>
#include "guiSFML.hpp"

GuiSFML::GuiSFML():
  IGui::IGui()
{
}

GuiSFML::~GuiSFML()
{
}

void GuiSFML::initGui(int x, int y, std::vector< std::vector<char> > *plat)
{
  board = plat;
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

void GuiSFML::update()
{
  sf::Shape head = sf::Shape::Rectangle(20, 0, 0, 20, sf::Color(0, 255, 0, 255));
  sf::Shape snakou = sf::Shape::Rectangle(20, 0, 0, 20, sf::Color(255, 255, 128, 128));
  int	cnt(0);
  for (unsigned int i(0); i < board->size(); i++)
    {
      for (unsigned int j(0);j < (*board)[i].size();j++)
	{
	  if ((*board)[i][j] != '0' && cnt)
	    {
	      snakou.Scale(1, 1);
	      snakou.SetPosition(j * 20, i * 20);
	      window->Draw(snakou);
	    }
	  else if ((*board)[i][j] != '0' && !cnt)
	    {
	      head.Scale(1, 1);
	      head.SetPosition(j * 20, i * 20);
	      window->Draw(head);
	      cnt++;
	    }
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
