/*//Victoria Todd, Jayson Morgado, Shaun Shahan
//TA: Lauren Olson
// 09/19/19
// CISC220 Lab 3/===========================================================================
 *
 * tictactoe.cpp
 *
 *  Created on: Sep 19, 2019
 *      Author: stsha
 */

#include "tictactoe.hpp"
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

//constructor for tictactoe
//creates the board filling each element with '-'
//sets counter equal to 0
tictactoe::tictactoe(string p1, string p2){
board = new char *[2];
initializeBoard();
x = p1;
y = p2;
counter = 0;
}//constructor

//takes no parameters returns nothing
//sets each element equal to '-'
void tictactoe::initializeBoard(){
for(int i = 0; i < 3; i++){
board[i] = new char[2];
for(int j = 0; j < 3; j++){
board[i][j] = '-';
}//for
}//for
}

//desconstructor
tictactoe::~tictactoe(){
for(int i = 0; i < 3;i++){
delete[]board[i];
}
delete[]board;
cout<<"board has been destroyed"<<endl;
}
//takes in no parameters
//returns nothing
//prints the current state of the board
void tictactoe::printBoard(char **b){
for(int i = 0; i < 3; i++){
for(int j = 0; j < 3;j++){
cout<<b[i][j]<< "\t";
}
cout << endl;
}
}


//takes in no parameters
//returns a boolean
//checks to see if the board is full
bool tictactoe::boardFull(){
int check;
for(int i = 0; i < 3; i++){
for(int j = 0; j < 3;j++){
if(board[i][j]=='-'){
check = 1;
break;
}//if
}//for
}//for
if(check == 1)
return false;
else
return true;
}

//takes in a character
//returns a boolean
//checks too see if there is a 3 in a row on the board
//returns true
bool tictactoe::checkWin(char xo){
bool win = true;
//vertical
if(board[0][0] == xo && board[1][0] == xo && board[2][0] == xo)
return win;
if(board[0][1] == xo && board[1][1] == xo && board[2][1] == xo)
return win;
if(board[0][2] == xo && board[1][2] == xo && board[2][2] == xo)
return win;

//horizontal
if(board[0][0] == xo && board[0][1] == xo && board[0][2] == xo)
return win;
if(board[1][0] == xo && board[1][1] == xo && board[1][2] == xo)
return win;
if(board[2][0] == xo && board[2][1] == xo && board[2][2] == xo)
return win;

//diagonal
if(board[0][0] == xo && board[1][1] == xo && board[2][2] == xo)
return win;
if(board[0][2] == xo && board[1][1] == xo && board[2][0] == xo)
return win;
return !win;
}

//takes in a char either x or y
//returns nothing
//asks current person playing what coordinate they would like to place the 'x' or 'o'
//checks if that spot is valid
//assigns that element to the x or o
//prints the current board
void tictactoe::personPlay(char xo){
char player = xo;
bool check = true;
int x_board;
int y_board;
while(check){
cout <<  player << "'s turn:"<< endl;
cout << player << ": Enter x: " << endl;
cin >> x_board;
cout << player << ": Enter y: " << endl;
cin >> y_board;
if((x_board < 3 || y_board < 3) && (board[x_board][y_board] == '-'))
   check = false;
}//while
if(player == 'x'){
board[x_board][y_board] = 'x';
}//
else{
board[x_board][y_board] = 'o';
}
printBoard(board);

 }

//takes in no parameters
//returns nothing
//calls personPlay inside while loop
//while loop finishes only when either: the board is full, or there is a three in a row
//announces the result of the game and prints final board
void tictactoe::playGame(){
while(!(boardFull() || checkWin('x') || checkWin('o'))){
if(counter % 2 == 0)
personPlay('x');
else
personPlay('o');
counter++;

}//while
if(checkWin('x')){
cout << x << " won" << endl;
}//if
else if(checkWin('o')){
cout << y << " won" << endl;
}//else if
else if(boardFull()){
cout << "The board is full" <<endl;
}//else if

printBoard(board);

}



