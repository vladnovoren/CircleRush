#include "Engine.h"
#include "GraphicsSystem.hpp"
#include "AngularVelocity.hpp"
#include <stdlib.h>
#include "CircleGraphicsComponent.hpp"
#include <memory.h>
#include "EntityManager.hpp"
#include "PhysicalSystem.hpp"
#include <stdio.h>

//
//  You are free to modify this file
//

//  is_key_pressed(int button_vk_code) - check if a key is pressed,
//                                       use keycodes (VK_SPACE, VK_RIGHT, VK_LEFT, VK_UP, VK_DOWN, VK_RETURN)
//
//  get_cursor_x(), get_cursor_y() - get mouse cursor position
//  is_mouse_button_pressed(int button) - check if mouse button is pressed (0 - left button, 1 - right button)
//  schedule_quit_game() - quit game after act()


// initialize game data in this function
void initialize()
{
}

// this function is called to update game data,
// dt - time elapsed since the previous update (in seconds)
void act(float dt)
{
  (void)dt;
  if (is_key_pressed(VK_ESCAPE))
    schedule_quit_game();
  if (is_key_pressed(VK_SPACE)) {
    PhysicalSystem::GetInstance().ChangeDir();
  }
  if (PhysicalSystem::GetInstance().Step(dt)) {
    std::cout << "SCORE: " << EntityManager::GetInstance().Score() << '\n';
    schedule_quit_game();
  }
}

const int START_X = 500;
const int START_Y = 350;

// fill buffer in this function
// uint32_t buffer[SCREEN_HEIGHT][SCREEN_WIDTH] - is an array of 32-bit colors (8 bits per R, G, B)
void draw()
{
  // clear backbuffer
  memset(buffer, 0, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(uint32_t));

  EntityManager::GetInstance().Draw();
}

// free game data in this function
void finalize()
{
}
