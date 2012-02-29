#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

/* サイズ選択 */
int InputNumber(int *mnu_counter);

/* 初期化 */
int Ini(int **data, int size);

/* 迷路作成部分 */
int Meiro(int **data, int size);

/* 出力 */
int Print(int **data, int size);


int main()
{

	int **data;
	int size;
	int i;
	int x = 1;
	int y = 1;

	do
	{
		printf("作成する迷路の大きさを入力。(大きさが5以上かつ奇数であること)\n");

		if(InputNumber(&size) != 0)
		{
			printf("Input Number Error!!\n");
			return 1;
		}
	}
	while(size < 5 || (size % 2 != 1));


	system("cls");


/*	int a = 0;

	fot(i = 0; i <= 24; i++){
		puts("");
	}
*/

	/* 1次元確保 */
	if((data = (int **)malloc(size * sizeof(int *))) == NULL)
	{
		printf("Malloc Error\n");
		return 2;
	}

	/* 2次元確保 */
	for(i = 0; i < size; i++)
	{
		if((data[i]=(int *)malloc(size * sizeof(int))) == NULL)
		{
			printf("Malloc Error\n");
			return 3;
		}
	}

	/* 初期化 */
	if(Ini(data, size))
	{
		printf("初期化エラー!!\n");
		return 2;
	}

	/* 迷路作成部分 */
	if(Meiro(data, size))
	{
		printf("迷路作成エラー!!\n");
		return 2;
	}

	/* Player */
	data[1][1] = 3;

	/* GOAL */
	data[size - 2][size - 2] = 2;
	
	/* 出力 */
	if(Print(data, size))
	{
		printf("出力エラー\n");
		return 2;
	}

	
	while(data[size - 2][size -2] != 3);


	/* メモリ開放*/
	for(i = 0; i < size; i++)
	{
		free(data[i]);
	}
	free(data);

	return 0;

	printf("メモリ解放\n");
}

/* サイズ選択 */
int InputNumber(int *mnu_counter)
{
	char *ch;
	if((ch = (char *)malloc(256 * sizeof(char))) == NULL)
	{
		printf("Malloc Error!!\n");
		return 1;
	}

	scanf("%d",&*mnu_counter);
	gets(ch);
	free(ch);

	return 0;
}

/* 初期化 */
int Ini(int **data, int size)
{
	int i, j;

	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			/* 外枠かどうか */
			if(i != 0 && j != 0 && i != size - 1 && j != size - 1)
			{	
				if(i % 2 == 1 || j % 2 ==1)
				{
					data[i][j] = 1;
				}
				else
				{
					data[i][j] = 0;
				}
			}
			/* 外枠の場合 */
			else
			{
				data[i][j] = 0;
			}
		}
	}
	return 0;
}

/* 迷路作成部分 */
int Meiro(int **data, int size)
{
	int i , j;
	int ran;

	srand((unsigned)time(NULL));

	for(i = 2; i < size - 2; i = i + 2)
	{
		for(j = 2; j < size - 2; j = j + 2)
		{
			if(i == 2)
			{
				ran = rand() % 4;
				if(ran == 0)
				{
					data[i - 1][j] = 0;
				}
				else if(ran == 1)
				{
					data[i][j + 1] = 0;
				}
				else if(ran == 2)
				{
					data[i + 1][j] = 0;
				}
				else
				{
					data[i][j - 1] = 0;
				}
			}
			else
			{
				ran = rand() % 3;
				if(ran == 0)
				{
					data[i][j + 1] = 0;
				}
				else if(ran == 1)
				{
					data[i + 1][j] = 0;
				}
				else
				{
					data[i][j - 1] = 0;
				}
			}
		}
	}
	return 0;
}



/* 出力 */
int Print(int **data, int size)
{
	int i, j;

	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			if(data[i][j] == 0)
			{
				printf("★");
			}
			else if(data[i][j] == 1)
			{
				printf("  ");
			}
			else if(data[i][j] == 2)
			{
				printf("ゴ");
			}
			else
			{
				printf("プ");
			}
		}
		printf("\n");
	}
	return 0;
}