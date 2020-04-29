#include<cstdio>
#include<cstring>
#include<algorithm>
#include<time.h>
#include<vector>
#include<string>
#include<map>
using namespace std;
#define N 105

bool mine_board[N][N];
char game_board[N][N];
int M,Num;

void menu()//初始界面 done
{
	char tmp_diff[20];
	puts("-----------------Minesweeper-----------------");
	puts("Difficulty:");
	puts("Easy: Board_width=15 Mine_number=30");
	puts("Difficult: Board_width=30 Mine_number=400");
	puts("---------------------------------------------");
	printf("Please enter the difficulty of your choice(Easy/Difficult): ");
	scanf("%s",&tmp_diff);
	if(tmp_diff[0]=='E') M=15,Num=30;
	if(tmp_diff[0]=='D') M=30,Num=400;
	return;
}
void initialize()//初始化 done
{
	memset(mine_board,sizeof(mine_board),0);
	for(int i=1;i<N;++i)
	for(int j=1;j<N;++j)
	{
		game_board[i][j]='*';
	}
	return;
}
void display_mine_board()
{
	for(int i=1;i<=M;++i)
	{
		for(int j=1;j<=M;++j) printf("%d ",mine_board[i][j]);
		puts("");
	}
	return;
}
void display_game_board()//显示棋盘 done
{
	printf("   ");
	for(int i=1;i<=M;++i) 
	{
		printf("%d",i);
		printf(i<10?"  ":" ");
	}
	puts("");
	for(int i=1;i<=M;++i)
	{
		printf("%d",i);
		printf(i<10?"  ":" ");
		for(int j=1;j<=M;++j) printf("%c  ",game_board[i][j]);
		puts("");
	}
	return;	
}
void generate(int mine_num)//随机生成雷 done
{
	srand(time(NULL));
	while(mine_num)
	{
		int tmp_x=rand()%M+1,tmp_y=rand()%M+1;
		if(!mine_board[tmp_x][tmp_y])
		{
			mine_board[tmp_x][tmp_y]=1;
			--mine_num;
		}
	}
	display_mine_board();
	return;
}

int sweep(int x,int y)
{
	if(mine_board[x][y]==1)//踩中雷，失败 
	{
		puts("--------------------Faild--------------------");
		display_mine_board();//显示正确位置 
		puts("---------------------------------------------");
		return 0;
	}
	if(mine_board[x][y]==0)//没踩中，递归更新game_board 
	{
		return 1;
	}
}
void Player_operation()
{
	menu();
	generate(Num);
	while(Num)
	{
		display_game_board();
		printf("Please enter the coordinate: ");
		int tmp_x,tmp_y,result;
		scanf("%d%d",&tmp_x,&tmp_y);
		result=sweep(tmp_x,tmp_y);
		if(!result) break;
	}
	return;
}

int main()
{
	initialize();
	Player_operation();
	return 0;
}
