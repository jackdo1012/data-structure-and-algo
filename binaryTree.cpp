#pragma once
#include "./array.cpp"
#include "header.h"

enum TraverseType
{
    PRE_ORDER,
    IN_ORDER,
    POST_ORDER,
    LEVEL_ORDER
};

template <typename T>
class BinaryTreeADT {
public:
    virtual bool isEmpty() = 0;
    virtual int size() = 0;
    virtual int height() = 0;
    virtual bool contains(T data) = 0;
    virtual void add(T data) = 0;
    virtual void remove(T data) = 0;
    virtual DynamicArray<T>* traverse(TraverseType type) = 0;
};

template <typename T>
class Node {
private:
    T data;
    Node<T>* left;
    Node<T>* right;

public:
    Node(T data, Node<T>* left, Node<T>* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }

    T getData()
    {
        return data;
    }
    void setData(T data)
    {
        this->data = data;
    }
    Node<T>* getLeft()
    {
        return left;
    }
    void setLeft(Node<T>* left)
    {
        this->left = left;
    }
    Node<T>* getRight()
    {
        return right;
    }
    void setRight(Node<T>* right)
    {
        this->right = right;
    }
};

template <typename T>
class BinarySearchTree : public BinaryTreeADT<T> {
private:
    Node<T>* root = NULL;
    int nodeCount = 0;

    int getHeight(Node<T>* node)
    {
        if (node == NULL)
        {
            return 0;
        }
        return 1 + max(this->getHeight(node->getLeft()), this->getHeight(node->getRight()));
    }

    Node<T>* addNode(Node<T>* node, T data)
    {
        if (node == NULL)
        {
            node = new Node<T>(data, NULL, NULL);
        }
        else
        {
            if (data <= node->getData())
            {
                node->setLeft(this->addNode(node->getLeft(), data));
            }
            else if (data > node->getData())
            {
                node->setRight(this->addNode(node->getRight(), data));
            }
        }
        return node;
    }

    Node<T>* removeNode(Node<T>* node, T data)
    {
        if ((T)data < node->getData())
        {
            node->setLeft(this->removeNode(node->getLeft(), data));
        }
        else if ((T)data > node->getData())
        {
            node->setRight(this->removeNode(node->getRight(), data));
        }
        else
        {
            if (node->getLeft() == NULL)
            {
                Node<T>* temp = node->getRight();
                delete node;
                return temp;
            }
            else if (node->getRight() == NULL)
            {
                Node<T>* temp = node->getLeft();
                delete node;
                return temp;
            }
            else
            {
                Node<T>* temp = node->getRight();
                while (temp->getLeft() != NULL)
                {
                    temp = temp->getLeft();
                }
                node->setData(temp->getData());
                node->setRight(this->removeNode(node->getRight(), temp->getData()));
            }
        }
        return node;
    }

    bool checkContain(Node<T>* node, T data)
    {
        if (node == NULL)
        {
            return false;
        }
        if (data < node->getData())
        {
            return this->checkContain(node->getLeft(), data);
        }
        else if (data > node->getData())
        {
            return this->checkContain(node->getRight(), data);
        }
        else
        {
            return true;
        }
        return false;
    }

    DynamicArray<T>* preOrder(Node<T>* node, DynamicArray<T>* result)
    {
        if (node == NULL)
        {
            return result;
        }
        result->push(node->getData());
        if (node->getLeft() != NULL)
        {
            this->preOrder(node->getLeft(), result);
        }
        if (node->getRight() != NULL)
        {
            this->preOrder(node->getRight(), result);
        }
        return result;
    }
    DynamicArray<T>* inOrder(Node<T>* node, DynamicArray<T>* result)
    {
        if (node == NULL)
        {
            return result;
        }
        if (node->getLeft() != NULL)
        {
            this->inOrder(node->getLeft(), result);
        }
        result->push(node->getData());
        if (node->getRight() != NULL)
        {
            this->inOrder(node->getRight(), result);
        }
        return result;
    }
    DynamicArray<T>* postOrder(Node<T>* node, DynamicArray<T>* result)
    {
        if (node == NULL)
        {
            return result;
        }
        if (node->getLeft() != NULL)
        {
            this->postOrder(node->getLeft(), result);
        }
        if (node->getRight() != NULL)
        {
            this->postOrder(node->getRight(), result);
        }
        result->push(node->getData());
        return result;
    }
    DynamicArray<T>* levelOrder(Node<T>* node, DynamicArray<T>* result)
    {
        if (node == NULL)
        {
            return result;
        }
        return result;
    }

public:
    BinarySearchTree()
    {
    }

    bool isEmpty()
    {
        return this->nodeCount == 0;
    };
    int size()
    {
        return this->nodeCount;
    };
    int height() {
        if (this->root == NULL)
        {
            return 0;
        }
        return this->getHeight(this->root);
    };
    bool contains(T data) {
        return this->checkContain(this->root, data);
    };
    void add(T data) {
        if (this->contains(data))
        {
            return;
        }
        this->root = this->addNode(this->root, data);
        this->nodeCount++;
    };
    void remove(T data) {
        if (this->contains(data) == false)
        {
            return;
        }
        this->root = this->removeNode(this->root, data);
        this->nodeCount--;
    };
    DynamicArray<T>* traverse(TraverseType type)
    {
        DynamicArray<T>* result = new DynamicArray<T>(this->nodeCount);
        switch (type)
        {
        case PRE_ORDER:
            return this->preOrder(this->root, result);
        case IN_ORDER:
            return this->inOrder(this->root, result);
        case POST_ORDER:
            return this->postOrder(this->root, result);
        case LEVEL_ORDER:
            return this->levelOrder(this->root, result);
        default:
            return NULL;
        }
    };
};
