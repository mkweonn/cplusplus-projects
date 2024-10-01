// ITP 365 Spring 2023
// HW06 – Vector and Poker Hands
// Name: Michelle Kweon
// Email: mkweon@usc.edu
// Platform: Mac
#pragma once
#include <sstream>
#include <ostream>
#include <stdexcept>

template <typename T>
class ITPVector
{
	const unsigned INITIAL_CAPACITY = 10;
	const unsigned CAPACITY_MULTIPLIER = 2;
    
public:
	// Function: Constructor
	// Purpose: Initializes the ITP vector to have a
	// capacity of INITIAL_SIZE and a size of 0.
	// It also dynamically allocates the underlining array data
	// Input: None
	// Returns: Nothing
	ITPVector()
	{
        // set the capacity to the initial default
        mCapacity = INITIAL_CAPACITY;
        // set the size to 0
        mSize = 0;
        // dynamically allocate an array of the initial capacity, and save its address
        mData = new T[mCapacity];
	}

	// Function: Constructor
	// Purpose: Initializes the ITP vector to have a
	// capacity of inputted value.
	// It also dynamically allocates the underlining array data
	// Input: Unsigned integer
	// Returns: Nothing
	ITPVector(unsigned inCapacity)
	{
        // set the capacity to the inputted value
        mCapacity = inCapacity;
        // set the size to 0
        mSize = 0;
        // dynamically allocate array of Ts to have capacity elements in it
        mData = new T[mCapacity];
	}

	// Function: Copy Constructor
	// Purpose: Initializes the ITP vector to have a
	// copy of the inputted vector
	// Input: Another ITPVector
	// Returns: Nothing
	ITPVector(const ITPVector<T>& other)
	{
        // vector<int> yourVec = myVec;
        // copy constructor to create a deep copy of the other ITPVector.
        
        // set the new capacity to the other's size and size = 0
        mCapacity = other.size();
        mSize = 0;
        // create a new underlying array with the new capacity
        T* newArray = new T[mCapacity];
        mData = newArray;
        // iterate over the other vector and push_back items to the new vector
        for (int i=0; i < other.size(); i++) {
//            mData[i] = other[i];
            this -> push_back(other[i]);
        }
        // similar to assignment but no need to clear old data and no return value (constructor)
	}

	// Function: Assignment operator
	// Purpose: Clears the current vector and sets
	// the vector to have a copy of the inputted vector
	// Input: Another ITPVector
	// Returns: Nothing
	ITPVector<T>& operator=(const ITPVector<T>& other)
	{
        // implementing deep copy of other ITPVector
        
        // call the clear function
        clear();
        // delete the current array
        delete[] mData;
        // set the new capacity to the other's size and size = 0
        mCapacity = other.size();
        mSize = 0;
        // create a new underlying array with the new capacity
        T* newArray = new T[mCapacity];
        mData = newArray;
        
        // iterate over the other vector and push_back items to the new vector
        for (int i=0; i < other.size(); i++) {
//            mData[i] = other.mData[i];
            this -> push_back(other[i]);
        }
        // by convention, operator= returns *this
        return *this;
	}

	// Function: Destructor
	// Purpose: Deletes the underlying array and
	// sets size/capacity to zero
	// Input: None
	// Returns: Nothing
	~ITPVector()
	{
        // delete underlying array
        delete[] mData;
        mData = nullptr;
        mSize = 0;
        mCapacity = 0;
	}

	// Function: clear
	// Purpose: Emptys the current vector
	// Input: None
	// Returns: None
	void clear()
	{
        // call delete [] on the underlying array
        delete[] mData;
        //mCapacity = INITIAL_CAPACITY;
        // create a new underlying array using the old capacity
        mData = new T[mCapacity];
        // set size back to 0
        mSize = 0;
	}

	// Function: empty
	// Purpose: Returns true if the vector is empty
	// Input: None
	// Returns: Boolean
	bool empty()
	{
        // check if there is nothing in the vector
        if (mSize == 0) {
            return true;
        }
        else {
            return false;
        }
	}
	
	// Function: capacity
	// Purpose: Returns the current capacity of the underlying array data
	// Input: None
	// Returns: Capacity of underlying array data
	unsigned capacity() const
	{
		// returns the capacity of the ITPVector
        return mCapacity;
	}

