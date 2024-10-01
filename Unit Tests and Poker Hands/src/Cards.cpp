// ITP 365 Spring 2023
// HW05 – Unit tests and Poker Hands
// Name: Michelle Kweon
// Email: mkweon@usc.edu
// Platform: Mac
#include "Cards.h"

#include <random>
#include <algorithm>
#include <ostream>

// Function: PokerHand Constructor
// Purpose: Draws 5 cards from the supplied deck, and sorts them by rank
// Input: Takes in a ITPVector of cards for the deck
// Returns: Nothing
PokerHand::PokerHand(std::vector<Card>& deck)
{
    // draw 5 cards from deck of cards
    for(int i=0; i <5; i++) {
        Card card = deck.back(); // draw from deck by getting from top of deck
        mHand.push_back(card); // add drawn card to hand - store to member variable
        deck.pop_back(); // remove from deck
    }

    // sort the hand by rank by calling sortHand function
    sortHand();
}

// Function: getBestPokerHand
// Purpose: Returns a string describing the poker hand this PokerHand contains
// Input: None
// Returns: The name of the best poker hand
std::string PokerHand::getBestPokerHand() const
{
    // start by checking for the best hand
    
    // straight flush
    if(hasStraight() && hasFlush()) {
        return "straight flush";
    }
    else if(hasFourOfAKind()) {
        return "four of a kind";
    }
    else if(hasFullHouse()) {
        return "full house";
    }
    else if(hasFlush()) {
        return "flush";
    }
    else if(hasStraight()) {
        return "straight";
    }
    else if(hasThreeOfAKind()) {
        return "three of a kind";
    }
    else if(hasTwoPairs()) {
        return "two pairs";
    }
    else if(hasPair()) {
        return "pair";
    }
    else {
        return "high card";
    }
}

// Function: hasStraight
// Purpose: Determines if the hand has a straight
// Input: None
// Returns: true if there's a straight
bool PokerHand::hasStraight() const
{
    bool retVal = false;
    // since it is already sorted, checks to make sure rank at index 0 is equal to one less than rank at index 1 and on...
    if ((mHand[0].mRank == mHand[1].mRank - 1) &&
        (mHand[1].mRank == mHand[2].mRank - 1) &&
        (mHand[2].mRank == mHand[3].mRank - 1) &&
        (mHand[3].mRank == mHand[4].mRank - 1)) {
        retVal = true;
    }
    return retVal;
}

// Function: hasFlush
// Purpose: Determines if the hand has a flush
// Input: None
// Returns: true if there's a flush
bool PokerHand::hasFlush() const
{

//  To check if it’s a flush, make sure the suit of every card is identical.
    bool retVal = false;
    if ((mHand[0].mSuit == mHand[1].mSuit) &&
        (mHand[1].mSuit == mHand[2].mSuit) &&
        (mHand[2].mSuit == mHand[3].mSuit) &&
        (mHand[3].mSuit == mHand[4].mSuit)) {
        retVal = true;
    }
    return retVal;
}

// Function: hasFourOfAKind
// Purpose: Determines if the hand has a 4 of a kind
// Input: None
// Returns: true if there's a 4 of a kind
bool PokerHand::hasFourOfAKind() const
{
    bool retVal = false;
    // check front 4 for same rank since it is sorted
    if ((mHand[0].mRank == mHand[1].mRank) &&
        (mHand[1].mRank == mHand[2].mRank) &&
        (mHand[2].mRank == mHand[3].mRank)) {
        return true;
    }
    // check back 4 for same rank since it is sorted
    else if ((mHand[4].mRank == mHand[3].mRank) &&
             (mHand[3].mRank == mHand[2].mRank) &&
             (mHand[2].mRank == mHand[1].mRank)) {
        return true;
    }
    return retVal;
}

// Function: hasFullHouse
// Purpose: Determines if the hand has a full house
// Input: None
// Returns: true if there's a full house
bool PokerHand::hasFullHouse() const
{
    bool retVal = false;
    // check possibility 1: x x x y y
    if ((mHand[0].mRank == mHand[1].mRank) &&
        (mHand[1].mRank == mHand[2].mRank) &&
        (mHand[3].mRank == mHand[4].mRank)) {
        return true;
    }
    // check possibility 2: x x y y y
    else if ((mHand[0].mRank == mHand[1].mRank) &&
             (mHand[2].mRank == mHand[3].mRank) &&
             (mHand[3].mRank == mHand[4].mRank)) {
        return true;
    }
    return retVal;
}

// Function: hasThreeOfAKind
// Purpose: Determines if the hand has a three of a kind
// Input: None
// Returns: true if there's a three of a kind
bool PokerHand::hasThreeOfAKind() const
{
    bool retVal = false;
    //  check possibility 1: x x x y z
    if ((mHand[0].mRank == mHand[1].mRank) &&
        (mHand[1].mRank == mHand[2].mRank)) {
        return true;
    }
    // check possibility 2: x y y y z
    else if ((mHand[1].mRank == mHand[2].mRank) &&
             (mHand[2].mRank == mHand[3].mRank)) {
        return true;
    }
    // check possibility 3: x y z z z
    else if ((mHand[2].mRank == mHand[3].mRank) &&
             (mHand[3].mRank == mHand[4].mRank)) {
        return true;
    }
    return retVal;
}

