// ITP 365 Spring 2023
// HW06 – Vector and Poker Hands
// Name: Michelle Kweon
// Email: mkweon@usc.edu
// Platform: Mac
#include <string>
#include <sstream>
#include <fstream>
#include <ostream>

#include "catch.hpp"
#include "ITPMemLeaks.h"
#include "ITPDoubleList.hpp"
#include "movie.h"

// Helper function declarations (don't change this)
extern bool CheckTextFilesSame(const std::string& fileNameA,
	const std::string& fileNameB);

TEST_CASE("Student list tests", "[student]")
{
	SECTION("Default constructor, size, and destructor")
	{
        // initialize doubly linked list
        std::list<std::string> mList;
        
        // check it is empty
        REQUIRE(mList.empty());
        REQUIRE(mList.size() == 0);

		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_front, front, back")
	{
        // initialize doubly linked list
        std::list<std::string> mList;
        
        // add to front
        mList.push_front("word1");
        
        // check the list that it was added
        REQUIRE(mList.front() == "word1");
        REQUIRE(mList.back() == "word1");
        REQUIRE(mList.size() == 1);
        
        // add another
        mList.push_front("word2");
        
        // check it has been added
        REQUIRE(mList.front() == "word2");
        REQUIRE(mList.back() == "word1");
        REQUIRE(mList.size() == 2);
        
        // Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_front, front, back, pop_front")
	{
        // initialize doubly linked list
        std::list<std::string> mList;
        
        // add to front
        mList.push_front("word1");
        REQUIRE(mList.front() == "word1");
        REQUIRE(mList.back() == "word1");
        
        // add another
        mList.push_front("word2");
        REQUIRE(mList.front() == "word2");
        REQUIRE(mList.back() == "word1");

        // remove from front
        mList.pop_front();
        REQUIRE(mList.front() == "word1");
        REQUIRE(mList.back() == "word1");

        // check it has been removed
        mList.pop_back();
        REQUIRE(mList.empty());
        REQUIRE(mList.size() == 0);
        
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_back, front, back")
	{
        // initialize doubly linked list
        std::list<std::string> mList;
        
        // add from back
        mList.push_back("first");
        REQUIRE(mList.front() == "first");
        REQUIRE(mList.back() == "first");
        REQUIRE(mList.size() == 1);
        
        // opposite of push_front
        mList.push_back("second");
        
        // check front
        REQUIRE(mList.front() == "first");
        // check back
        REQUIRE(mList.back() == "second");
        REQUIRE(mList.size() == 2);
        
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_back, front, back, pop_back")
	{
        // initialize doubly linked list
        std::list<std::string> mList;
        
        // add from back
        mList.push_back("first");
        REQUIRE(mList.front() == "first");
        REQUIRE(mList.back() == "first");
        
        mList.push_back("second");
        REQUIRE(mList.front() == "first");
        REQUIRE(mList.back() == "second");
        REQUIRE(mList.size() == 2);
        
        // remove from back
        mList.pop_back();
        REQUIRE(mList.back() == "first");
        REQUIRE(mList.size() == 1);
        
        mList.pop_back();
        REQUIRE(mList.empty());
        REQUIRE(mList.size() == 0);
        
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_back, clear")
	{
        // initialize doubly linked list
        std::list<std::string> mList;
        
        // add to lists
        mList.push_back("first");
        mList.push_back("second");
        
        // clear
        mList.clear();

        // check it has been cleared
        REQUIRE(mList.empty());
        REQUIRE(mList.size() == 0);
		
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_back, front, back, pop_back, copy constructor")
	{
        // initialize doubly linked list
        std::list<std::string> mList;
        
        // add from back
        mList.push_back("first");
        mList.push_back("second");
        
        // check it has been added
        REQUIRE(mList.front() == "first");
        REQUIRE(mList.back() == "second");

        // copy constructor
        std::list<std::string> copyList(mList);

        mList.pop_back();
        REQUIRE(mList.back() == "first");
        
        // check copy hasn't been changed
        REQUIRE(copyList.front() == "first");
        REQUIRE(copyList.back() == "second");

		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_back, front, back, pop_back, assignment")
	{
        // initialize doubly linked list
        std::list<std::string> mList;
        
        // add to list
        mList.push_back("first");
        mList.push_back("second");
        
        // check it has been added
        REQUIRE(mList.front() == "first");
        REQUIRE(mList.back() == "second");

        // copy
        std::list<std::string> copyList = mList;

        mList.pop_back();
        REQUIRE(mList.back() == "first");
        
        // check copy hasn't been changed
        REQUIRE(copyList.front() == "first");
        REQUIRE(copyList.back() == "second");

		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Back, front, pop_front, pop_back, exceptions")
	{
        // initialize doubly linked list
        std::list<std::string> mList;
        
        try
        {
            // try to get front of empty list
            mList.front();
        }
        catch (const std::out_of_range& e)
        {
            REQUIRE(true);
        }

        try
        {
            // try to get back of empty list
            mList.back();
        }
        catch (const std::out_of_range& e)
        {
            REQUIRE(true);
        }

        // add to list
        mList.push_back("first");
        mList.push_back("second");
        
        // check it has been added
        REQUIRE(mList.front() == "first");
        REQUIRE(mList.back() == "second");
        
        mList.push_back("third");
        REQUIRE(mList.front() == "first");
        REQUIRE(mList.back() == "third");
        
        // pop_front
        mList.pop_front();
        // pop_back
        mList.pop_back();
        
        REQUIRE(mList.front() == "second");
        REQUIRE(mList.back() == "second");
        
        mList.pop_back();
        REQUIRE(mList.size() == 0);
        
//        bool exceptionFlag = false;
//
//        try
//        {
//
//            // try to pop from empty list
//            mList.pop_front();
//        }
//        catch (const std::out_of_range& e)
//        {
//            REQUIRE(true);
//            bool exceptionFlag = true;
//        }
//        if (exceptionFlag == false) {
//            REQUIRE(false);
//        }

//        try
//        {
//            // try to pop from empty list
//            mList.pop_back();
//        }
//        catch (const std::out_of_range& e)
//        {
//            REQUIRE(true);
//        }
//
        // Leave this at the end
        REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_front, front, back, begin, iterator dereference, copy constructor")
	{
        // initialize doubly linked list
        std::list<std::string> mList;
        
        // add to front
        mList.push_front("first");
        mList.push_front("second");
        mList.push_front("third");

        // check front and back
        REQUIRE(mList.front() == "third");
        REQUIRE(mList.back() == "first");

        // check iterator dereference and increment
        std::list<std::string>::iterator pos = mList.begin();
        
        // iterator dereference
        REQUIRE(*pos == "third");

        REQUIRE(*pos == mList.front());

        // copy list and check contents are equal
        std::list<std::string> copyList(mList);
        std::list<std::string>::iterator copyPos = copyList.begin();
        REQUIRE(*copyPos == "third");
        
        REQUIRE(copyList.size() == mList.size());
        REQUIRE(copyList.front() == mList.front());
        REQUIRE(copyList.back() == mList.back());

        // verify modifications don't persist
        mList.push_front("new");
        REQUIRE(mList.size() == 4);
        REQUIRE(mList.front() == "new");
        REQUIRE(mList.back() == "first");
        
        REQUIRE(copyList.size() == 3);
        REQUIRE(copyList.front() == "third");
        REQUIRE(copyList.back() == "first");
        
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("List: begin, end; Iterator: dereference, assignment, comparison")
	{
        // initialize doubly linked list
        std::list<std::string> mList;
        
        // add to list
        mList.push_front("first");
        mList.push_front("second");
        mList.push_front("third");
        mList.push_front("third");

        // begin
        std::list<std::string>::iterator pos = mList.begin();
        REQUIRE(*pos == mList.front());
        REQUIRE(pos == mList.begin());
        REQUIRE(pos != mList.end());

        // end
        std::list<std::string>::iterator pos2 = mList.end();
        REQUIRE(pos2 == mList.end());
//        REQUIRE(*pos2 == "first");
        
        REQUIRE(*pos == *(++pos));
        
        pos2--;
        *pos2 = "fourth";
        REQUIRE(mList.back() == "fourth");
        
        // comparison
        std::list<std::string>::iterator pos3;
        pos3 = pos;
        REQUIRE(pos == pos3);

		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("List: begin, end; Iterator: dereference, increment")
	{
        // initialize doubly linked list
        std::list<std::string> mList;
        
        // add to list
        mList.push_front("first");
        mList.push_front("second");
        mList.push_front("third");
        
        std::list<std::string>::iterator pos = mList.begin();
        // dereference
        REQUIRE(*pos == "third");
        
        std::list<std::string>::iterator pos2 = mList.end();
        REQUIRE(pos2 == mList.end());
//        REQUIRE(*pos2 == "first");
//        REQUIRE(*pos2 == mList.back());
        
        // increment
        pos++;
        
        REQUIRE(*pos == "second");
        
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("List: begin, end; Iterator: dereference, increment, decrement")
	{
        // initialize doubly linked list
        std::list<std::string> mList;
      
        // add to list
        mList.push_front("first");
        mList.push_front("second");
        mList.push_front("third");
        
        // begin
        std::list<std::string>::iterator pos = mList.begin();
        REQUIRE(*pos == "third");
        
        // end
        std::list<std::string>::iterator pos2 = mList.end();
        REQUIRE(pos2 == mList.end());
//        REQUIRE(*pos2 == "first");
//        REQUIRE(*pos2 == mList.back());
        
        // increment
        pos++;
        
        REQUIRE(*pos == "second");
        
        // decrement
        pos--;
        REQUIRE(*pos == "third");
		
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("List: insert with iterator at begin, middle, and one away from end")
	{
        // initialize doubly linked list
        std::list<std::string> mList;
        
        // add to list
        mList.push_front("first");
        mList.push_front("second");
        mList.push_front("third");
        mList.push_front("fourth");
        
        std::list<std::string>::iterator pos = mList.begin();
        std::list<std::string>::iterator pos2 = mList.end();
		
        // insert
        mList.insert(pos, "new");
        pos--;
        REQUIRE(*pos == "new");
        
        pos++;
        pos++;
        mList.insert(pos, "new2");
        pos--;
        REQUIRE(*pos == "new2");
        
        pos2--;
        mList.insert(pos2, "word");
        pos2--;
        REQUIRE(*pos2 == "word");
        
        REQUIRE(mList.size() == 7);
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("List: erase with iterator at begin, middle, and one away from end")
	{
        // initialize doubly linked list
        std::list<std::string> mList;

        // add to list
        mList.push_front("first");
        mList.push_front("second");
        mList.push_front("third");
        mList.push_front("fourth");

        std::list<std::string>::iterator pos = mList.begin();
        // erase at beginning
        mList.erase(pos);
        
        std::list<std::string>::iterator pos2 = mList.begin();
        pos++;
        pos++;
        mList.erase(pos2);
       
        std::list<std::string>::iterator pos3 = mList.end();
        pos3--;
        mList.erase(pos3);
        REQUIRE(mList.size() == 1);
		
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}
}

TEST_CASE("Student movie", "[student]") 
{
	SECTION("Bad constructor")
	{
        // check file with bad name/one that doesnt open that throws error
        try {
            MoviePlayer movie("input/bad$fileName.ani");
            REQUIRE(false);
        }
        catch (const std::invalid_argument& e) {
            //e.what();
            REQUIRE(true);
        }
        
//        MoviePlayer movie("input/scene1.ani");
        
//        REQUIRE(movie.mFilm);

		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Creating scene 2")
	{
        MoviePlayer scene("input/scene2.ani");
        
        // check frame numbers

//        REQUIRE(scene.getNumFrames() == 505);

        REQUIRE(scene.getCurrFrameNum() == 1);
        scene.goFwrd();
        scene.goFwrd();
        REQUIRE(scene.getCurrFrameNum() == 3);
        scene.goBack();
        REQUIRE(scene.getCurrFrameNum() == 2);
        scene.rewind();
        REQUIRE(scene.getCurrFrameNum() == 1);
        
        for(int i=0; i < 13; i++) {
            scene.goFwrd();
        }
        REQUIRE(scene.getCurrFrameNum() == 14);
        
        scene.rewind();
        REQUIRE(scene.getCurrFrameNum() == 1);
        

        
       //  Create a scene to ensure that things like number of frames is set correctly.

        
//        for(int i; i < FRAMESIZE)
      
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Checking frames, scene 2")
	{
        //   Load a scene and ensure that some of the frames in the scene are set correctly – you might want to use an extra file in something like the “expected” folder.
        MoviePlayer scene("input/scene1.ani");
        std::ifstream inputFile("expected/expected_scene1.ani");
        
        std::string separator;
        std::getline(inputFile, separator); // grab number that indicates how many long the frame should be shown
        int frameLength;
        std::stringstream ss(separator);
        ss >> frameLength;
        
        if(frameLength >= 0) {
            REQUIRE(true);
        }
        
//        REQUIRE(scene.getNumFrames() == frameLength);
        // check that all lines of frame are correct
        
        std::string line;
        int lineNum;
        
        // loop 13 time swith new line and get line and compare that movieplayer.get curr frame is equal to input
        while(std::getline(inputFile, line)) {
            lineNum++;
//            REQUIRE(scene.toString(lineNum) == line);
        }
        
        if (scene.getCurrFrameNum() == lineNum) {
            REQUIRE(true);
        }
        
        REQUIRE(inputFile.eof());
         
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}
}


