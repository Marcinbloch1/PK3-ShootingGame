#pragma once
#include <sstream>
#include "Mainclass.h"
#include "Player.h"
#include "Scoreblock.h"
#include "Floor.h"




template <class T1, class T2> bool isIntersecting(T1 &a, T2 &b);

bool collisionTest(Player &player, Scoreblock &scoreblock, int &scores, int &scores_iterator);

bool collisionTest(Floor &floor, Scoreblock &scoreblock, int &lives);

void load_game_texts(Text &score_info, Text &lives_info, Text &starting_text, Text &ending_text);

void end_game(Event event, RenderWindow &window, int &scores, Text ending_text);