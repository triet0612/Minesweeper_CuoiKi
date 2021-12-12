#pragma once
#include "Console.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <utility>
#include <string>
#include <time.h>
#include <cstdlib>
#define consoleWidth 80
#define consoleHeight 25
using namespace std;

enum trangthai { UP, DOWN, LEFT, RIGHT };
struct player
{
	string name;
	int vitri[4][8];
	int diem;
	int ROW, COL, BOMB, DIFF, flag, total_move, gameover, move;
	vector<vector<string>> PROCESS_MAP;
	vector<vector<string>> DISPLAY_MAP;
	time_t begin, end;
	int timet;
	int level;
};
struct trochon
{
	int x, y;
	trangthai tt;
	int vitri[10];
};
struct luudiem
{
	string ten;
	int diem;
};

//game loading
void new_game();
void new_game1(player& player);
void new_game2(player& player);
//console pointer genertion
void khoitaotrochon1(trochon& trochon);
void khoitaotrochon2(trochon& trochon);
//game control
void dieukhientrochon1(trochon& trochon);
void dieukhientrochon2(player& player, trochon& trochon);
void dieukhientrochon3(trochon& trochon);
//home screen
void manHinh1();
//map game proccessing
void MAP_GEN(player& player);
void PLANT_BOMB(player& player);
void PRINT_MAP(player& player);
void PRINT_ANS_MAP(player& player);
bool CHECK_CELL(int R, int C, player& player);
bool CHECK_BOMB(int R, int C, player& player);
vector<pair<int, int>> SURROUNDING(int r, int c, player& player);
int COUNT_SURROUNDING(int r, int c, player& player);
void OPEN_CELL(int R, int C, player& player);
//save load game
void save_game(player& player);
void load_game(player& player);
//highscore
void input_highscore(player& player);
void gethighscore(player& player);