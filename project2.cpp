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
	int score=0;
	int target=1000;
	int remainsteps=10;

	void setfruit()
	{
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				temp = (rand() % 5) + 1;
				switch (temp)
				{
				case 1:
					candy[i][j] = 1;
					break;
				case 2:
					candy[i][j] = 10;	break;
				case 3:
					candy[i][j] = 100;	break;
				case 4:
					candy[i][j] = 1000;	break;
				case 5:
					candy[i][j] = 10000;	break;

				}
			}
		}

	}

	void outputfruit()
	{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			start_color();
			init_pair(1, COLOR_CYAN, COLOR_BLACK);
			init_pair(2, COLOR_RED, COLOR_BLACK);
			init_pair(3, COLOR_GREEN, COLOR_BLACK);
			init_pair(4, COLOR_BLUE, COLOR_BLACK);
			init_pair(5, COLOR_YELLOW, COLOR_BLACK);
			init_pair(6, COLOR_RED, COLOR_WHITE);
			switch (candy[i][j])
			{
			case 1:
				attrset(COLOR_PAIR(1));
				mvaddstr(i,j,"A"); break;
				
				
			case 10:
				attrset(COLOR_PAIR(2));
				mvaddstr(i, j, "B");	break;
				
			case 100:
				attrset(COLOR_PAIR(3));
				mvaddstr(i, j, "C"); break;
				
			case 1000:
				attrset(COLOR_PAIR(4));
				mvaddstr(i, j, "D");	break;
			
			case 10000:
				attrset(COLOR_PAIR(5));
				mvaddstr(i, j, "E"); break;
			case 100000:
				attrset(COLOR_PAIR(6));
				mvaddstr(i, j, "O"); break;
			case -1:
				mvaddstr(i, j,  " "); break;
			
			}
		}
		mvprintw(i, 10, "\n");
	}
	}
	//一顆100分
	bool swapable()
	{
		for (int i = 0; i < 6; i++)//special bomb
		{
			for (int j = 0; j < 8; j++)
			{
				if ((candy[i][j] + candy[i][j + 1] + candy[i][j + 2] == 300000) || (candy[i][j]+candy[i][j+1]+candy[i][j+2]==300000))
				{
					return true;
				}
			}
		}
		//------------------------------------------------------橫的-------------------------------------------//
		

		//A
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 8; j++)
			{



				if (j + 3 <= 3)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] + candy[i][j + 9] == 10) //10個
					{

				
						return true;
					}
				}
				if (j + 3 <= 4)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] == 9) //九個
					{

						
						 return true;
					}
				}
				if (j + 3 <= 5)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] == 8) //八個
					{

						
						return true;
					}
				}
				if (j + 3 <= 6)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] == 7) //七個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = -1;

						 return true;
					}
				}
				if (j + 3 <= 7)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] == 6) //六個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = -1;

						return true;
					}
				}
				if (j + 3 <= 8)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] == 5) //五個
					{

						return true;

					}
				}
				if (j + 3 <= 9)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] == 4) //四個
					{

				 return true;

					}
				}
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] == 3)//三個
				{

					 return true;

				}
			}
		}
	//B
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 8; j++)
		{



			if (j + 3 <= 3)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] + candy[i][j + 9] == 100) //10個
				{

				
					return true;
				}
			}
			if (j + 3 <= 4)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] == 90) //九個
				{

					 return true;
				}
			}
			if (j + 3 <= 5)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] == 80) //八個
				{

					 return true;

				}
			}
			if (j + 3 <= 6)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] == 70) //七個
				{

					 return true;
				}
			}
			if (j + 3 <= 7)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] == 60) //六個
				{

					 return true;
				}
			}
			if (j + 3 <= 8)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] == 50) //五個
				{

					 return true;
				}
			}
			if (j + 3 <= 9)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] == 40) //四個
				{

					 return true;
				}
			}
			if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] == 30)//三個
			{

				 return true;

			}
		}
	}
	//c
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 8; j++)
		{



			if (j + 3 <= 3)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] + candy[i][j + 9] == 1000) //九個
				{

					 return true;

				}
			}
			if (j + 3 <= 4)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] == 900) //九個
				{

					 return true;

				}
			}
			if (j + 3 <= 5)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] == 800) //八個
				{

					 return true;
				}
			}
			if (j + 3 <= 6)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] == 700) //七個
				{

					 return true;
				}
			}
			if (j + 3 <= 7)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] == 600) //六個
				{

					 return true;

				}
			}
			if (j + 3 <= 8)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] == 500) //五個
				{

					 return true;
				}
			}
			if (j + 3 <= 9)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] == 400) //四個
				{

					 return true;

				}
			}
			if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] == 300)//三個
			{

				 return true;
			}
		}
	}
	//D
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 8; j++)
		{



			if (j + 3 <= 3)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] + candy[i][j + 9] == 10000) //九個
				{

					 return true;
				}
			}
			if (j + 3 <= 4)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] == 9000) //九個
				{

				 return true;
				}
			}
			if (j + 3 <= 5)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] == 8000) //八個
				{

					 return true;

				}
			}
			if (j + 3 <= 6)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] == 7000) //七個
				{

				 return true;
				}
			}
			if (j + 3 <= 7)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] == 6000) //六個
				{

					 return true;
				}
			}
			if (j + 3 <= 8)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] == 5000) //五個
				{

					 return true;
				}
			}
			if (j + 3 <= 9)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] == 4000) //四個
				{

					 return true;

				}
			}
			if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] == 3000)//三個
			{

				 return true;

			}
		}
	}
	//E
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 8; j++)
		{



			if (j + 3 <= 3)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] + candy[i][j + 9] == 100000) //九個
				{

					 return true;
				}
			}
			if (j + 3 <= 4)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] == 90000) //九個
				{

					 return true;

				}
			}
			if (j + 3 <= 5)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] == 80000) //八個
				{

					 return true;
				}
			}
			if (j + 3 <= 6)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] == 70000) //七個
				{

					 return true;
				}
			}
			if (j + 3 <= 7)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] == 60000) //六個
				{

					 return true;

				}
			}
			if (j + 3 <= 8)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] == 50000) //五個
				{

					 return true;
				}
			}
			if (j + 3 <= 9)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] == 40000) //四個
				{

					 return true;

				}
			}
			if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] == 30000)//三個
			{

				 return true;

			}
		}
	}
	//------------------------------------------直的--------------------------------------------------
	//A
	//直的 六個 
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 10; j++)
		{

			if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] + candy[i + 3][j] + candy[i + 4][j] + candy[i + 5][j] == 6)
			{

				

				return true;
			}

		}
	}
	//直的 五個
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 10; j++)
		{

			if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] + candy[i + 3][j] + candy[i + 4][j] == 5)
			{

				
				return true;

			}

		}
	}
	//直的 四個
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 10; j++)
		{

			if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] + candy[i + 3][j] == 4)
			{

			
				return true;

			}

		}
	}
	//直的 三個
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 10; j++)
		{

			if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] == 3)
			{

			
				return true;

			}

		}
	}

	//B
	//直的 六個 
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 10; j++)
		{

			if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] + candy[i + 3][j] + candy[i + 4][j] + candy[i + 5][j] == 60)
			{

			

				return true;

			}

		}
	}
	//直的 五個
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 10; j++)
		{

			if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] + candy[i + 3][j] + candy[i + 4][j] == 50)
			{

			
				return true;


			}

		}
	}
	//直的 四個
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 10; j++)
		{

			if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] + candy[i + 3][j] == 40)
			{

			

				return true;

			}

		}
	}
	//直的 三個
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 10; j++)
		{

			if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] == 30)
			{

				
				return true;

			}

		}
	}
	//C
	//直的 六個 
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 10; j++)
		{

			if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] + candy[i + 3][j] + candy[i + 4][j] + candy[i + 5][j] == 600)
			{

			
				return true;

			}

		}
	}
	//直的 五個
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 10; j++)
		{

			if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] + candy[i + 3][j] + candy[i + 4][j] == 500)
			{

				
				return true;


			}

		}
	}
	//直的 四個
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 10; j++)
		{

			if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] + candy[i + 3][j] == 400)
			{

				

				return true;
			}

		}
	}
	//直的 三個
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 10; j++)
		{

			if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] == 300)
			{

			
				return true;

			}

		}
	}

	//D
	//直的 六個 
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 10; j++)
		{

			if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] + candy[i + 3][j] + candy[i + 4][j] + candy[i + 5][j] == 6000)
			{

				
				return true;


			}

		}
	}
	//直的 五個
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 10; j++)
		{

			if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] + candy[i + 3][j] + candy[i + 4][j] == 5000)
			{

				

				return true;

			}

		}
	}
	//直的 四個
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 10; j++)
		{

			if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] + candy[i + 3][j] == 4000)
			{

				

				return true;
			}

		}
	}
	//直的 三個
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 10; j++)
		{

			if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] == 3000)
			{

				
				return true;


			}

		}
	}
	//E
	//直的 六個 
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 10; j++)
		{

			if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] + candy[i + 3][j] + candy[i + 4][j] + candy[i + 5][j] == 60000)
			{

			
				return true;
			}

		}
	}
	//直的 五個
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 10; j++)
		{

			if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] + candy[i + 3][j] + candy[i + 4][j] == 50000)
			{

			

				return true;

			}

		}
	}
	//直的 四個
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 10; j++)
		{

			if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] + candy[i + 3][j] == 40000) //四個
			{

			
				return true;


			}

		}
	}
	//直的 三個
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 10; j++)
		{

			if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] == 30000) //四個
			{

				

				return true;

			}

		}
	}


	return false;
}
	void setempty()//判斷可消後，消掉並設為-1
	{   //  x
		//  x
		//xxo
		for (int i = 2; i < 6; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i - 1][j + 2] + candy[i - 2][j + 2] == 5)
				{
					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i - 1][j + 2] = candy[i - 2][j + 2] = -1; score += 500;
					candy[i][j+2] = 100000;
				}
			}
		}
		for (int i = 2; i < 6; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i - 1][j + 2] + candy[i - 2][j + 2] == 50)
				{
					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i - 1][j + 2] = candy[i - 2][j + 2] = -1; score += 500; candy[i][j+2] = 100000;
				}
			}
		}
		for (int i = 2; i < 6; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i - 1][j + 2] + candy[i - 2][j + 2] == 500)
				{
					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i - 1][j + 2] = candy[i - 2][j + 2] = -1; score += 500; candy[i][j+2] = 100000;
				}
			}
		}
		for (int i = 2; i < 6; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i - 1][j + 2] + candy[i - 2][j + 2] == 5000)
				{
					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i - 1][j + 2] = candy[i - 2][j + 2] = -1; score += 500; candy[i][j+2] = 100000;
				}
			}
		}
		for (int i = 2; i < 6; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i - 1][j + 2] + candy[i - 2][j + 2] == 50000)
				{
					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i - 1][j + 2] = candy[i - 2][j + 2] = -1; score += 500; candy[i][j+2] = 100000;
				}
			}
		}
		//x
		//x
		//o x x
		for (int i = 2; i < 6; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i - 1][j] + candy[i - 2][j] == 5)
				{
					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i - 1][j] = candy[i - 2][j] = -1; candy[i][j] = 100000;
					score += 500;
				}
			}
		}
		for (int i = 2; i < 6; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i - 1][j] + candy[i - 2][j] == 50)
				{
					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i - 1][j] = candy[i - 2][j] = -1; candy[i][j] = 100000;
					score += 500;
				}
			}
		}
		for (int i = 2; i < 6; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i - 1][j] + candy[i - 2][j] == 500)
				{
					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i - 1][j] = candy[i - 2][j] = -1; candy[i][j] = 100000;
					score += 500;
				}
			}
		}
		for (int i = 2; i < 6; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i - 1][j] + candy[i - 2][j] == 5000)
				{
					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i - 1][j] = candy[i - 2][j] = -1; candy[i][j] = 100000;
					score += 500;
				}
			}
		}
		for (int i = 2; i < 6; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i - 1][j] + candy[i - 2][j] == 50000)
				{
					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i - 1][j] = candy[i - 2][j] = -1; candy[i][j] = 100000;
					score += 500;
				}
			}
		}
		//x x o
		//    x
		//    x
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i+1][j+2] + candy[i +2][j+2] == 5)
				{
					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i +1][j+2] = candy[i + 2][j+2] = -1; candy[i][j+2] = 100000;
					score += 500;
				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i + 1][j + 2] + candy[i + 2][j + 2] == 50)
				{
					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i + 1][j+2] = candy[i + 2][j+2] = -1; candy[i][j+2] = 100000;
					score += 500;
				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i + 1][j + 2] + candy[i + 2][j + 2] == 500)
				{
					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i + 1][j+2] = candy[i + 2][j+2] = -1; candy[i][j+2] = 100000;
					score += 500;
				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i + 1][j + 2] + candy[i + 2][j + 2] == 5000)
				{
					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i + 1][j+2] = candy[i - 2][j+2] = -1; candy[i][j+2] = 100000;
					score += 500;
				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i + 1][j + 2] + candy[i + 2][j + 2] == 50000)
				{
					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i + 1][j+2] = candy[i + 2][j+2] = -1; candy[i][j+2] = 100000;
					score += 500;
				}
			}
		}
		//o x x
		//x
		//x
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i + 1][j] + candy[i + 2][j] == 5)
				{
					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i + 1][j] = candy[i +2][j] = -1; candy[i][j] = 100000;
					score += 500;
				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i + 1][j] + candy[i + 2][j] == 50)
				{
					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i + 1][j] = candy[i + 2][j] = -1; candy[i][j] = 100000;
					score += 500;
				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i + 1][j] + candy[i + 2][j] == 500)
				{
					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i + 1][j] = candy[i + 2][j] = -1; candy[i][j] = 100000;
					score += 500;
				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i + 1][j] + candy[i + 2][j] == 5000)
				{
					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i + 1][j] = candy[i + 2][j] = -1; candy[i][j] = 100000;
					score += 500;
				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i + 1][j] + candy[i + 2][j] == 50000)
				{
					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i + 1][j] = candy[i + 2][j] = -1; candy[i][j] = 100000;
					score += 500;
				}
			}
		}
		//     x
		// x x o
		//     x
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i + 1][j+2] + candy[i -1][j+2] == 5)
				{
					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i + 1][j+2] = candy[i -1][j+2] = -1; candy[i][j+2] = 100000;
					score += 500;
				}
			}
		}

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i + 1][j + 2] + candy[i - 1][j + 2] == 50)
				{
					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i + 1][j + 2] = candy[i - 1][j + 2] = -1; candy[i][j+2] = 100000;
					score += 500;
				}
			}
		}
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i + 1][j + 2] + candy[i - 1][j + 2] == 500)
				{
					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i + 1][j + 2] = candy[i - 1][j + 2] = -1; candy[i][j+2] = 100000;
					score += 500;
				}
			}
		}
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i + 1][j + 2] + candy[i - 1][j + 2] == 5000)
				{
					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i + 1][j + 2] = candy[i - 1][j + 2] = -1; candy[i][j+2] = 100000;
					score += 500;
				}
			}
		}
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i + 1][j + 2] + candy[i - 1][j + 2] == 50000)
				{
					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i + 1][j + 2] = candy[i - 1][j + 2] = -1; candy[i][j+2] = 100000;
					score += 500;
				}
			}
		}

		//   x
		//   o x x
		//   x
		//
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i + 1][j] + candy[i - 1][j] == 5)
				{
					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i + 1][j] = candy[i - 1][j] = -1; candy[i][j] = 100000;
					score += 500;
				}
			}
		}
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i + 1][j] + candy[i - 1][j] == 50)
				{
					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i + 1][j] = candy[i - 1][j] = -1; candy[i][j] = 100000;
					score += 500;
				}
			}
		}
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i + 1][j] + candy[i - 1][j] == 500)
				{
					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i + 1][j] = candy[i - 1][j] = -1; candy[i][j] = 100000;
					score += 500;
				}
			}
		}
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i + 1][j] + candy[i - 1][j] == 5000)
				{
					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i + 1][j] = candy[i - 1][j] = -1; candy[i][j] = 100000;
					score += 500;
				}
			}
		}
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i + 1][j] + candy[i - 1][j] == 50000)
				{
					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i + 1][j] = candy[i - 1][j] = -1; candy[i][j] = 100000;
					score += 500;
				}
			}
		}
		//x o x
		//  x
		//  x
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i + 1][j+1] + candy[i+2][j+1] == 5)
				{
					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i + 1][j+1] = candy[i +2][j+1] = -1; candy[i][j+1] = 100000;
					score += 500;
				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i + 1][j + 1] + candy[i + 2][j + 1] == 50)
				{
					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i + 1][j + 1] = candy[i + 2][j + 1] = -1; candy[i][j+1] = 100000;
					score += 500;
				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i + 1][j + 1] + candy[i + 2][j + 1] == 500)
				{
					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i + 1][j + 1] = candy[i + 2][j + 1] = -1; candy[i][j+1] = 100000;
					score += 500;
				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i + 1][j + 1] + candy[i + 2][j + 1] == 5000)
				{
					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i + 1][j + 1] = candy[i + 2][j + 1] = -1; candy[i][j+1] = 100000;
					score += 500;
				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i + 1][j + 1] + candy[i + 2][j + 1] == 50000)
				{
					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i + 1][j + 1] = candy[i + 2][j + 1] = -1; candy[i][j+1] = 100000;
					score += 500;
				}
			}
		}

		//  x
		//  x
		//x o x
		for (int i = 2; i < 6; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i - 1][j + 1] + candy[i - 2][j + 1] == 5)
				{
					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i - 1][j + 1] = candy[i - 2][j + 1] = -1; candy[i][j+1] = 100000;
					score += 500;
				}
			}
		}
		for (int i = 2; i < 6; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i - 1][j + 1] + candy[i - 2][j + 1] == 50)
				{
					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i - 1][j + 1] = candy[i - 2][j + 1] = -1; candy[i][j+1] = 100000;
					score += 500;
				}
			}
		}
		for (int i = 2; i < 6; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i - 1][j + 1] + candy[i - 2][j + 1] == 500)
				{
					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i - 1][j + 1] = candy[i - 2][j + 1] = -1; candy[i][j+1] = 100000;
					score += 500;
				}
			}
		}
		for (int i = 2; i < 6; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i - 1][j + 1] + candy[i - 2][j + 1] == 5000)
				{
					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i - 1][j + 1] = candy[i - 2][j + 1] = -1; candy[i][j+1] = 100000;
					score += 500;
				}
			}
		}
		for (int i = 2; i < 6; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i - 1][j + 1] + candy[i - 2][j + 1] == 50000)
				{
					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i - 1][j + 1] = candy[i - 2][j + 1] = -1; candy[i][j+1] = 100000;
					score += 500;
				}
			}
		}
		//------------------------------------------------------橫的-------------------------------------------//
		

		//A
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 8; j++)
			{


				
				if (j + 3 <= 3)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8]+candy[i][j+9] == 10) //10個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = candy[i][j + 8]=candy[i][j+9] = -1;
						candy[i][j] = 100000;
						score += 1000;
					}
				}
				if (j + 3 <= 4)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7]+candy[i][j+8] == 9) //九個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7]=candy[i][j+8] = -1;

						score += 900;
					}
				}
				if (j + 3 <= 5)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6]+candy[i][j+7] == 8) //八個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = -1;

						score += 800;
					}
				}
				if (j + 3 <= 6)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5]+candy[i][j+6] == 7) //七個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5]=candy[i][j+6] = -1;

						score += 700;
					}
				}
				if (j + 3 <= 7)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] +candy[i][j+5]== 6) //六個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] =candy[i][j+5]= -1;
					
						score += 600;
					}
				}
				if (j + 3 <= 8)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3]+candy[i][j+4] == 5) //五個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j+4]=-1;
						candy[i][j] = 100000;
						score += 500;

					}
				}
				if (j + 3 <= 9)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] == 4) //四個
					{
						
							candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = -1;
							score += 400;
				
					}
				}
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] == 3)//三個
				{

					candy[i][j] = candy[i][j + 1] = candy[i][j + 2]  = -1;
					
					score += 300;

				}
			}
		}
		//B
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 8; j++)
			{



				if (j + 3 <= 3)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] + candy[i][j + 9] == 100) //10個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = candy[i][j + 8] = candy[i][j + 9] = -1;
						score += 1000;

					}
				}
				if (j + 3 <= 4)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] == 90) //九個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = candy[i][j + 8] = -1;

						score += 900;
					}
				}
				if (j + 3 <= 5)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] == 80) //八個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = -1;
						score += 800;

					}
				}
				if (j + 3 <= 6)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] == 70) //七個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = -1;

						score += 700;
					}
				}
				if (j + 3 <= 7)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] == 60) //六個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = -1;

						score += 600;
					}
				}
				if (j + 3 <= 8)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] == 50) //五個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = -1;
						candy[i][j] = 100000;
						score += 500;
					}
				}
				if (j + 3 <= 9)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] == 40) //四個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = -1;

						score += 400;
					}
				}
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] == 30)//三個
				{

					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = -1;
					
					score += 300;

				}
			}
		}
		//c
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 8; j++)
			{



				if (j + 3 <= 3)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] + candy[i][j + 9] == 1000) //九個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = candy[i][j + 8] = candy[i][j + 9] = -1;
						score += 1000;

					}
				}
				if (j + 3 <= 4)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] == 900) //九個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = candy[i][j + 8] = -1;
						score += 900;

					}
				}
				if (j + 3 <= 5)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] == 800) //八個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = -1;

						score += 800;
					}
				}
				if (j + 3 <= 6)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] == 700) //七個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = -1;

						score += 700;
					}
				}
				if (j + 3 <= 7)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] == 600) //六個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = -1;
						score += 600;

					}
				}
				if (j + 3 <= 8)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] == 500) //五個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = -1;
						candy[i][j] = 100000;
						score += 500;
					}
				}
				if (j + 3 <= 9)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] == 400) //四個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = -1;
						score += 400;

					}
				}
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] == 300)//三個
				{

					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = -1;


					score += 300;
				}
			}
		}
		//D
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 8; j++)
			{



				if (j + 3 <= 3)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] + candy[i][j + 9] == 10000) //九個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = candy[i][j + 8] = candy[i][j + 9] = -1;

						score += 1000;
					}
				}
				if (j + 3 <= 4)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] == 9000) //九個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = candy[i][j + 8] = -1;

						score += 900;
					}
				}
				if (j + 3 <= 5)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] == 8000) //八個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = -1;
						score += 800;

					}
				}
				if (j + 3 <= 6)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] == 7000) //七個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = -1;

						score += 700;
					}
				}
				if (j + 3 <= 7)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] == 6000) //六個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = -1;

						score += 600;
					}
				}
				if (j + 3 <= 8)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] == 5000) //五個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = -1;
						candy[i][j] = 100000;
						score += 500;
					}
				}
				if (j + 3 <= 9)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] == 4000) //四個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = -1;
						score += 400;

					}
				}
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] == 3000)//三個
				{

					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = -1;

					score += 300;

				}
			}
		}
		//E
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 8; j++)
			{



				if (j + 3 <= 3)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] + candy[i][j + 9] == 100000) //九個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = candy[i][j + 8] = candy[i][j + 9] = -1;

						score += 1000;
					}
				}
				if (j + 3 <= 4)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] == 90000) //九個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = candy[i][j + 8] = -1;
						score += 900;

					}
				}
				if (j + 3 <= 5)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] == 80000) //八個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = -1;

						score += 800;
					}
				}
				if (j + 3 <= 6)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] == 70000) //七個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = -1;

						score += 700;
					}
				}
				if (j + 3 <= 7)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] == 60000) //六個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = -1;
						score += 600;

					}
				}
				if (j + 3 <= 8)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] == 50000) //五個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = -1;
						candy[i][j] = 100000;
						score += 500;
					}
				}
				if (j + 3 <= 9)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] == 40000) //四個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = -1;
						score += 400;

					}
				}
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] == 30000)//三個
				{

					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = -1;

					score += 300;

				}
			}
		}
		//------------------------------------------直的--------------------------------------------------
		//A
		//直的 六個 
		for (int i = 0; i < 1; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] + candy[i + 3][j] + candy[i + 4][j]+ candy[i+5][j]== 6) 
				{

					candy[i][j] = candy[i + 1][j] = candy[i + 2][j] = candy[i + 3][j] = candy[i + 4][j]=candy[i+5][j] = -1;



					score += 600;


				}

			}
		}
		//直的 五個
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] + candy[i + 3][j] +candy[i+4][j]== 5) 
				{

					candy[i][j] = candy[i + 1][j] = candy[i + 2][j] = candy[i + 3][j] =candy[i+4][j]= -1;

					score += 500;

					candy[i][j] = 100000;


				}

			}
		}
		//直的 四個
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] + candy[i + 3][j] == 4) 
				{
				
						candy[i][j] = candy[i + 1][j] = candy[i + 2][j] = candy[i + 3][j] = -1;
							
					

						score += 400;


				}

			}
		}
		//直的 三個
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] == 3) 
				{

					candy[i][j] = candy[i + 1][j] = candy[i + 2][j]  = -1;



					score += 300;


				}

			}
		}

		//B
		//直的 六個 
		for (int i = 0; i < 1; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] + candy[i + 3][j] + candy[i + 4][j] + candy[i + 5][j] == 60) 
				{

					candy[i][j] = candy[i + 1][j] = candy[i + 2][j] = candy[i + 3][j] = candy[i + 4][j] = candy[i + 5][j] = -1;


					score += 600;



				}

			}
		}
		//直的 五個
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] + candy[i + 3][j] + candy[i + 4][j] == 50) 
				{

					candy[i][j] = candy[i + 1][j] = candy[i + 2][j] = candy[i + 3][j] = candy[i + 4][j] = -1;

					candy[i][j] = 100000;
					score += 500;



				}

			}
		}
		//直的 四個
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] + candy[i + 3][j] == 40) 
				{

					candy[i][j] = candy[i + 1][j] = candy[i + 2][j] = candy[i + 3][j] = -1;


					score += 400;



				}

			}
		}
		//直的 三個
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] == 30) 
				{

					candy[i][j] = candy[i + 1][j] = candy[i + 2][j] = -1;



					score += 300;


				}

			}
		}
		//C
		//直的 六個 
		for (int i = 0; i < 1; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] + candy[i + 3][j] + candy[i + 4][j] + candy[i + 5][j] == 600) 
				{

					candy[i][j] = candy[i + 1][j] = candy[i + 2][j] = candy[i + 3][j] = candy[i + 4][j] = candy[i + 5][j] = -1;



					score += 600;


				}

			}
		}
		//直的 五個
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] + candy[i + 3][j] + candy[i + 4][j] == 500) 
				{

					candy[i][j] = candy[i + 1][j] = candy[i + 2][j] = candy[i + 3][j] = candy[i + 4][j] = -1;

					candy[i][j] = 100000;
					score += 500;



				}

			}
		}
		//直的 四個
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] + candy[i + 3][j] == 400) 
				{

					candy[i][j] = candy[i + 1][j] = candy[i + 2][j] = candy[i + 3][j] = -1;



					score += 400;


				}

			}
		}
		//直的 三個
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] == 300) 
				{

					candy[i][j] = candy[i + 1][j] = candy[i + 2][j] = -1;



					score += 300;


				}

			}
		}

		//D
		//直的 六個 
		for (int i = 0; i < 1; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] + candy[i + 3][j] + candy[i + 4][j] + candy[i + 5][j] == 6000) 
				{

					candy[i][j] = candy[i + 1][j] = candy[i + 2][j] = candy[i + 3][j] = candy[i + 4][j] = candy[i + 5][j] = -1;


					score += 600;



				}

			}
		}
		//直的 五個
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] + candy[i + 3][j] + candy[i + 4][j] == 5000) 
				{

					candy[i][j] = candy[i + 1][j] = candy[i + 2][j] = candy[i + 3][j] = candy[i + 4][j] = -1;

					candy[i][j] = 100000;
					score += 500;



				}

			}
		}
		//直的 四個
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] + candy[i + 3][j] == 4000) 
				{

					candy[i][j] = candy[i + 1][j] = candy[i + 2][j] = candy[i + 3][j] = -1;



					score += 400;


				}

			}
		}
		//直的 三個
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] == 3000) 
				{

					candy[i][j] = candy[i + 1][j] = candy[i + 2][j] = -1;


					score += 300;



				}

			}
		}
		//E
		//直的 六個 
		for (int i = 0; i < 1; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] + candy[i + 3][j] + candy[i + 4][j] + candy[i + 5][j] == 60000) 
				{

					candy[i][j] = candy[i + 1][j] = candy[i + 2][j] = candy[i + 3][j] = candy[i + 4][j] = candy[i + 5][j] = -1;




					score += 600;

				}

			}
		}
		//直的 五個
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] + candy[i + 3][j] + candy[i + 4][j] == 50000) 
				{

					candy[i][j] = candy[i + 1][j] = candy[i + 2][j] = candy[i + 3][j] = candy[i + 4][j] = -1;
					candy[i][j] = 100000;

					score += 500;



				}

			}
		}
		//直的 四個
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] + candy[i + 3][j] == 40000) //四個
				{

					candy[i][j] = candy[i + 1][j] = candy[i + 2][j] = candy[i + 3][j] = -1;


					score += 400;



				}

			}
		}
		//直的 三個
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] == 30000) //四個
				{

					candy[i][j] = candy[i + 1][j] = candy[i + 2][j] = -1;


					score += 300;



				}

			}
		}
	
	}
	void skyfall()//天降
	{
	
		for (int i = 0; i <6; i++)
		{
			
			for (int j = 0; j < 10; j++) {

				if (candy[i][j] == -1 && i - 1 >= 0)
				{
					while (i > 0)//天降
					{
						candy[i][j] = candy[i - 1][j];

						i--;
					}
					candy[0][j] = -1;

				}
				if (candy[0][j] == -1) {
					int temp = (rand() % 5) + 1;
					switch (temp)
					{

					case 1:
						candy[0][j] = 1;
						break;
					case 2:
						candy[0][j] = 10;	break;
					case 3:
						candy[0][j] = 100;	break;
					case 4:
						candy[0][j] = 1000;	break;
					case 5:
						candy[0][j] = 10000;	break;

					}

				}
			}
		}
		






	}







	bool fuckyet=0;
	int go_on = 1;
	int preX;
	int preY;
	int nextX ;
	int nextY ;
	void lets_play_a_game()//play   
	{
		clear();
		refresh();
		setempty();
		skyfall();
		setempty();
		skyfall();
		setempty();
		skyfall();
		setempty();
		skyfall();
		setempty();
		skyfall();
		outputfruit();
		score = 0;
		while (go_on)
		{
		
			mvaddstr(1, 30, "target scores : ");
			mvprintw(1, 50, "%d", target);
			mvaddstr(2, 30, "your scores : ");
			mvprintw(2, 50, "%d", score);
			mvaddstr(0, 30, "remaining steps : ");
			mvprintw(0, 50, "%d", remainsteps);
		
			if (remainsteps == 0 && score<target)
			{
				attrset(A_REVERSE);//set background
				start_color();
				init_pair(6, COLOR_CYAN, COLOR_RED);
				attrset(COLOR_PAIR(6));
				mvaddstr(2, 15, "Out of moves");
				int gameover; gameover = getch(); go_on = false; break;
				
			}
			for (int i = 0; i < 6; i++)//special bomb 如果三個連在一起，就炸掉全部，直接獲勝(橫的)
			{
				for (int j = 0; j < 8; j++)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] == 300000)
					{


						score = target;
						clear();
						refresh();
						mvaddstr(6, 2, "You eliminate special bomb!!!!!");
						mvaddstr(1, 30, "target scores : ");
						mvprintw(1, 50, "%d", target);
						mvaddstr(2, 30, "your scores : ");
						mvprintw(2, 50, "%d", score);
						mvaddstr(0, 30, "remaining steps : ");
						mvprintw(0, 50, "%d", remainsteps);
					
					}
				}
			}
			for (int i = 0; i < 4; i++)//special bomb 如果三個連在一起，就炸掉全部，直接獲勝(直的)
			{
				for (int j = 0; j < 10; j++)
				{

					if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] == 300000)
					{


						score = target;
						clear();
						refresh();
						mvaddstr(6, 2, "You eliminate special bomb!!!!!");
						mvaddstr(1, 30, "target scores : ");
						mvprintw(1, 50, "%d", target);
						mvaddstr(2, 30, "your scores : ");
						mvprintw(2, 50, "%d", score);
						mvaddstr(0, 30, "remaining steps : ");
						mvprintw(0, 50, "%d", remainsteps);



					}

				}
			}
			if (score >= target)
			{
				attrset(A_REVERSE);//set background
				start_color();
				init_pair(7, COLOR_CYAN, COLOR_BLUE);
				attrset(COLOR_PAIR(7));
				mvaddstr(8, 2, "You Win!!!!!");
				int win; win = getch(); go_on = false; break;

			}
		//	attrset(A_UNDERLINE);
			mvaddstr(0, 15, "Easy LEVEL");
			mvaddstr(4, 30, "wanna quit game?press q");
			mvaddstr(5, 30, "Manual:");
			mvaddstr(6, 30, "press s to select and press t to choose places");
			cbreak(); // disable key buffering
			noecho(); // disable echoing
			keypad(stdscr, TRUE); // enable keypad reading
			getmaxyx(stdscr, height, width); // get screen size
			go_on = TRUE;
			move(y, x);
			
			int c;
			
			c = getch();
			switch (c) {
				//quit
			case 'q':  go_on = false; break;//退出遊戲
			case 's'://select

				preX = x;
				preY = y;
				break;
			case 't':
			{
				nextX = x;
				nextY = y;

				swap(candy[preY][preX], candy[nextY][nextX]); //成功交換
				if (swapable()) {

					remainsteps--;
					fuckyet = 1;
				}
				else //不能交換

				{
					swap(candy[preY][preX], candy[nextY][nextX]);//換回來
				
					fuckyet = 1;
					attrset(A_REVERSE);//set background
					attrset(COLOR_PAIR(6));
					mvaddstr(12, 1, "invalid move! "); int fuck; fuck = getch();
				}


				break;
			}
			case KEY_LEFT: --x; mvaddstr(10, 54, "Left "); break;
			case KEY_RIGHT: ++x; mvaddstr(10, 54, "Right"); break;
			case KEY_UP: --y; mvaddstr(10, 54, "Uppp "); break;
			case KEY_DOWN: ++y; mvaddstr(10, 54, "Down "); break;
			} // switch (c)
			
			while (x < 0) x += width;
			while (x >= width) x -= width;
			while (y < 0) y += height;
			while (y >= height) y -= height;
			refresh();
			// while (go_on)

			
			clear();
			refresh();
			setempty();
			outputfruit();
			

			if (fuckyet)
			{
				usleep(100000);
				int shit = getch();
			}
			skyfall();
			setempty();
			skyfall();
			setempty();
			skyfall();
			setempty();
			skyfall();
			setempty();
			skyfall();
			setempty();
			skyfall();
			setempty();
			skyfall();
			setempty();
			skyfall();
			setempty();
			skyfall();
			setempty();
			skyfall();
			setempty();
			skyfall();
			setempty();
			skyfall();
			setempty();
			outputfruit();
			fuckyet = 0;
		}
		
	}


	void swap(int & x, int & x2)
	{
		int tmp = x;
		x = x2;
		x2 = tmp;
	}



	
	
	

};
class Normal {
public:
	int candy[6][10] = { 0 };
	int temp;
	int height; int width;
	int c, x = 0, y = 1;
	int score = 0;
	int target = 10000;
	int remainsteps = 10;

