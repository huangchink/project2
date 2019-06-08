#include <iostream>
#include<ctime>
#include<curses.h>
#include<cstdlib>
#include <unistd.h>
#include"class.h"
using namespace std;
int main()
{
	

	srand(time(0));
	initscr();
	clear();
	refresh();
	attrset(A_BOLD);
	restart:
	mvaddstr(0, 0, "welcome to Candy Crush");
	mvaddstr(3, 0, "You can choose 1. easy  2.normal 3.crazy or q to leave" );//讓玩家選擇難度
	int c;
	c = getch();
	clear();
	refresh();
	easy Easy;
	Normal normal;
	Crazy crazy;

		switch (c)// 選擇難度
		{
		case '1':


			int startgame1;//開始遊戲
			mvaddstr(2, 10, "Press any key to start");
			startgame1 = getch();
			clear();
			refresh();
			Easy.setfruit();
			Easy.lets_play_a_game();//開玩
			break;
		case '2':
			int startgame2;//開始遊戲
			mvaddstr(2, 10, "Press any key to start");
			startgame2 = getch();
			clear();
			refresh();
			normal.setfruit();
			normal.lets_play_a_game();//開玩
			break;
		case '3':
			int startgame3;//開始遊戲
			mvaddstr(2, 10, "Press any key to start");
			startgame3 = getch();
			clear();
			refresh();
			crazy.setfruit();
			crazy.lets_play_a_game();//開玩
			break;
		case 'q':
			goto endgame;
		
		}
		clear();
		refresh();
		mvaddstr(0, 0, "Welcome to Candy Crush");
		mvaddstr(3, 0, "You can choose 1. easy  2.normal 3.crazy or q to leave");//讓玩家選擇難度
		goto restart;
		endgame:
	endwin();
	cout << "End Game";


}



