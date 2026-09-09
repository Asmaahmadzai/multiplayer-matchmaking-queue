# Multiplayer Matchmaking Queue
A multiplayer matchmaking queue implemented in **C** using a linked-list-based queue. The program reads player information from a text file, stores players in matchmaking order, and provides operations for managing and analyzing the queue.

## Features
* Load player information from a text file
* Add players to the matchmaking queue
* View the next player waiting for a match
* Remove players in **FIFO (First-In, First-Out)** order
* Display all players currently waiting
* Track the number of players in the queue
* Calculate the average player level
* Find the highest-level player
* Validate player data before adding it to the queue
* Dynamically allocate and release memory

## Concepts Demonstrated
This project demonstrates several fundamental C programming and data structure concepts: 
* Linked lists
* Queue data structures
* Structures
* Pointers
* Dynamic memory allocation with `malloc()` and `free()`
* File input/output
* String manipulation
* Functions and modular programming
* Input validation
* Memory management

## Queue Structure
Each player is represented as a node containing:
* Player ID
* Player name
* Player level
* Pointer to the next player

The matchmaking queue maintains pointers to both the **front** and **rear** of the linked list, allowing players to be added at the rear and removed from the front.

```
  Front                                    Rear
    |                                       |
    v                                       v
[Player 1] -> [Player 2] -> [Player 3] -> NULL
```

Players are matched in the same order they entered the queue.

## Player File Format

Each player in `players.txt` follows this format:

```
player_id player_name level
```
Example:
```
101 Alex 25
102 Sam 18
103 Emma 30
104 Liam 22
105 Nora 27
```
Player IDs must be greater than `0`, and player levels must be between `1` and `100`.

## Example Output

```
Welcome to the Multiplayer Matchmaking Queue

Loading players from file...

Current Matchmaking Queue
-----------------------------------------------
Player ID: 101
Name: Alex
Level: 25
Player ID: 102
Name: Sam
Level: 18
Player ID: 103
Name: Emma
Level: 30
-----------------------------------------------

Players Waiting: 5
Average Level: 24.40
Highest-Level Player: Emma

Next Player Waiting:
Player ID: 101
Name: Alex
Level: 25

Matching next two players...

Updated Matchmaking Queue
-----------------------------------------------
Player ID: 103
Name: Emma
Level: 30
-----------------------------------------------
```
