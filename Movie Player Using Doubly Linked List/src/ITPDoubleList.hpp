// ITP 365 Spring 2023
// HW08 – Doubly Linked List and Movie Player
// Name: Michelle Kweon
// Email: mkweon@usc.edu
// Platform: Mac

// ITPDoubleList.hpp
// Defines and implements the ITPDoubleList collection

#pragma once
#include <ostream>
#include <sstream>
#include <stdexcept>

template <typename T>
class ITPDoubleList
{
private:
    
    // Node only used internally to list
    struct Node
    {
        // Data in this node
        T mData;
        // Link to previous node
        Node* mPrev;
        // Link to next node
        Node* mNext;
    };
    
    // Pointer to the head node
    Node* mHead;
    // Pointer to the tail node
    Node* mTail;
    // Number of nodes currently in the list
    unsigned mSize;
    
public:
    // Iterator helper class...
    // used to keep track of a position in the list
    class Iterator
    {
    private:
        Node* mCurr;
    public:
        // Needed for List access
        friend class ITPDoubleList;
        
        // Constructors
        // default constructor
        Iterator()
        {
            mCurr = nullptr;
		}
        
        // paramterized constructor
        Iterator(Node* inCurr)
        {
            mCurr = inCurr;
        }
        
        // copy constructor
        Iterator(const Iterator& src)
        {
             mCurr = src.mCurr;
        }
        
        // Assignment
        Iterator& operator=(const Iterator& src)
        {
             mCurr = src.mCurr;
             return *this;
		}
        
        // Incrementors / Decrementors
        // ++i
        Iterator& operator++()
        {
            mCurr = mCurr -> mNext;
            return *this;
		}
        
        // i++
        Iterator operator++(int)
        {
            Iterator retval(*this);
            mCurr = mCurr -> mNext;
            return retval;
//            return *(new Iterator); // FIX RETURN VALUE
        }
        
        // --i
        Iterator& operator--()
        {
            mCurr = mCurr -> mPrev;
            return *this;
        }
        
        // i--
        Iterator operator--(int)
        {
            Iterator retval(*this);
            mCurr = mCurr -> mPrev;
            return retval;
//            return *(new Iterator); // FIX RETURN VALUE
        }
        
        // Dereference
        T& operator*() const
        {
            return mCurr -> mData;
//            return *(new T()); // FIX RETURN VALUE
        }
        
        Node* operator->() const
        {
            return mCurr;
        }
        
        // Comparison
        bool operator==(const Iterator& rhs) const
        {
            return (mCurr == rhs.mCurr);
        }
        
        bool operator!=(const Iterator& rhs) const
        {
            return (mCurr != rhs.mCurr);
        }
    };
    
    // List functions...
    
    // Function: Default Constructor
    // Purpose: Initializes size to 0 and head/tail to null
    // Input: None
    // Returns: Nothing
    ITPDoubleList()
    {
        // set size to 0
        mSize = 0;
        // set head to null
        mHead = nullptr;
        // set tail to null
        mTail = nullptr;
    }
    
    // Function: Copy Constructor
    // Purpose: Initializes this list as a deep copy of other
    // Input: Other list to copy (const reference)
    // Returns: Nothing
    ITPDoubleList(const ITPDoubleList& other)
    {
        // set size to 0, head to null, tail to null
        mSize = 0;
        mHead = nullptr;
        mTail = nullptr;
        
        // create a temp that points to the head node in “other”
        Node* temp = other.mHead;
        // while temp is not null...
        while(temp != nullptr) {
            // push_back temp’s data into this list
            push_back(temp -> mData);
            // advance temp to the next node
            temp = temp -> mNext;
        }
    }
    
    // Function: Destructor
    // Purpose: Calls the clear function to delete the list
    // Input: None
    // Returns: Nothing
    ~ITPDoubleList()
    {
        // call the clear function
        clear();
	}
    
    // Function: clear
    // Purpose: Deletes every node in this list, sets size to 0, and head/tail to null
    // Input: None
    // Returns: Nothing
    void clear()
    {
        // while size > 0...
        while(mSize > 0) {
            // call pop_front
            pop_front();
        }
        
        // automatically turns to this once everything deleted
//        mSize = 0;
//        mHead = nullptr;
//        mTail = nullptr;
    }
    
    // Assignment Operator
    // Function: Assignment Operator
    // Purpose: Clear this list, and then make a deep copy of other
    // Input: Other list to copy (const reference)
    // Returns: *this
    ITPDoubleList& operator=(const ITPDoubleList& other)
    {
        // call clear (to clear out any values already in this list)
        clear();
        // create a temp that points to the head node in “other”
        Node* temp = other.mHead;
        // while temp is not null...
        while(temp != nullptr) {
            // push_back temp’s data into this list
            push_back(temp -> mData);
            // advance temp to the next node
            temp = temp -> mNext;
        }
        // by convention, operator= returns *this
        return *this;
    }
    
