#include <string>
#include <ctime>

using namespace std;

#ifndef LEADERBOARD_FUNC_H
#define LEADERBOARD_FUNC_H


//Functions for leaderboard and time attack function. For detailed documentation see leaderboard_func.cpp

void time_calculation(clock_t& start, clock_t& end, double& time_interval, int flag );

void write_leaderboard(string user_name, double time_record);

void read_leaderboard();

#endif
