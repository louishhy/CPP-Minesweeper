main.o: main.cpp leaderboard_func.h
	g++ -c main.cpp

leaderboard_func.o: leaderboard_func.cpp leaderboard_func.h
	g++ -c leaderboard_func.cpp

main: main.o leaderboard_func.o
	g++ main.o leaderboard_func.o -o main