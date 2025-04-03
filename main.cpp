/*
Author - Dominic Aidoo
Date - April 15th, 2024
A program that allows two users to have pieces to place on a board game until one of the users has 
three of their pieces lined up diagonally, horizontally or vertically to determine the winner and 
also gives the players the opportunity to undo their move
*/

#include <iostream>
#include <string>
#include <cctype>
#include <typeinfo>
#include "board.h"

using namespace std;

// A node class that holds the data and the pointer to the next node
class Node {
    public:
        Board board;
        Node* next;
};

// A function that adds new elements to the start of the linked list
void prepend(Node*& head, Board board){
    Node* newBoard = new Node();
    newBoard -> board = Board(board.getSmallRedCount(), board.getmidRedCount(), board.getLargeRedCount(), 
    board.getSmallYellowCount(), board.getmidYellowCount(), board.getlargeYellowCount(), board.gameArray);
    newBoard -> next = head;
    head = newBoard;
}


int main() 
{   
    string location;
    Node* head = new Node();
    head -> board = Board(); 
    string currentPlayer = "yellow";
    // while loop that keeps running until user inputs q`
    while (location != "q") { 
        string position;
        string sizeLetter;
        string squareSpace;
        //if-statement that runs if the bool valid is not false
        if (head->board.getValid() != false) {
            head->board.displayBoard();
            cout << endl;
            if (currentPlayer == "yellow") {
                cout << "a. YY  " << head->board.getCount(currentPlayer, 'a') << " remain." << endl;
                cout << "b. Y   " << head->board.getCount(currentPlayer, 'b') << " remain." << endl;
                cout << "c. y   " << head->board.getCount(currentPlayer, 'c') << " remain." << endl;
            }
            else {
                cout << "a. RR  " << head->board.getCount(currentPlayer, 'a') << " remain." << endl;
                cout << "b. R   " << head->board.getCount(currentPlayer, 'b') << " remain." << endl;
                cout << "c. r   " << head->board.getCount(currentPlayer, 'c') << " remain." << endl;
            }
            cout << "q to exit." << endl;
        }
        cout << "It is " << currentPlayer << "'s turn." << endl;
        cout << "Choose action and location, for example a2: ";
        cin >> location;
        // if-statement that gets out of loop if input is q
        if (location == "q") {
            break;
        }
        // if-statement that undoes a move when the input is u
        if (location == "u") {
            // if-statement that does not undo when the board is empty
            if ((head->board.gameArray[0][0][0] == ' ') && (head->board.gameArray[0][1][0] == ' ') &&   
            (head->board.gameArray[0][2][0] == ' ') && (head->board.gameArray[1][0][0] == ' ') &&
            (head->board.gameArray[1][1][0] == ' ') && (head->board.gameArray[1][2][0] == ' ') &&
            (head->board.gameArray[2][0][0] == ' ') && (head->board.gameArray[2][1][0] == ' ') && 
            (head->board.gameArray[2][2][0] == ' ')) {
                cout << "Cannot undo." << endl;
                head -> board.setValid(false);
            }
            // else-statement that changes the head when an undo is to be done
            else {
                head = head -> next;
                if (currentPlayer == "yellow") {
                    currentPlayer = "red";
                }
                else {
                    currentPlayer = "yellow";
                }
            }
            continue;
        }
        sizeLetter = location[0];
        position = "";
        position += location.substr(1, location.size() - 1);
        squareSpace = " " + position;
        cout << endl;
        head->board.setValid(false);
        head -> board.checkValid(position, sizeLetter, squareSpace, location);
        // if-statement that only adds to the beginning of the linked list if the move is valid
        if (head -> board.getValid() == true) {
            prepend(head, head->board);
            head->board.checkSquare(currentPlayer, position, sizeLetter, squareSpace, location);
        }
        head->board.checkWins();
        // if-statement that gets out of loop if there is a winner or tie
        if (head->board.getWinCheck() == true) {
            break;
        }
        //if-statement that switches the player if there is not an invalid move
        if (head->board.getValid() == true) {
            
            if (currentPlayer == "yellow") {
                currentPlayer = "red";
            }
            else {
                currentPlayer = "yellow";
            }
        }
        else if ((head->board.getValid() != true) && (head->board.getWinCheck() != true)){
            cout << "Invalid move. Try again." << endl;
        } 
}
}