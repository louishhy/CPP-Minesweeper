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

void menu();//Print menu
void initialize();//Initialize each array
void Player_operation(clock_t& start_time, clock_t& end_time, double& time_record);
void display_mine_board();
void display_game_board();
void generate(int mine_num);//Random mine generation
int count_mine(int x,int y);//Count the number of surrounding mines
void sweep_dfs(int x,int y,bool vis[N][N]);//Update game board via DFS
int sweep(int x,int y);
void time_calculation(clock_t& start, clock_t& end, double& time_interval, int flag ); //A time calculation function, flag 0 -> start, flag 1 -> end and print time used
void read_leaderboard();//displays the leaderboard
void write_leaderboard(string user_name, double time_record);//input the user name and the time record in seconds, then write to leaderboards

int main()
{
	initialize();
	clock_t starting_time, ending_time;
	double time_record;
	Player_operation(starting_time, ending_time, time_record);
	return 0;
}

void Player_operation(clock_t& start_time, clock_t& end_time, double& time_record)
{
	menu();
	generate(Num);//Generate a mine board witn Num mines
	time_calculation(start_time, end_time, time_record, 0);
	display_game_board();
	while(Num)//Still have mines
	{
		int tmp_x,tmp_y,result;
		char mode[5];
		printf("Please enter the coordinate: ");
		scanf("%s%d%d",&mode,&tmp_x,&tmp_y);
		if(tmp_x<1||tmp_x>M||tmp_y<1||tmp_y>M)//Coordinate exceeds limits
		{
			puts("Illegal coordinate, please enter again.");
			continue;
		}
		if(mode[0]=='S')
		{
			result=sweep(tmp_x,tmp_y);
			if(result==0)//Coordinate exceeds limits
			{
				puts("Illegal coordinate, please enter again.");
				continue;
			}
			if(result==1) break;//Stepped on a mine
		}		
		if(mode[0]=='M')
		{
			if(game_board[tmp_x][tmp_y]=='*')
			{
				game_board[tmp_x][tmp_y]='?';
				if(mine_board[tmp_x][tmp_y]) Num--;//Successfully find the mine location
			}
			else 
			{
				puts("Illegal coordinate, please enter again.");
				continue;
			}
		}
		display_game_board();
	}
	
	if(!Num) 
	{
		puts("---------------------WIN!--------------------");
		display_mine_board();
	}
	
	time_calculation(start_time, end_time, time_record, 1);
	
	string name;
	printf("Please enter your name: ");
	cin >> name;
	write_leaderboard(name, time_record);
	return;
}

void menu()
{
	char tmp_diff[20];
	puts("-----------------Minesweeper-----------------");
	puts("Mode selection:");
	puts("	Beginner: Board_width=5 Mine_number=3");
	puts("	Easy: Board_width=9 Mine_number=10");
	puts("	Normal: Board_width=15 Mine_number=30");
	puts("	Hard: Board_width=30 Mine_number=200");
	puts("	Leaderboards");
	puts("---------------------------------------------");
	puts("Operation:");
	puts("	S x y: Sweep and view the status of coordinates(x,y)");
	puts("	M x y: Mark the location with a question mark '?' (May be a mine at this location)");
	puts("Conditions for players to win:");
	puts("	All mines are marked with '?'");
	puts("---------------------------------------------");
	printf("Please enter your choice(Easy/Normal/Hard/Leaderboards): ");
	scanf("%s",&tmp_diff);
	if(tmp_diff[0]=='B') M=5,Num=3;
	else if(tmp_diff[0]=='E') M=9,Num=10;
 	else if(tmp_diff[0]=='N') M=15,Num=30;
	else if(tmp_diff[0]=='H') M=30,Num=200;
	else if(tmp_diff[0]=='L'){
		read_leaderboard();
		menu();
	}
	else {
		puts("Illegal input, please enter again.");
		menu();
	}
	return;
}

void initialize()
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

void display_game_board()
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

void generate(int mine_num)
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
//	display_mine_board();
	return;
}

int count_mine(int x,int y)
{
	int tmp_num=0;
	if(mine_board[x-1][y-1]) tmp_num++;
	if(mine_board[x][y-1]) tmp_num++;
	if(mine_board[x+1][y-1]) tmp_num++;
	if(mine_board[x-1][y]) tmp_num++;
	if(mine_board[x+1][y]) tmp_num++;
	if(mine_board[x-1][y+1]) tmp_num++;
	if(mine_board[x][y+1]) tmp_num++;
	if(mine_board[x+1][y+1]) tmp_num++;
	return tmp_num;
}

void sweep_dfs(int x,int y,bool **vis)
{
	if(x<1||x>M||y<1||y>M) return;
	if(mine_board[x][y]==1) return;
	if(vis[x][y]) return;
	vis[x][y]=1;
	if(count_mine(x,y))
	{
		game_board[x][y]='0'+count_mine(x,y);
		return;
	}
	game_board[x][y]='\0';
	sweep_dfs(x-1,y-1,vis);sweep_dfs(x,y-1,vis);sweep_dfs(x+1,y-1,vis);sweep_dfs(x-1,y,vis);
	sweep_dfs(x+1,y,vis);sweep_dfs(x-1,y+1,vis);sweep_dfs(x,y+1,vis);sweep_dfs(x+1,y+1,vis);
	return;
}

int sweep(int x,int y)
{
	if(x<1||x>M||y<1||y>M)
	{
		return 0;
	}
	if(mine_board[x][y]==1)//Touch the mine, failed
	{
		puts("--------------------Failed--------------------");
		display_mine_board();//display the correct mine board using 0-1
		puts("---------------------------------------------");
		return 1;
	}
	if(mine_board[x][y]==0)//refresh game board recursively 
	{
		bool **vis=new bool* [N];
		for(int i=0;i<N;++i)
		{
			vis[i]=new bool[N];
			for(int j=0;j<N;++j) vis[i][j]=0;
		}
		sweep_dfs(x,y,vis);
		for(int i=0;i<N;++i)
		{
			delete[] vis[i];
		}
		delete[] vis;
		return 2;
	}
}

void time_calculation(clock_t& start, clock_t& end, double& time_interval, int flag ){       
	if (flag==0){
		start = clock();
	}
	else if (flag == 1) {
		end = clock();
		cout << "Time used: " << (end - start) / (double)CLOCKS_PER_SEC << " seconds." <<endl;
		time_interval = (end - start) / (double)CLOCKS_PER_SEC;
	}
}

void write_leaderboard(string user_name, double time_record){            
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

void read_leaderboard(){    
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
