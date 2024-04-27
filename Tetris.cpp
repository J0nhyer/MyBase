#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <conio.h>
using namespace std;
const int nFieldWidth = 18;
const int nFieldHeight = 24;
const int LeftDistance = 4;
const int TopDistance = 4;
const int DeadLine = TopDistance + 1;
int status, typecraft, TopMoving, LeftMoving, RemoveLine, Score;
bool MySignal;
char Field[TopDistance + nFieldHeight][LeftDistance + nFieldWidth];
char DynamicField[TopDistance + nFieldHeight + 10][LeftDistance + nFieldWidth + 10];


struct Craft
{
	int x;
	int y;
};

Craft mCraft[7][4][4];

void CreateCraft()
{
	mCraft[0][0][0].x = 3;
	mCraft[0][0][0].y = 1;
	mCraft[0][0][1].x = 3;
	mCraft[0][0][1].y = 2;
	mCraft[0][0][2].x = 3;
	mCraft[0][0][2].y = 3;
	mCraft[0][0][3].x = 3;
	mCraft[0][0][3].y = 4;

	mCraft[0][1][0].x = 1;
	mCraft[0][1][0].y = 3;
	mCraft[0][1][1].x = 2;
	mCraft[0][1][1].y = 3;
	mCraft[0][1][2].x = 3;
	mCraft[0][1][2].y = 3;
	mCraft[0][1][3].x = 4;
	mCraft[0][1][3].y = 3;

	mCraft[0][2][0].x = 2;
	mCraft[0][2][0].y = 1;
	mCraft[0][2][1].x = 2;
	mCraft[0][2][1].y = 2;
	mCraft[0][2][2].x = 2;
	mCraft[0][2][2].y = 3;
	mCraft[0][2][3].x = 2;
	mCraft[0][2][3].y = 4;

	mCraft[0][3][0].x = 1;
	mCraft[0][3][0].y = 2;
	mCraft[0][3][1].x = 2;
	mCraft[0][3][1].y = 2;
	mCraft[0][3][2].x = 3;
	mCraft[0][3][2].y = 2;
	mCraft[0][3][3].x = 4;
	mCraft[0][3][3].y = 2;

	mCraft[1][0][0].x = 3;
	mCraft[1][0][0].y = 1;
	mCraft[1][0][1].x = 2;
	mCraft[1][0][1].y = 2;
	mCraft[1][0][2].x = 3;
	mCraft[1][0][2].y = 2;
	mCraft[1][0][3].x = 2;
	mCraft[1][0][3].y = 3;

	mCraft[1][1][0].x = 4;
	mCraft[1][1][0].y = 3;
	mCraft[1][1][1].x = 3;
	mCraft[1][1][1].y = 2;
	mCraft[1][1][2].x = 3;
	mCraft[1][1][2].y = 3;
	mCraft[1][1][3].x = 2;
	mCraft[1][1][3].y = 2;

	mCraft[1][2][0].x = 3;
	mCraft[1][2][0].y = 2;
	mCraft[1][2][1].x = 2;
	mCraft[1][2][1].y = 3;
	mCraft[1][2][2].x = 3;
	mCraft[1][2][2].y = 3;
	mCraft[1][2][3].x = 2;
	mCraft[1][2][3].y = 4;

	mCraft[1][3][0].x = 1;
	mCraft[1][3][0].y = 3;
	mCraft[1][3][1].x = 2;
	mCraft[1][3][1].y = 2;
	mCraft[1][3][2].x = 2;
	mCraft[1][3][2].y = 3;
	mCraft[1][3][3].x = 3;
	mCraft[1][3][3].y = 2;

	mCraft[2][0][0].x = 2;
	mCraft[2][0][0].y = 1;
	mCraft[2][0][1].x = 2;
	mCraft[2][0][1].y = 2;
	mCraft[2][0][2].x = 3;
	mCraft[2][0][2].y = 2;
	mCraft[2][0][3].x = 3;
	mCraft[2][0][3].y = 3;

	mCraft[2][1][0].x = 4;
	mCraft[2][1][0].y = 2;
	mCraft[2][1][1].x = 3;
	mCraft[2][1][1].y = 2;
	mCraft[2][1][2].x = 3;
	mCraft[2][1][2].y = 3;
	mCraft[2][1][3].x = 2;
	mCraft[2][1][3].y = 3;

	mCraft[2][2][0].x = 2;
	mCraft[2][2][0].y = 2;
	mCraft[2][2][1].x = 2;
	mCraft[2][2][1].y = 3;
	mCraft[2][2][2].x = 3;
	mCraft[2][2][2].y = 3;
	mCraft[2][2][3].x = 3;
	mCraft[2][2][3].y = 4;

	mCraft[2][3][0].x = 1;
	mCraft[2][3][0].y = 3;
	mCraft[2][3][1].x = 2;
	mCraft[2][3][1].y = 2;
	mCraft[2][3][2].x = 2;
	mCraft[2][3][2].y = 3;
	mCraft[2][3][3].x = 3;
	mCraft[2][3][3].y = 2;

	mCraft[3][0][0].x = 2;
	mCraft[3][0][0].y = 2;
	mCraft[3][0][1].x = 2;
	mCraft[3][0][1].y = 3;
	mCraft[3][0][2].x = 3;
	mCraft[3][0][2].y = 2;
	mCraft[3][0][3].x = 3;
	mCraft[3][0][3].y = 3;

	mCraft[3][1][0].x = 2;
	mCraft[3][1][0].y = 2;
	mCraft[3][1][1].x = 2;
	mCraft[3][1][1].y = 3;
	mCraft[3][1][2].x = 3;
	mCraft[3][1][2].y = 2;
	mCraft[3][1][3].x = 3;
	mCraft[3][1][3].y = 3;

	mCraft[3][2][0].x = 2;
	mCraft[3][2][0].y = 2;
	mCraft[3][2][1].x = 2;
	mCraft[3][2][1].y = 3;
	mCraft[3][2][2].x = 3;
	mCraft[3][2][2].y = 2;
	mCraft[3][2][3].x = 3;
	mCraft[3][2][3].y = 3;

	mCraft[3][3][0].x = 2;
	mCraft[3][3][0].y = 2;
	mCraft[3][3][1].x = 2;
	mCraft[3][3][1].y = 3;
	mCraft[3][3][2].x = 3;
	mCraft[3][3][2].y = 2;
	mCraft[3][3][3].x = 3;
	mCraft[3][3][3].y = 3;

	mCraft[4][0][0].x = 3;
	mCraft[4][0][0].y = 1;
	mCraft[4][0][1].x = 3;
	mCraft[4][0][1].y = 2;
	mCraft[4][0][2].x = 3;
	mCraft[4][0][2].y = 3;
	mCraft[4][0][3].x = 2;
	mCraft[4][0][3].y = 2;

	mCraft[4][1][0].x = 4;
	mCraft[4][1][0].y = 3;
	mCraft[4][1][1].x = 3;
	mCraft[4][1][1].y = 2;
	mCraft[4][1][2].x = 3;
	mCraft[4][1][2].y = 3;
	mCraft[4][1][3].x = 2;
	mCraft[4][1][3].y = 3;

	mCraft[4][2][0].x = 2;
	mCraft[4][2][0].y = 2;
	mCraft[4][2][1].x = 2;
	mCraft[4][2][1].y = 3;
	mCraft[4][2][2].x = 2;
	mCraft[4][2][2].y = 4;
	mCraft[4][2][3].x = 3;
	mCraft[4][2][3].y = 3;

	mCraft[4][3][0].x = 1;
	mCraft[4][3][0].y = 2;
	mCraft[4][3][1].x = 2;
	mCraft[4][3][1].y = 2;
	mCraft[4][3][2].x = 2;
	mCraft[4][3][2].y = 3;
	mCraft[4][3][3].x = 3;
	mCraft[4][3][3].y = 2;

	mCraft[5][0][0].x = 2;
	mCraft[5][0][0].y = 2;
	mCraft[5][0][1].x = 3;
	mCraft[5][0][1].y = 2;
	mCraft[5][0][2].x = 3;
	mCraft[5][0][2].y = 3;
	mCraft[5][0][3].x = 3;
	mCraft[5][0][3].y = 4;

	mCraft[5][1][0].x = 3;
	mCraft[5][1][0].y = 2;
	mCraft[5][1][1].x = 3;
	mCraft[5][1][1].y = 3;
	mCraft[5][1][2].x = 2;
	mCraft[5][1][2].y = 3;
	mCraft[5][1][3].x = 1;
	mCraft[5][1][3].y = 3;

	mCraft[5][2][0].x = 2;
	mCraft[5][2][0].y = 1;
	mCraft[5][2][1].x = 2;
	mCraft[5][2][1].y = 2;
	mCraft[5][2][2].x = 2;
	mCraft[5][2][2].y = 3;
	mCraft[5][2][3].x = 3;
	mCraft[5][2][3].y = 3;

	mCraft[5][3][0].x = 2;
	mCraft[5][3][0].y = 2;
	mCraft[5][3][1].x = 2;
	mCraft[5][3][1].y = 3;
	mCraft[5][3][2].x = 3;
	mCraft[5][3][2].y = 2;
	mCraft[5][3][3].x = 4;
	mCraft[5][3][3].y = 2;

	mCraft[6][0][0].x = 2;
	mCraft[6][0][0].y = 2;
	mCraft[6][0][1].x = 3;
	mCraft[6][0][1].y = 2;
	mCraft[6][0][2].x = 2;
	mCraft[6][0][2].y = 3;
	mCraft[6][0][3].x = 2;
	mCraft[6][0][3].y = 4;

	mCraft[6][1][0].x = 1;
	mCraft[6][1][0].y = 2;
	mCraft[6][1][1].x = 2;
	mCraft[6][1][1].y = 2;
	mCraft[6][1][2].x = 3;
	mCraft[6][1][2].y = 2;
	mCraft[6][1][3].x = 3;
	mCraft[6][1][3].y = 3;

	mCraft[6][2][0].x = 3;
	mCraft[6][2][0].y = 1;
	mCraft[6][2][1].x = 3;
	mCraft[6][2][1].y = 2;
	mCraft[6][2][2].x = 3;
	mCraft[6][2][2].y = 3;
	mCraft[6][2][3].x = 2;
	mCraft[6][2][3].y = 3;

	mCraft[6][3][0].x = 2;
	mCraft[6][3][0].y = 2;
	mCraft[6][3][1].x = 2;
	mCraft[6][3][1].y = 3;
	mCraft[6][3][2].x = 3;
	mCraft[6][3][2].y = 3;
	mCraft[6][3][3].x = 4;
	mCraft[6][3][3].y = 3;
}

