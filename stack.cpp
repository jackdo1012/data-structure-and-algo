#pragma once
#include "./array.cpp"
#include "./linkedList.cpp"
#include "header.h"

template <typename T>
class StackADT {
public:
    virtual void push(T value) = 0;
    virtual void pop() = 0;
    virtual T top() = 0;
    virtual int getSize() = 0;
    virtual bool isEmpty() = 0;
};

template <typename T>
class ArrayBasedStack : public StackADT<T> {
private:
    DynamicArray<T>* array;
    int index = -1;

public:
    ArrayBasedStack(int size)
    {
        this->array = new DynamicArray<T>(size);
    }

    void push(T value) override
    {
        this->index++;
        array->push(value);
    }

    void pop() override
    {
        if (this->isEmpty())
        {
            throw new invalid_argument("Stack is empty");
        }
        array->pop();
        this->index--;
    }

    T top() override
    {
        return array->get(this->index);
    }

    int getSize() override
    {
        return array->getSize();
    }

    bool isEmpty() override
    {
        return array->isEmpty();
    }
    T* getArray()
    {
        return array->getArray();
    }
};

template <typename T>
class LinkedListBasedStack : public StackADT<T> {
private:
    DoublyLinkedList<T>* list;

public:
    LinkedListBasedStack()
    {
        this->list = new DoublyLinkedList<T>();
    }

    void push(T value) override
    {

        this->list->append(value);
    }

    void pop() override
    {
        if (this->isEmpty())
        {
            throw new invalid_argument("Stack is empty");
        }
        list->removeLast();
    }

    T top() override
    {
        if (this->isEmpty())
        {
            throw new invalid_argument("Stack is empty");
        }
        return list->getLast();
    }

    int getSize() override
    {
        return list->getSize();
    }

    bool isEmpty() override
    {
        return list->getSize() == 0;
    }
};
