// ITP 365 Spring 2023
// HW09 – Tic-tac-toe AI
// Name: Michelle Kweon
// Email: mkweon@usc.edu
// Platform: Mac

// You can use this for the std::min / std::max functions
#include <algorithm>
#include "tttgameai.h"
#include "tttgame.h"
#include "tttgamedata.h"

bool IsGameOver(const GameState& state)
{
    float score = GetScore(state);
    if(score == 0.0) {
        for(int r=0; r < 3; r++) {
            for(int c=0; c < 3; c++) {
                if(state.mBoard[r][c] == GameState::Empty) {
                    // empty spaces left so there are spots left to use
                    return false;
                }
            }
        }
        // no spaces left and no winner so game over
        return true;
    }
    else { // score is 1.0 or -1.0 so there is a winner
        return true;
    }
}

void GenStates(GTNode* root, bool xPlayer)
{
//    // check if game over
    if(IsGameOver(root->mState)) {
        return;
    }
    
    // generate child states
    
    // iterate through all the positions of the board
    for(int i=0; i < 3; i++) {
        for(int j=0; j < 3; j++) {
            // each position that is empty should:
            // start at inputted root to create game tree
            if(root->mState.mBoard[i][j] == GameState::Empty) {
                
                // generate a new child node
                GTNode* child = new GTNode();
                
                // set childs state for board to roots board
                child->mState = root->mState;

                // Boolean indicates if it’s X’s turn.
                if(xPlayer) {
                    // If true, claim the empty child spots for X
                    child->mState.mBoard[i][j] = GameState::X;
                }
                else {
                    // if false, claim it for O
                    child->mState.mBoard[i][j] = GameState::O;
                }
                // Each state (and its subtree of states) needs to be added to the vector.
                // add the node as a child to root
                root->mChildren.push_back(child);
                
                // generate the child nodes for this child (call the function recursively)
                // !xPlayer to generate subtrees for the next player's turn
                GenStates(child, !xPlayer);
            }
        }
    }
}

float GetScore(const GameState& state)
{
    // check rows
    for(int i=0; i < 3; i++) {
        if(state.mBoard[i][0] != GameState::Empty &&
           state.mBoard[i][0] == state.mBoard[i][1] &&
           state.mBoard[i][1] == state.mBoard[i][2]){
            if(state.mBoard[i][0] == GameState::O) {
                // O wins
                return 1.0;
            }
            else { // else if(state.mBoard[i][0] == GameState::X)
                // X wins
                return -1.0;
            }
        }
    }
 
    // check column
    for(int j=0; j < 3; j++) {
        if(state.mBoard[0][j] != GameState::Empty &&
           state.mBoard[0][j] == state.mBoard[1][j] &&
           state.mBoard[1][j] == state.mBoard[2][j]){
            if(state.mBoard[0][j] == GameState::O) {
                // O wins
                return 1.0;
            }
            else {
                // X wins
                return -1.0;
            }
        }
    }
    
    // check diagonals
    if(state.mBoard[0][0] != GameState::Empty &&
       state.mBoard[0][0] == state.mBoard[1][1] &&
       state.mBoard[1][1] == state.mBoard[2][2]){
        if(state.mBoard[0][0] == GameState::O) {
            // O wins
            return 1.0;
        }
        else {
            // X wins
            return -1.0;
        }
    }
    
    if(state.mBoard[2][0] != GameState::Empty &&
       state.mBoard[2][0] == state.mBoard[1][1] &&
       state.mBoard[1][1] == state.mBoard[0][2]){
        if(state.mBoard[2][0] == GameState::O) {
            // O wins
            return 1.0;
        }
        else {
            // X wins
            return -1.0;
        }
    }
    
//    // check if empty spaces
//    bool emptySpace = false;
//    for(int r=0; r < 3; r++) {
//        for(int c=0; c < 3; c++) {
//            if(state.mBoard[r][c] == GameState::Empty) {
//                emptySpace = true;
//            }
//        }
//    }
//
//    // no empty spaces and no winner - tie
//    if(!emptySpace) {
//        return 0.0;
//    }
    
    // tie game or empty spaces
    return 0.0;
 }

float MinPlayer(const GTNode* node)
{
    // x wants to minimize score
    // x = best possible score/infinity
    float minVal = 50;
 
    // if node is a leaf node, return its score
    if(node->mChildren.empty()) { // leaf node when it has no children, so mChildren vector is empty
        return GetScore(node->mState);
    }
    // otherwise, return the smallest max score of all the child nodes (call the maxplayer function on all children)
    else {
        // check all children
        for(GTNode* child : node ->mChildren) {
            // get minimum score of branch that can yield
            // each subtree determine lowest score by looking at the worst move for the opposing player
            // find the min value given by maxplayer or finding the move the opponent can make that yields a win for the min player
            minVal = std::min(minVal, MaxPlayer(child));
        }
        return minVal;
    }
}

float MaxPlayer(const GTNode* node)
{
    float maxVal = -50;
    // if node is a leaf node, return its score
    if(node->mChildren.empty()) {
        return GetScore(node->mState);
    }
    // otherwise, return the largest min score of all the child nodes (call the minplayer function on all children)
    else {
        // check all children
        for(GTNode* child : node ->mChildren) {
            // get max score of branch that can yield - max score - best possible score
            // each subtree will try to determine highest score by looking at worst move for opposing player
            // find max value given by minplayer or finding the move the opponent can make that yield a win for max player
            maxVal = std::max(maxVal, MinPlayer(child));
        }
        return maxVal;
    }
}

const GTNode* MinimaxDecide(const GTNode* root)
{
    float max = -50;
    const GTNode* current = nullptr;
    
    // start with given (root) node, this will be current state of game
    // go through each child node of the root
    for(GTNode* child : root->mChildren) {
        // find the node with the largest MinPlayer score
        // go through each subtree and find the max value (best move for max player) as given by minplayer function
        float val = MinPlayer(child);
        
        // if child node val > current max
        if(val > max) {
            max = val; // new max
            // set current node to child node with this score
            current = child;
        }
    }
    // make the move yield the state found above
    // winning game state for O - most beneficial position
    return current;
}

unsigned changedSquare(const GameState& oldState, const GameState& newState) {
    for(int i=0; i < 3; i++) {
        for(int j=0; j < 3; j++) {
            // changed square
            if(oldState.mBoard[i][j] != newState.mBoard[i][j]) {
                // add 1 to convert from zero based index
                return (i * 3) + j + 1; // get square number that changed from index
            }
        }
    }
}

unsigned pickMove(const GameState& board)
{
    // keep track of current state of game
    GTNode* current = new GTNode();
    
    // put board into current node
    current->mState = board;
    
    // generate game tree
    GenStates(current, false);
    
    // get next best move
    const GTNode* move = MinimaxDecide(current);
    
    // return number of square that changed between the board and move
    return changedSquare(board, move->mState);
}




