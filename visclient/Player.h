// -*-c++-*-

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "vc_structures.h"


namespace client
{


class Player {
  public:
  void* ptr;
  Player(_Player* ptr = NULL);

  // Accessors
  ///Unique Identifier
  int id();
  ///Player's Name
  char* playerName();
  ///Time remaining, updated at start of turn
  float time();
  ///Number of spores this player has to spawn a new unit
  int spores();

  // Actions
  ///Allows a player to display messages on the screen
  int talk(char* message);
  ///Allows a player to spawn a Plant.
  int spawnPlant(int x, int y, int mutation);

  // Properties


  friend std::ostream& operator<<(std::ostream& stream, Player ob);
};

}

#endif

