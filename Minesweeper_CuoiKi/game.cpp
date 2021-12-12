#include "Header.h"
#include "Console.h"

void new_game()
{
	gotoXY(consoleWidth / 2, 0);
	cout << "Choose your difficulty: \n";
	cout << "\n";
	for (int i = 0; i < 50; i++)
	{
		cout << "_+";
	}
	cout << "\n";
	gotoXY(consoleWidth / 2, 4);
	cout << "-[1] 9x9 10 Bomb   (for newbie)\n";
	gotoXY(consoleWidth / 2, 5);
	cout << "-[2] 16x16 40 Bomb (for intermediate)";
	gotoXY(consoleWidth / 2, 6);
	cout << "-[3] 16x20 99 Bomb (for experts)\n";
	gotoXY(consoleWidth / 2 - 5, 10);
	cout << "Press Enter then press down arrow to choose ";
}
void new_game1(player& player) {
	MAP_GEN(player);
	PLANT_BOMB(player);
	player.flag = player.BOMB;
	player.total_move = player.ROW * player.COL - player.BOMB;
	player.move = 0;
	player.gameover = false;
	player.diem = 0;
	player.timet = 0;
	int a;
	time(&player.begin);
	while (!player.gameover)
	{
		system("cls");
		gotoXY(55, 0);
		cout << "Trang Thai: Dang Choi";
		time(&player.end);
		gotoXY(55, 1);
		a = difftime(player.end, player.begin);
		player.timet += a;
		cout << "Thoi gian choi: " << player.timet;
		gotoXY(55, 2);
		cout << "Diem: " << player.diem;
		gotoXY(0, 7);
		PRINT_MAP(player);
		gotoXY(0, 0);
		char cmd;
		int r, c;
		int a = 0;
		cout << "Remaining flag: " << player.flag << endl << endl;
		cout << "[S] to save game" << endl;
		cout << "[F]/[O](F: Flag, O: Open) [row] [col]" << endl;
		Sleep(2000);
		cin >> cmd;
		if (cmd == 'S')
		{
			save_game(player);
			break;
		}
		cin >> r >> c;
		cout << endl;
		if (r >= player.ROW || r < 0 || c >= player.COL || c < 0) {
			cout << "Invalid Cell Try Again" << endl;
		}
		else {
			if (cmd == 'F')
			{
				if (player.DISPLAY_MAP[r][c] == "-")
				{
					if (player.flag != 0)
					{
						player.DISPLAY_MAP[r][c] = "F";
						player.flag--;
					}
					else
					{
						cout << "Run out of flags, LMAO!!!!" << endl;
					}
				}
				else if (player.DISPLAY_MAP[r][c] == "F")
				{
					player.DISPLAY_MAP[r][c] = "-";
					player.flag++;
				}
				else
				{
					cout << "Already open, try again :v!!" << endl;
				}
			}
			if (cmd == 'O')
			{
				if (player.DISPLAY_MAP[r][c] == "-" && player.PROCESS_MAP[r][c] == "-")
				{
					player.diem += int((player.move * 100) / (player.timet + 0.1) + 5);
					OPEN_CELL(r, c, player);
					if (player.move == player.total_move)
					{
						input_highscore(player);
						system("cls");
						PRINT_MAP(player);
						gotoXY(0, 0);
						cout << "BOMB HAS BEEN DEFUSED, COUNTER TERRORIST WIN :v" << endl;
						player.gameover = true;
						gotoXY(55, 0);
						cout << "Trang Thai: Ket Thuc" << endl;
						gotoXY(55, 1);
						cout << "Thoi gian choi: " << player.timet;
						gotoXY(55, 2);
						cout << "Diem: " << player.diem << " ";
						system("pause");
					}
				}
				else if (player.DISPLAY_MAP[r][c] == "-" && player.PROCESS_MAP[r][c] == "B")
				{
					input_highscore(player);
					system("cls");
					player.DISPLAY_MAP[r][c] = "B";
					gotoXY(0, 2);
					PRINT_ANS_MAP(player);
					player.gameover = true;
					gotoXY(0, 0);
					cout << "TERRORIST WIN!!! BOOOM" << endl;
					gotoXY(55, 0);
					cout << "Trang Thai: Ket Thuc" << endl;
					gotoXY(55, 1);
					cout << "Thoi gian choi: " << player.timet;
					gotoXY(55, 2);
					cout << "Diem: " << player.diem << " ";
					system("pause");
				}
				else
				{
					if (player.DISPLAY_MAP[r][c] == "F")
					{
						cout << "THIS IS A FLAG, F again to De-Flag" << endl;
					}
					else
					{
						cout << "This cell opened" << endl;
					}
				}
			}
		}
	}
	return;
}
void new_game2(player& player)
{
	int a;
	time(&player.begin);
	while (!player.gameover)
	{
		system("cls");
		gotoXY(55, 0);
		cout << "Trang Thai: Dang Choi";
		time(&player.end);
		gotoXY(55, 1);
		a = difftime(player.end, player.begin);
		player.timet += a;
		cout << "Thoi gian choi: " << player.timet;
		gotoXY(55, 2);
		cout << "Diem: " << player.diem;
		gotoXY(0, 8);
		PRINT_MAP(player);
		gotoXY(0, 0);
		char cmd;
		int r, c;
		int a = 0;
		cout << "Remaining flag: " << player.flag << endl << endl;
		cout << "[S] to save game" << endl;
		cout << "[F]/[O](F: Flag, O: Open) [row] [col]" << endl;
		Sleep(2000);
		cin >> cmd;
		if (cmd == 'S')
		{
			save_game(player);
			break;
		}
		cin >> r >> c;
		cout << endl;
		if (r >= player.ROW || r < 0 || c >= player.COL || c < 0) {
			cout << "Invalid Cell Try Again" << endl;
		}
		else {
			if (cmd == 'F')
			{
				if (player.DISPLAY_MAP[r][c] == "-")
				{
					if (player.flag != 0)
					{
						player.DISPLAY_MAP[r][c] = "F";
						player.flag--;
					}
					else
					{
						cout << "Run out of flags, LMAO!!!!" << endl;
					}
				}
				else if (player.DISPLAY_MAP[r][c] == "F")
				{
					player.DISPLAY_MAP[r][c] = "-";
					player.flag++;
				}
				else
				{
					cout << "Already open, try again :v!!" << endl;
				}
			}
			if (cmd == 'O')
			{
				if (player.DISPLAY_MAP[r][c] == "-" && player.PROCESS_MAP[r][c] == "-")
				{
					player.diem += int((player.move * 100) / (player.timet + 0.1) + 5);
					OPEN_CELL(r, c, player);
					if (player.move == player.total_move)
					{
						input_highscore(player);
						system("cls");
						PRINT_MAP(player);
						gotoXY(0, 0);
						cout << "BOMB HAS BEEN DEFUSED, COUNTER TERRORIST WIN :v" << endl;
						player.gameover = true;
						gotoXY(55, 0);
						cout << "Trang Thai: Ket Thuc" << endl;
						gotoXY(55, 1);
						cout << "Thoi gian choi: " << player.timet;
						gotoXY(55, 2);
						cout << "Diem: " << player.diem << " ";
						system("pause");
					}
				}
				else if (player.DISPLAY_MAP[r][c] == "-" && player.PROCESS_MAP[r][c] == "B")
				{
					input_highscore(player);
					system("cls");
					player.DISPLAY_MAP[r][c] = "B";
					gotoXY(0, 2);
					PRINT_ANS_MAP(player);
					player.gameover = true;
					gotoXY(0, 0);
					cout << "TERRORIST WIN!!! BOOOM" << endl;
					gotoXY(55, 0);
					cout << "Trang Thai: Ket Thuc" << endl;
					gotoXY(55, 1);
					cout << "Thoi gian choi: " << player.timet;
					gotoXY(55, 2);
					cout << "Diem: " << player.diem << " ";
					system("pause");
				}
				else
				{
					if (player.DISPLAY_MAP[r][c] == "F")
					{
						cout << "THIS IS A FLAG, F again to De-Flag" << endl;
					}
					else
					{
						cout << "This cell opened" << endl;
					}
				}
			}
		}
	}
	return;
}

