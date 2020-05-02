#include<cstdio>
#include<cstring>
#include<algorithm>
#include<time.h>
#include<vector>
#include<string>
#include<map>
#include<ctime>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#define N 105

bool mine_board[N][N];
char game_board[N][N];
int M,Num;

void time_calculation(clock_t& start, clock_t& end, double& time_interval, int flag );
void read_leaderboard();
void write_leaderboard(string user_name, double time_record);

void menu()//menu done
{
	char tmp_diff[20];
	puts("-----------------Minesweeper-----------------");
	puts("Difficulty:");
	puts("Easy: Board_width=15 Mine_number=30");
	puts("Difficult: Board_width=30 Mine_number=400");
	puts("Leaderboards");
	puts("---------------------------------------------");
	printf("Please enter your choice(Easy/Difficult/Leaderboards): ");
	scanf("%s",&tmp_diff);
	if(tmp_diff[0]=='E') M=15,Num=30;
	if(tmp_diff[0]=='D') M=30,Num=400;
	if(tmp_diff[0]=='L'){
		read_leaderboard();
		menu();
	}
	return;
}
void initialize()//initialization done
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
void display_game_board()//game board display done
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
void generate(int mine_num)//random mine generation done
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
	if(mine_board[x][y]==1)//Touch the mine, failed
	{
		puts("--------------------Failed--------------------");
		display_mine_board();//display the correct mine board using 0-1
		puts("---------------------------------------------");
		return 0;
	}
	if(mine_board[x][y]==0)//refresh game board recursively 
	{
		return 1;
	}
}
void Player_operation(clock_t& start_time, clock_t& end_time, double& time_record)
{
	menu();
	generate(Num);
	time_calculation(start_time, end_time, time_record, 0);
	while(Num)
	{
		display_game_board();
		printf("Please enter the coordinate: ");
		int tmp_x,tmp_y,result;
		scanf("%d%d",&tmp_x,&tmp_y);
		result=sweep(tmp_x,tmp_y);
		if(!result) break;
	}
	
	time_calculation(start_time, end_time, time_record, 1);
	
	string name;
	printf("Please enter your name: ");
	cin >> name;
	write_leaderboard(name, time_record);
	return;
}

void time_calculation(clock_t& start, clock_t& end, double& time_interval, int flag ){        //A time calculation function, flag 0 -> start, flag 1 -> end and print time used
	if (flag==0){
		start = clock();
	}
	else if (flag == 1) {
		end = clock();
		cout << "Time used: " << (end - start) / (double)CLOCKS_PER_SEC << " seconds." <<endl;
		time_interval = (end - start) / (double)CLOCKS_PER_SEC;
	}
}

void write_leaderboard(string user_name, double time_record){            //input the user name and the time record in seconds, then write to leaderboards
	ofstream fout;
	fout.open("leaderboard.txt",ios::app);
	if(fout.fail()){
		cout << "Error in opening the leaderboard!"<<endl;
		return;
	}
	fout << user_name << " " << time_record << "seconds" <<endl;
	fout.close();
	return;
}

void read_leaderboard(){    //displays the leaderboard
	cout << "--------------------LEADERBOARD--------------------" <<endl;
	ifstream fin;
	fin.open("leaderboard.txt",ios::app);
	if(fin.fail()){
		cout << "Error in opening the leaderboard!"<<endl;
		return;
	}
	string line;
	while(getline(fin,line)){
		cout << line << endl;
	}
	cout<<endl;
	fin.close();
	return;
}

int main()
{
	initialize();
	clock_t starting_time, ending_time;
	double time_record;
	Player_operation(starting_time, ending_time, time_record);
	return 0;
}
