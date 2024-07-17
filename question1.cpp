// Lab3.cpp
//Question 1 
// Nicolas Vicente, student number: 1271740
// Data Structures Lakehead University

#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

template <class ItemType>
class SLL
{
private:
    node *start;
    node *last;
    int length;

    mutable node *loc;
    mutable node *ploc;

public:
    SLL() : start(nullptr), last(nullptr), length(0), loc(nullptr), ploc(nullptr) {}

    /**
     * @brief The function IsThere checks if an element with a specific key exists in the linked list.
     *
     * The function searches the linked list to determine whether an element specified by the parameter is in the list.
     * It returns true if the element exists in the list and false if it doesn't.
     *
     * @param item The item of type ItemType to search for in the list
     * @return true if the item is found within the list and false if it is not.
     */
    bool IsThere(ItemType item) const
    {
        loc = start;
        ploc = nullptr;
        while (loc != nullptr && loc->data != item)
        {
            ploc = loc;
            loc = loc->next;
        }

        return (loc != nullptr);
    }
}; 

int main()
{
    SLL<int> list;

    if (list.IsThere(2))
    {
        cout << "element 2 is in the list" << endl;
    }
    else
    {
        cout << "element 2 is not in the list" << endl;
    }

    return 0;
}