    // Function: size
    // Purpose: Gets the current size of the linked list
    // Input: None
    // Returns: size of the list
    unsigned size() const
    {
        return mSize;
    }
    
    // Function: push_front
    // Purpose: Inserts a node at the front of the linked list
    // Input: Value to store in the new node
    // Returns: Nothing
    void push_front(const T& value)
    {
        // dynamically allocate a new node
//        Node<T>* newNode = new Node<T>();
        Node* newNode = new Node();
            // set its data to the requested value
        newNode -> mData = value;
            // set its previous to null (since this will be the new head)
        newNode -> mPrev = nullptr;
            // set its next to the current head
        newNode -> mNext = mHead;
        // if the size is 0..
        if(mSize == 0) {
            // the tail is the new node
            mTail = newNode;
        }
        // otherwise
        else {
            // set the previous of the current head to the new node
            mHead -> mPrev = newNode;
        }
        // set the head to the new node (address the new node is at)
        mHead = newNode;
        // increment the size
        mSize++;
    }
    
    // Function: front
    // Purpose: Gets the value of the node at the front of the list
    // Input: None
    // Returns: Value of the node at the front of the list
    T& front()
    {
        // if the size is 0
        if(mSize == 0) {
            // error!
            throw std::out_of_range("ITPDoubleList is empty, can't front!");
        }
        // return the data at the head node
        return mHead -> mData;
//        return *(new T()); // FIX RETURN VALUE
    }
    
    // Function: pop_front
    // Purpose: Removes the node at the front of the list
    // Input: None
    // Returns: None
    void pop_front()
    {
        // if the size is 0...
        if(mSize == 0) {
            // error!
            throw std::out_of_range("ITPDoubleList is empty, can't pop_front!");
        }
        // otherwise if the size is 1...
        else if(mSize == 1) {
            // delete the head node
            delete mHead;
            // set head and tail to null, size to 0
            mHead = nullptr;
            mTail = nullptr;
            mSize = 0;
        }
        // otherwise...
        else {
            // set a temp equal to the next node after head
            Node* temp = mHead -> mNext;
            // delete the head node
            delete mHead;
            // the new head is temp
            mHead = temp;
            // the new head previous is now null
            mHead -> mPrev = nullptr;
            // decrement size
            mSize--;
        }
    }
    
    // Function: push_back
    // Purpose: Inserts a node at the end of the linked list
    // Input: Value to store in the new node
    // Returns: Nothing
    void push_back(const T& value)
    {
        // dynamically allocate a new node
        Node* newNode = new Node();
            // set its data to the value
        newNode -> mData = value;
            // set its previous to the current tail
        newNode -> mPrev = mTail;
            // set the next to null (since this will be the new tail)
        newNode -> mNext = nullptr;
        // if the size is 0...
        if(mSize == 0) {
            // the head is the new node
            mHead = newNode;
        }
        // otherwise...
        else {
            // set the next of the current tail to the new node
            mTail -> mNext = newNode;
        }
        // set the tail to the new node
        mTail = newNode;
        // increment the size
        mSize++;
    }
    
    // Function: back
    // Purpose: Gets the value of the node at the back of the list
    // Input: None
    // Returns: Value of the node at the back of the list
    T& back()
    {
        // if the size is 0...
        if(mSize == 0) {
            // error!
            throw std::out_of_range("ITPDoubleList is empty, can't back!");
        }
        // return the data at the tail node
        return mTail -> mData;
//        return *(new T()); // FIX RETURN VALUE
    }

    // Function: pop_back
    // Purpose: Removes the node at the end of the list
    // Input: None
    // Returns: None
    void pop_back()
    {
        if(mSize == 0) {
            // error!
            throw std::out_of_range("ITPDoubleList is empty, can't pop_back!");
        }
        // otherwise if the size is 1...
        else if(mSize == 1) {
            // delete the tail node
            delete mTail;
            // set head and tail to null, size to 0
            mHead = nullptr;
            mTail = nullptr;
            mSize = 0;
        }
        // otherwise...
        else {
            // set a temp equal to the previous node before the tail
            Node* temp = mTail -> mPrev;
            // delete the tail node
            delete mTail;
            // the new tail is temp
            mTail = temp;
            // the new tail next is now null
            mTail -> mNext = nullptr;
            // decrement size
            mSize--;
        }
    }
    
    // Function: begin
    // Purpose: Gets an iterator for the start of the list
    // Input: None
    // Returns: Iterator pointing to beginning of list
    Iterator begin() const
    {
//        return Iterator(mData, 0);
        return Iterator(mHead);
//        return *(new Iterator); // FIX RETURN VALUE
    }
    
