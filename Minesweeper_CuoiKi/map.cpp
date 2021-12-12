#include "Header.h"
#include "Console.h"

void MAP_GEN(player& player) {
	vector<vector<string>> temp(player.ROW, vector<string>(player.COL));
	for (int i = 0; i < player.ROW; i++) {
		for (int j = 0; j < player.COL; j++) {
			temp[i][j] = "-";
		}
	}
	player.PROCESS_MAP = temp;
	player.DISPLAY_MAP = temp;
	return;
}
void PLANT_BOMB(player& player) {
	int remaining_bombs = player.BOMB;
	srand(time(NULL));
	while (remaining_bombs > 0) {
		int random_x = rand() % player.ROW;
		int random_y = rand() % player.COL;
		if (player.PROCESS_MAP[random_x][random_y] != "B") {
			player.PROCESS_MAP[random_x][random_y] = "B";
			remaining_bombs--;
		}
	}
	return;
}
void PRINT_MAP(player& player) {
	cout << endl;

	for (int x = 0; x < player.COL; x++)
	{
		SetColor(10);
		if (x <= 9)
		{
			cout << "  " << x << "  ";
		}
		else
		{
			cout << " " << x << "  ";
		}
		SetColor(15);
	}
	SetBGColor(8);
	cout << endl;
	cout << " ";
	for (int a = 0; a < player.COL; a++)
	{
		cout << "     ";
	}
	for (int i = 0; i < player.ROW; i++) {
		cout << endl;
		SetBGColor(8);
		cout << " ";
		for (int j = 0; j < player.COL; j++) {
			SetColor(9);
			if (player.DISPLAY_MAP[i][j] != "-") {
				if (player.DISPLAY_MAP[i][j] == "0") {
					cout << "     ";
				}
				else if (player.DISPLAY_MAP[i][j] == "F") {
					SetColor(4);
					SetBGColor(15);
					cout << " " << player.DISPLAY_MAP[i][j] << " ";
					SetBGColor(8);
					cout << "  ";
				}
				else {
					SetColor(0);
					SetBGColor(15);
					cout << " " << player.DISPLAY_MAP[i][j] << " ";
					SetBGColor(8);
					cout << "  ";
				}
			}
			else {
				SetBGColor(15);
				SetColor(15);
				cout << " " << "#" << " ";
				SetBGColor(8);
				cout << "  ";
			}
			SetColor(15);
		}
		SetBGColor(0);
		SetColor(10);
		cout << " " << i;
		SetColor(15);
		cout << endl;
		SetBGColor(8);
		cout << " ";
		for (int a = 0; a < player.COL; a++)
		{
			cout << "     ";
		}
		SetBGColor(0);
	}
	cout << endl;
	for (int x = 0; x < player.COL; x++)
	{
		SetColor(10);
		if (x <= 9)
		{
			cout << "  " << x << "  ";
		}
		else
		{
			cout << " " << x << "  ";
		}
		SetColor(15);
	}
	cout << endl;
}
void PRINT_ANS_MAP(player& player) {
	cout << endl;

	for (int x = 0; x < player.COL; x++)
	{
		SetColor(10);
		if (x <= 9)
		{
			cout << "  " << x << "  ";
		}
		else
		{
			cout << " " << x << "  ";
		}
		SetColor(15);
	}
	SetBGColor(8);
	cout << endl;
	cout << " ";
	for (int a = 0; a < player.COL; a++)
	{
		cout << "     ";
	}
	for (int i = 0; i < player.ROW; i++) {
		cout << endl;
		SetBGColor(8);
		cout << " ";
		for (int j = 0; j < player.COL; j++) {
			SetColor(9);
			if (player.PROCESS_MAP[i][j] != "-") {
				if (player.PROCESS_MAP[i][j] == "0") {
					cout << "     ";
				}
				else if (player.PROCESS_MAP[i][j] == "F") {
					SetColor(4);
					SetBGColor(15);
					cout << " " << player.PROCESS_MAP[i][j] << " ";
					SetBGColor(8);
					cout << "  ";
				}
				else {
					SetColor(0);
					SetBGColor(15);
					cout << " " << player.PROCESS_MAP[i][j] << " ";
					SetBGColor(8);
					cout << "  ";
				}
			}
			else {
				SetBGColor(15);
				SetColor(15);
				cout << " " << "#" << " ";
				SetBGColor(8);
				cout << "  ";
			}
			SetColor(15);
		}
		SetBGColor(0);
		SetColor(10);
		cout << " " << i;
		SetColor(15);
		cout << endl;
		SetBGColor(8);
		cout << " ";
		for (int a = 0; a < player.COL; a++)
		{
			cout << "     ";
		}
		SetBGColor(0);
	}
	cout << endl;
	for (int x = 0; x < player.COL; x++)
	{
		SetColor(10);
		if (x <= 9)
		{
			cout << "  " << x << "  ";
		}
		else
		{
			cout << " " << x << "  ";
		}
		SetColor(15);
	}
	cout << endl;
}
bool CHECK_CELL(int R, int C, player& player) {
	return (R >= 0) && (R < player.ROW) && (C >= 0) && (C < player.COL);
}
bool CHECK_BOMB(int R, int C, player& player) {
	return (player.PROCESS_MAP[R][C] == "B");
}
vector<pair<int, int>> SURROUNDING(int r, int c, player& player) {
	vector<pair<int, int>> surround;
	for (int dr = -1; dr <= 1; dr++) {
		for (int dc = -1; dc <= 1; dc++) {
			if (dr != 0 || dc != 0) {
				if (CHECK_CELL(r + dr, c + dc, player)) {
					surround.push_back(make_pair(r + dr, c + dc));
				}
			}
		}
	}
	return surround;
}
int COUNT_SURROUNDING(int r, int c, player& player) {
	vector<pair<int, int>> surround = SURROUNDING(r, c, player);

	int count = 0;
	for (int i = 0; i < surround.size(); i++) {
		if (CHECK_BOMB(surround[i].first, surround[i].second, player)) {
			count++;
		}
	}
	return count;
}
void OPEN_CELL(int R, int C, player& player) {
	(player.move)++;
	int count = COUNT_SURROUNDING(R, C, player);
	player.DISPLAY_MAP[R][C] = to_string(count);

	if (count == 0) {
		vector<pair<int, int>> surround = SURROUNDING(R, C, player);

		for (int i = 0; i < surround.size(); i++) {
			if (player.DISPLAY_MAP[surround[i].first][surround[i].second] == "-") {
				OPEN_CELL(surround[i].first, surround[i].second, player);
			}
		}
	}
}