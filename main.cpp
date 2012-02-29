#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>


/* 初期化 */
int Ini(int Data[20][20], int size);

/* 迷路作成部分 */
int Meiro(int Data[20][20], int size);

/* 出力 */
int Print(int Data[20][20], int size);


int main(){
  int size = 20;
	int i;
	//	int a;
	int Data[20][20];

	system("cls");

	/*for(a = 1; a<=24 ; a++){	
		puts("");
	}
	*/


	/* 初期化 */
	if(Ini(Data, size)){
		printf("初期化エラー\n");
		return 2;
	}

	/* 迷路作成部分 */
	if(Meiro(Data, size)){
		printf("迷路作成エラー\n");
		return 2;
	}

	/* Player */
	Data[1][1] = 3;

	/* GOAL */
	Data[size - 2][size - 2] = 2;
	
	/* 出力 */
	if(Print(Data, size)){
		printf("出力エラー\n");
		return 2;
	}


	while(Data[size - 2][size -2] != 3);


	/* メモリ開放*/
	for(i = 0; i < size; i++){
		free(Data[i]);
	}
	free(Data);

	return 0;

	printf("解放完了\n");
}


/* 初期化 */
int Ini(int Data[20][20], int size){
	int i, j;

	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			/* 外枠かどうか */
			if(i != 0 && j != 0 && i != size - 1 && j != size - 1){	
				if(i % 2 == 1 || j % 2 ==1){
					Data[i][j] = 1;
				}
				else{
					Data[i][j] = 0;
				}
			}
			/* 外枠の場合 */
			else{
				Data[i][j] = 0;
			}
		}
	}
	return 0;
}

/* 迷路作成部分 */
int Meiro(int Data[20][20], int size){
	int i , j;
	int ran;

	srand((unsigned)time(NULL));

	for(i = 2; i < size - 2; i = i + 2){
		for(j = 2; j < size - 2; j = j + 2){
			if(i == 2){
				ran = rand() % 4;
				if(ran == 0){
					Data[i - 1][j] = 0;
				}
				else if(ran == 1){
					Data[i][j + 1] = 0;
				}
				else if(ran == 2){
					Data[i + 1][j] = 0;
				}
				else{
					Data[i][j - 1] = 0;
				}
			}
			else{
				ran = rand() % 3;
				if(ran == 0){
					Data[i][j + 1] = 0;
				}
				else if(ran == 1){
					Data[i + 1][j] = 0;
				}
				else{
					Data[i][j - 1] = 0;
				}
			}
		}
	}
	return 0;
}



/* 出力 */
int Print(int Data[20][20], int size){
	int i, j;

	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			if(Data[i][j] == 0){
				printf("★");
			}
			else if(Data[i][j] == 1){
				printf("  ");
			}
			else if(Data[i][j] == 2){
				printf("ゴ");
			}
			else{
				printf("プ");
			}
		}
		printf("\n");
	}
	return 0;
}