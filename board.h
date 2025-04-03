#include <iostream>
#include <string>
#include <cctype>
#include <typeinfo>

using namespace std;

/*
A Board class that will the hold the counts of all the players with different sizes, place the pieces
on the board and decrease the counts of the sizes of the corresponding players
*/
class Board
{
    int smallRedCount;
    int midRedCount;
    int largeRedCount;
    int smallYellowCount;
    int midYellowCount;
    int largeYellowCount;
    bool valid;
    bool winCheck;

public:
    /*
    Function that takes in the current player and the size inputted and returns the current count
    corresponding to that player and size
    */
    int getCount(string player, char size)
    {
        // bunch of if-statements that returns the count based on the player and size
        if ((size == 'a') && (player == "yellow"))
        {
            return largeYellowCount;
        }
        else if ((size == 'a') && (player == "red"))
        {
            return largeRedCount;
        }
        else if ((size == 'b') && (player == "yellow"))
        {
            return midYellowCount;
        }
        else if ((size == 'b') && (player == "red"))
        {
            return midRedCount;
        }
        else if ((size == 'c') && (player == "yellow"))
        {
            return smallYellowCount;
        }
        else if ((size == 'c') && (player == "red"))
        {
            return smallRedCount;
        }
    }
    string gameArray[3][3] = {{" 1", " 2", " 3"},
                              {" 4", " 5", " 6"},
                              {" 7", " 8", " 9"}};

    // returns the counts of all the pieces
    int getSmallRedCount()
    {
        return smallRedCount;
    }
    int getmidRedCount()
    {
        return midRedCount;
    }
    int getLargeRedCount()
    {
        return largeRedCount;
    }
    int getSmallYellowCount()
    {
        return smallYellowCount;
    }
    int getmidYellowCount()
    {
        return midYellowCount;
    }
    int getlargeYellowCount()
    {
        return largeYellowCount;
    }

    // function that takes in the bool value and sets the private member valid to that
    void setValid(bool value)
    {
        valid = value;
    }

    // function that takes in no parameters and returns what the member valid is set to
    bool getValid()
    {
        return valid;
    }

    /*
    function that takes in no parameters and returns what the member valid is set to which could be
    true if there is a winner or tie or false if there is no winner or tie
    */
    bool getWinCheck()
    {
        return winCheck;
    }

    // function that takes no parameters and outputs the board and with the pieces on it
    void displayBoard()
    {
        cout << gameArray[0][0] << '|' << gameArray[0][1] << '|' << gameArray[0][2];
        cout << endl;
        cout << "--------" << endl;
        cout << gameArray[1][0] << '|' << gameArray[1][1] << '|' << gameArray[1][2];
        cout << endl;
        cout << "--------" << endl;
        cout << gameArray[2][0] << '|' << gameArray[2][1] << '|' << gameArray[2][2];
        cout << endl;
        cout << endl;
    }

