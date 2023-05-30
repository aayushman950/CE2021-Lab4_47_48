// Include the header file for ArrayBST
#include "./ArrayBST.h"
#include <iostream>
using namespace std;

int main()
{
    ArrayBST a;

    // Checking and Printing whether the BST is empty or not
    cout << "Checking the BST is Empty or not before adding"
         << "\t";
    cout << a.isEmpty() << endl;

    // Adding elements to the BST
    a.addBST(10, 10);
    a.addBST(4, 4);
    a.addBST(20, 20);
    a.addBST(9, 5);
    a.addBST(10, 7);
    a.addBST(5, 9);
    a.addBST(1, 8);

    // Checking and  Printing whether the BST is empty or not after adding
    cout << "Checking the BST is Empty or not after adding"
         << "\t";
    cout << a.isEmpty() << endl;

    // Search for an element in the BST and print the result
    cout << "Searching 4 in BST:"
         << "\t";
    cout << a.searchBST(1) << endl;

    // Remove an element from the BST
    a.removeBST(5);
}