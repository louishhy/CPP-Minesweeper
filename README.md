# CPP-Minesweeper
A C++ minesweeper game project for HKU ENGG1340. 

## 1. Team Members
HUANG Haoyu     UID: 3035638002

ZHU Wendi       UID: 3035638521

## 2. Game Introduction
This game is a text-based game adopted from the Microsoft Minesweeper, the iconic built-in game in the Windows operating system.

### 2.1 The goal
  The goal for the player is to mark all the units on the board with a "mine" without revealing any of them. If any of the mines is revealed, then the game is over.
  
### 2.2 Revealing the unit
The player can reveal any of the unrevealed unit they want. If the unit doesn't contain a mine, a number would be displayed indicating the number of the mines in the adjacent units.

If the adjacent units doesn't contain any mines, all adjacent cells would be uncovered and would be automatically revealed recursively.
  
### 2.3 Marking the mine
One unit in the game can only have 0 or 1 mine. The size of the board and the numbers of the mine would change in different difficulty modes. The player can mark the unit which they think contains a mine.
 

## 3. Features
### 3.1 Interactive interface of the game
The player acts by entering a coordinate in the board with the type of judgment (whether there are mines or not), and the program outputs an updated board based on the player's input.

(Requirement 2: Data structures for storing game status)

### 3.2 Update to the board.

After reading the coordinates entered by the player, the board is automatically updated (by recursively updating the state of each unit and using dynamic memory to record the state of the board to save memory space)

(Requirement 3: Dynamic memory management)

### 3.3 Multiple Difficulty Levels and random mine units distribution
An essential feature in any minesweeping game. Players can customize the difficulty (by choosing the number of mines and the size of the board). The program will randomly generate a certain number of mines depending on the difficulty chosen by the player, and mines' positions will change every time the game starts.

(Requirement 1: Generation of random game sets or events)

### 3.4 Time attack and leaderboard
Clock's ticking during the gameplay. You can take a look at the leaderboard and beat all other players in the time attack!

(Requirement 4: File input/output; 5: Program codes in multiple files)


## 4. Compilation and Execution Instructions
(A video demonstration is attached in the repo.)

### Compilation
On linux environment, clone this repo, then change to the game directory.
```bash
git clone https://github.com/louishhy/CPP-Minesweeper
cd CPP-Minesweeper
```
Use makefile to make the main executable.
```bash
make main
```
Run the executable.
```bash
./main
```

### Execution
You are ready to play the game. Follow the instruction on the screen.
- Type in to choose difficulty 
- Use S or M command to sweep(reveal) or mark units.
- If you win, the game will invite you to enter your name, and your time and name will be uploaded to the leaderboard for time attack challenges.
