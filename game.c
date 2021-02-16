#include"game.h"

void displayboard(char arr[COW][COL],int col,int cow)
{
	for (int i = 0; i < col; i++)//以每两行作为一组，列方向的循环
	{
		for (int j = 0; j < cow; j++)//以空格行当中的两列作为一组，行方先的循环
		{
			printf(" %c ",arr[i][j]);
			if (j < cow- 1)
				printf("|");
		}
		printf("\n");
		if (i < col - 1)
		{
			for (int k = 0; k < cow; k++)//以间隔行当中的两列作为一组，行方先的循环
			{
				printf("---");
				if (k < cow - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}
int player(char arr[COL][COW])
{
	int x, y;
	printf("玩家请下棋： （输入坐标x,y）");
	do
	{
		scanf("%d%d", &x, &y);
		if (1 <= x && 1 <= y && x <= COW && y <= COL)
		{
			if (arr[x-1][y-1] != ' ')
				printf("此格已被下子：");
			else
			{
				arr[x - 1][y - 1] = '*';
				break;
			}
		}
		else
			printf("输入范围不符合，重新输入：");
	} while (1);
}
void ComptureMove(char arr[COL][COW],int col,int cow)
{
	printf("电脑下棋：\n");
	int x, y;
	do
	{
		x = rand() % col;//取模得到的是0 1 2，和玩家输入1 2 3不同
		y = rand() % cow;
		if (arr[x][y] != ' ')
			;
		else
		{
			arr[x][y] = '#';
			break;
		}
	} while (1);
}
//'*'
//'#'
//Q 平局
//C 继续
int IsFull(char arr[COL][COW], int col, int cow)
{
	for(int i=0;i<col;i++)
		for (int j = 0; j < cow; j++)
		{
			if (arr[i][j] == ' ')
			{
				return 0;
				break;
			}
		}
	return 1;
}
char IsWin(char arr[COL][COW],int col,int cow)
{
	for (int i = 0; i < COL; i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2] && arr[i][0] != ' ')
			return arr[i][0];
	}
	for (int i = 0; i < COW; i++)
	{
		if (arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i] && arr[0][i] != ' ')
			return arr[0][i];
	}
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != ' ')
		return arr[1][1];
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[1][1] != ' ')
		return arr[1][1];
	if(IsFull(arr,col,cow))
		return 'Q';
		return 'C';
}

void game(char arr[COL][COW],int col,int cow)
{
	char ret;
	//打印游戏表格
	//   |   |   
	//---|---|---
	//   |   | 
	//---|---|---
	//   |   |  
	displayboard(arr,col,cow);
	//人机对弈
	do
	{
		//玩家下棋
		player(arr);
		//展示玩家下棋情况
		displayboard(arr, col, cow);
		//判断玩家是否赢了
		ret=IsWin(arr,col,cow);
		if (ret == '*')//此处可以归结为ret!='C',之后玩家和电脑的判断可以归结为一个代码块
		{
			printf("玩家赢");
			break;
		}
		if (ret == 'Q')
		{
			printf("平局");
			break;
		}

		//电脑下棋
		srand((unsigned)time(NULL));
		ComptureMove(arr,col,cow);
		//展示电脑下棋情况
		displayboard(arr, col, cow);
		ret = IsWin(arr, col, cow);
		if (ret == '#')
		{
			printf("电脑赢");
			break;
		}
		if (ret == 'Q')
		{
			printf("平局");
			break;
		}
	} while (1);
}