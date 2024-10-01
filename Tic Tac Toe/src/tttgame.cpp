// ITP 365 Spring 2023
// HW09 – Tic-tac-toe AI
// Name: Michelle Kweon
// Email: mkweon@usc.edu
// Platform: Mac

#include "tttgame.h"
#include "tttgameai.h"

TicTacToeGame::TicTacToeGame()
{
    // go through each position in row
    for(int i=0; i < 3; i++) {
        // go through column
        for(int j=0; j < 3; j++) {
            // initialize the board by setting all the spaces to empty
            // GameState with empty spots
            currentState.mBoard[i][j] = GameState::Empty;
        }
    }
}

GameState TicTacToeGame::getBoard() const
{
    // return current GameState
    return currentState;
}

bool TicTacToeGame::setSquareState(unsigned short row, unsigned short col, GameState::SquareState state)
{
    // check if the spot is empty/available
    if(currentState.mBoard[row][col] == GameState::Empty) {
        // claim position of the inputted state
        currentState.mBoard[row][col] = state;
        // true if set successfully
        return true;
    }
    else {
        // spot already filled
        return false;
    }
}

bool TicTacToeGame::setSquareState(unsigned short square, GameState::SquareState state)
{
    // 1 is upper left corner, 9 is lower, right corner
    // subtract by 1 to get zero-based index to get number ordering of spot
    // get row
    unsigned row = (square - 1) / 3;
    // get column
    unsigned col = (square - 1) % 3;
    // claim entered spot - if already claimed, returns false in the setSquareState function
    return setSquareState(row, col, state);
    
}

char TicTacToeGame::getWinner()
{
    // check rows
    for (int i = 0; i < 3; i++) {
      if(currentState.mBoard[i][0] != GameState::Empty &&
         currentState.mBoard[i][0] == currentState.mBoard[i][1] &&
         currentState.mBoard[i][0] == currentState.mBoard[i][2]) {
          if(currentState.mBoard[i][0] == GameState::X) {
              // X wins
              return 'X';
          }
          else {
              // O wins
              return 'O';
          }
        }
      }
    
    // check columns
    for (int j = 0; j < 3; j++) {
        if(currentState.mBoard[0][j] != GameState::Empty &&
           currentState.mBoard[0][j] == currentState.mBoard[1][j] &&
           currentState.mBoard[0][j] == currentState.mBoard[2][j]) {
          if(currentState.mBoard[0][j] == GameState::X) {
              // X wins
              return 'X';
          }
          else {
              // O wins
              return 'O';
          }
        }
      }
    
    // check diagonals
    if(currentState.mBoard[0][0] != GameState::Empty &&
       currentState.mBoard[0][0] == currentState.mBoard[1][1] &&
       currentState.mBoard[0][0] == currentState.mBoard[2][2]) {
        if(currentState.mBoard[0][0] == GameState::X) {
            // X wins
            return 'X';
        }
        else {
            // O wins
            return 'O';
        }
    }
    
    if(currentState.mBoard[2][0] != GameState::Empty &&
       currentState.mBoard[2][0] == currentState.mBoard[1][1] &&
       currentState.mBoard[2][0] == currentState.mBoard[0][2]) {
        if(currentState.mBoard[2][0] == GameState::X) {
            // X wins
            return 'X';
        }
        else {
            // O wins
            return 'O';
        }
    }
    
    // check if empty spaces
    // return true if there are unclaimed spots on the board
    bool emptySpace = false;
    for(int i=0; i < 3; i++) {
        for(int j=0; j < 3; j++) {
            if(currentState.mBoard[i][j] == GameState::Empty) {
                emptySpace = true;
            }
        }
    }
    
    // no more empty spaces and no winner - tie
    if(!emptySpace) {
        return 'N';
    }
 
    // no winner yet and empty space exists, so game is not over
    return ' ';
}

