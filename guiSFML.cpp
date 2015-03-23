//
// guiSDL.cpp for guiSDL in /home/amstuta/rendu/cpp_nibbler
//
// Made by arthur
// Login   <amstuta@epitech.net>
//
// Started on  Tue Mar 17 18:55:33 2015 arthur
// Last update Mon Mar 23 14:36:18 2015 raphael elkaim
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

void GuiSFML::initGui()
{
  window = new sf::RenderWindow(sf::VideoMode(200, 200, 32), "Nibbler");
}

int GuiSFML::rcv_event()
{
  sf::Event Event;

  while (window->GetEvent(Event))
    {
      if (Event.Type == sf::Event::Closed)
	return 1;
      if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Escape))
	return 1;
      if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Left))
	return 2;
      if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Right))
	return 3;
    }
  return 0;
}
  
extern "C"
{
  IGui	*create_gui()
  {
    return new GuiSFML;
  }
}
