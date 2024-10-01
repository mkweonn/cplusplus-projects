// ITP 365 Spring 2023
// HW06 – Vector and Poker Hands
// Name: Michelle Kweon
// Email: mkweon@usc.edu
// Platform: Mac
#include "catch.hpp"

#include "Cards.h"
#include "ITPVector.hpp"

// Helper function declarations (don't change this)
extern bool CheckTextFilesSame(const std::string& fileNameA,
	const std::string& fileNameB);

// Your tests
TEST_CASE("Vector tests", "[student]") 
{
    // Complete tests are worth 2 points for each test
    
        SECTION("Default constructor, size, capacity, and destructor")
        {
            // initialize vector
            ITPVector<unsigned> vec = ITPVector<unsigned>();
            
            // check capacity is equal to inital capacity
            REQUIRE(vec.capacity() == 10);
            
            // check size is 0
            REQUIRE(vec.size() == 0);
            
            // check vector is empty
            REQUIRE(vec.empty());
            
        }
            
        SECTION("Parameterized constructor, size, capacity, and destructor")
        {
            // initialize vector
            ITPVector<unsigned> vec = ITPVector<unsigned>(15);
            
            // make vector of capacity
            REQUIRE(vec.capacity() == 15);
            
            // check size is 0
            REQUIRE(vec.size() == 0);
            
        }
            
        SECTION("Push_back x1, back, pop_back, destructor")
        {
            // initialize vector
            ITPVector<unsigned> vec = ITPVector<unsigned>();
            
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
        
        SECTION("Push_back x3, operator[], destructor")
        {
            // initialize empty vector
            ITPVector<unsigned> vec = ITPVector<unsigned>();
            
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
        
        SECTION("Push_back (over capacity), size, capacity, destructor")
        {
            // initialize empty vector
            ITPVector<unsigned> vec = ITPVector<unsigned>(4);
            
            // add three item to the vector
            vec.push_back(1);
            vec.push_back(2);
            vec.push_back(3);
            vec.push_back(4);
            
            REQUIRE(vec.size() == 4);
            REQUIRE(vec.capacity() == 4);
            
            // push one more past capacity
            vec.push_back(5);
            
            // check it was added and capacity multiplied
            REQUIRE(vec.size() == 5);
            REQUIRE(vec.capacity() == 8);
            
        }
        
        SECTION("Push_back (over capacity), operator[], destructor")
        {
            // initialize empty vector
            ITPVector<unsigned> vec = ITPVector<unsigned>(4);
            
            // add items to the vector
            vec.push_back(1);
            vec.push_back(2);
            vec.push_back(3);
            vec.push_back(4);
            vec.push_back(5);
            
            REQUIRE(vec.size() == 5);
            REQUIRE(vec.capacity() == 8);
            
            // check items are added correctly in vector with operator[]
            REQUIRE(vec[0] == 1);
            REQUIRE(vec[1] == 2);
            REQUIRE(vec[2] == 3);
            REQUIRE(vec[3] == 4);
            REQUIRE(vec[4] == 5);
            
        }
        
        SECTION("Push_back, pop_back, back, operator[], exceptions")
        {
            // initialize empty vector
            ITPVector<unsigned> vec = ITPVector<unsigned>(1);
            
            try
            {
                vec.push_back(1);
                vec.push_back(1);
            }
            catch (const std::out_of_range& e)
            {
                // above size
                REQUIRE(true);
            }
        
            try
            {
                vec.pop_back();
            }
            catch (const std::out_of_range& e)
            {
                // no elements return error
                REQUIRE(true);
            }
            
            try
            {
                vec.back();
            }
            catch (const std::out_of_range& e)
            {
                // no elements return error
                REQUIRE(true);
            }
            
            try
            {
                // over size
                vec[4] = 1;
            }
            catch (const std::out_of_range& e)
            {
                // return error
                REQUIRE(true);
            }
            
            try
            {
                // since < 0
                vec[-1] = 1;
            }
            catch (const std::out_of_range& e)
            {
                // return error
                REQUIRE(true);
            }
        }
        
        SECTION("Push_back (over capacity), operator[] (with assignment), destructor")
        {
            // initialize empty vector
            ITPVector<unsigned> vec = ITPVector<unsigned>(3);
            
            // add item
            vec.push_back(1);
            vec.push_back(2);
            vec.push_back(3);
            vec.push_back(4);
            
            // checking it was added
            REQUIRE(vec.size() == 4);
            REQUIRE(vec.capacity() == 6);
            
            // checking vector has that item by checking last item in vector
            REQUIRE(vec.back() == 4);
            
            // modify with assignment
            vec[3] = 8;
            
            // check value is modified
            REQUIRE(vec.back() == 8);
        }
        
        SECTION("Clear")
        {
            // initialize empty vector
            ITPVector<unsigned> vec = ITPVector<unsigned>();
            
            // add items to vector
            vec.push_back(1);
            vec.push_back(2);
            
            // clear vector
            vec.clear();
            
            // check it is empty
            REQUIRE(vec.size() == 0);
            REQUIRE(vec.empty());
        }
        
        //	SECTION("Destructor")
        //	{
        //		REQUIRE(true);
        //		// TODO: Tests go here
        //	}
        
        SECTION("Copy constructor deep copies")
        {
            ITPVector<unsigned> vec1 = ITPVector<unsigned>(5);
            vec1.push_back(1);
            vec1.push_back(2);
            vec1.push_back(3);
//            vec1[0] = 1;
//            vec1[1] = 2;
//            vec1[2] = 3;
            
            // copy vec1 to another vector using copy constructor
            ITPVector<unsigned> vec2 = ITPVector<unsigned>(vec1);
            REQUIRE(vec1[0] == vec2[0]);
            REQUIRE(vec1[1] == vec2[1]);
            REQUIRE(vec1[2] == vec2[2]);
            REQUIRE(vec2.size() == 3);
            vec2[1] = 4;
            REQUIRE(vec1[1] != vec2[1]);
        }
        
        SECTION("Assignment operator deep copies")
        {
            ITPVector<unsigned> vec1 = ITPVector<unsigned>(5);
            vec1.push_back(1);
            vec1.push_back(2);
            vec1.push_back(3);
//            vec1[0] = 1;
//            vec1[1] = 2;
//            vec1[2] = 3;
            
            // copy vec1 to another vector for assignement operator copy
            ITPVector<unsigned> vec2 = vec1;
            REQUIRE(vec1[0] == vec2[0]);
            REQUIRE(vec1[1] == vec2[1]);
            REQUIRE(vec1[2] == vec2[2]);
            REQUIRE(vec2.size() == 3);
        }
        
        // Complete tests for this section is worth 24 points
}