    // default constructor that sets all the counts to 2
    Board()
    {
        smallRedCount = 2;
        midRedCount = 2;
        largeRedCount = 2;
        smallYellowCount = 2;
        midYellowCount = 2;
        largeYellowCount = 2;
        valid = true;
        winCheck = false;
    }

    
    // Constructor that takes all the elements from the previous board and clones it
    Board(int smallRed, int midRed, int largeRed, int smallYellow, int midYellow, int largeYellow, string arrayGame[3][3])
    {
        smallRedCount = smallRed;
        midRedCount = midRed;
        largeRedCount = largeRed;
        smallYellowCount = smallYellow;
        midYellowCount = midYellow;
        largeYellowCount = largeYellow;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                gameArray[i][j] = arrayGame[i][j];
            }
        }
    }

    /*
    Function that takes the square, size, space plus the square and location as parameters.
    It checks if a move is valid and if it is, valid stays at true but if it is invalid, valid
    is set to false
    */
    void checkValid(string square, string sizes, string space, string location)
    {
        string dupSquare = square;
        string dupSpace = space;

        // sets the valid to false if the size of the input is not 2
        if ((location.size() != 2))
        {
            valid = false;
            return;
        }
        // sets the valid to false if the second character is not an integer
        else if (!isdigit(location[1]))
        {
            valid = false;
            return;
        }
        // sets the valid to false if the second character is 0
        else if (location[1] == '0')
        {
            valid = false;
            return;
        }
        /*
        sets the valid to false if the size is not a, b or c and the second input is greater than
        9  or less than 1
        */
        else if (((sizes != "a") || (sizes != "b") || (sizes != "c")) &&
                 ((stoi(square) < 1) && (stoi(square) > 9)))
        {
            valid = false;
            return;
        }
        // sets the valid to false if the first character of the input is uppercase
        int row = (stoi(dupSquare) - 1) / 3;
        int column = (stoi(dupSquare) - 1) % 3;
        if (isupper((gameArray[row][column][0])) &&
            isupper((gameArray[row][column][1])))
        {
            valid = false;
            return;
        }
        // Sets valid to false if there is a piece of the same size at that spot
        if (sizes == "a" && (gameArray[row][column][1] == 'Y' || gameArray[row][column][1] == 'R'))
        {
            valid = false;
        }
        // sets valid to false if there is a piece of the same size or bigger size
        else if (sizes == "b" && (gameArray[row][column][0] == 'Y' || gameArray[row][column][0] == 'R'))
        {
            valid = false;
        }
        // sets valid to false if there is a piece of the same size or bigger size
        else if (sizes == "c" && (gameArray[row][column][0] == 'Y' || gameArray[row][column][0] == 'R' || 
        gameArray[row][column][1] == 'Y' || gameArray[row][column][1] == 'R' || 
        gameArray[row][column][0] == 'y' || gameArray[row][column][0] == 'r')) {
            valid = false;
        }
        else {
            valid = true;
        }
    }
    /*
    Function that takes the player, square, size, space plus the square and location as parameters.
    It checks if an input is an invalid first and if it is valid, it places the piece on the board
    */
    void checkSquare(string player, string square, string sizes, string space, string location)
    {
        // puts pieces on the board and sets the valid to true because the input is valid
        string dupSquare = square;
        string dupSpace = space;
        decreasingCount(player, sizes);
        if (valid == true)
        {
            int row = (stoi(dupSquare) - 1) / 3;
            int column = (stoi(dupSquare) - 1) % 3;
            if (player == "yellow")
            {
                /*
                places YY on the board if size is a and there is not another big piece covering
                that spot
                */
                if (sizes == "a")
                {
                    if ((gameArray[row][column] == dupSpace) || (isdigit(dupSpace[1])))
                    {
                        square = "YY";
                        gameArray[row][column] = square;
                        valid = true;
                    }
                    else
                    {
                        valid = false;
                    }
                }
                // places Y and the number if there is not a piece of the same size or bigger size
                if (sizes == "b")
                {
                    if ((gameArray[row][column] == dupSpace) || (!isupper(square[0])))
                    {
                        square = "Y" + dupSquare;
                        gameArray[row][column] = square;
                        valid = true;
                    }
                    else
                    {
                        valid = false;
                    }
                }
                // places y and the number if there is not a piece of the same size or bigger size
                if (sizes == "c")
                {
                    if (gameArray[row][column] == dupSpace)
                    {
                        square = "y" + dupSquare;
                        gameArray[row][column] = square;
                        valid = true;
                    }
                    else
                    {
                        valid = false;
                    }
                }
            }
            else if (player == "red")
            {
                if (sizes == "a")
                {
                    /*
                    places RR on the board if size is a and there is not another big piece covering
                    that spot
                    */
                    if ((gameArray[row][column] == dupSquare) || (isdigit(dupSpace[1])))
                    {
                        square = "RR";
                        gameArray[row][column] = square;
                        valid = true;
                    }
                    else
                    {
                        valid = false;
                    }
                }
                // places R and the number if there is not a piece of the same size or bigger size
                if (sizes == "b")
                {
                    if ((gameArray[row][column] == dupSpace) || (!isupper(square[0])))
                    {
                        square = "R" + dupSquare;
                        gameArray[row][column] = square;
                        valid = true;
                    }
                    else
                    {
                        valid = false;
                    }
                }
                // places r and the number if there is not a piece of the same size or bigger size
                if (sizes == "c")
                {
                    if (gameArray[row][column] == dupSpace)
                    {
                        square = "r" + dupSquare;
                        gameArray[row][column] = square;
                        valid = true;
                    }
                    else
                    {
                        valid = false;
                    }
                }
            }
        }
        else
        {
            valid = false;
        }
    }
    /*
    function that takes in the player and size as parameters and decreases the corresponding count
    and set the member valid to true if the current count is greater than 0 else it sets the member
    valid to false
    */
    void decreasingCount(string player, string size)
    {
        if ((size == "a") && (player == "yellow"))
        {
            if (largeYellowCount > 0)
            {
                largeYellowCount--;
                valid = true;
            }
            else
            {
                valid = false;
            }
        }
        else if ((size == "a") && (player == "red"))
        {
            if (largeRedCount > 0)
            {
                largeRedCount--;
                valid = true;
            }
            else
            {
                valid = false;
            }
        }
        else if ((size == "b") && (player == "yellow"))
        {
            if (midYellowCount > 0)
            {
                midYellowCount--;
                valid = true;
            }
            else
            {
                valid = false;
            }
        }
        else if ((size == "b") && (player == "red"))
        {
            if (midRedCount > 0)
            {
                midRedCount--;
                valid = true;
            }
            else
            {
                valid = false;
            }
        }
        else if ((size == "c") && (player == "yellow"))
        {
            if (smallYellowCount > 0)
            {
                smallYellowCount--;
                valid = true;
            }
            else
            {
                valid = false;
            }
        }
        else if ((size == "c") && (player == "red"))
        {
            if (smallRedCount > 0)
            {
                smallRedCount--;
                valid = true;
            }
            else
            {
                valid = false;
            }
        }
    }

    // function that takes no parameters and checks for a possible winner or tie
    void checkWins()
    {
        // checks if the first vertical row has y or Y to give yellow the win
        if ((gameArray[0][0][0] == 'Y') || (gameArray[0][0][0] == 'y'))
        {
            if ((gameArray[0][1][0] == 'Y') || gameArray[0][1][0] == 'y')
            {
                if ((gameArray[0][2][0] == 'Y') || gameArray[0][2][0] == 'y')
                {
                    displayBoard();
                    cout << "Yellow wins!" << endl;
                    winCheck = true;
                }
            }
        }
        // checks if the second vertical row has y or Y to give yellow the win
        if ((gameArray[1][0][0] == 'Y') || (gameArray[1][0][0] == 'y'))
        {
            if ((gameArray[1][1][0] == 'Y') || gameArray[1][1][0] == 'y')
            {
                if ((gameArray[1][2][0] == 'Y') || (gameArray[1][2][0] == 'y'))
                {
                    displayBoard();
                    cout << "Yellow wins!" << endl;
                    winCheck = true;
                }
            }
        }
        // checks if the third vertical row has y or Y to give yellow the win
        if ((gameArray[2][0][0] == 'Y') || (gameArray[2][0][0] == 'y'))
        {
            if ((gameArray[2][1][0] == 'Y') || gameArray[2][1][0] == 'y')
            {
                if ((gameArray[2][2][0] == 'Y') || (gameArray[2][2][0] == 'y'))
                {
                    displayBoard();
                    cout << "Yellow wins!" << endl;
                    winCheck = true;
                }
            }
        }
        // checks if the first horizontal row has y or Y to give yellow the win
        if ((gameArray[0][0][0] == 'Y') || (gameArray[0][0][0] == 'y'))
        {
            if ((gameArray[1][0][0] == 'Y') || gameArray[1][0][0] == 'y')
            {
                if ((gameArray[2][0][0] == 'Y') || (gameArray[2][0][0] == 'y'))
                {
                    displayBoard();
                    cout << "Yellow wins!" << endl;
                    winCheck = true;
                }
            }
        }
        // checks if the second horizontal row has y or Y to give yellow the win
        if ((gameArray[0][1][0] == 'Y') || (gameArray[0][1][0] == 'y'))
        {
            if ((gameArray[1][1][0] == 'Y') || gameArray[1][1][0] == 'y')
            {
                if ((gameArray[2][1][0] == 'Y') || (gameArray[2][1][0] == 'y'))
                {
                    displayBoard();
                    cout << "Yellow wins!" << endl;
                    winCheck = true;
                }
            }
        }
        // checks if the third horizontal row has y or Y to give yellow the win
        if ((gameArray[0][2][0] == 'Y') || (gameArray[0][2][0] == 'y'))
        {
            if ((gameArray[1][2][0] == 'Y') || gameArray[1][2][0] == 'y')
            {
                if ((gameArray[2][2][0] == 'Y') || (gameArray[2][2][0] == 'y'))
                {
                    displayBoard();
                    cout << "Yellow wins!" << endl;
                    winCheck = true;
                }
            }
        }
        // checks if the first diagonal row has y or Y to give yellow the win
        if ((gameArray[0][0][0] == 'Y') || (gameArray[0][0][0] == 'y'))
        {
            if ((gameArray[1][1][0] == 'Y') || gameArray[1][1][0] == 'y')
            {
                if ((gameArray[2][2][0] == 'Y') || (gameArray[2][2][0] == 'y'))
                {
                    displayBoard();
                    cout << "Yellow wins!" << endl;
                    winCheck = true;
                }
            }
        }
        // checks if the second diagonal row has y or Y to give yellow the win
        if ((gameArray[0][2][0] == 'Y') || (gameArray[0][2][0] == 'y'))
        {
            if ((gameArray[1][1][0] == 'Y') || gameArray[1][1][0] == 'y')
            {
                if ((gameArray[2][0][0] == 'Y') || (gameArray[2][0][0] == 'y'))
                {
                    displayBoard();
                    cout << "Yellow wins!" << endl;
                    winCheck = true;
                }
            }
        }
        // checks if the first vertical row has r or R to give red the win
        if ((gameArray[0][0][0] == 'R') || (gameArray[0][0][0] == 'r'))
        {
            if ((gameArray[0][1][0] == 'R') || gameArray[0][1][0] == 'r')
            {
                if ((gameArray[0][2][0] == 'R') || gameArray[0][2][0] == 'r')
                {
                    displayBoard();
                    cout << "Red wins!" << endl;
                    winCheck = true;
                }
            }
        }
        // checks if the second vertical row has r or R to give red the win
        if ((gameArray[1][0][0] == 'R') || (gameArray[1][0][0] == 'r'))
        {
            if ((gameArray[1][1][0] == 'R') || gameArray[1][1][0] == 'r')
            {
                if ((gameArray[1][2][0] == 'R') || (gameArray[1][2][0] == 'r'))
                {
                    displayBoard();
                    cout << "Red wins!" << endl;
                    winCheck = true;
                }
            }
        }
        // checks if the third vertical row has r or R to give red the win
        if ((gameArray[2][0][0] == 'R') || (gameArray[2][0][0] == 'r'))
        {
            if ((gameArray[2][1][0] == 'R') || gameArray[2][1][0] == 'r')
            {
                if ((gameArray[2][2][0] == 'R') || (gameArray[2][2][0] == 'r'))
                {
                    displayBoard();
                    cout << "Red wins!" << endl;
                    winCheck = true;
                }
            }
        }
        // checks if the first horizontal row has r or R to give red the win
        if ((gameArray[0][0][0] == 'R') || (gameArray[0][0][0] == 'r'))
        {
            if ((gameArray[1][0][0] == 'R') || gameArray[1][0][0] == 'r')
            {
                if ((gameArray[2][0][0] == 'R') || (gameArray[2][0][0] == 'r'))
                {
                    displayBoard();
                    cout << "Red wins!" << endl;
                    winCheck = true;
                }
            }
        }
        // checks if the second horizontal row has r or R to give red the win
        if ((gameArray[0][1][0] == 'R') || (gameArray[0][1][0] == 'r'))
        {
            if ((gameArray[1][1][0] == 'R') || gameArray[1][1][0] == 'r')
            {
                if ((gameArray[2][1][0] == 'R') || (gameArray[2][1][0] == 'r'))
                {
                    displayBoard();
                    cout << "Red wins!" << endl;
                    winCheck = true;
                }
            }
        }
        // checks if the third horizontal row has r or R to give red the win
        if ((gameArray[0][2][0] == 'R') || (gameArray[0][2][0] == 'r'))
        {
            if ((gameArray[1][2][0] == 'R') || gameArray[1][2][0] == 'r')
            {
                if ((gameArray[2][2][0] == 'R') || (gameArray[2][2][0] == 'r'))
                {
                    displayBoard();
                    cout << "Red wins!" << endl;
                    winCheck = true;
                }
            }
        }
        // checks if the first diagonal row has r or R to give red the win
        if ((gameArray[0][0][0] == 'R') || (gameArray[0][0][0] == 'r'))
        {
            if ((gameArray[1][1][0] == 'R') || gameArray[1][1][0] == 'r')
            {
                if ((gameArray[2][2][0] == 'R') || (gameArray[2][2][0] == 'r'))
                {
                    displayBoard();
                    cout << "Red wins!" << endl;
                    winCheck = true;
                }
            }
        }
        // checks if the second diagonal row has r or R to give red the win
        if ((gameArray[0][2][0] == 'R') || (gameArray[0][2][0] == 'r'))
        {
            if ((gameArray[1][1][0] == 'R') || gameArray[1][1][0] == 'r')
            {
                if ((gameArray[2][0][0] == 'R') || (gameArray[2][0][0] == 'r'))
                {
                    displayBoard();
                    cout << "Red wins!" << endl;
                    winCheck = true;
                }
            }
        }
        // checks if there are no pieces left to give tie
        if (((smallRedCount == 0) && (midRedCount == 0) && (largeRedCount == 0)) &&
            ((smallYellowCount == 0) && (midYellowCount == 0) && (largeYellowCount == 0)))
        {
            displayBoard();
            cout << "Tie game." << endl;
            winCheck = true;
        }
    }
};