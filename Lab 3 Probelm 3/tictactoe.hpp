/*//Victoria Todd, Jayson Morgado, Shaun Shahan
//TA: Lauren Olson
// 09/19/19
// CISC220 Lab 3/===========================================================================
 *
 * tictactoe.hpp
 *
 *  Created on: Sep 19, 2019
 *      Author: stsha
 */



/*
 * tictactoe.hpp
 *
 *  Created on: Sep 12, 2019
 *      Author: Jayson
 */

#ifndef TICTACTOE_HPP_
#define TICTACTOE_HPP_
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

class tictactoe{
char **board;
string y;
string x;
int counter;

public:
tictactoe(string p1, string p2);
bool boardFull();
bool checkWin(char xo);
void printBoard(char **b);
void initializeBoard();
~tictactoe();//destructor
void personPlay(char xo);
void playGame();
};



#endif /* TICTACTOE_HPP_ */