	// Function: size
	// Purpose: Returns the current size of the vector
	// Input: None
	// Returns: Size of vector
	unsigned size() const
	{
		// returns the size of the ITPVector
		return mSize;
	}

	// Function: data
	// Purpose: Returns the pointer to the underlying array
	// Input: None
	// Returns: T*
	T* data() const
	{
		// returns the pointer to the underlying array
		return mData;
	}

	// Function: Subscript operator (read/write version)
	// Purpose: Grabs the specified index from vector
	// Causes an error if the index is out of bounds
	// Input: Index to access
	// Returns: Value at index, by reference
	T& operator[](unsigned index)
	{
        // if index >= size - error
        if (index < 0 || index >= mSize) {
            throw std::out_of_range("Out of bounds!");
        }
        else {
            // return value at the requested index
            return mData[index];
            //        return *(new T);
        }
	}

	// Function: Subscript operator (read-only version)
	// Purpose: Grabs the specified index from vector
	// Causes an error if the index is out of bounds
	// Input: Index to access
	// Returns: Value at index, by reference
	const T& operator[](unsigned index) const 
	{
        if (index < 0 || index >= mSize) {
            throw std::out_of_range("Out of bounds!");
        }
        else {
            return mData[index];
            //        return *(new T);
        }
	}

	// Function: insert_back
	// Purpose: Adds the specified element to the end of the ITPVector
	// It automatically reallocates the underlying array if we are
	// going over capacity
	// Input: Value to add (by const reference)
	// Returns: Nothing
	void push_back(const T& value)
	{
        if (mSize < mCapacity) { // add element as long as current size is less than current capacity because enough room on underlying array to add
            // place the element at index size
            mData[mSize] = value;
            
            // increment size
            mSize++;
        }
        else if (mSize == mCapacity) { // at capacity (insertion go over capacity)
            // increase the capacity (usually double)
            mCapacity *= CAPACITY_MULTIPLIER;
            
            // dynamically allocate a new underlying array w/ new capacity
            T* newArray = new T[mCapacity];
            
            // copy the data from the old array to the new array
            for (int i=0; i < mSize; i++) {
                newArray[i] = mData[i];
            }
            
            // delete the old array
            delete[] mData;
            
            // set the pointer to the new array
            mData = newArray;
            
            // add an element at index size
            mData[mSize] = value;
            
            // increment size by 1
            mSize++;
        }
	}

	// Function: get_back
	// Purpose: Returns the current last element in the vector
	// Does not remove this element from the vector
	// Causes an error if there are no elements in the vector
	// Input: Nothing
	// Returns: Value at back of vector, by reference
	T& back()
	{
        // if size == 0 - error
        if (mSize == 0){
            throw std::out_of_range("No elements in the vector!");
        }
        // return the element size - 1 (last element in ITPVector)
        return mData[mSize - 1];
//        return *(new T);
	}

	// Function: remove_back
	// Purpose: Removes the last element from the ITPVector
	// Causes an error if there are no elements in the vector
	// Input: Nothing
	// Returns: Nothing
	void pop_back()
	{
        // if size == 0 - error
        if (mSize == 0){
            throw std::out_of_range("No elements in the vector!");
        }
        // decrement size by 1 to remove last element
        mSize--;
	}

	// Function: Output Stream Operator
	// Purpose: Prints the contents of the vector to the provided stream
	// Written in the format of {x, y, ..., z}
	// Input: Stream to write to, vector to write
	// Output: Stream after values are written
	friend std::ostream& operator<<(std::ostream& os, const ITPVector<T>& vector)
	{
        os << "{";
        // bool to keep track whether to add comma before element
        // used to avoid comma at the end
        bool first = true;
        
        // loop through the vector from the start to end indices, and output a comma separated list of the elements in the vector
        for(int i=0; i < vector.size(); i++) {
            // adds comma before card if it is not first item
            if(!first) {
                os << ",";
            }
            else {
                first = false;
            }
            os << " " << vector[i];
        }
        os << " }";
        
		return os;
	}
    
private:
	// member variables
    
    // total elements in the array
    unsigned mSize;
    // maximum number of elements that can be stored in current array
    unsigned mCapacity;
    // pointer to underlying data (array of type T)
    T* mData;
};
