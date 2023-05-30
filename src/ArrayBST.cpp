#include "ArrayBST.h"

ArrayBST::ArrayBST()
{
    for (int i = 0; i < MAX_NUM_NODES; i++)
    {
        node[i] = NULL;
        size = 0;
    }
}
ArrayBST::~ArrayBST()
{
}

bool ArrayBST::isEmpty()
{
    return this->node[0] == NULL; // Check if the root node is NULL to determine if the BST is empty
}

void ArrayBST::addBST(int key, int value)
{
    ArrayNode *newData(new ArrayNode(key, value));
    size++;
    for (int i = 0; i < MAX_NUM_NODES;)
    {
        ArrayNode *nodes = this->node[i];

        if (this->node[i] == NULL)
        {
            node[i] = newData;
            break;
        }
        else if (node[i]->key > key)
        {
            i = 2 * i + 1;
        }
        else
        {
            i = 2 * i + 2;
        }
    }
    cout << "Node Added with key:" << key << endl;
}

int ArrayBST::searchBST(int targetKey)
{
    if (isEmpty())
    {
        cout << "Empty BST" << endl;
        return -1;
    }
    int i = 0;
    while (i < MAX_NUM_NODES && node[i] != NULL)
    {
        // cout<<"i:"<<i<<endl;
        if (node[i]->key > targetKey)
        {
            cout << node[i]->key << endl;
            i = 2 * i + 1;
        }
        else if (node[i]->key < targetKey)
        {
            cout << node[i]->key << endl;
            i = 2 * i + 2;
        }
        else
        {
            cout << "FOUND" << endl;
            return node[i]->value;
        }
    }
    cout << "Key Not Found" << endl;
    return -1;
}

void ArrayBST::removeBST(int targetKey)
{
    if (isEmpty())
    {
        cout << "Empty BST" << endl;
        return;
    }

    int i = 0;
    while (i < MAX_NUM_NODES && node[i] != NULL)
    {
        if (node[i]->key > targetKey)
        {
            i = 2 * i + 1; // Move to the left child
        }
        else if (node[i]->key < targetKey)
        {
            i = 2 * i + 2; // Move to the right child
        }
        else
        {
            // For node with no child
            if (node[2 * i + 1] == NULL && node[2 * i + 2] == NULL)
            {
                // delete node[i];
                node[i] = NULL;
            }
            // For node with one child
            else if (node[2 * i + 1] == NULL && node[2 * i + 2] != NULL)
            {
                node[i] = node[2 * i + 2];
                // delete node[2*i + 2];
                node[2 * i + 2] = NULL;
            }
            // For node with one child
            else if (node[2 * i + 1] != NULL && node[2 * i + 2] == NULL)
            {
                node[i] = node[2 * i + 1];
                // delete node[2*i + 1];
                node[2 * i + 1] = NULL;
            }
            // For node with two childs
            else
            {
                int currentIndex = i;
                int currentMax = i;
                i = 2 * i + 1;
                while (i < MAX_NUM_NODES && node[i] != NULL)
                {
                    if (node[i]->key > currentMax)
                    {
                        currentMax = i;
                    }
                    i = 2 * i + 2;
                }
                node[currentIndex] = node[i];
                // delete node[i];
                node[i] = NULL;
            }
            size--;
            cout << "Node with key " << targetKey << " Deleted" << endl;
            return;
        }
    }
    cout << "Node with key " << targetKey << " Not Found" << endl;
}
