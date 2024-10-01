// ITP 365 Spring 2023
// HW08 – Doubly Linked List and Movie Player
// Name: Michelle Kweon
// Email: mkweon@usc.edu
// Platform: Mac

#include "catch.hpp"
#include "ITPMemLeaks.h"
#include "ITPDoubleList.hpp"
#include "movie.h"
#include <fstream>

// Helper function declarations (don't change this)
extern bool CheckTextFilesSame(const std::string& fileNameA,
	const std::string& fileNameB);

TEST_CASE("Student list tests", "[student]")
{
	SECTION("Default constructor, size, and destructor")
	{
        {
            // initialize doubly linked list
            ITPDoubleList<std::string> mList = ITPDoubleList<std::string>();

            // check if size is set to 0
            REQUIRE(mList.size() == 0);
//            REQUIRE(mList.empty());
        }
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_front, front, back")
	{
        {
            // initialize doubly linked list
            ITPDoubleList<std::string> mList = ITPDoubleList<std::string>();

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
        }
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_front, front, back, pop_front")
	{
        {
            // initialize doubly linked list
            ITPDoubleList<std::string> mList = ITPDoubleList<std::string>();

            // add to front
            mList.push_front("word1");
            REQUIRE(mList.front() == "word1");
            REQUIRE(mList.back() == "word1");
            REQUIRE(mList.size() == 1);

            // add another
            mList.push_front("word2");
            REQUIRE(mList.front() == "word2");
            REQUIRE(mList.back() == "word1");
            REQUIRE(mList.size() == 2);

            // remove from front
            mList.pop_front();
            REQUIRE(mList.front() == "word1");
            REQUIRE(mList.back() == "word1");
            REQUIRE(mList.size() == 1);

            // check it has been removed
            mList.pop_front();
            //        REQUIRE(mList.empty());
            REQUIRE(mList.size() == 0);
        }
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_back, front, back")
	{
        {
            // initialize doubly linked list
            ITPDoubleList<std::string> mList = ITPDoubleList<std::string>();

            // add from back
            mList.push_back("first");
            
            // check item was added
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
        }
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_back, front, back, pop_back")
	{
        {
            // initialize doubly linked list
            ITPDoubleList<std::string> mList = ITPDoubleList<std::string>();

            // add from back
            mList.push_back("first");
            REQUIRE(mList.front() == "first");
            REQUIRE(mList.back() == "first");
            REQUIRE(mList.size() == 1);

            mList.push_back("second");
            REQUIRE(mList.front() == "first");
            REQUIRE(mList.back() == "second");
            REQUIRE(mList.size() == 2);

            // remove from back
            mList.pop_back();
            REQUIRE(mList.front() == "first");
            REQUIRE(mList.back() == "first");
            REQUIRE(mList.size() == 1);

            // check it has been removed
            mList.pop_back();
            //        REQUIRE(mList.empty());
            REQUIRE(mList.size() == 0);
        }
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_back, clear")
	{
        {
            // initialize doubly linked list
            ITPDoubleList<std::string> mList = ITPDoubleList<std::string>();

            // add to lists
            mList.push_back("first");
            mList.push_back("second");
            REQUIRE(mList.size() == 2);

            // clear
            mList.clear();

            // check it has been cleared
            //        REQUIRE(mList.empty());
            REQUIRE(mList.size() == 0);
        }
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_back, front, back, pop_back, copy constructor")
	{
        {
            // initialize doubly linked list
            ITPDoubleList<std::string> mList = ITPDoubleList<std::string>();

            // add from back
            mList.push_back("first");
            mList.push_back("second");

            // check it has been added
            REQUIRE(mList.front() == "first");
            REQUIRE(mList.back() == "second");
            REQUIRE(mList.size() == 2);

            // copy constructor
            ITPDoubleList<std::string> copyList(mList);

            mList.pop_back();
            REQUIRE(mList.back() == "first");

            // check copy hasn't been changed
            REQUIRE(copyList.front() == "first");
            REQUIRE(copyList.back() == "second");
        }
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_back, front, back, pop_back, assignment")
	{
        {
            // initialize doubly linked list
            ITPDoubleList<std::string> mList = ITPDoubleList<std::string>();

            // add to list
            mList.push_back("first");
            mList.push_back("second");

            // check it has been added
            REQUIRE(mList.front() == "first");
            REQUIRE(mList.back() == "second");
            REQUIRE(mList.size() == 2);

            // copy
            ITPDoubleList<std::string> copyList = mList;

            mList.pop_back();
            REQUIRE(mList.back() == "first");

            // check copy hasn't been changed
            REQUIRE(copyList.front() == "first");
            REQUIRE(copyList.back() == "second");
        }
        
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Back, front, pop_front, pop_back, exceptions")
	{
        {
            // initialize doubly linked list
            ITPDoubleList<std::string> mList = ITPDoubleList<std::string>();

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

//            bool exceptionFlag = false;
            try
            {
                // try to get front of empty list
                mList.pop_front();
            }
            catch (const std::out_of_range& e)
            {
                REQUIRE(true);
//                bool exceptionFlag = true;
            }
//            if (exceptionFlag == false) {
//                REQUIRE(false);
//            }

            try
            {
                // try to get back of empty list
                mList.pop_back();
            }
            catch (const std::out_of_range& e)
            {
                REQUIRE(true);
            }
        }
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Push_front, front, back, begin, iterator dereference, copy constructor")
	{
        {
            // initialize doubly linked list
            ITPDoubleList<std::string> mList = ITPDoubleList<std::string>();

            // add to front
            mList.push_front("first");
            mList.push_front("second");
            mList.push_front("third");

            // check front and back
            REQUIRE(mList.front() == "third");
            REQUIRE(mList.back() == "first");
            REQUIRE(mList.size() == 3);

            // check iterator dereference and increment
            // initialize iterator
            ITPDoubleList<std::string>::Iterator pos = mList.begin();

            // iterator dereference to get value at beginning
            REQUIRE(*pos == "third");
            REQUIRE(*pos == mList.front());
            
            pos++;
            // iterator dereference to get value next
            REQUIRE(*pos == "second");
            
            // copy list and check contents are equal
            ITPDoubleList<std::string> copyList(mList);
            ITPDoubleList<std::string>::Iterator copyPos = copyList.begin();
            REQUIRE(*copyPos == "third");
            REQUIRE(copyList.size() == 3);
            
            copyPos++;
            // iterator dereference to get value next
            REQUIRE(*copyPos == "second");

            // check copy elements equal
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
        }
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("List: begin, end; Iterator: dereference, assignment, comparison")
	{
        {
            // initialize doubly linked list
            ITPDoubleList<std::string> mList = ITPDoubleList<std::string>();

            // add to list
            mList.push_front("first");
            mList.push_front("second");
            mList.push_front("third");

            // begin
            ITPDoubleList<std::string>::Iterator pos = mList.begin();
            // make sure dereference is front
            REQUIRE(*pos == mList.front());
            REQUIRE(*pos == "third");
            REQUIRE(pos == mList.begin());
            REQUIRE(pos != mList.end());
            
            pos++;
            REQUIRE(*pos == "second");

            pos++;
            REQUIRE(*pos == "first");
            
            // end
            ITPDoubleList<std::string>::Iterator pos2 = mList.end();
            REQUIRE(pos2 == mList.end());
            
//            // *********************************************************
//            // sentinel node at end of list not las element
//            pos2--;
//            REQUIRE(*pos2 == mList.back());
//            REQUIRE(*pos2 == "first");

//            REQUIRE(*pos == *(++pos));

            
            ITPDoubleList<std::string> mList2 = mList;
            ITPDoubleList<std::string>::Iterator copy = mList2.end();
            while (pos != mList.end() && copy != mList2.end()) {
                REQUIRE(*pos == *copy);
                pos++;
                copy++;
            }
//            REQUIRE(pos == mList.end());
//            REQUIRE(copy == mList2.end());
            
            // comparison
            ITPDoubleList<std::string>::Iterator pos3;
            pos3 = pos;
            REQUIRE(pos == pos3);
        }
        
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("List: begin, end; Iterator: dereference, increment")
	{
        {
            // initialize doubly linked list
            ITPDoubleList<std::string> mList = ITPDoubleList<std::string>();

            // add to list
            mList.push_front("first");
            mList.push_front("second");
            mList.push_front("third");

            ITPDoubleList<std::string>::Iterator pos = mList.begin();
            // dereference
            REQUIRE(*pos == "third");

            ITPDoubleList<std::string>::Iterator pos2 = mList.end();
            REQUIRE(pos2 == mList.end());
            // *********************************************************** sentinel
            //        REQUIRE(*pos2 == "first");
            //        REQUIRE(*pos2 == mList.back());

            // increment
            pos++;

            REQUIRE(*pos == "second");
            
            // increment
            pos++;

            REQUIRE(*pos == "first");
        }
        
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("List: begin, end; Iterator: dereference, increment, decrement")
	{
        {
            // initialize doubly linked list
            ITPDoubleList<std::string> mList = ITPDoubleList<std::string>();

            // add to list
            mList.push_front("first");
            mList.push_front("second");
            mList.push_front("third");

            // begin
            ITPDoubleList<std::string>::Iterator pos = mList.begin();
            REQUIRE(*pos == "third");

            // end
            ITPDoubleList<std::string>::Iterator pos2 = mList.end();
            REQUIRE(pos2 == mList.end());
            // *********************************************************** sentinel
            //        REQUIRE(*pos2 == "first");
            //        REQUIRE(*pos2 == mList.back());

            // increment
            pos++;

            REQUIRE(*pos == "second");

            // decrement
            pos--;
            REQUIRE(*pos == "third");
        }
        
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("List: insert with iterator at begin, middle, and one away from end")
	{
        {
            // initialize doubly linked list
            ITPDoubleList<std::string> mList = ITPDoubleList<std::string>();

            // add to list
            mList.push_front("first");
            mList.push_front("second");
            mList.push_front("third");
            mList.push_front("fourth");

            ITPDoubleList<std::string>::Iterator pos = mList.begin();
            ITPDoubleList<std::string>::Iterator pos2 = mList.end();

            // insert at beginning
            mList.insert(pos, "new");
            pos--;
            REQUIRE(*pos == "new");

            // insert at middle
            pos++;
            pos++;
            mList.insert(pos, "new2");
            pos--;
            REQUIRE(*pos == "new2");
            
            // insert one away from end
            pos++;
            pos++;
            mList.insert(pos, "one end");
            pos--;
            REQUIRE(*pos == "one end");

//            // insert one away end
//            pos2--;
//            mList.insert(pos2, "word");
//            pos2--;
//            REQUIRE(*pos2 == "word");

            REQUIRE(mList.size() == 7);
        }
        
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("List: erase with iterator at begin, middle, and one away from end")
	{
        {
            // initialize doubly linked list
            ITPDoubleList<std::string> mList = ITPDoubleList<std::string>();

            // add to list
            mList.push_front("first");
            mList.push_front("second");
            mList.push_front("third");
            mList.push_front("fourth");

            ITPDoubleList<std::string>::Iterator pos = mList.begin();
            // erase at beginning
            ITPDoubleList<std::string>::Iterator afterPos = mList.erase(pos);
            REQUIRE(mList.size() == 3);
            REQUIRE(*afterPos == "third");
     
            // erase at middle
            ++afterPos;
            afterPos = mList.erase(afterPos);
            REQUIRE(mList.size() == 2);
            REQUIRE(*afterPos == "first");
            
            // erase at end
            --afterPos;
            afterPos = mList.erase(afterPos);
            REQUIRE(mList.size() == 1);
            REQUIRE(*afterPos == "first");
            
//            ITPDoubleList<std::string>::Iterator pos3 = mList.end();
//            pos3--;
//            mList.erase(pos3);
//            REQUIRE(mList.size() == 1);
        }
        
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}
}

TEST_CASE("Student movie", "[student]")
{
	SECTION("Bad constructor")
	{
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
        }
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Creating scene 2")
	{
        {
            // check frame numbers
            MoviePlayer scene("input/scene2.ani");
        
            // check member variables to see if it was created correctly
            REQUIRE(scene.getFrameSize() == 13);
            // counting total frames (36) with the frame length multipliier
            REQUIRE(scene.getNumFrames() == 69);
    
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
        }
        
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}

	SECTION("Checking frames, scene 2")
	{
        {
            // load a scene
            MoviePlayer scene("input/scene2.ani");
            
            // use expectected to check it was set correctly
            std::ifstream inputFile("expected/expected_scene2.ani");
            
            // check member variables to see if it was created correctly
            REQUIRE(scene.getFrameSize() == 13);
            // counting total frames (36) with the frame length multipliier
            REQUIRE(scene.getNumFrames() == 69);
            REQUIRE(scene.getCurrFrameNum() == 1);
            
            std::string separator;
            std::getline(inputFile, separator);
            
            std::stringstream ss;
            std::string line;
            
            // loop 13 times to get first frame
            // check one frame to see if it was set correctly
            for (int i=0; i < 13; i++){
                std::getline(inputFile, line);
                ss << line + "\n";
            }
    
            // check line strings are same
            REQUIRE(scene.getCurrFrame() == ss.str());
        }
		// Leave this at the end
		REQUIRE(ITPMemLeaks::CheckIfMemoryFreed());
	}
}
