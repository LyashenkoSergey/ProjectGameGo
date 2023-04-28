#pragma once

#include <iostream>
#include <malloc/malloc.h>

using namespace std;

const int FIELD_SIZE=19;
const int EMPTY=0;
const int BLACK=1;
const int WHITE=2;
const int EXIT = 100;

int** createField();
void Board(int**& array);
void showField(int** array);
bool validMove(int**& array, int x, int y, int color);
void makeMove(int**& array, int x, int y, int color, int& moveCount);
bool gameOver(int** array, int moveCount);
int getStoneColor(int**& array, int x, int y);
int getOppositeColor(int color);
void removeStones(int**& array, int x, int y, int color);
bool checkCapture(int**& array, int x, int y, int color);
bool checkCaptureHelper(int**& array, int x, int y, int color);
