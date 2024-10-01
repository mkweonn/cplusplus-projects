// ITP 365 Spring 2023
// HW05 – Unit tests and Poker Hands
// Name: Michelle Kweon
// Email: mkweon@usc.edu
// Platform: Mac

#include "catch.hpp"
#include <vector>
#include "Cards.h"
#include <sstream>

// Helper function declarations (don't change this)
extern bool CheckTextFilesSame(const std::string& fileNameA,
	const std::string& fileNameB);

// Your tests
TEST_CASE("Vector tests", "[student]") 
{
	// Complete tests are worth 2 points for each test
    
	SECTION("Default constructor, size, empty")
	{
        // initialize empty vector
        std::vector<int> vec;
        
        // check is 0
        REQUIRE(vec.size() == 0);
        
        // check vector is empty
        REQUIRE(vec.empty());
	}

	SECTION("Push_back x1, back, pop_back")
	{
        // initialize empty vector
        std::vector<int> vec;
        
        // pushing back/adding one item
        vec.push_back(7);
        
        // checking it was added
        REQUIRE(vec.size() == 1);
       
        // checking vector has that item by checking last item in vector
        REQUIRE(vec.back() == 7);
        
        // popping back/removing last item
        vec.pop_back();
        
        // check is 0
        REQUIRE(vec.size() == 0);
        
        // check item was removed
        REQUIRE(vec.empty());
	}

	SECTION("Push_back x3, operator[]")
	{
        // initialize empty vector
        std::vector<int> vec;
        
        // add three item to the vector
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        
        // check all 3 items added
        REQUIRE(vec.size() == 3);
        
        // check items are added correctly in vector with operator[]
        REQUIRE(vec[0] == 1);
        REQUIRE(vec[1] == 2);
        REQUIRE(vec[2] == 3);
	}

	SECTION("Push_back, operator[] (with assignment)")
	{
        // initialize empty vector
        std::vector<int> vec;
        
        // add item
        vec.push_back(7);
        
        // checking it was added
        REQUIRE(vec.size() == 1);
        
        // checking vector has that item by checking last item in vector
        REQUIRE(vec.back() == 7);
        
        // modify with assignment
        vec[0] = 8;
        
        // check value is modified
		REQUIRE(vec.back() == 8);
	}

	SECTION("Clear")
	{
        // initialize empty vector
        std::vector<int> vec;
        
        // add items to vector
        vec.push_back(1);
        vec.push_back(2);

        // clear vector
        vec.clear();
        
        // check it is empty
        REQUIRE(vec.size() == 0);
        REQUIRE(vec.empty());
	}

// not needed according to piazza
//	SECTION("Copy constructor deep copies")
//	{
//        REQUIRE(true);
//        // TODO: Tests go here
//	}
//
//	SECTION("Assignment operator deep copies")
//	{
//        REQUIRE(true);
//        // TODO: Tests go here
//	}

	// Complete tests for this section is worth 14 points
}

// test several cards to make sure the struct works correctly
TEST_CASE("Card tests", "[student]")
{
	// Complete tests are worth 2 points for each test
	
	SECTION("Card constructors")
	{
        // check default constructor
        Card defaultCard;
        REQUIRE(defaultCard.mRank == 2);
        REQUIRE(defaultCard.mSuit == CLUBS);
		
        Card card2 = Card(11, HEARTS);
        REQUIRE(card2.mRank == 11);
        REQUIRE(card2.mSuit == HEARTS);
        
        Card card3 = Card(6, DIAMONDS);
        REQUIRE(card3.mRank == 6);
        REQUIRE(card3.mSuit == DIAMONDS);
        
	}

	SECTION("Output stream")
	{
        std::ostringstream out1;
        Card card1 = Card(3, DIAMONDS);
        out1 << card1;
		REQUIRE(out1.str() == "3 of Diamonds");
        
        std::ostringstream out2;
        Card card2 = Card(11, SPADES);
        out2 << card2;
        REQUIRE(out2.str() == "Jack of Spades");
        
        std::ostringstream out3;
        Card card3 = Card(6, CLUBS);
        out3 << card3;
        REQUIRE(out3.str() == "6 of Clubs");
	}

	SECTION("Card comparisons")
	{
        Card card1 = Card(3, DIAMONDS);
        Card card2 = Card(3, SPADES);
        Card card3 = Card(4, DIAMONDS);
		REQUIRE(card2 > card1);
        REQUIRE(card3 > card2);
        REQUIRE(card3 > card1);
        REQUIRE(card1 < card2);
        REQUIRE(card1 < card3);
        REQUIRE(card2 < card3);
	}
	// Complete tests for this section is worth 6 points
}

