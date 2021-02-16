#include"game.h"

//初始化数组
void initial(char arr[COL][COW], int col, int cow)
{
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < cow; j++)
		{
			arr[i][j] = ' ';
		}
	}
	return 0;
}
void meun()
{
	printf("***********************\n");
	printf("***** play:1 no:0 *****\n");
	printf("***********************\n");
	return 0;
}
int makesure()
{
	int ret;
	scanf("%d", &ret);
	if (ret == 1)
		return 1;
	else
		if (ret == 0)
			return 0;
		else
		{
			printf("输入错误，请重新输入：");
			return 2;
		}
}


int main()
{
	//创建数组，用于记录表格
	char arr[COL][COW];
	initial(arr,COL,COW);
	//显示菜单,并做选择
	meun();
	//是否进入游戏,由于输入错误的关系，需要进行重复确认
	do
	{
		int ret;
		ret=makesure();
		if (ret == 1)
		{
			game(arr,COL,COW);
			break;
		}
		else
		{
			if (ret == 0)
				break;
		} 
	} while (1);
	return 0;
}