	void setfruit()
	{
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				temp = (rand() % 5) + 1;
				switch (temp)
				{
				case 1:
					candy[i][j] = 1;
					break;
				case 2:
					candy[i][j] = 10;	break;
				case 3:
					candy[i][j] = 100;	break;
				case 4:
					candy[i][j] = 1000;	break;
				case 5:
					candy[i][j] = 10000;	break;

				}
			}
		}

	}

	void outputfruit()
	{
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (i < 3)
				{


					start_color();
					init_pair(1, COLOR_CYAN, COLOR_BLACK);
					init_pair(2, COLOR_RED, COLOR_BLACK);
					init_pair(3, COLOR_GREEN, COLOR_BLACK);
					init_pair(4, COLOR_BLUE, COLOR_BLACK);
					init_pair(5, COLOR_YELLOW, COLOR_BLACK);
					init_pair(6, COLOR_RED, COLOR_WHITE);
					switch (candy[i][j])
					{
					case 1:
						attrset(COLOR_PAIR(1));
						mvaddstr(i, j, "A"); break;


					case 10:
						attrset(COLOR_PAIR(2));
						mvaddstr(i, j, "B");	break;

					case 100:
						attrset(COLOR_PAIR(3));
						mvaddstr(i, j, "C"); break;

					case 1000:
						attrset(COLOR_PAIR(4));
						mvaddstr(i, j, "D");	break;

					case 10000:
						attrset(COLOR_PAIR(5));
						mvaddstr(i, j, "E"); break;
					case 100000:
						attrset(COLOR_PAIR(6));
						mvaddstr(i, j, "O"); break;
					case -1:
						mvaddstr(i, j, " "); break;

					}
				}
				else if (i == 3)
				{
					attrset(A_REVERSE);//set background
					mvaddstr(i, j, " ");

				}
				if(i>=3)
				switch (candy[i][j])
				{
				case 1:
					attrset(COLOR_PAIR(1));
					mvaddstr(i+1, j, "A"); break;


				case 10:
					attrset(COLOR_PAIR(2));
					mvaddstr(i+1, j, "B");	break;

				case 100:
					attrset(COLOR_PAIR(3));
					mvaddstr(i+1, j, "C"); break;

				case 1000:
					attrset(COLOR_PAIR(4));
					mvaddstr(i+1, j, "D");	break;

				case 10000:
					attrset(COLOR_PAIR(5));
					mvaddstr(i+1, j, "E"); break;
				case 100000:
					attrset(COLOR_PAIR(6));
					mvaddstr(i+1, j, "O"); break;
				case -1:
					mvaddstr(i+1, j, " "); break;

				}





			}
			/*if (i == 3)
			{
				for (int j = 0; j < 10; j++)
				{
					mvaddstr(i, j, " "); 
				}

			}*/
		}
	}
	bool swapable()
	{
		for (int i = 0; i < 6; i++)//special bomb
		{
			for (int j = 0; j < 8; j++)
			{
				if ((candy[i][j] + candy[i][j + 1] + candy[i][j + 2] == 300000) || (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] == 300000))
				{
					return true;
				}
			}
		}


		//------------------------------------------------------橫的-------------------------------------------//


		//A 0~2
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 8; j++)
			{



				if (j + 3 <= 3)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] + candy[i][j + 9] == 10) //10個
					{

						return true;
					}
				}
				if (j + 3 <= 4)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] == 9) //九個
					{

						return true;
					}
				}
				if (j + 3 <= 5)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] == 8) //八個
					{
						return true;
					}
				}
				if (j + 3 <= 6)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] == 7) //七個
					{

						return true;
					}
				}
				if (j + 3 <= 7)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] == 6) //六個
					{

						return true;
					}
				}
				if (j + 3 <= 8)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] == 5) //五個
					{

						return true;

					}
				}
				if (j + 3 <= 9)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] == 4) //四個
					{

						return true;

					}
				}
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] == 3)//三個
				{

					return true;

				}
			}
		}
		//A 3~5
		for (int i = 3; i < 6; i++)
		{
			for (int j = 0; j < 8; j++)
			{



				if (j + 3 <= 3)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] + candy[i][j + 9] == 10) //10個
					{

						return true;
					}
				}
				if (j + 3 <= 4)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] == 9) //九個
					{
						return true;
					}
				}
				if (j + 3 <= 5)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] == 8) //八個
					{

						return true;
					}
				}
				if (j + 3 <= 6)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] == 7) //七個
					{

						return true;
					}
				}
				if (j + 3 <= 7)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] == 6) //六個
					{

						return true;
					}
				}
				if (j + 3 <= 8)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] == 5) //五個
					{

						return true;

					}
				}
				if (j + 3 <= 9)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] == 4) //四個
					{

						return true;

					}
				}
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] == 3)//三個
				{

					return true;

				}
			}
		}
		//B
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 8; j++)
			{



				if (j + 3 <= 3)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] + candy[i][j + 9] == 100) //10個
					{

						return true;

					}
				}
				if (j + 3 <= 4)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] == 90) //九個
					{

						return true;
					}
				}
				if (j + 3 <= 5)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] == 80) //八個
					{

						return true;
					}
				}
				if (j + 3 <= 6)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] == 70) //七個
					{

						return true;
					}
				}
				if (j + 3 <= 7)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] == 60) //六個
					{

						return true;
					}
				}
				if (j + 3 <= 8)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] == 50) //五個
					{

						return true;
					}
				}
				if (j + 3 <= 9)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] == 40) //四個
					{

						return true;
					}
				}
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] == 30)//三個
				{

					return true;

				}
			}
		}
		//B 3~5
		for (int i = 3; i < 6; i++)
		{
			for (int j = 0; j < 8; j++)
			{



				if (j + 3 <= 3)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] + candy[i][j + 9] == 100) //10個
					{

						return true;

					}
				}
				if (j + 3 <= 4)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] == 90) //九個
					{

						return true;
					}
				}
				if (j + 3 <= 5)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] == 80) //八個
					{

						return true;

					}
				}
				if (j + 3 <= 6)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] == 70) //七個
					{

						return true;
					}
				}
				if (j + 3 <= 7)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] == 60) //六個
					{

						return true;
					}
				}
				if (j + 3 <= 8)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] == 50) //五個
					{

						return true;
					}
				}
				if (j + 3 <= 9)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] == 40) //四個
					{

						return true;
					}
				}
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] == 30)//三個
				{

					return true;

				}
			}
		}
		//c
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 8; j++)
			{



				if (j + 3 <= 3)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] + candy[i][j + 9] == 1000) //九個
					{

						return true;

					}
				}
				if (j + 3 <= 4)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] == 900) //九個
					{

						return true;

					}
				}
				if (j + 3 <= 5)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] == 800) //八個
					{

						return true;
					}
				}
				if (j + 3 <= 6)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] == 700) //七個
					{

						return true;
					}
				}
				if (j + 3 <= 7)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] == 600) //六個
					{

						return true;

					}
				}
				if (j + 3 <= 8)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] == 500) //五個
					{

						return true;
					}
				}
				if (j + 3 <= 9)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] == 400) //四個
					{

						return true;

					}
				}
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] == 300)//三個
				{

					return true;
				}
			}
		}

		//c 3~5
		for (int i = 3; i < 6; i++)
		{
			for (int j = 0; j < 8; j++)
			{



				if (j + 3 <= 3)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] + candy[i][j + 9] == 1000) //九個
					{
						return true;

					}
				}
				if (j + 3 <= 4)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] == 900) //九個
					{

						return true;

					}
				}
				if (j + 3 <= 5)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] == 800) //八個
					{

						return true;
					}
				}
				if (j + 3 <= 6)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] == 700) //七個
					{

						return true;
					}
				}
				if (j + 3 <= 7)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] == 600) //六個
					{

						return true;

					}
				}
				if (j + 3 <= 8)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] == 500) //五個
					{

						return true;
					}
				}
				if (j + 3 <= 9)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] == 400) //四個
					{

						return true;

					}
				}
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] == 300)//三個
				{

					return true;
				}
			}
		}
		//D
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 8; j++)
			{



				if (j + 3 <= 3)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] + candy[i][j + 9] == 10000) //九個
					{

						return true;
					}
				}
				if (j + 3 <= 4)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] == 9000) //九個
					{

						return true;
					}
				}
				if (j + 3 <= 5)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] == 8000) //八個
					{

						return true;

					}
				}
				if (j + 3 <= 6)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] == 7000) //七個
					{

						return true;
					}
				}
				if (j + 3 <= 7)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] == 6000) //六個
					{

						return true;
					}
				}
				if (j + 3 <= 8)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] == 5000) //五個
					{

						
						return true;
					}
				}
				if (j + 3 <= 9)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] == 4000) //四個
					{

						return true;

					}
				}
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] == 3000)//三個
				{

					return true;

				}
			}
		}
		//D 3~5
		for (int i = 3; i < 6; i++)
		{
			for (int j = 0; j < 8; j++)
			{



				if (j + 3 <= 3)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] + candy[i][j + 9] == 10000) //九個
					{

						return true;
					}
				}
				if (j + 3 <= 4)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] == 9000) //九個
					{

						return true;
					}
				}
				if (j + 3 <= 5)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] == 8000) //八個
					{

						return true;

					}
				}
				if (j + 3 <= 6)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] == 7000) //七個
					{

						return true;
					}
				}
				if (j + 3 <= 7)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] == 6000) //六個
					{

						return true;
					}
				}
				if (j + 3 <= 8)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] == 5000) //五個
					{

						return true;
					}
				}
				if (j + 3 <= 9)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] == 4000) //四個
					{

						return true;

					}
				}
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] == 3000)//三個
				{

					return true;

				}
			}
		}
		//E
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 8; j++)
			{



				if (j + 3 <= 3)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] + candy[i][j + 9] == 100000) //九個
					{

						return true;
					}
				}
				if (j + 3 <= 4)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] == 90000) //九個
					{

						return true;

					}
				}
				if (j + 3 <= 5)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] == 80000) //八個
					{

						return true;
					}
				}
				if (j + 3 <= 6)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] == 70000) //七個
					{

						return true;
					}
				}
				if (j + 3 <= 7)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] == 60000) //六個
					{

						return true;

					}
				}
				if (j + 3 <= 8)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] == 50000) //五個
					{

						return true;
					}
				}
				if (j + 3 <= 9)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] == 40000) //四個
					{

						return true;

					}
				}
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] == 30000)//三個
				{

					return true;

				}
			}
		}


		//E 3~5
		for (int i = 3; i < 6; i++)
		{
			for (int j = 0; j < 8; j++)
			{



				if (j + 3 <= 3)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] + candy[i][j + 9] == 100000) //九個
					{
						return true;
					}
				}
				if (j + 3 <= 4)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] == 90000) //九個
					{

						return true;

					}
				}
				if (j + 3 <= 5)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] == 80000) //八個
					{

						return true;
					}
				}
				if (j + 3 <= 6)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] == 70000) //七個
					{

						return true;
					}
				}
				if (j + 3 <= 7)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] == 60000) //六個
					{

						return true;

					}
				}
				if (j + 3 <= 8)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] == 50000) //五個
					{

						return true;
					}
				}
				if (j + 3 <= 9)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] == 40000) //四個
					{

						return true;

					}
				}
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] == 30000)//三個
				{

					return true;

				}
			}
		}
		//------------------------------------------直的--------------------------------------------------
		//A



		//直的 三個
		for (int i = 0; i < 1; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] == 3)
				{

					return true;
				


				}

			}
		}
		for (int i = 3; i < 4; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] == 3)
				{

					return true;


				}

			}
		}
		//B

		//直的 三個
		for (int i = 0; i < 1; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] == 30)
				{

					return true;


				}

			}
		}
		//直的 三個
		for (int i = 3; i < 4; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] == 30)
				{

					return true;


				}

			}
		}
		//C


		//直的 三個
		for (int i = 0; i < 1; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] == 300)
				{

					return true;


				}

			}
		}
		//C


		//直的 三個
		for (int i = 3; i < 4; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] == 300)
				{

					return true;


				}

			}
		}
		//D

		//直的 三個
		for (int i = 0; i < 1; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] == 3000)
				{

					return true;



				}

			}
		}
		//D

		//直的 三個
		for (int i = 3; i < 4; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] == 3000)
				{

					return true;



				}

			}
		}
		//E

		//直的 三個
		for (int i = 0; i < 1; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] == 30000)
				{

					return true;



				}

			}
		}
		for (int i = 3; i < 4; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] == 30000)
				{

					return true;


				}

			}
		}
		return false;

	}
	//一顆100分
	void setempty()//判斷可消後，消掉並設為-1
	{
		//  x
		//  x
		//xxo
		
			for (int j = 0; j < 8; j++)
			{
				if (candy[2][j] + candy[2][j + 1] + candy[2][j + 2] + candy[1][j + 2] + candy[0][j + 2] == 5)
				{
					candy[2][j] = candy[2][j + 1] = candy[2][j + 2] = candy[1][j + 2] = candy[0][j + 2] = -1; score += 500;
					candy[2][j+2] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[5][j] + candy[5][j + 1] + candy[5][j + 2] + candy[4][j + 2] + candy[3][j + 2] == 5)
				{
					candy[5][j] = candy[5][j + 1] = candy[5][j + 2] = candy[4][j + 2] = candy[3][j + 2] = -1; score += 500;
					candy[5][j+2] = 100000;
				}
			}

			for (int j = 0; j < 8; j++)
			{
				if (candy[2][j] + candy[2][j + 1] + candy[2][j + 2] + candy[1][j + 2] + candy[0][j + 2] == 50)
				{
					candy[2][j] = candy[2][j + 1] = candy[2][j + 2] = candy[1][j + 2] = candy[0][j + 2] = -1; score += 500;
					candy[2][j+2] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[5][j] + candy[5][j + 1] + candy[5][j + 2] + candy[4][j + 2] + candy[3][j + 2] == 50)
				{
					candy[5][j] = candy[5][j + 1] = candy[5][j + 2] = candy[4][j + 2] = candy[3][j + 2] = -1; score += 500;
					candy[5][j+2] = 100000;
				}
			}

			for (int j = 0; j < 8; j++)
			{
				if (candy[2][j] + candy[2][j + 1] + candy[2][j + 2] + candy[1][j + 2] + candy[0][j + 2] == 500)
				{
					candy[2][j] = candy[2][j + 1] = candy[2][j + 2] = candy[1][j + 2] = candy[0][j + 2] = -1; score += 500;
					candy[2][j+2] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[5][j] + candy[5][j + 1] + candy[5][j + 2] + candy[4][j + 2] + candy[3][j + 2] == 500)
				{
					candy[5][j] = candy[5][j + 1] = candy[5][j + 2] = candy[4][j + 2] = candy[3][j + 2] = -1; score += 500;
					candy[5][j+2] = 100000;
				}
			}

			for (int j = 0; j < 8; j++)
			{
				if (candy[2][j] + candy[2][j + 1] + candy[2][j + 2] + candy[1][j + 2] + candy[0][j + 2] == 5000)
				{
					candy[2][j] = candy[2][j + 1] = candy[2][j + 2] = candy[1][j + 2] = candy[0][j + 2] = -1; score += 500;
					candy[2][j+2] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[5][j] + candy[5][j + 1] + candy[5][j + 2] + candy[4][j + 2] + candy[3][j + 2] == 5000)
				{
					candy[5][j] = candy[5][j + 1] = candy[5][j + 2] = candy[4][j + 2] = candy[3][j + 2] = -1; score += 500;
					candy[5][j+2] = 100000;
				}
			}

			for (int j = 0; j < 8; j++)
			{
				if (candy[2][j] + candy[2][j + 1] + candy[2][j + 2] + candy[1][j + 2] + candy[0][j + 2] == 50000)
				{
					candy[2][j] = candy[2][j + 1] = candy[2][j + 2] = candy[1][j + 2] = candy[0][j + 2] = -1; score += 500;
					candy[2][j+2] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[5][j] + candy[5][j + 1] + candy[5][j + 2] + candy[4][j + 2] + candy[3][j + 2] == 50000)
				{
					candy[5][j] = candy[5][j + 1] = candy[5][j + 2] = candy[4][j + 2] = candy[3][j + 2] = -1; score += 500;
					candy[5][j+2] = 100000;
				}
			}
		//x
		//x
		//o x x
			for (int j = 0; j < 8; j++)
			{
				if (candy[2][j] + candy[2][j + 1] + candy[2][j + 2] + candy[1][j] + candy[0][j] == 5)
				{
					candy[2][j] = candy[2][j + 1] = candy[2][j + 2] = candy[1][j] = candy[0][j] = -1; score += 500;
					candy[2][j] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[5][j] + candy[5][j + 1] + candy[5][j + 2] + candy[4][j] + candy[3][j] == 5)
				{
					candy[5][j] = candy[5][j + 1] = candy[5][j + 2] = candy[4][j] = candy[3][j] = -1; score += 500;
					candy[5][j] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[2][j] + candy[2][j + 1] + candy[2][j + 2] + candy[1][j] + candy[0][j] == 50)
				{
					candy[2][j] = candy[2][j + 1] = candy[2][j + 2] = candy[1][j] = candy[0][j] = -1; score += 500;
					candy[2][j] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[5][j] + candy[5][j + 1] + candy[5][j + 2] + candy[4][j] + candy[3][j] == 50)
				{
					candy[5][j] = candy[5][j + 1] = candy[5][j + 2] = candy[4][j] = candy[3][j] = -1; score += 500;
					candy[5][j] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[2][j] + candy[2][j + 1] + candy[2][j + 2] + candy[1][j] + candy[0][j] == 500)
				{
					candy[2][j] = candy[2][j + 1] = candy[2][j + 2] = candy[1][j] = candy[0][j] = -1; score += 500;
					candy[2][j] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[5][j] + candy[5][j + 1] + candy[5][j + 2] + candy[4][j] + candy[3][j] == 500)
				{
					candy[5][j] = candy[5][j + 1] = candy[5][j + 2] = candy[4][j] = candy[3][j] = -1; score += 500;
					candy[5][j] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[2][j] + candy[2][j + 1] + candy[2][j + 2] + candy[1][j] + candy[0][j] == 5000)
				{
					candy[2][j] = candy[2][j + 1] = candy[2][j + 2] = candy[1][j] = candy[0][j] = -1; score += 500;
					candy[2][j] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[5][j] + candy[5][j + 1] + candy[5][j + 2] + candy[4][j] + candy[3][j] == 5000)
				{
					candy[5][j] = candy[5][j + 1] = candy[5][j + 2] = candy[4][j] = candy[3][j] = -1; score += 500;
					candy[5][j] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[2][j] + candy[2][j + 1] + candy[2][j + 2] + candy[1][j] + candy[0][j] == 50000)
				{
					candy[2][j] = candy[2][j + 1] = candy[2][j + 2] = candy[1][j] = candy[0][j] = -1; score += 500;
					candy[2][j] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[5][j] + candy[5][j + 1] + candy[5][j + 2] + candy[4][j] + candy[3][j] == 50000)
				{
					candy[5][j] = candy[5][j + 1] = candy[5][j + 2] = candy[4][j] = candy[3][j] = -1; score += 500;
					candy[5][j] = 100000;
				}
			}
		//x x o
		//    x
		//    x
			for (int j = 0; j < 8; j++)
			{
				if (candy[0][j] + candy[0][j + 1] + candy[0][j + 2] + candy[1][j+2] + candy[2][j+2] == 5)
				{
					candy[0][j] = candy[0][j + 1] = candy[0][j + 2] = candy[1][j+2] = candy[2][j+2] = -1; score += 500;
					candy[0][j+2] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[3][j] + candy[3][j + 1] + candy[3][j + 2] + candy[4][j + 2] + candy[5][j + 2] == 5)
				{
					candy[3][j] = candy[3][j + 1] = candy[3][j + 2] = candy[4][j + 2] = candy[5][j + 2] = -1; score += 500;
					candy[3][j+2] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[0][j] + candy[0][j + 1] + candy[0][j + 2] + candy[1][j + 2] + candy[2][j + 2] == 50)
				{
					candy[0][j] = candy[0][j + 1] = candy[0][j + 2] = candy[1][j + 2] = candy[2][j + 2] = -1; score += 500;
					candy[0][j+2] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[3][j] + candy[3][j + 1] + candy[3][j + 2] + candy[4][j + 2] + candy[5][j + 2] == 50)
				{
					candy[3][j] = candy[3][j + 1] = candy[3][j + 2] = candy[4][j + 2] = candy[5][j + 2] = -1; score += 500;
					candy[3][j+2] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[0][j] + candy[0][j + 1] + candy[0][j + 2] + candy[1][j + 2] + candy[2][j + 2] == 500)
				{
					candy[0][j] = candy[0][j + 1] = candy[0][j + 2] = candy[1][j + 2] = candy[2][j + 2] = -1; score += 500;
					candy[0][j+2] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[3][j] + candy[3][j + 1] + candy[3][j + 2] + candy[4][j + 2] + candy[5][j + 2] == 500)
				{
					candy[3][j] = candy[3][j + 1] = candy[3][j + 2] = candy[4][j + 2] = candy[5][j + 2] = -1; score += 500;
					candy[3][j+2] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[0][j] + candy[0][j + 1] + candy[0][j + 2] + candy[1][j + 2] + candy[2][j + 2] == 5000)
				{
					candy[0][j] = candy[0][j + 1] = candy[0][j + 2] = candy[1][j + 2] = candy[2][j + 2] = -1; score += 500;
					candy[0][j+2] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[3][j] + candy[3][j + 1] + candy[3][j + 2] + candy[4][j + 2] + candy[5][j + 2] == 5000)
				{
					candy[3][j] = candy[3][j + 1] = candy[3][j + 2] = candy[4][j + 2] = candy[5][j + 2] = -1; score += 500;
					candy[3][j+2] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[0][j] + candy[0][j + 1] + candy[0][j + 2] + candy[1][j + 2] + candy[2][j + 2] == 50000)
				{
					candy[0][j] = candy[0][j + 1] = candy[0][j + 2] = candy[1][j + 2] = candy[2][j + 2] = -1; score += 500;
					candy[0][j+2] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[3][j] + candy[3][j + 1] + candy[3][j + 2] + candy[4][j + 2] + candy[5][j + 2] == 50000)
				{
					candy[3][j] = candy[3][j + 1] = candy[3][j + 2] = candy[4][j + 2] = candy[5][j + 2] = -1; score += 500;
					candy[3][j+2] = 100000;
				}
			}
		//o x x
		//x
		//x
			for (int j = 0; j < 8; j++)
			{
				if (candy[0][j] + candy[0][j + 1] + candy[0][j + 2] + candy[1][j] + candy[2][j] == 5)
				{
					candy[0][j] = candy[0][j + 1] = candy[0][j + 2] = candy[1][j] = candy[2][j] = -1; score += 500;
					candy[0][j] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[3][j] + candy[3][j + 1] + candy[3][j + 2] + candy[4][j] + candy[5][j] == 5)
				{
					candy[3][j] = candy[3][j + 1] = candy[3][j + 2] = candy[4][j] = candy[5][j] = -1; score += 500;
					candy[3][j] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[0][j] + candy[0][j + 1] + candy[0][j + 2] + candy[1][j] + candy[2][j] == 50)
				{
					candy[0][j] = candy[0][j + 1] = candy[0][j + 2] = candy[1][j] = candy[2][j] = -1; score += 500;
					candy[0][j] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[3][j] + candy[3][j + 1] + candy[3][j + 2] + candy[4][j] + candy[5][j] == 50)
				{
					candy[3][j] = candy[3][j + 1] = candy[3][j + 2] = candy[4][j] = candy[5][j] = -1; score += 500;
					candy[3][j] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[0][j] + candy[0][j + 1] + candy[0][j + 2] + candy[1][j] + candy[2][j] == 500)
				{
					candy[0][j] = candy[0][j + 1] = candy[0][j + 2] = candy[1][j] = candy[2][j] = -1; score += 500;
					candy[0][j] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[3][j] + candy[3][j + 1] + candy[3][j + 2] + candy[4][j] + candy[5][j] == 500)
				{
					candy[3][j] = candy[3][j + 1] = candy[3][j + 2] = candy[4][j] = candy[5][j] = -1; score += 500;
					candy[3][j] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[0][j] + candy[0][j + 1] + candy[0][j + 2] + candy[1][j] + candy[2][j] == 5000)
				{
					candy[0][j] = candy[0][j + 1] = candy[0][j + 2] = candy[1][j] = candy[2][j] = -1; score += 500;
					candy[0][j] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[3][j] + candy[3][j + 1] + candy[3][j + 2] + candy[4][j] + candy[5][j] == 5000)
				{
					candy[3][j] = candy[3][j + 1] = candy[3][j + 2] = candy[4][j] = candy[5][j] = -1; score += 500;
					candy[3][j] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[0][j] + candy[0][j + 1] + candy[0][j + 2] + candy[1][j] + candy[2][j] == 50000)
				{
					candy[0][j] = candy[0][j + 1] = candy[0][j + 2] = candy[1][j] = candy[2][j] = -1; score += 500;
					candy[0][j] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[3][j] + candy[3][j + 1] + candy[3][j + 2] + candy[4][j] + candy[5][j] == 50000)
				{
					candy[3][j] = candy[3][j + 1] = candy[3][j + 2] = candy[4][j] = candy[5][j] = -1; score += 500;
					candy[3][j] = 100000;
				}
			}
		//     x
		// x x o
		//     x
			for (int j = 0; j < 8; j++)
			{
				if (candy[1][j] + candy[1][j + 1] + candy[1][j + 2] + candy[0][j+2] + candy[2][j+2] == 5)
				{
					candy[1][j] = candy[1][j + 1] = candy[1][j + 2] = candy[0][j+2] = candy[2][j+2] = -1; score += 500;
					candy[1][j + 2] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[4][j] + candy[4][j + 1] + candy[4][j + 2] + candy[3][j + 2] + candy[5][j + 2] == 5)
				{
					candy[4][j] = candy[4][j + 1] = candy[4][j + 2] = candy[3][j + 2] = candy[5][j + 2] = -1; score += 500;
					candy[4][j + 2] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[1][j] + candy[1][j + 1] + candy[1][j + 2] + candy[0][j + 2] + candy[2][j + 2] == 50)
				{
					candy[1][j] = candy[1][j + 1] = candy[1][j + 2] = candy[0][j + 2] = candy[2][j + 2] = -1; score += 500;
					candy[1][j + 2] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[4][j] + candy[4][j + 1] + candy[4][j + 2] + candy[3][j + 2] + candy[5][j + 2] == 50)
				{
					candy[4][j] = candy[4][j + 1] = candy[4][j + 2] = candy[3][j + 2] = candy[5][j + 2] = -1; score += 500;
					candy[4][j + 2] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[1][j] + candy[1][j + 1] + candy[1][j + 2] + candy[0][j + 2] + candy[2][j + 2] == 500)
				{
					candy[1][j] = candy[1][j + 1] = candy[1][j + 2] = candy[0][j + 2] = candy[2][j + 2] = -1; score += 500;
					candy[1][j + 2] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[4][j] + candy[4][j + 1] + candy[4][j + 2] + candy[3][j + 2] + candy[5][j + 2] == 500)
				{
					candy[4][j] = candy[4][j + 1] = candy[4][j + 2] = candy[3][j + 2] = candy[5][j + 2] = -1; score += 500;
					candy[4][j + 2] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[1][j] + candy[1][j + 1] + candy[1][j + 2] + candy[0][j + 2] + candy[2][j + 2] == 5000)
				{
					candy[1][j] = candy[1][j + 1] = candy[1][j + 2] = candy[0][j + 2] = candy[2][j + 2] = -1; score += 500;
					candy[1][j + 2] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[4][j] + candy[4][j + 1] + candy[4][j + 2] + candy[3][j + 2] + candy[5][j + 2] == 5000)
				{
					candy[4][j] = candy[4][j + 1] = candy[4][j + 2] = candy[3][j + 2] = candy[5][j + 2] = -1; score += 500;
					candy[4][j + 2] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[1][j] + candy[1][j + 1] + candy[1][j + 2] + candy[0][j + 2] + candy[2][j + 2] == 50000)
				{
					candy[1][j] = candy[1][j + 1] = candy[1][j + 2] = candy[0][j + 2] = candy[2][j + 2] = -1; score += 500;
					candy[1][j + 2] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[4][j] + candy[4][j + 1] + candy[4][j + 2] + candy[3][j + 2] + candy[5][j + 2] == 50000)
				{
					candy[4][j] = candy[4][j + 1] = candy[4][j + 2] = candy[3][j + 2] = candy[5][j + 2] = -1; score += 500;
					candy[4][j + 2] = 100000;
				}
			}
		//   x
		//   o x x
		//   x
		//
			for (int j = 0; j < 8; j++)
			{
				if (candy[1][j] + candy[1][j + 1] + candy[1][j + 2] + candy[0][j] + candy[2][j] == 5)
				{
					candy[1][j] = candy[1][j + 1] = candy[1][j + 2] = candy[0][j] = candy[2][j] = -1; score += 500;
					candy[1][j] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[4][j] + candy[4][j + 1] + candy[4][j + 2] + candy[3][j] + candy[5][j] == 5)
				{
					candy[4][j] = candy[4][j + 1] = candy[4][j + 2] = candy[3][j] = candy[5][j] = -1; score += 500;
					candy[4][j] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[1][j] + candy[1][j + 1] + candy[1][j + 2] + candy[0][j] + candy[2][j] == 50)
				{
					candy[1][j] = candy[1][j + 1] = candy[1][j + 2] = candy[0][j] = candy[2][j] = -1; score += 500;
					candy[1][j] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[4][j] + candy[4][j + 1] + candy[4][j + 2] + candy[3][j] + candy[5][j] == 50)
				{
					candy[4][j] = candy[4][j + 1] = candy[4][j + 2] = candy[3][j] = candy[5][j] = -1; score += 500;
					candy[4][j] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[1][j] + candy[1][j + 1] + candy[1][j + 2] + candy[0][j] + candy[2][j] == 500)
				{
					candy[1][j] = candy[1][j + 1] = candy[1][j + 2] = candy[0][j] = candy[2][j] = -1; score += 500;
					candy[1][j] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[4][j] + candy[4][j + 1] + candy[4][j + 2] + candy[3][j] + candy[5][j] == 500)
				{
					candy[4][j] = candy[4][j + 1] = candy[4][j + 2] = candy[3][j] = candy[5][j] = -1; score += 500;
					candy[4][j] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[1][j] + candy[1][j + 1] + candy[1][j + 2] + candy[0][j] + candy[2][j] == 5000)
				{
					candy[1][j] = candy[1][j + 1] = candy[1][j + 2] = candy[0][j] = candy[2][j] = -1; score += 500;
					candy[1][j] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[4][j] + candy[4][j + 1] + candy[4][j + 2] + candy[3][j] + candy[5][j] == 5000)
				{
					candy[4][j] = candy[4][j + 1] = candy[4][j + 2] = candy[3][j] = candy[5][j] = -1; score += 500;
					candy[4][j] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[1][j] + candy[1][j + 1] + candy[1][j + 2] + candy[0][j] + candy[2][j] == 50000)
				{
					candy[1][j] = candy[1][j + 1] = candy[1][j + 2] = candy[0][j] = candy[2][j] = -1; score += 500;
					candy[1][j] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[4][j] + candy[4][j + 1] + candy[4][j + 2] + candy[3][j] + candy[5][j] == 50000)
				{
					candy[4][j] = candy[4][j + 1] = candy[4][j + 2] = candy[3][j] = candy[5][j] = -1; score += 500;
					candy[4][j] = 100000;
				}
			}
		//x o x
		//  x
		//  x
			for (int j = 0; j < 8; j++)
			{
				if (candy[0][j] + candy[0][j + 1] + candy[0][j + 2] + candy[1][j+1] + candy[2][j+1] == 5)
				{
					candy[0][j] = candy[0][j + 1] = candy[0][j + 2] = candy[1][j+1] = candy[2][j+1] = -1; score += 500;
					candy[0][j+1] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[3][j] + candy[3][j + 1] + candy[3][j + 2] + candy[4][j + 1] + candy[5][j + 1] == 5)
				{
					candy[3][j] = candy[3][j + 1] = candy[3][j + 2] = candy[4][j + 1] = candy[5][j + 1] = -1; score += 500;
					candy[3][j + 1] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[0][j] + candy[0][j + 1] + candy[0][j + 2] + candy[1][j + 1] + candy[2][j + 1] == 50)
				{
					candy[0][j] = candy[0][j + 1] = candy[0][j + 2] = candy[1][j + 1] = candy[2][j + 1] = -1; score += 500;
					candy[0][j + 1] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[3][j] + candy[3][j + 1] + candy[3][j + 2] + candy[4][j + 1] + candy[5][j + 1] == 50)
				{
					candy[3][j] = candy[3][j + 1] = candy[3][j + 2] = candy[4][j + 1] = candy[5][j + 1] = -1; score += 500;
					candy[3][j + 1] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[0][j] + candy[0][j + 1] + candy[0][j + 2] + candy[1][j + 1] + candy[2][j + 1] == 500)
				{
					candy[0][j] = candy[0][j + 1] = candy[0][j + 2] = candy[1][j + 1] = candy[2][j + 1] = -1; score += 500;
					candy[0][j + 1] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[3][j] + candy[3][j + 1] + candy[3][j + 2] + candy[4][j + 1] + candy[5][j + 1] == 500)
				{
					candy[3][j] = candy[3][j + 1] = candy[3][j + 2] = candy[4][j + 1] = candy[5][j + 1] = -1; score += 500;
					candy[3][j + 1] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[0][j] + candy[0][j + 1] + candy[0][j + 2] + candy[1][j + 1] + candy[2][j + 1] == 5000)
				{
					candy[0][j] = candy[0][j + 1] = candy[0][j + 2] = candy[1][j + 1] = candy[2][j + 1] = -1; score += 500;
					candy[0][j + 1] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[3][j] + candy[3][j + 1] + candy[3][j + 2] + candy[4][j + 1] + candy[5][j + 1] == 5000)
				{
					candy[3][j] = candy[3][j + 1] = candy[3][j + 2] = candy[4][j + 1] = candy[5][j + 1] = -1; score += 500;
					candy[3][j + 1] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[0][j] + candy[0][j + 1] + candy[0][j + 2] + candy[1][j + 1] + candy[2][j + 1] == 50000)
				{
					candy[0][j] = candy[0][j + 1] = candy[0][j + 2] = candy[1][j + 1] = candy[2][j + 1] = -1; score += 500;
					candy[0][j + 1] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[3][j] + candy[3][j + 1] + candy[3][j + 2] + candy[4][j + 1] + candy[5][j + 1] == 50000)
				{
					candy[3][j] = candy[3][j + 1] = candy[3][j + 2] = candy[4][j + 1] = candy[5][j + 1] = -1; score += 500;
					candy[3][j + 1] = 100000;
				}
			}
		//  x
		//  x
		//x o x
			for (int j = 0; j < 8; j++)
			{
				if (candy[2][j] + candy[2][j + 1] + candy[2][j + 2] + candy[1][j + 1] + candy[0][j + 1] == 5)
				{
					candy[2][j] = candy[2][j + 1] = candy[2][j + 2] = candy[1][j + 1] = candy[0][j + 1] = -1; score += 500;
					candy[2][j + 1] = 100000;
				}
			}
			for (int j = 0; j < 8; j++)
			{
				if (candy[5][j] + candy[5][j + 1] + candy[5][j + 2] + candy[4][j + 1] + candy[3][j + 1] == 5)
				{
					candy[5][j] = candy[5][j + 1] = candy[5][j + 2] = candy[4][j + 1] = candy[3][j + 1] = -1; score += 500;
					candy[5][j + 1] = 100000;
				}
			}

		//------------------------------------------------------橫的-------------------------------------------//


		//A 0~2
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 8; j++)
			{



				if (j + 3 <= 3)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] + candy[i][j + 9] == 10) //10個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = candy[i][j + 8] = candy[i][j + 9] = -1;
						candy[i][j] = 100000;
						score += 1000;
					}
				}
				if (j + 3 <= 4)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] == 9) //九個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = candy[i][j + 8] = -1;

						score += 900;
					}
				}
				if (j + 3 <= 5)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] == 8) //八個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = -1;

						score += 800;
					}
				}
				if (j + 3 <= 6)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] == 7) //七個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = -1;

						score += 700;
					}
				}
				if (j + 3 <= 7)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] == 6) //六個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = -1;

						score += 600;
					}
				}
				if (j + 3 <= 8)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] == 5) //五個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = -1;
						candy[i][j] = 100000;
						score += 500;

					}
				}
				if (j + 3 <= 9)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] == 4) //四個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = -1;
						score += 400;

					}
				}
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] == 3)//三個
				{

					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = -1;

					score += 300;

				}
			}
		}
		//A 3~5
		for (int i = 3; i < 6; i++)
		{
			for (int j = 0; j < 8; j++)
			{



				if (j + 3 <= 3)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] + candy[i][j + 9] == 10) //10個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = candy[i][j + 8] = candy[i][j + 9] = -1;
						candy[i][j] = 100000;
						score += 1000;
					}
				}
				if (j + 3 <= 4)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] == 9) //九個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = candy[i][j + 8] = -1;

						score += 900;
					}
				}
				if (j + 3 <= 5)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] == 8) //八個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = -1;

						score += 800;
					}
				}
				if (j + 3 <= 6)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] == 7) //七個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = -1;

						score += 700;
					}
				}
				if (j + 3 <= 7)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] == 6) //六個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = -1;

						score += 600;
					}
				}
				if (j + 3 <= 8)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] == 5) //五個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = -1;
						candy[i][j] = 100000;
						score += 500;

					}
				}
				if (j + 3 <= 9)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] == 4) //四個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = -1;
						score += 400;

					}
				}
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] == 3)//三個
				{

					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = -1;

					score += 300;

				}
			}
		}
		//B
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 8; j++)
			{



				if (j + 3 <= 3)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] + candy[i][j + 9] == 100) //10個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = candy[i][j + 8] = candy[i][j + 9] = -1;
						score += 1000;

					}
				}
				if (j + 3 <= 4)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] == 90) //九個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = candy[i][j + 8] = -1;

						score += 900;
					}
				}
				if (j + 3 <= 5)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] == 80) //八個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = -1;
						score += 800;

					}
				}
				if (j + 3 <= 6)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] == 70) //七個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = -1;

						score += 700;
					}
				}
				if (j + 3 <= 7)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] == 60) //六個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = -1;

						score += 600;
					}
				}
				if (j + 3 <= 8)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] == 50) //五個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = -1;
						candy[i][j] = 100000;
						score += 500;
					}
				}
				if (j + 3 <= 9)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] == 40) //四個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = -1;

						score += 400;
					}
				}
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] == 30)//三個
				{

					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = -1;

					score += 300;

				}
			}
		}
		//B 3~5
		for (int i = 3; i < 6; i++)
		{
			for (int j = 0; j < 8; j++)
			{



				if (j + 3 <= 3)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] + candy[i][j + 9] == 100) //10個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = candy[i][j + 8] = candy[i][j + 9] = -1;
						score += 1000;

					}
				}
				if (j + 3 <= 4)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] == 90) //九個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = candy[i][j + 8] = -1;

						score += 900;
					}
				}
				if (j + 3 <= 5)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] == 80) //八個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = -1;
						score += 800;

					}
				}
				if (j + 3 <= 6)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] == 70) //七個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = -1;

						score += 700;
					}
				}
				if (j + 3 <= 7)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] == 60) //六個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = -1;

						score += 600;
					}
				}
				if (j + 3 <= 8)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] == 50) //五個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = -1;
						candy[i][j] = 100000;
						score += 500;
					}
				}
				if (j + 3 <= 9)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] == 40) //四個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = -1;

						score += 400;
					}
				}
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] == 30)//三個
				{

					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = -1;

					score += 300;

				}
			}
		}
		//c
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 8; j++)
			{



				if (j + 3 <= 3)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] + candy[i][j + 9] == 1000) //九個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = candy[i][j + 8] = candy[i][j + 9] = -1;
						score += 1000;

					}
				}
				if (j + 3 <= 4)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] == 900) //九個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = candy[i][j + 8] = -1;
						score += 900;

					}
				}
				if (j + 3 <= 5)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] == 800) //八個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = -1;

						score += 800;
					}
				}
				if (j + 3 <= 6)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] == 700) //七個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = -1;

						score += 700;
					}
				}
				if (j + 3 <= 7)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] == 600) //六個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = -1;
						score += 600;

					}
				}
				if (j + 3 <= 8)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] == 500) //五個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = -1;
						candy[i][j] = 100000;
						score += 500;
					}
				}
				if (j + 3 <= 9)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] == 400) //四個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = -1;
						score += 400;

					}
				}
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] == 300)//三個
				{

					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = -1;


					score += 300;
				}
			}
		}

		//c 3~5
		for (int i = 3; i < 6; i++)
		{
			for (int j = 0; j < 8; j++)
			{



				if (j + 3 <= 3)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] + candy[i][j + 9] == 1000) //九個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = candy[i][j + 8] = candy[i][j + 9] = -1;
						score += 1000;

					}
				}
				if (j + 3 <= 4)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] == 900) //九個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = candy[i][j + 8] = -1;
						score += 900;

					}
				}
				if (j + 3 <= 5)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] == 800) //八個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = -1;

						score += 800;
					}
				}
				if (j + 3 <= 6)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] == 700) //七個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = -1;

						score += 700;
					}
				}
				if (j + 3 <= 7)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] == 600) //六個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = -1;
						score += 600;

					}
				}
				if (j + 3 <= 8)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] == 500) //五個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = -1;
						candy[i][j] = 100000;
						score += 500;
					}
				}
				if (j + 3 <= 9)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] == 400) //四個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = -1;
						score += 400;

					}
				}
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] == 300)//三個
				{

					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = -1;


					score += 300;
				}
			}
		}
		//D
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 8; j++)
			{



				if (j + 3 <= 3)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] + candy[i][j + 9] == 10000) //九個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = candy[i][j + 8] = candy[i][j + 9] = -1;

						score += 1000;
					}
				}
				if (j + 3 <= 4)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] == 9000) //九個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = candy[i][j + 8] = -1;

						score += 900;
					}
				}
				if (j + 3 <= 5)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] == 8000) //八個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = -1;
						score += 800;

					}
				}
				if (j + 3 <= 6)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] == 7000) //七個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = -1;

						score += 700;
					}
				}
				if (j + 3 <= 7)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] == 6000) //六個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = -1;

						score += 600;
					}
				}
				if (j + 3 <= 8)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] == 5000) //五個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = -1;
						candy[i][j] = 100000;
						score += 500;
					}
				}
				if (j + 3 <= 9)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] == 4000) //四個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = -1;
						score += 400;

					}
				}
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] == 3000)//三個
				{

					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = -1;

					score += 300;

				}
			}
		}
		//D 3~5
		for (int i = 3; i < 6; i++)
		{
			for (int j = 0; j < 8; j++)
			{



				if (j + 3 <= 3)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] + candy[i][j + 9] == 10000) //九個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = candy[i][j + 8] = candy[i][j + 9] = -1;

						score += 1000;
					}
				}
				if (j + 3 <= 4)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] == 9000) //九個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = candy[i][j + 8] = -1;

						score += 900;
					}
				}
				if (j + 3 <= 5)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] == 8000) //八個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = -1;
						score += 800;

					}
				}
				if (j + 3 <= 6)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] == 7000) //七個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = -1;

						score += 700;
					}
				}
				if (j + 3 <= 7)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] == 6000) //六個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = -1;

						score += 600;
					}
				}
				if (j + 3 <= 8)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] == 5000) //五個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = -1;
						candy[i][j] = 100000;
						score += 500;
					}
				}
				if (j + 3 <= 9)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] == 4000) //四個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = -1;
						score += 400;

					}
				}
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] == 3000)//三個
				{

					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = -1;

					score += 300;

				}
			}
		}
		//E
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 8; j++)
			{



				if (j + 3 <= 3)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] + candy[i][j + 9] == 100000) //九個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = candy[i][j + 8] = candy[i][j + 9] = -1;

						score += 1000;
					}
				}
				if (j + 3 <= 4)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] == 90000) //九個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = candy[i][j + 8] = -1;
						score += 900;

					}
				}
				if (j + 3 <= 5)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] == 80000) //八個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = -1;

						score += 800;
					}
				}
				if (j + 3 <= 6)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] == 70000) //七個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = -1;

						score += 700;
					}
				}
				if (j + 3 <= 7)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] == 60000) //六個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = -1;
						score += 600;

					}
				}
				if (j + 3 <= 8)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] == 50000) //五個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = -1;
						candy[i][j] = 100000;
						score += 500;
					}
				}
				if (j + 3 <= 9)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] == 40000) //四個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = -1;
						score += 400;

					}
				}
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] == 30000)//三個
				{

					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = -1;

					score += 300;

				}
			}
		}


		//E 3~5
		for (int i = 3; i < 6; i++)
		{
			for (int j = 0; j < 8; j++)
			{



				if (j + 3 <= 3)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] + candy[i][j + 9] == 100000) //九個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = candy[i][j + 8] = candy[i][j + 9] = -1;

						score += 1000;
					}
				}
				if (j + 3 <= 4)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] + candy[i][j + 8] == 90000) //九個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = candy[i][j + 8] = -1;
						score += 900;

					}
				}
				if (j + 3 <= 5)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] + candy[i][j + 7] == 80000) //八個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = candy[i][j + 7] = -1;

						score += 800;
					}
				}
				if (j + 3 <= 6)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] + candy[i][j + 6] == 70000) //七個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = candy[i][j + 6] = -1;

						score += 700;
					}
				}
				if (j + 3 <= 7)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] + candy[i][j + 5] == 60000) //六個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = candy[i][j + 5] = -1;
						score += 600;

					}
				}
				if (j + 3 <= 8)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] + candy[i][j + 4] == 50000) //五個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = candy[i][j + 4] = -1;
						candy[i][j] = 100000;
						score += 500;
					}
				}
				if (j + 3 <= 9)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] + candy[i][j + 3] == 40000) //四個
					{

						candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = candy[i][j + 3] = -1;
						score += 400;

					}
				}
				if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] == 30000)//三個
				{

					candy[i][j] = candy[i][j + 1] = candy[i][j + 2] = -1;

					score += 300;

				}
			}
		}
		//------------------------------------------直的--------------------------------------------------
		//A
	
		
		
		//直的 三個
		for (int i = 0; i < 1; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] == 3)
				{

					candy[i][j] = candy[i + 1][j] = candy[i + 2][j] = -1;



					score += 300;


				}

			}
		}
		for (int i = 3; i < 4; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] == 3)
				{

					candy[i][j] = candy[i + 1][j] = candy[i + 2][j] = -1;



					score += 300;


				}

			}
		}
		//B
		
		//直的 三個
		for (int i = 0; i < 1; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] == 30)
				{

					candy[i][j] = candy[i + 1][j] = candy[i + 2][j] = -1;



					score += 300;


				}

			}
		}
		//直的 三個
		for (int i = 3; i < 4; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] == 30)
				{

					candy[i][j] = candy[i + 1][j] = candy[i + 2][j] = -1;



					score += 300;


				}

			}
		}
		//C
		
		
		//直的 三個
		for (int i = 0; i < 1; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] == 300)
				{

					candy[i][j] = candy[i + 1][j] = candy[i + 2][j] = -1;



					score += 300;


				}

			}
		}
		//C


		//直的 三個
		for (int i = 3; i < 4; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] == 300)
				{

					candy[i][j] = candy[i + 1][j] = candy[i + 2][j] = -1;



					score += 300;


				}

			}
		}
		//D
		
		//直的 三個
		for (int i = 0; i < 1; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] == 3000)
				{

					candy[i][j] = candy[i + 1][j] = candy[i + 2][j] = -1;


					score += 300;



				}

			}
		}
		//D

		//直的 三個
		for (int i = 3; i < 4; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] == 3000)
				{

					candy[i][j] = candy[i + 1][j] = candy[i + 2][j] = -1;


					score += 300;



				}

			}
		}
		//E
		
		//直的 三個
		for (int i = 0; i < 1; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] == 30000) 
				{

					candy[i][j] = candy[i + 1][j] = candy[i + 2][j] = -1;


					score += 300;



				}

			}
		}
		for (int i = 3; i < 4; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] == 30000)
				{

					candy[i][j] = candy[i + 1][j] = candy[i + 2][j] = -1;


					score += 300;



				}

			}
		}

	}
	void skyfall()//天降
	{

		for (int i = 0; i <6; i++)
		{

			for (int j = 0; j < 10; j++) {

				if (candy[i][j] == -1 && i - 1 >= 0)
				{
					while (i > 0)//天降
					{
						candy[i][j] = candy[i - 1][j];

						i--;
					}
					candy[0][j] = -1;

				}
				if (candy[0][j] == -1) {
					int temp = (rand() % 5) + 1;
					switch (temp)
					{

					case 1:
						candy[0][j] = 1;
						break;
					case 2:
						candy[0][j] = 10;	break;
					case 3:
						candy[0][j] = 100;	break;
					case 4:
						candy[0][j] = 1000;	break;
					case 5:
						candy[0][j] = 10000;	break;

					}

				}
			}
		}







	}







	bool fuckyet = 0;
	int go_on = 1;
	int preX;
	int preY;
	int nextX;
	int nextY;
	void lets_play_a_game()//play   
	{
		clear();
		refresh();
		setempty();
		skyfall();
		setempty();
		skyfall();
		setempty();
		skyfall();
		setempty();
		skyfall();
		setempty();
		skyfall();
		outputfruit();
		score = 0;
		while (go_on)
		{
			mvaddstr(1, 30, "target scores : ");
			mvprintw(1, 50, "%d", target);
			mvaddstr(2, 30, "your scores : ");
			mvprintw(2, 50, "%d", score);
			mvaddstr(0, 30, "remaining steps : ");
			mvprintw(0, 50, "%d", remainsteps);

			if (remainsteps == 0 && score < target)
			{
				attrset(A_REVERSE);//set background
				start_color();
				init_pair(6, COLOR_CYAN, COLOR_RED);
				attrset(COLOR_PAIR(6));
				mvaddstr(8, 2, "Out of move");
				int gameover; gameover = getch(); go_on = false; break;

			}
			for (int i = 0; i < 6; i++)//special bomb 如果三個連在一起，就炸掉全部，直接獲勝(橫的)
			{
				for (int j = 0; j < 8; j++)
				{
					if (candy[i][j] + candy[i][j + 1] + candy[i][j + 2] == 300000)
					{


						score = target;
						clear();
						refresh();
						mvaddstr(6, 2, "You eliminate special bomb!!!!!");
						mvaddstr(1, 30, "target scores : ");
						mvprintw(1, 50, "%d", target);
						mvaddstr(2, 30, "your scores : ");
						mvprintw(2, 50, "%d", score);
						mvaddstr(0, 30, "remaining steps : ");
						mvprintw(0, 50, "%d", remainsteps);

					}
				}
			}
			for (int i = 0; i < 4; i++)//special bomb 如果三個連在一起，就炸掉全部，直接獲勝(直的)
			{
				for (int j = 0; j < 10; j++)
				{

					if (candy[i][j] + candy[i + 1][j] + candy[i + 2][j] == 300000)
					{


						score = target;
						clear();
						refresh();
						mvaddstr(6, 2, "You eliminate special bomb!!!!!");
						mvaddstr(1, 30, "target scores : ");
						mvprintw(1, 50, "%d", target);
						mvaddstr(2, 30, "your scores : ");
						mvprintw(2, 50, "%d", score);
						mvaddstr(0, 30, "remaining steps : ");
						mvprintw(0, 50, "%d", remainsteps);



					}

				}
			}
			if (score >= target)
			{
				attrset(A_REVERSE);//set background
				start_color();
				init_pair(7, COLOR_CYAN, COLOR_BLUE);
				attrset(COLOR_PAIR(7));
				mvaddstr(8, 2, "You Win!!!!!");
				int win; win = getch(); go_on = false; break;

			}
			//	attrset(A_UNDERLINE);
			mvaddstr(0, 15, "Normal LEVEL");
			mvaddstr(4, 30, "wanna quit game?press q");
			mvaddstr(5, 30, "Manual:");
			mvaddstr(6, 30, "press s to select and press t to choose places");

			cbreak(); // disable key buffering
			noecho(); // disable echoing
			keypad(stdscr, TRUE); // enable keypad reading
			getmaxyx(stdscr, height, width); // get screen size
			go_on = TRUE;
			move(y, x);

			int c;
			c = getch();
			switch (c) {
				//quit
			case 'q':mvaddstr(27, 1, "you already quit the game,press any key to leave");  go_on = false; break;
			case 's'://select
				attrset(A_REVERSE);//set background
				if (y > 3)
				{
					preX = x;
					preY = y-1;
				}
				else {
					preX = x;
					preY = y;
				}
				break;
			case 't':
			{
				if (y > 3)
				{
					nextX = x;
					nextY = y - 1;
				}
				else
				{
					nextX = x;
					nextY = y;
				}
				swap(candy[preY][preX], candy[nextY][nextX]);
				if (swapable()) {

					remainsteps--;
					fuckyet = 1;
				}
				else //不能交換

				{
					swap(candy[preY][preX], candy[nextY][nextX]);//換回來
					
					fuckyet = 1;
					attrset(A_REVERSE);//set background
					attrset(COLOR_PAIR(6));
					mvaddstr(12, 1, "invalid move! "); int fuck; fuck = getch();
				}



				break;
			}
			case KEY_LEFT: --x; mvaddstr(10, 54, "Left "); break;
			case KEY_RIGHT: ++x; mvaddstr(10, 54, "Right"); break;
			case KEY_UP: --y; mvaddstr(10, 54, "Uppp "); break;
			case KEY_DOWN: ++y; mvaddstr(10, 54, "Down "); break;
			} // switch (c)

			while (x < 0) x += width;
			while (x >= width) x -= width;
			while (y < 0) y += height;
			while (y >= height) y -= height;
			refresh();
			// while (go_on)




			clear();
			refresh();
			setempty();
			outputfruit();
			if (fuckyet)
			{
				int fuck = getch();
				usleep(100000);
			}
			skyfall();
			setempty();
			skyfall();
			setempty();
			skyfall();
			setempty();
			skyfall();
			setempty();
			skyfall();
			setempty();
			skyfall();
			setempty();
			skyfall();
			setempty();
			skyfall();
			setempty();
			skyfall();
			setempty();
			skyfall();
			setempty();
			skyfall();
			setempty();
			skyfall();
			setempty();
			outputfruit();
			fuckyet = 0;
		}

	}


	void swap(int & x, int & x2)
	{
		int tmp = x;
		x = x2;
		x2 = tmp;
	}







};
int main()
{
	

	srand(time(0));
	initscr();
	clear();
	refresh();
	attrset(A_BOLD);
	restart:
	mvaddstr(0, 0, "welcome to Candy Crush");
	mvaddstr(1, 0, "please choose 1. easy or 2.normal 3.crazy" );//讓玩家選擇難度
	int c;
	c = getch();
	clear();
	refresh();
	easy Easy;
	Normal normal;
	

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

		}
		clear();
		refresh();
		mvaddstr(0, 0, "welcome to Candy Crush");
		mvaddstr(1, 0, "please choose 1. easy or 2.normal 3.crazy");//讓玩家選擇難度
		goto restart;
	endwin();
	cout << "End Game";


}