    // Function: end
    // Purpose: Gets an iterator for the end of the list
    // Input: None
    // Returns: Iterator pointing to end of list
    Iterator end() const
    {
        // return Iterator(mData, mSize);
        return Iterator(mTail->mNext);
//        return *(new Iterator); // FIX RETURN VALUE
    }

	// Function: erase
	// Purpose: Removes the item at the node pointed to by i
	// Input: Iterator pointing to a valid node to remove before
	// Returns: A new iterator pointing to the node after the removed item
    Iterator erase(Iterator& i)
    {
        // if the iterator is invalid...
        if(i == nullptr) {
            // error!
            throw std::out_of_range("Invalid Iterator Position!");
        }
        // if the iterator is at begin
        else if(i == begin()) {
            // pop_front
            pop_front();
            // return begin
            return begin();
        }
        // if the iterator is at the tail
        else if(i == mTail) {
            // pop_back
            pop_back();
            // return end
            return end();
        }
        // otherwise...
        else {
            // make “before”, “after”, and “toDel” pointers
            Node* before = i.mCurr -> mPrev;
            Node* after = i.mCurr -> mNext;
            Node* toDel = i.mCurr;
            // delete “toDel”
            delete toDel;
            // set before’s next to after
            before -> mNext = after;
            // set after’s previous to before
            after -> mPrev = before;
            // decrement size
            mSize--;
            // return an iterator to after (item after removed item)
            return Iterator(after);
        }
//        return *(new Iterator); // FIX RETURN VALUE
    }

	// Function: insert
	// Purpose: Inserts a list item before node pointed to by i
	// Input: Iterator pointing to a valid node to insert before
	// Returns: A new iterator pointing to the inserted value
    Iterator insert(Iterator& i, const T& val)
    {
        // if the iterator is invalid...
        if(i == nullptr) {
            // error!
            throw std::out_of_range("Invalid Iterator Position!");
        }
        // if the iterator is at begin
        else if (i == begin()) {
            // push_front
            push_front(val);
            // return begin
            return begin();
        }
        // if the iterator is at end
        else if (i == end()) {
            // push_back
            push_back(val);
            // return iterator to last element (not end!)
            return Iterator(mTail);
        }
        // otherwise...
        else {
            // make “before” and “after” pointers
            Node* before = i.mCurr -> mPrev;
            Node* after = i.mCurr;
            // dynamically allocate a new node
            Node* newNode = new Node;
            // set its data to the value
            newNode -> mData = val;
            // set its previous to before
            newNode -> mPrev = before;
            // set its next to after
            newNode -> mNext = after;
            // set before’s next to the new node
            before -> mNext = newNode;
            // set after’s previous to the new node
            after -> mPrev = newNode;
            // increment size
            mSize++;
            // return an iterator pointing to the inserted node
            return Iterator(newNode);
        }
//        return *(new Iterator); // FIX RETURN VALUE
    }
    
public:
    // Function: Output Stream Operator
    // Purpose: Prints the contents of the list to the provided stream
    // Written in the format of {x, y, ..., z}
    // Input: Stream to write to, list to write
    // Output: Stream after values are written
    friend std::ostream& operator<<(std::ostream& os, const ITPDoubleList<T>& list)
    {
        os << "{";
        // create a pointer variable (temp) that stores the address of the head node
        Node* temp = list.mHead;
        // while temp != nullptr...
        while (temp != nullptr) {
            // output the data for the "temp" node
            os << temp -> mData;
            if(temp != list.mTail) {
                os << ",";
            }
            // update the temp node to be the next node in the link
            temp = temp -> mNext;
        }
        os << "}";
        return os; // FIX RETURN VALUE
    }
    
    // Function: toString
    // Purpose: Converts list to a string
    // Input: None
    // Output: String (in the format as the ostream)
    std::string toString() const
    {
        std::stringstream ss;
        
        // take in the list in string stream
        ss << *this;
        
        // return as a string
        return ss.str();
//        return *(new std::string); // FIX RETURN VALUE
    }
    
    // Function: toReverseString
    // Purpose: Outputs the list in reverse
    // Input: None
    // Output: String in reverse
    std::string toReverseString() const
    {
        std::stringstream ss;
        ss << "{";
        
        // opposite of output stream operator
        // create a pointer variable (temp) that stores the address of the tail node
        Node* temp = mTail;
        // while temp != nullptr...
        while(temp != nullptr) {
            // output the data for the "temp" node
            ss << temp -> mData;
            if(temp != mHead) {
                ss << ",";
            }
            // update the temp node to be the previous node in the link
            temp = temp -> mPrev;
        }
        ss << "}";
        
        // return string in string stream
        return ss.str();
//        return *(new std::string); // FIX RETURN VALUE
    }
};
