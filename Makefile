main.o: main.cpp leaderboard_func.h
	g++ -w -c main.cpp

leaderboard_func.o: leaderboard_func.cpp leaderboard_func.h
	g++ -w -c leaderboard_func.cpp

main: main.o leaderboard_func.o
	g++ -w main.o leaderboard_func.o -o main
