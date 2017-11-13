#ifndef AVLTREE
#define AVLTREE
#include "treenode.h"
#include <cstdlib>

template <class T>

class avlTree
{

private:
    treeNode<T>* root;
    treeNode<T>* iterate;

    /*Behind the scenes functions
     * These functions handle balancing, checking, balancing the tree, parsing,
     * inserting nodes, and clearing the tree.
     *The user shouldn't do any node handling thanks to these functions
     */

    //Rotate a tree to fix left, left imbalance.
    void RotateRight(treeNode<T>* node)
    {
        iterate = node->getLeft();
        node->setLeft(iterate->getLeft());
        iterate->setRight(node);

        node->updateHeight();
        iterate->updateHeight();

    }

    //rotate tree solves case right, right imbalance
    treeNode<T>* RotateLeft(treeNode<T>* node)
    {
        iterate = node->getRight();
        node->setRight(iterate->getLeft());
        iterate->setLeft(node);

        node->updateHeight();
        iterate->updateHeight();

    }

     /*checks the height of all nodes for balance and accounts for all
    *  4 cases of binary tree imbalance using right an left rotation */
    void balance(treeNode<T>* node)
    {
        node->updateHeight();

        treeNode<T>* Left = node->getLeft();
        treeNode<T>* Right = node->getRight();
        int lHeight = 0;
        int rHeight = 0;

        if(Left != nullptr)
        {
            lHeight = Left->updateHeight();
        }

        if(Right != nullptr)
        {
            rHeight = Right->updateHeight();
        }

        int bal = node->getHeight();

        if(bal <= -2)
        {
            lHeight = 0;
            rHeight = 0;

            //these if statements keep me from calling update on nodes that dont exist
            //because seg faults are bad
            if(Left != nullptr)
            {
                Left = node->getLeft()->getLeft();
                lHeight = Left->updateHeight();
            }

            if(Right != nullptr)
            {
                Right = node->getLeft()->getRight();
                rHeight = Right->updateHeight();
            }

            //case 1 (Left,Left) imbalance
            if(lHeight > rHeight)
            {
                RotateRight(node);
            }

            //case 2 (Left,Right) imbalance
            else if(rHeight > lHeight)
            {
                RotateLeft(node);
                RotateRight(node);
            }

        }

        else if(bal >= 2)
        {
            lHeight = 0;
            rHeight = 0;

            if(Left != nullptr)
            {
                Left = node->getRight()->getLeft();
                lHeight = Left->updateHeight();
            }

            if(Right != nullptr)
            {
                Right = node->getRight()->getRight();
                rHeight = Right->updateHeight();
            }

            //case 3 (Right, Right) imbalance
            if(rHeight > lHeight)
            {
                RotateLeft(node);
            }

            //case 4 (Right, Left) imbalance
            else if(rHeight > lHeight)
            {
                RotateRight(node);
                RotateLeft(node);
            }
        }
    }

    void insert(treeNode<T>* node, treeNode<T>* temp)
    {

        //parse left
        if(temp->nodeCmpr(*root) == -1)
        {
            //insert left
            if(node->getLeft() == nullptr)
            {
                node->setLeft(temp);
            }

            else
            {
                insert(node->getLeft(), temp);
            }
        }

        //parse right
        else if(temp->nodeCmpr(*root) == 1)
        {
            //insert right
            if(node->getRight() == nullptr)
            {
                node->setRight(temp);
            }

            else
            {
                insert(node->getRight(),temp);
            }
        }

        balance(node);
    }

    //clears from left to right of all nodes beneath parent node
    void clear(treeNode<T>* node)
    {
        if(node->getLeft() != nullptr)
        {
            clear(node->getLeft());
        }

        if(node->getRight() != nullptr)
        {
            clear(node->getRight());
        }

            node->setData(nullptr);
            node->~treeNode();
    }

public:

    /*Front end functions:
    * these functions can be accessed by the user and allow creation, searching, and deletion of the
    * AVL tree by the user.
    */
    avlTree()
    {
        this->root = nullptr;
        this->iterate = root;
    }

    //This function simply checks if any data has been added to the tree.
    bool isEmpty()
    {
        if(root == nullptr)
        {
            return true;
        }

        return false;
    }

    /*This allows the user to insert data into the tree but the user cannot alter
    //where it will be in the tree. That will all be handled automatically.
    */
    void insert(T& data)
    {
        treeNode<T>* temp = new treeNode<T>(data);

        if(isEmpty() == true)
        {
            root = temp;
        }

        else if(temp->nodeCmpr(*root) == -1)
        {
            if(root->getLeft() == nullptr)
            {
                root->setLeft(temp);
                root->updateHeight();
            }

            else
            {
                insert(root->getLeft(), temp);
            }
        }

        else if(temp->nodeCmpr(*root) == 1)
        {
            if(root->getRight() == nullptr)
            {
                root->setRight(temp);
                root->updateHeight();
            }

            else
            {
                insert(root->getRight(), temp);
            }
        }
    }

    //for emptying the tree completely
    void clear()
    {
        if(isEmpty() == false)
        {
            clear(root);
        }

        root = nullptr;
        iterate = nullptr;
    }

    ~avlTree()
    {
        clear();
    }

};

#endif // AVLTREE
