#ifndef TREENODE
#define TREENODE

template <class U>

class treeNode
{
private:

    treeNode* right;
    treeNode* left;
    U* data;
    int height;

public:

    treeNode()
    {
        this->right = nullptr;
        this->left = nullptr;
        this->data = nullptr;
        this->height = 0;
    }

    treeNode(U& data)
    {
        this->right = nullptr;
        this->left = nullptr;
        this->data = &data;
        this->height = 0;
    }

    treeNode(U* data, treeNode* up)
    {
        this->right = nullptr;
        this->left = nullptr;
        this->data = data;
    }

    treeNode (const treeNode& node)
    {
        this->right = node.right;
        this->left = node.left;
        this->data = node.data;
    }

    treeNode& operator=(const treeNode& node)
    {
        this->right = node.right;
        this->left = node.left;
        this->data = node.data;

        return *this;
    }

    bool operator==(const treeNode& node)
    {
          if(this->data == node.data)
          {
              return true;
          }

          return false;
    }

    int nodeCmpr(treeNode node)
    {
        if(*data < *(node.getData()))
        {
            return -1;
        }

        else if(*data == *(node.getData()))
        {
            return 0;
        }

        else
        {
            return 1;
        }

        return false;
    }

    int max(int a, int b)
    {
        return (a > b)? a : b;

    }

    int updateHeight()
    {
        this->height = 0;
        int lHeight = 0;
        int rHeight = 0;

        if(left != nullptr)
        {
            lHeight = left->getHeight()-1;
        }

        if(right != nullptr)
        {
            rHeight = right->getHeight()+1;
        }

        this->height = max(lHeight,rHeight);

        return height;
    }

    ~treeNode()
    {
        this->right = nullptr;
        this->left = nullptr;
        this->data = nullptr;
        height = 0;
    }

    //getters and setters
    void setRight(treeNode* node)
    {
        this->right = node;
    }

    void setLeft(treeNode* node)
    {
        this->left = node;
    }

    void setData(U* data)
    {
            this->data = data;
    }

    treeNode* getRight()
    {
        return right;
    }

    treeNode* getLeft()
    {
        return left;
    }

    U* getData()
    {
        return data;
    }

    int getHeight()
    {
        return height;
    }

};

#endif // TREENODE
