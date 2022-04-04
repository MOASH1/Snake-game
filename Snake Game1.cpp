#include <iostream>
using namespace::std;
#include"Map.h"
#include"Snake.h"
#include"Player.h"
#include <Windows.h>
#include <conio.h>

Map map2;
Snake snake1;
Player player1;

void shift_right(int arr[], int size)
{
    for (int i = size - 2;i >= 0;i--)
    {
        arr[i + 1] = arr[i];

    }
}

void Draw()
{
    system("cls");
    for (int i = 0; i < map2.Get_Hight();i++) {
        for (int j = 0;j < map2.Get_wihdt();j++) {
            if (i == 0 || i == map2.Get_Hight() - 1)cout << "*";
            else if (j == 0 || j == map2.Get_wihdt() - 1)cout << "*";
            else if (i == snake1.HeadY && j == snake1.HeadX)cout << "O";
            else if (i == map2.FruitY && j == map2.FruitX)cout << "$";
            else {
                bool printed = false;
                for (int z = 0;z < snake1.Tail_N;z++) {
                    if (snake1.Tail_X[z] == j && snake1.Tail_Y[z] == i) {
                        cout << "o";
                        printed = false;
                        break;
                    }
                }
                if (!printed)cout << " ";

            }
        }
        cout << endl;
    }
    cout << "Player Score :" << player1.Score << endl;
}

void Generate_fruti()
{
    srand(time(NULL));
    map2.FruitX = rand() % (map2.Get_wihdt() - 2) + 1;
    map2.FruitY = rand() % (map2.Get_Hight() - 2) + 1;
}

void Move()
{
    shift_right(snake1.Tail_X, 50);
    shift_right(snake1.Tail_Y, 50);
    snake1.Tail_X[0] = snake1.HeadX;
    snake1.Tail_Y[0] = snake1.HeadY;

    switch (snake1.Dir)
    {
    case snake1.Top: snake1.HeadY--; break;
    case snake1.Down: snake1.HeadY++; break;
    case snake1.Right: snake1.HeadX++; break;
    case snake1.Left: snake1.HeadX--; break;

    }
    if (snake1.HeadY >= map2.Get_Hight() || snake1.HeadY <= 0 || snake1.HeadX >= map2.Get_wihdt() || snake1.HeadX <= 0)
        player1.Lose = true;
    if (snake1.HeadX == map2.FruitX && snake1.HeadY == map2.FruitY) {
        Generate_fruti();
        player1.Score += 1;
        snake1.Tail_N++;
    }
    for (int i = 0; i < snake1.Tail_N; i++)
    {
        if (snake1.Tail_X[i] == snake1.HeadX && snake1.Tail_Y[i] == snake1.HeadY)
        {
            player1.Lose = true;
            break;
        }
    }
}

void InPut()
{

    if (_kbhit()) {
        char c = _getch();
        switch (c)
        {
        case 'w': snake1.Dir = snake1.Top; break;
        case 's': snake1.Dir = snake1.Down; break;
        case 'd': snake1.Dir = snake1.Right; break;
        case 'a': snake1.Dir = snake1.Left; break;
        case 'x': exit(0);
            break;
        }
    }
}


int main()
{
    while (!player1.Lose)
    {
     Draw();
     InPut();
     Move();
     Sleep(50);
    }

    system("pause");
    return 0;
    
}

