#include <iostream>
#include <fstream>
#include <string>
#include <time.h> 
#include "leaderboard_func.h"

using namespace std;

//A stopwatch used to calculate the time consumed, flag 0 = start, flag 1 = end, directly modify the time-recording variable in main.cpp
void time_calculation(time_t& start, time_t& end, double& time_interval, int flag ){       
	if (flag==0){
		start = time(NULL);
	}
	else if (flag == 1) {
		end = time(NULL);
		cout << "Time used: " << (end - start) << " seconds." <<endl;
		time_interval = (end - start) ;
	}
}

//write leaderboard, input user name and stream it to leaderboard.txt
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

//read leaderboard from leaderboard.txt and display it on screen
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
