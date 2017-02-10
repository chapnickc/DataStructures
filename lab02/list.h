// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// A list is a sequence of objects of a single type.
//
// One way is to use a legitimate array in C++
// The other way is the linked list. This is not 
// indexed by integers. We put all elements at a node, 
// where a node is a value and a pointer to the next obj.
//
// containers store objects of other types
// you need a mechanism to store said objects
// 
// We are just defining the common interface, not 
// looking at the implementation for how things are
// stored
// 
// "virtual" functions are functions in an abstract base 
// class that doesnt have an implementation that must be implemented
// for the children. Setting the virtual function to zero 
// let's c++ compiler know this is a virtual func.
// 
// templates allow you to define "placeholders"
// E is a placeholder for some type
//
// by storing the current position, a lot of the 
// methods are not const. Even the find and/or 
// index() func from python . Sine we have to 
// call movePos() and stuff for many methods
template <typename E> class List { // List ADT

    private:
        // don't worry about why these are private rn
        void operator =(const List&) {}       // Protect assignment
        List(const List&) {}                  // Protect copy constructor

    public:
        List() {}                             // Default constructor
        virtual ~List() {}                    // Base destructor

        // Clear contents from the list, to make it empty.
        virtual void clear() = 0;

        // Insert an element at the current location.
        // item: The element to be inserted
        virtual void insert(const E& item) = 0;       // we have to define the implicit 'currrent location'

        // Append an element at the end of the list.
        // item: The element to be appended.
        virtual void append(const E& item) = 0;

        // Remove and return the current element.
        // Return: the element that was removed.
        virtual E remove() = 0;

        // Set the current position to the start of the list
        virtual void moveToStart() = 0;

        // Set the current position to the end of the list
        virtual void moveToEnd() = 0;

        // Move the current position one step left. No change
        // if already at beginning.
        virtual void prev() = 0;

        // Move the current position one step right. No change
        // if already at end.
        virtual void next() = 0;
        /*void next() {
            // probably not a good idea
            // to virtualize currPos() and moveToPos()
            if (curr < length()){
                moveToPos(currPos() + 1);
            }
            else {
                return;
            }
        };
        */

        // Return: The number of elements in the list.
        virtual int length() const = 0;

        // Return: The position of the current element.
        virtual int currPos() const = 0;

        // Set current position.
        // pos: The position to make current.
        //virtual void moveToPos(int pos) = 0;
        void moveToPos(int pos){
            moveToStart();
            for(int i = 0; i < pos; i++){
                next();
            }
        }

        // Return: The current element.
        virtual const E& getValue() const = 0;

        // we could write an index() function herre
        // in terms of these virtual functions
};