void ShowMenu()
{
	cout << "***********************************" << endl;
	cout << "***********************************" << endl;
	cout << "***********************************" << endl;
	cout << "*********   1、开始游戏   *********" << endl;
	cout << "*********   0、退出游戏   *********" << endl;
	cout << "***********************************" << endl;
	cout << "***********************************" << endl;
	cout << "***********************************" << endl;
}

void ShowFrame()
{
	system("cls");
	for (int i = 0; i <= TopDistance + nFieldHeight - 1; i++)
	{
		for (int j = 0; j <= LeftDistance + nFieldWidth - 1; j++)
		{
			cout << Field[i][j];
		}
		cout << endl;
	}
	cout << endl;
	cout << "      SCORE: " << Score;
}

void GameFrame()
{
	for (int i = 0; i <= TopDistance + nFieldHeight - 1; i++)
	{
		for (int j = 0; j <= LeftDistance + nFieldWidth - 1; j++)
		{
			if ((j == LeftDistance && i >= TopDistance) || (j == LeftDistance + nFieldWidth - 1 && i >= TopDistance) || (i == TopDistance + nFieldHeight - 1 && j >= LeftDistance))
			{
				Field[i][j] = '#';
			}
			else
			{
				Field[i][j] = ' ';
			}
		}
	}
	ShowFrame();
}