// Function: hasTwoPairs
// Purpose: Determines if the hand has two pairs
// Input: None
// Returns: true if there's two pairs
bool PokerHand::hasTwoPairs() const
{
    bool retVal = false;
    // check possibility 1: x x y y z
    if ((mHand[0].mRank == mHand[1].mRank) &&
        (mHand[2].mRank == mHand[3].mRank)) {
        return true;
    }
    // check possibility 2: x y y z z
    else if ((mHand[1].mRank == mHand[2].mRank) &&
             (mHand[3].mRank == mHand[4].mRank)) {
        return true;
    }
    // check possibility 3: x x y z z
    else if ((mHand[0].mRank == mHand[1].mRank) &&
             (mHand[3].mRank == mHand[4].mRank)) {
        return true;
    }
    return retVal;
}

// Function: hasPair
// Purpose: Determines if there's a pair
// Input: None
// Returns: true if there's a pair
bool PokerHand::hasPair() const
{
	// There’s a pair if the rank of any card is equal to the rank of its neighbor
    bool retVal = false;
    // || to get only one pair
    if ((mHand[0].mRank == mHand[1].mRank) ||
        (mHand[1].mRank == mHand[2].mRank) ||
        (mHand[2].mRank == mHand[3].mRank) ||
        (mHand[3].mRank == mHand[4].mRank)) {
        retVal = true;
    }
    return retVal;
}

// Function: sortHand
// Purpose: sorts the Cards in Hand through selection sort
// Input: none
// Returns: nothing
void PokerHand::sortHand()
{
    for (unsigned i=0; i< mHand.size()-1; i++) { // loop/go through entire vector to find smallest element from i to total vector size and compare each to sort
        // start at index i because everything before i has been sorted already
        unsigned smallestIndex = i; // make i smallest index to begin
        Card smallest = mHand[i];
        for (unsigned next = i + 1; next < mHand.size(); next++){
            // is this smaller than the current smallest?
            // if ranks are equal, check ranking of suits
            if (mHand[next].mRank == mHand[smallestIndex].mRank) {
                if (mHand[next].mSuit < mHand[smallestIndex].mSuit){ // compare rank
                    // grab smallest index and value;
                    smallestIndex = next;
                    smallest = mHand[next];
                }
            }
            else if (mHand[next].mRank < mHand[smallestIndex].mRank) { // compare rank
                // grab smallest index and value;
                smallestIndex = next;
                smallest = mHand[next];
            }
        }
        // swap
        mHand[smallestIndex] = mHand[i]; // mHand[next]
        mHand[i] = smallest; // switched in for loop if it is larger
    }
}

// Function: createDeck
// Purpose: Given an empty ITPVector of Cards, inserts a standard 52 card deck and shuffles it
// Input: An ITPVector of Cards (by reference)
// Returns: nothing
void createDeck(std::vector<Card>& deck)
{
    // fill vector with a standard 52 card deck
    // grab the suit
    for(int i=0; i<4; i++) {
        Suit suit = Suit(i);
        // grab the rank for each suit
        for(int rank=2; rank <= 14; rank++){
            deck.push_back(Card(rank, suit)); // fill vector of cards
        }
    }
    
    // shuffle the deck
    std::sort(&deck[0], &deck[0] + deck.size());
    std::random_shuffle(&deck[0], &deck[0] + deck.size());
}

// Function: << operator for Card
// Purpose: Outputs the name and suit of the card
// Input: ostream and card
// Returns: ostream, with card data output to it
std::ostream& operator<<(std::ostream& os, const Card& card)
{
    std::string rankName;
//    if (card.mRank < 11 ) { // cards 2 - 10
//       rankName = card.mRank;
//    }
//    else { // face card
        switch (card.mRank) {
            case 2:
                rankName = "2";
                break;
            case 3:
                rankName = "3";
                break;
            case 4:
                rankName = "4";
                break;
            case 5:
                rankName = "5";
                break;
            case 6:
                rankName = "6";
                break;
            case 7:
                rankName = "7";
                break;
            case 8:
                rankName = "8";
                break;
            case 9:
                rankName = "9";
                break;
            case 10:
                rankName = "10";
                break;
            case 11:
                rankName = "Jack";
                break;
            case 12:
                rankName = "Queen";
                break;
            case 13:
                rankName = "King";
                break;
            case 14:
                rankName = "Ace";
                break;
            default:
                rankName = "Invalid";
                break;
//        }
    }
    
    std::string suitName;
    switch (card.mSuit) {
        case CLUBS:
            suitName = "Clubs";
            break;
        case DIAMONDS:
            suitName = "Diamonds";
            break;
        case HEARTS:
            suitName = "Hearts";
            break;
        case SPADES:
            suitName = "Spades";
            break;
    }
    return os << rankName + " of " + suitName;
}


// Function: < comparison operator for Card
// Purpose: Compares the value of the left and right card
// Input: Two cards to compare
// Returns: true if left < right
bool operator<(const Card& left, const Card& right)
{
    // if rankings equal, compare suit
    if (left.mRank == right.mRank) {
        return left.mSuit < right.mSuit;
    }
    else {
        // compare rankings
        return left.mRank < right.mRank;
    }
}

// Function: > comparison operator for Card
// Purpose: Compares the value of the left and right card
// Input: Two cards to compare
// Returns: true if left > right
bool operator>(const Card& left, const Card& right)
{
    // if rankings equal, compare suit
    if (left.mRank == right.mRank) {
        return left.mSuit > right.mSuit;
    }
    else {
        // compare rankings
        return left.mRank > right.mRank;
    }
}

// Function: << operator
// Purpose: Prints out the hand
std::ostream& operator<<(std::ostream& os, const PokerHand& hand)
{
    os << "{";
    // bool to keep track whether to add comma before element
    // used to avoid comma at the end
    bool first = true;
    
    for(const auto& card : hand.mHand) {
        // adds comma before card if it is not first item
        if(!first) {
            os << ",";
        }
        else {
            first = false;
        }
        os << " " << card;
    }
    os << " }";
    return os;
}