void khoitaotrochon1(trochon& trochon)
{
	trochon.x = 39;
	trochon.y = 4;
}
void khoitaotrochon2(trochon& trochon)
{
	trochon.x = 39;
	trochon.y = 4;
	trochon.vitri[4] = 1;
	trochon.vitri[5] = 2;
	trochon.vitri[6] = 3;

}

void dieukhientrochon1(trochon& trochon)
{
	int a = _getch();
	if (a == 80)
	{
		trochon.tt = DOWN;
	}
	else if (a == 72)
	{
		trochon.tt = UP;
	}
	if (trochon.tt == DOWN)
	{
		if (trochon.y < 7)
			trochon.y++;
	}
	else if (trochon.tt == UP)
	{
		if (trochon.y > 4)
			trochon.y--;
	}
	gotoXY(trochon.x, trochon.y);
	cout << "*";
}
void dieukhientrochon2(player& player, trochon& trochon)
{
	int a = _getch();
	if (a == 80)
	{
		trochon.tt = DOWN;
	}
	else if (a == 72)
	{
		trochon.tt = UP;
	}
	if (trochon.tt == DOWN)
	{
		if (trochon.y < 6)
			trochon.y++;
	}
	else if (trochon.tt == UP)
	{
		if (trochon.y > 4)
			trochon.y--;
	}
	if (trochon.vitri[trochon.y] == 1) {
		player.ROW = 9;
		player.COL = 9;
		player.BOMB = 10;
		player.level = 1;
	}
	if (trochon.vitri[trochon.y] == 2) {
		player.ROW = 16;
		player.COL = 16;
		player.BOMB = 40;
		player.level = 2;
	}
	if (trochon.vitri[trochon.y] == 3) {
		player.ROW = 16;
		player.COL = 20;
		player.BOMB = 99;
		player.level = 3;
	}
	gotoXY(trochon.x, trochon.y);
	cout << "*";
}
void dieukhientrochon3(trochon& trochon)
{
	clrscr();
	gotoXY(trochon.x, trochon.y);
	cout << "*";
	int a = _getch();
	if (a == 80)
	{
		trochon.tt = DOWN;
	}
	else if (a == 72)
	{
		trochon.tt = UP;
	}
	else if (a == 75)
	{
		trochon.tt = LEFT;
	}
	else if (a == 77)
	{
		trochon.tt = RIGHT;
	}
	if (trochon.tt == UP)
	{
		trochon.y--;
	}
	else if (trochon.tt == DOWN)
	{
		trochon.y++;
	}
	else if (trochon.tt == LEFT)
	{
		trochon.x--;
	}
	else if (trochon.tt == RIGHT)
	{
		trochon.x++;
	}
}

