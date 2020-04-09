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
### 3.1 Multiple Difficulty Levels
The player can challenge themselves by playing a higher difficulty level with a broader board and more mines!

(Requirement 3: Dynamic memory management)

### 3.2 Time attack and leaderboard
Clock's ticking during the gameplay. You can take a look at the leaderboard and beat all other players in the time attack!

(Requirement 2: Data structures for storing game status; 4: File input/output; 5: Program codes in multiple files)
  
### 3.3 Random mine units distribution
An essential feature in any minesweeping game, mines' positions will change every time the game starts.
  
(Requirement 1: Generation of random game sets or events)
