#include "Console.h"
#include "Header.h"

//main game
int main()
{
xy:
	system("cls");
	manHinh1();
	player player1;
	trochon chon1;
	khoitaotrochon1(chon1);
	gotoXY(chon1.x, chon1.y);
	cout << "*";
	trochon chon2;
	khoitaotrochon2(chon2);
	while (_getch() != 13)
	{
		clrscr();
		manHinh1();
		dieukhientrochon1(chon1);
	}
	chon2.y--;
	if (chon1.y == 4)
	{
		while (_getch() != 13)
		{
			clrscr();
			new_game();
			dieukhientrochon2(player1, chon2);
		}
		clrscr();
		cout << "Your name: ";
		getline(cin, player1.name, '\n');
		if (player1.name == "")
		{
			player1.name = "player";
		}
		new_game1(player1);
	}
	if (chon1.y == 5)
	{
		player player2;
		load_game(player2);
		new_game2(player2);
	}
	if (chon1.y == 6)
	{
		gethighscore();
	}
	if (chon1.y != 7)
	{
		goto xy;
	}
	clrscr();
	return 0;

}