int ProduceCraft(Craft* MyCraft)
{
	Sleep(1000);
	srand(unsigned(time(NULL)));
	int r = rand() % 7;	
	for (int i = 0; i < 4; i++)
	{

		MyCraft[i].x = mCraft[r][0][i].x + LeftDistance + nFieldWidth / 2 - 3;
		MyCraft[i].y = mCraft[r][0][i].y + TopDistance - 2;
		Field[MyCraft[i].y][MyCraft[i].x] = 'X';
	}
	ShowFrame();
	return r;
}

bool IsCrash(Craft* MyCraft, Craft* NextCraft)
{
	for (int i = 0; i < 4; i++)
	{
		MySignal = true;
		if (Field[NextCraft[i].y][NextCraft[i].x] == '#' )
		{
			return true;
		}
		else if (Field[NextCraft[i].y][NextCraft[i].x] == 'X')
		{
			for (int j = 0; j < 4; j++)
			{
				if (NextCraft[i].y == MyCraft[j].y && NextCraft[i].x == MyCraft[j].x)
				{
					MySignal = false;
					break;
				}
			}
			if (MySignal)
			{
				return true;
			}
		}
	}
	return false;
}

void LeftMove(Craft* MyCraft, Craft* NextCraft)
{
	for (int i = 0; i < 4; i++)
	{
		NextCraft[i].x = MyCraft[i].x - 1;
	}
	if (!IsCrash(MyCraft, NextCraft))
	{
		LeftMoving--;
		for (int i = 0; i < 4;i++)
		{
			Field[MyCraft[i].y][MyCraft[i].x] = ' ';
			MyCraft[i].x--;
		}
		for (int i = 0; i < 4; i++)
		{
			Field[MyCraft[i].y][MyCraft[i].x] = 'X';
		}
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		NextCraft[i].x = MyCraft[i].x + 1;
	}

}

