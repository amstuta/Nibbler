//
// guiOpenGL.cpp for IGui in /home/bruno_a/rendu/cpp_nibbler
// 
// Made by Lauranne Bruno
// Login   <bruno_a@epitech.net>
// 
// Started on  Mon Mar 30 10:41:36 2015 Lauranne Bruno
// Last update Wed Apr  1 16:18:10 2015 Lauranne Bruno
//

#include <stdlib.h>
#include <unistd.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include "guiOpenGL.hpp"

GuiOpenGL::GuiOpenGL():
  IGui::IGui()
{}

GuiOpenGL::~GuiOpenGL()
{
  SDL_Quit();
}

void	GuiOpenGL::initGui(int x, int y, std::vector<Point *> *snake)
{
  this->snk = snake;
  this->x_decal = decal(x);
  this->y_decal = decal(y);
  // (this->x_decal % 2 == 0) ? (0.0) : (0.5);
  this->x_size = 2.0 / x;
  this->y_size = 2.0 / y;
  this->x = x;
  this->y = y;
  SDL_Init(SDL_INIT_VIDEO);
  this->window = SDL_SetVideoMode(x * BOX, y * BOX, 32, SDL_OPENGL);
  glColor3ub(100 + rand() % 155, rand() % 255, rand() % 255);
  glPointSize(BOX - 1);
  glClear(GL_COLOR_BUFFER_BIT);
}

int	GuiOpenGL::rcv_event()
{
  SDL_Event	event;

  SDL_PollEvent(&(event));
  if (event.type == SDL_QUIT)
    return 2;
  if (event.type == SDL_KEYDOWN)
    {
      if (event.key.keysym.sym == SDLK_ESCAPE)
	return 2;
      if (event.key.keysym.sym == SDLK_LEFT)
	return LEFT;
      if (event.key.keysym.sym == SDLK_RIGHT)
	return RIGHT;
      if (event.key.keysym.sym == SDLK_UP)
	return UP;
      if (event.key.keysym.sym == SDLK_DOWN)
	return DOWN;
    }
  return (0);
}

void	GuiOpenGL::refresh()
{
  glFlush();
  SDL_GL_SwapBuffers();
}

void	GuiOpenGL::update()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POINTS);
  // glColor3ub(100 + rand() % 155, rand() % 255, rand() % 255);
  for (std::vector<Point*>::const_iterator it = snk->begin();
       it != snk->end(); ++it)
    {
      glVertex2d(- this->x / 2 * this->x_size + this->x_size * (((*it)->first) + this->x_decal),
		 this->y / 2 * this->y_size - this->y_size * (((*it)->second) + this->y_decal));
    }
  glEnd();
}

void	GuiOpenGL::dispFruit(std::map<Point, Fruit> &fruits)
{
  glBegin(GL_POINTS);
  for (std::map<Point, Fruit>::iterator it = fruits.begin();
       it != fruits.end(); it++)
    {
      glVertex2d(- this->x / 2 * this->x_size + this->x_size * (((*it).first.first) + this->x_decal),
		 this->y / 2 * this->y_size - this->y_size * (((*it).first.second) + this->y_decal));
    }
  glEnd();
}

void	GuiOpenGL::showScore(__attribute__((unused))int score)
{}

extern "C"
{
  IGui	*create_gui()
  {
    return new GuiOpenGL;
  }
}
