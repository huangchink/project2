#ifndef _CLASS_H_
#define _CLASS_H_
#include <iostream>
#include<ctime>
#include<curses.h>
#include<cstdlib>
#include <unistd.h>

using namespace std;
class easy {
public:
	int candy[6][10] = { 0 };
	int temp;
	int height; int width;
	int c, x = 0, y = 1;
	int score = 0;
	int target = 8700;
	int remainsteps = 20;
	int set = 0;
	int jx = 0;
	int jy = 0;
	void setfruit();
	bool shuffle();
	void outputfruit();
	bool swapable();
	void setempty();
	void skyfall();
	bool fuckyet = 0;
	int go_on = 1;
	int preX;
	int preY;
	int nextX;
	int nextY;
	void lets_play_a_game();
	void swap(int & x, int & x2);
};
class Normal
{ 
public:
	int candy[6][10] = { 0 };
	int temp;
	int height; int width;
	int c, x = 0, y = 1;
	int score = 0;
	int target = 10000;
	int remainsteps = 20;
	int set = 0;
	int jx = 0;
	int jy = 0;
	void setfruit();
	bool shuffle();
	void outputfruit();
	bool swapable();
	void setempty();
	void skyfall();
	bool fuckyet = 0;
	int go_on = 1;
	int preX;
	int preY;
	int nextX;
	int nextY;
	void lets_play_a_game();
	void swap(int & x, int & x2);
};
	

class Crazy
{
public:
	int candy[6][10] = { 0 };
	int temp;
	int height; int width;
	int c, x = 0, y = 1;
	int score = 0;
	int target = 10000;
	int remainsteps = 20;
	int set = 0;
	int jx = 0;
	int jy = 0;
	void setfruit();
	bool shuffle();
	void outputfruit();
	bool swapable();
	void setempty();
	void skyfall();
	bool fuckyet = 0;
	int go_on = 1;
	int preX;
	int preY;
	int nextX;
	int nextY;
	void lets_play_a_game();
	void swap(int & x, int & x2);
};
#endif