void RightMove(Craft* MyCraft, Craft* NextCraft)
{
	for (int i = 0; i < 4; i++)
	{
		NextCraft[i].x = MyCraft[i].x + 1;
	}
	if (!IsCrash(MyCraft, NextCraft))
	{
		LeftMoving++;
		for (int i = 0; i < 4;i++)
		{
			Field[MyCraft[i].y][MyCraft[i].x] = ' ';
			MyCraft[i].x++;
		}
		for (int i = 0; i < 4; i++)
		{
			Field[MyCraft[i].y][MyCraft[i].x] = 'X';
		}
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		NextCraft[i].x = MyCraft[i].x - 1;
	}
}

void DownMove(Craft* MyCraft, Craft* NextCraft)
{
	for (int i = 0; i < 4; i++)
	{
		NextCraft[i].y = MyCraft[i].y + 1;
	}
	if (!IsCrash(MyCraft, NextCraft))
	{
		TopMoving++;
		for (int i = 0; i < 4;i++)
		{
			Field[MyCraft[i].y][MyCraft[i].x] = ' ';
			MyCraft[i].y++;
		}
		for (int i = 0; i < 4;i++)
		{
			Field[MyCraft[i].y][MyCraft[i].x] = 'X';
		}
	}
}

void ShapeCraft(Craft* MyCraft, Craft* NextCraft, int r)
{
	status++;
	status %= 4;
	for (int i = 0; i < 4; i++)
	{
		NextCraft[i].x = mCraft[r][status][i].x + LeftDistance + nFieldWidth / 2 - 3 + LeftMoving ;
		NextCraft[i].y = mCraft[r][status][i].y + TopDistance - 2 + TopMoving;
	}
	if (!IsCrash(MyCraft, NextCraft))
	{
		for (int i = 0; i < 4;i++)
		{
			Field[MyCraft[i].y][MyCraft[i].x] = ' ';
			MyCraft[i].x = NextCraft[i].x;
			MyCraft[i].y = NextCraft[i].y;
		}
		for (int i = 0; i < 4; i++)
		{
			Field[NextCraft[i].y][NextCraft[i].x] = 'X';
		}
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		status--;
		status %= 4;
		NextCraft[i].x = mCraft[r][status][i].x + LeftDistance + nFieldWidth / 2 - 3 + LeftMoving;
		NextCraft[i].y = mCraft[r][status][i].y + TopDistance - 2 + TopMoving;
	}
}

