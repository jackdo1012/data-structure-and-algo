#pragma once
#include "./linkedList.cpp"
#include "header.h"

template <typename T>
class Queue {
public:
    virtual void enqueue(T data) = 0;
    virtual void dequeue() = 0;
    virtual T peek() = 0;
    virtual bool isEmpty() = 0;
    virtual int getSize() = 0;
};

template <typename T>
class CircularArrayBasedQueue : public Queue<T> {
private:
    T* arr;
    int front;
    int rear;
    int capacity;

public:
    CircularArrayBasedQueue(int size)
    {
        arr = new T[size];
        this->front = 0;
        this->rear = -1;
        this->capacity = size;
    }

    void enqueue(T data) override
    {
        arr[rear + 1] = data;
        if (this->rear == this->capacity)
        {
            this->rear = 0;
        }
        else
        {
            this->rear++;
        }
        if (rear + 1 == front)
        {
            throw "Queue is full";
        }
    }

    void dequeue() override
    {
        if (this->isEmpty())
        {
            throw "Queue is empty";
        }
        T element = this->arr[this->front];
        if (this->front == this->capacity)
        {
            this->front = 0;
        }
        else
        {
            this->front++;
        }
    }

    T peek() override
    {
        if (this->isEmpty())
        {
            throw "Queue is empty";
        }
        return this->arr[front];
    }

    bool isEmpty() override
    {
        return front == rear + 1;
    }

    int getSize() override
    {
        if (rear >= front)
        {
            return rear - front;
        }
        else
        {
            return capacity - front + rear;
        }
    }
};

template <typename T>
class LinkedListBasedQueue : public Queue<T> {
private:
    DoublyLinkedList<T>* list = new DoublyLinkedList<T>();

public:
    LinkedListBasedQueue()
    {
    }

    LinkedListBasedQueue(T firstElement)
    {
        this->enqueue(firstElement);
    }

    void enqueue(T data) override
    {
        list->append(data);
    }

    void dequeue() override
    {
        if (this->isEmpty())
        {
            throw "Queue is empty";
        }
        list->removeFirst();
    }

    T peek() override
    {
        if (this->isEmpty())
        {
            throw "Queue is empty";
        }
        return list->getFirst();
    }

    bool isEmpty() override
    {
        return list->getSize() == 0;
    }

    int getSize() override
    {
        return list->getSize();
    }
};
