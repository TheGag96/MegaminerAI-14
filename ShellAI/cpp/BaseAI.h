//Copyright (C) 2009 - Missouri S&T ACM AI Team
//Please do not modify this file while building your AI
//See AI.h & AI.cpp for that
#ifndef BASEAI_H
#define BASEAI_H

#include <vector>
#include <ctime>
#include "game.h"

#include "Player.h"
#include "Mappable.h"
#include "Plant.h"
#include "Mutation.h"

/// \brief A basic AI interface.

///This class implements most the code an AI would need to interface with the lower-level game code.
///AIs should extend this class to get a lot of boiler-plate code out of the way
///The provided AI class does just that.
class BaseAI
{
protected:
  Connection* c;
  std::vector<Player> players;
  std::vector<Mappable> mappables;
  std::vector<Plant> plants;
  std::vector<Mutation> mutations;
public:
  ///The width of the total map.
  int mapWidth();
  ///The height of the total map.
  int mapHeight();
  ///The current turn number.
  int turnNumber();
  ///The maximum number of Plants allowed per player.
  int maxPlants();
  ///The id of the current player.
  int playerID();
  ///What number game this is for the server.
  int gameNumber();
  ///The maximum distance that a bumbleweed can move during an uproot
  int bumbleweedSpeed();
  ///The damage taken from standing in a pool
  int poolDamage();
  ///The strength buff taken from standing in a pool
  int poolBuff();
  ///The strength debuff caused by an enemy Titan
  int titanDebuff();
  ///The rate which your spores return to maxSpores
  int sporeRate();
  ///The maximum number of spores a player can have
  int maxSpores();
  
  BaseAI(Connection* c);
  virtual ~BaseAI();
  ///
  ///Make this your username, which should be provided.
  virtual const char* username() = 0;
  ///
  ///Make this your password, which should be provided.
  virtual const char* password() = 0;
  ///
  ///This function is run once, before your first turn.
  virtual void init() = 0;
  ///
  ///This function is called each time it is your turn
  ///Return true to end your turn, return false to ask the server for updated information
  virtual bool run() = 0;
  ///
  ///This function is called after the last turn.
  virtual void end() = 0;


  bool startTurn();
};

#endif