void MoveCraft(Craft* MyCraft, Craft* NextCraft, int r)
{
	status = 0;
	TopMoving = 0;
	LeftMoving = 0;
	while (!IsCrash(MyCraft, NextCraft))
	{
		for (int i = 0; i < 4; i++)
		{
			NextCraft[i].x = MyCraft[i].x;
			NextCraft[i].y = MyCraft[i].y;
		}
		for (int i = 0; i < 20; i++)
		{
			if (_kbhit())
			{
				char input = _getch();
				if (input == 'a')
				{
					LeftMove(MyCraft, NextCraft);
				}
				else if (input == 'w')
				{
					ShapeCraft(MyCraft, NextCraft, r);
				}
				else if (input == 'd')
				{
					RightMove(MyCraft, NextCraft);
				}
				else if (input == 's')
				{
					DownMove(MyCraft, NextCraft);
				}
			}
			Sleep(1);
			ShowFrame();
		}
		DownMove(MyCraft, NextCraft);

		/*for (int i = 0; i <= TopDistance + nFieldHeight - 1; i++)
		{
			for (int j = 0; j <= LeftDistance + nFieldWidth - 1; j++)
			{
				if (DynamicField[i][j] == 'X')
				{
					DynamicField[i][j] = ' ';
				}
			}
		}
		for (int i = 0; i <= TopDistance + nFieldHeight - 1; i++)
		{
			for (int j = 0; j <= LeftDistance + nFieldWidth - 1; j++)
			{
				if (Field[i][j] == 'X')
				{
					DynamicField[i + 1][j] = Field[i][j];
					if (DynamicField[i][j] == 'X')
					{
						continue;
					}
					DynamicField[i][j] = ' ';
					continue;
				}
				if (DynamicField[i][j] == 'X')
				{
					continue;
				}
				DynamicField[i][j] = Field[i][j];

			}
		}
		for (int i = 0; i <= TopDistance + nFieldHeight - 1; i++)
		{
			for (int j = 0; j <= LeftDistance + nFieldWidth - 1; j++)
			{
				Field[i][j] = DynamicField[i][j];
			}
		}
		ShowFrame();*/
	}
}

void MyScore()
{
	Score += 10 * RemoveLine;
}

void IsRemove()
{
	RemoveLine = 0;
	for (int i = TopDistance; i <= TopDistance + nFieldHeight - 2; i++)
	{
		MySignal = true;
		for (int j = LeftDistance + 1; j <= LeftDistance + nFieldWidth - 2; j++)
		{
			if (Field[i][j] == ' ')
			{
				MySignal = false;
				break;
			}
		}
		if (MySignal)
		{
			RemoveLine++;
			Sleep(10);
			for (int k = LeftDistance + 1; k <= LeftDistance + nFieldWidth - 2; k++)
			{
				Field[i][k] = '=';
			}
			ShowFrame();
			Sleep(100);
			for (int a = i; a >= TopDistance; a--)
			{
				for (int b = LeftDistance + 1; b <= LeftDistance + nFieldWidth - 2; b++)
				{
					Field[a][b] = Field[a - 1][b];
				}
			}
		}
	}
	MyScore();
}

bool IsEnd(Craft* MyCraft, Craft* NextCraft)
{
	if (IsCrash(MyCraft, NextCraft))
	{
		for (int i = LeftDistance + 1; i <= LeftDistance + nFieldWidth - 2; i++)
		{
			if (Field[DeadLine][i] == 'X')
			{
				return true;
			}
		}
	}
	return false;
}

void EndShow()
{
	cout << "                         " << endl;
	cout << "                         " << endl;
	cout << "                         " << endl;
	cout << "        YOU LOSE !!!!!!       " << endl;
	cout << "     YOUR SCORE IS " << Score << endl;
	cout << "                         " << endl;
	cout << "                         " << endl;
	cout << "                         " << endl;
	cout << "                         " << endl;

}

void Game()
{
	while (1)
	{
		Craft MyCraft[4];
		Craft NextCraft[4];
		//生成方块
		int r = ProduceCraft(MyCraft);
		//方块移动
		for (int i = 0; i < 4; i++)
		{
			NextCraft[i].x = MyCraft[i].x;
			NextCraft[i].y = MyCraft[i].y;
		}
		MoveCraft(MyCraft, NextCraft, r);
		//消灭判断
		IsRemove();
		//结束判断
		if (IsEnd(MyCraft, NextCraft))
		{
			system("cls");
			EndShow();
			break;
		}
	}
}

int main()
{
	int GameSignal = 1;
	CreateCraft();
	while (GameSignal)
	{
		ShowMenu();
		cin >> GameSignal;
		system("cls");
		GameFrame();
		if (GameSignal == 0)
		{
			cout << "您已退出游戏！" << endl;
			break;
		}
		if (GameSignal == 1)
		{
			Game();
			system("pause");
			system("cls");
		}
		else
		{
			system("cls");
			cout << "请重新输入！";
			Sleep(2000);
			system("cls");
			continue;
		}
	}
	return 0;
}
