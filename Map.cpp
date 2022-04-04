#include "Map.h"
#include "Snake.h"
#include "Player.h"

Map::Map()
{
    Wihdt = 40;
    Hight = 20;
    srand(time(NULL));
    FruitX = rand() % (Wihdt - 2) + 1;
    FruitY = rand() % (Hight - 2) + 1;
}

Map::~Map()
{

}

int Map::Get_wihdt()
{
    return Wihdt;
}

int Map::Get_Hight()
{
    return Hight;
}






