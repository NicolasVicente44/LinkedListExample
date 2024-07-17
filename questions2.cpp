
// Lab3.cpp
//Question 2
// Nicolas Vicente, student number: 1271740
// Data Structures Lakehead University


#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node
{
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

// Single Linked List class
class SLL
{
private:
    Node *start;
    Node *last;
    int length;

public:
    Node *loc;
    Node *ploc;

    SLL() : start(nullptr), last(nullptr), length(0), loc(nullptr), ploc(nullptr) {}

    // Method to insert an item into the linked list
    void insert(int item)
    {
        Node *newNode = new Node(item);

        if (start == nullptr)
        {
            start = newNode;
            last = newNode;
        }
        else
        {
            last->next = newNode;
            last = newNode;
        }

        length++;
    }

    // Method to search for an item in the linked list with the three loop terminating conditions discussded in class
    bool IsThere(int item)
    {
        loc = start;
        ploc = nullptr;

        while (loc != nullptr && loc->data < item)
        {
            ploc = loc;
            loc = loc->next;
        }

        if (loc == nullptr)
        {
            cout << "Condition 1: loc == nullptr. The element " << item << " is NOT in the list." << endl;
            return true;
        }

        // Condition 2: loc->data == item
        if (loc != nullptr && loc->data == item)
        {
            cout << "Condition 2: loc->data == item. The element " << item << " is in the list and was found." << endl;
            return true;
        }

        // Condition 3: loc->data != item (element not found)
        cout << "Condition 3: loc->data != item. Element " << item << " belongs at this location but it isn’t in the list." << endl;
        loc = nullptr;
        return false;
    }

    // Method to print all items in the linked list
    void printItems()
    {
        if (!isEmpty())
        {
            Node *temp = start;
            while (temp != nullptr)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        else
        {
            cout << "List is empty" << endl;
        }
    }

    // Method to check if the linked list is empty
    bool isEmpty() const
    {
        return start == nullptr;
    }
};

int main()
{
    SLL list;
    int item;

    // Getting 10 elements from the user and inserting them into the linked list
    cout << "Enter 10 integers to insert into the linked list:" << endl;
    for (int i = 0; i < 10; ++i)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> item;
        list.insert(item);
    }

    // Printing the linked list items that the user gave
    cout << "\nThe linked list items are:" << endl;
    list.printItems();

    // Test case 1: Searching for an element th4at exists in the list (Condition 2)
    int searchItem1;
    cout << "\nEnter the element to search that is NOT in the list (test case 1): ";
    cin >> searchItem1;
    cout << "Searching for " << searchItem1 << ":" << endl;
    list.IsThere(searchItem1);

    // Test case 2: Searching for an element that does not exist in the list (Condition 1)
    int searchItem2;
    cout << "\nEnter the element to search for that IS in the list (test case 2): ";
    cin >> searchItem2;
    cout << "Searching for " << searchItem2 << ":" << endl;
    list.IsThere(searchItem2);

    // Test case 3: Search for an element where loc != nullptr and loc->data != keyvalue (Condition 3)
    int searchItem3;
    cout << "\nEnter element that belongs at this location but it isn’t in the list. (test case 3): ";
    cin >> searchItem3;
    cout << "Searching for " << searchItem3 << ":" << endl;
    list.IsThere(searchItem3);

    return 0;
}
