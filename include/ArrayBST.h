#ifndef ArrayBST_H
#define ArrayBST_H
#include "./AbstractBST.h"
#define MAX_NUM_NODES 128

class ArrayNode
{
public:
    int key;
    int value;
    ArrayNode(int key, int value) : key(key), value(value) {}
};

class ArrayBST : public AbstractBST
{
public:
    int size;
    ArrayNode *node[MAX_NUM_NODES];
    ArrayBST();
    ~ArrayBST();
    bool isEmpty();
    void addBST(int key, int value);
    void removeBST(int targetkey);
    int searchBST(int targetKey);
};

#endif