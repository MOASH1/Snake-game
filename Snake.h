#include<iostream>
#include"Map.h"
#include"Player.h"
using namespace::std;
class Snake
{
private:
	Map Map1;
	
public:
	int Tail_N;
	int HeadX, HeadY;
	Snake();
	int Tail_X[50],Tail_Y[50];char Dir;
	enum Direction { Top = 1, Down, Right, Left };
};

