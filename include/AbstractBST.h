#ifndef AbstractBST_h
#define AbstractBST_h
#include <iostream>
using namespace std;
class AbstractBST
{
public:
    virtual bool isEmpty() = 0;
    virtual void addBST(int key, int value) = 0;
    virtual void removeBST(int targetkey) = 0;
    virtual int searchBST(int targetKey) = 0;
};
#endif