// testing at least 1 hand is required
// creating a vector with 5 specific cards on the top to pass into the PokerHand constructor to test different hand combinations
TEST_CASE("Poker hand tests", "[student]")
{
	// Complete tests are worth 2 points for each test
	
	SECTION("Poker hand constructor and stream output")
	{
        std::vector<Card> handDeck = {Card(2, HEARTS), Card(3, DIAMONDS), Card(11, HEARTS), Card(6, CLUBS), Card(13, SPADES)};
        PokerHand deck(handDeck);
    
        std::ostringstream out;
        out << deck;
        REQUIRE(out.str() == "{ 2 of Hearts, 3 of Diamonds, 6 of Clubs, Jack of Hearts, King of Spades }");
	}

	SECTION("High card")
	{
        std::vector<Card> handDeck = {Card(3, CLUBS), Card(8, DIAMONDS), Card(9, SPADES), Card(6, DIAMONDS), Card(7, SPADES)};
        PokerHand deck(handDeck);
		REQUIRE(deck.getBestPokerHand() == "high card");
	}

	SECTION("Pair")
	{
        std::vector<Card> handDeck = {Card(8, HEARTS), Card(5, HEARTS), Card(14, SPADES), Card(8, DIAMONDS), Card(12, SPADES)};
        PokerHand deck(handDeck);
        REQUIRE(deck.getBestPokerHand() == "pair");
        REQUIRE(deck.hasPair());

	}

	SECTION("Two pair")
	{
        std::vector<Card> handDeck = {Card(3, HEARTS), Card(9, CLUBS), Card(9, DIAMONDS), Card(10, DIAMONDS), Card(10, SPADES)};
        PokerHand deck(handDeck);
        REQUIRE(deck.getBestPokerHand() == "two pairs");
        REQUIRE(deck.hasTwoPairs());
	}

	SECTION("Three of a kind")
	{
        std::vector<Card> handDeck = {Card(2, CLUBS), Card(8, CLUBS), Card(8, DIAMONDS), Card(8, SPADES), Card(11, SPADES)};
        PokerHand deck(handDeck);
        REQUIRE(deck.getBestPokerHand() == "three of a kind");
        REQUIRE(deck.hasThreeOfAKind());
	}

	SECTION("Straight")
	{
        std::vector<Card> handDeck = {Card(10, HEARTS), Card(6, HEARTS), Card(9, CLUBS), Card(8, DIAMONDS), Card(7, SPADES)};
        PokerHand deck(handDeck);
        REQUIRE(deck.getBestPokerHand() == "straight");
        REQUIRE(deck.hasStraight());
	}

	SECTION("Flush")
	{
        std::vector<Card> handDeck = {Card(13, CLUBS), Card(10, CLUBS), Card(8, CLUBS), Card(7, CLUBS), Card(5, CLUBS)};
        PokerHand deck(handDeck);
        REQUIRE(deck.getBestPokerHand() == "flush");
        REQUIRE(deck.hasFlush());
	}

	SECTION("Full house")
	{
        std::vector<Card> handDeck = {Card(14, HEARTS), Card(14, CLUBS), Card(14, DIAMONDS), Card(3, SPADES), Card(3, HEARTS)};
        PokerHand deck(handDeck);
        REQUIRE(deck.getBestPokerHand() == "full house");
        REQUIRE(deck.hasFullHouse());
	}

	SECTION("Four of a kind")
	{
        std::vector<Card> handDeck = {Card(9, HEARTS), Card(9, CLUBS), Card(9, DIAMONDS), Card(9, SPADES), Card(13, HEARTS)};
        PokerHand deck(handDeck);
        REQUIRE(deck.getBestPokerHand() == "four of a kind");
        REQUIRE(deck.hasFourOfAKind());
	}

	SECTION("Straight flush")
	{
        std::vector<Card> handDeck = {Card(11, SPADES), Card(10, SPADES), Card(9, SPADES), Card(8, SPADES), Card(7, SPADES)};
        PokerHand deck(handDeck);
        REQUIRE(deck.getBestPokerHand() == "straight flush");
        REQUIRE(deck.hasStraight());
        REQUIRE(deck.hasFlush());
	}

	// Complete tests for this section is worth 20 points
}