void manHinh1()
{
	gotoXY(consoleWidth / 2, 0);
	cout << "MINSWEEPER\n";
	cout << "\n";
	for (int i = 0; i < 50; i++)
	{
		cout << "_+";
	}
	cout << "\n";
	gotoXY(consoleWidth / 2 + 1, 4);
	cout << "NEW GAME";
	gotoXY(consoleWidth / 2, 5);
	cout << "LOAD GAME";
	gotoXY(consoleWidth / 2, 6);
	cout << "HIGH SCORE";
	gotoXY(consoleWidth / 2 + 3, 7);
	cout << "EXIT";
	gotoXY(consoleWidth / 2 - 13, 10);
	cout << "Press Enter then press down arrow to choose ";
}

void input_highscore(player& player)
{
	luudiem danhsach[11];
	ifstream highscore;
	if (player.level == 1)
	{
		highscore.open("highscore1.txt");
	}
	if (player.level == 2)
	{
		highscore.open("highscore2.txt");
	}
	if (player.level == 3)
	{
		highscore.open("highscore3.txt");
	}
	for (int i = 0; i < 10; i++)
	{
		getline(highscore, danhsach[i].ten, '\n');
		highscore >> danhsach[i].diem;
		highscore.ignore(1000, '\n');
	}
	highscore.close();
	danhsach[10].ten = player.name;
	danhsach[10].diem = player.diem;
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 10 - i; j++)
		{
			if (danhsach[j].diem < danhsach[j + 1].diem)
			{
				string temp = danhsach[j].ten;
				int temp1 = danhsach[j].diem;
				danhsach[j].ten = danhsach[j + 1].ten;
				danhsach[j].diem = danhsach[j + 1].diem;
				danhsach[j + 1].ten = temp;
				danhsach[j + 1].diem = temp1;
			}
		}
	}
	ofstream fout;
	if (player.level == 1)
	{
		fout.open("highscore1.txt");
	}
	if (player.level == 2)
	{
		fout.open("highscore2.txt");
	}
	if (player.level == 3)
	{
		fout.open("highscore3.txt");
	}
	for (int i = 0; i < 10; i++)
	{
		fout << danhsach[i].ten << endl;
		fout << danhsach[i].diem << endl;
	}
	fout.close();
}
void gethighscore(player& player)
{
	system("cls");
	int diem;
	char str[100];
	ifstream highscore;
	if (player.level == 1)
	{
		highscore.open("highscore1.txt");
	}
	if (player.level == 2)
	{
		highscore.open("highscore2.txt");
	}
	if (player.level == 3)
	{
		highscore.open("highscore3.txt");
	}
	for (int i = 0; i < 10; i++)
	{
		cout << "player " << i + 1 << endl;
		highscore.get(str, 100, '\n');
		printf("%s\n", str);
		highscore >> diem;
		cout << diem << endl;
		cout << "-----------------" << endl;
		highscore.ignore(1000, '\n');
	}
	highscore.close();
	system("pause");

}

void save_game(player& player) {
	ofstream process("Process.txt");
	ofstream display("Display.txt");
	ofstream getother("Others.txt");
	for (int i = 0; i < player.ROW; i++) {
		for (int j = 0; j < player.COL; j++) {
			process << player.PROCESS_MAP[i][j] << endl;
			display << player.DISPLAY_MAP[i][j] << endl;
		}
	}
	getother << player.name << endl << player.level << endl << player.ROW << endl << player.COL << endl << player.BOMB << endl << player.diem << endl << player.flag << endl << player.total_move << endl << player.move << endl << player.timet << endl << player.gameover;
	getother.close();
	process.close();
	display.close();
	return;
	return;
}
void load_game(player& player) {
	ifstream process("Process.txt");
	ifstream display("Display.txt");
	ifstream getother("Others.txt");
	getline(getother, player.name, '\n');
	getother >> player.level >> player.ROW >> player.COL >> player.BOMB >> player.diem >> player.flag >> player.total_move >> player.move >> player.timet >> player.gameover;
	player.PROCESS_MAP = vector<vector<string>>(player.ROW, vector<string>(player.COL));
	player.DISPLAY_MAP = vector<vector<string>>(player.ROW, vector<string>(player.COL));
	for (int i = 0; i < player.ROW; i++) {
		for (int j = 0; j < player.COL; j++) {
			process >> player.PROCESS_MAP[i][j];
			display >> player.DISPLAY_MAP[i][j];
		}
	}
	return;

}