#pragma once
#include "header.h"

template <typename T>
class LinkedListADT {
private:
    int size;

public:
    // get at index
    virtual T get(int index) = 0;
    // get the first element
    virtual T getFirst() = 0;
    // get the last element
    virtual T getLast() = 0;
    // get size
    virtual int getSize() = 0;
    // clear the linked list
    virtual void clear() = 0;
    // add a node to the beginning of the linked list
    virtual void insertToFirst(T data) = 0;
    // add a node after the index of a node in the linked list
    virtual void insertAfter(T data, int index) = 0;
    // add a node to the end of the linked list
    virtual void append(T data) = 0;
    // remove a node from the linked list by its data
    virtual void remove(T data) = 0;
    // remove the node at the index of the linked list
    virtual void removeAt(int index) = 0;
    // remove the first node of the linked list
    virtual void removeFirst() = 0;
    // remove the last node of the linked list
    virtual void removeLast() = 0;
    // find the index of a node data in the linked list
    virtual int indexOf(T data) = 0;
    // specify if the linked list contains the data
    virtual bool contains(T data) = 0;
    // print the linked list
    virtual void print() = 0;
};

template <typename T>
class SLLNode {
private:
    T data;
    SLLNode* next;

public:
    SLLNode()
    {
    }

    SLLNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }

    SLLNode(T data, SLLNode* next)
    {
        this->data = data;
        this->next = next;
    }

    T getData()
    {
        return this->data;
    }

    void setData(T data)
    {
        this->data = data;
    }

    SLLNode* getNext()
    {
        return this->next;
    }

    void setNext(SLLNode* next)
    {
        this->next = next;
    }
};

template <typename T>
class SinglyLinkedList : public LinkedListADT<T> {
private:
    SLLNode<T>* head;
    int size;

public:
    SinglyLinkedList()
    {
        head = NULL;
        size = 0;
    }

    T get(int index) override
    {
        if (index < 0 || index >= size)
        {
            throw "Index out of bounds";
        }

        SLLNode<T>* current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->getNext();
        }

        return current->getData();
    }

    T getFirst() override
    {
        if (this->size == 0)
        {
            throw "Empty linked list";
        }

        return head->getData();
    }

    T getLast() override
    {
        if (this->size == 0)
        {
            throw "Empty linked list";
        }

        SLLNode<T>* current = head;
        while (current->getNext() != NULL)
        {
            current = current->getNext();
        }

        return current->getData();
    }

    int getSize() override
    {
        return this->size;
    }

    void clear() override
    {
        SLLNode<T>* processing = this->head;
        this->head = NULL;
        for (int i = 0; i < size; i++)
        {
            SLLNode<T>* temp = processing;
            processing = temp->getNext();
            free(temp);
        }
        size = 0;
        free(processing);
    }

    void insertToFirst(T data) override
    {
        if (this->head == NULL)
        {
            this->head = new SLLNode<T>(data);
        }
        else
        {
            SLLNode<T>* newNode = new SLLNode<T>(data, this->head);
            this->head = newNode;
        }
        size++;
    }

    void insertAfter(T data, int index) override
    {
        if (index >= size)
        {
            throw out_of_range("Index out of range");
        }
        if (this->head == NULL)
        {
            throw new invalid_argument("List is empty");
        }
        SLLNode<T>* temp = this->head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->getNext();
        }
        SLLNode<T>* newNode = new SLLNode<T>(data, temp->getNext());
        temp->setNext(newNode);
        size++;
    }

    void append(T data) override
    {
        if (this->head == NULL)
        {
            this->head = new SLLNode<T>(data);
        }
        else
        {
            SLLNode<T>* temp = this->head;
            for (int i = 1; i < size; i++)
            {
                temp = temp->getNext();
            }
            SLLNode<T>* newNode = new SLLNode<T>(data);
            temp->setNext(newNode);
        }
        size++;
    }

    void remove(T data) override
    {
        if (this->head == NULL)
        {
            throw new invalid_argument("List is empty");
        }
        SLLNode<T>* temp = this->head;
        for (int i = 0; i < size; i++)
        {
            if (temp->getNext()->getData() == data)
            {
                SLLNode<T>* itemNeededToBeRemoved = temp->getNext();
                temp->setNext(itemNeededToBeRemoved->getNext());
                free(itemNeededToBeRemoved);
                size--;
                return;
            }
            temp = temp->getNext();
        }
        cout << "Element not found" << endl;
    }

    void removeAt(int index) override
    {
        if (index >= size)
        {
            throw out_of_range("Index out of range");
        }
        if (this->head == NULL)
        {
            throw new invalid_argument("List is empty");
        }
        if (index == 0)
        {
            SLLNode<T>* temp = this->head;
            this->head = this->head->getNext();
            free(temp);
            size--;
            return;
        }
        SLLNode<T>* temp = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->getNext();
        }
        SLLNode<T>* itemNeededToBeRemoved = temp->getNext();
        temp->setNext(itemNeededToBeRemoved->getNext());
        free(itemNeededToBeRemoved);
        size--;
    }

    void removeFirst() override
    {
        if (this->head == NULL)
        {
            throw new invalid_argument("List is empty");
        }
        SLLNode<T>* temp = this->head;
        this->head = this->head->getNext();
        free(temp);
        this->size--;
    }

    void removeLast() override
    {
        if (this->head == NULL)
        {
            throw new invalid_argument("List is empty");
        }
        SLLNode<T>* temp = this->head;
        for (int i = 0; i < size - 1; i++)
        {
            temp = temp->getNext();
        }
        SLLNode<T>* itemNeededToBeRemoved = temp->getNext();
        temp->setNext(NULL);
        free(itemNeededToBeRemoved);
        this->size--;
    }

    int indexOf(T data) override
    {
        SLLNode<T>* temp = this->head;
        for (int i = 0; i < size; i++)
        {
            if (temp->getData() == data)
            {
                return i;
            }
            temp = temp->getNext();
        }
        return -1;
    }

    bool contains(T data) override
    {
        return this->indexOf(data) != -1;
    }

    void print() override
    {
        SLLNode<T>* temp = this->head;

        for (int i = 0; i < size; i++)
        {
            cout << temp->getData() << " ";
            temp = temp->getNext();
        }
        cout << endl;
    }
};

template <typename T>
class DLLNode {
private:
    T data;
    DLLNode* next;
    DLLNode* prev;

public:
    DLLNode()
    {
    }

    DLLNode(DLLNode* prev, T data, DLLNode* next)
    {
        this->prev = prev;
        this->data = data;
        this->next = next;
    }
    T getData()
    {
        return this->data;
    }
    void setData(T data)
    {
        this->data = data;
    }

    DLLNode* getNext()
    {
        return this->next;
    }

    void setNext(DLLNode* next)
    {
        this->next = next;
    }

    DLLNode* getPrev()
    {
        return this->prev;
    }

    void setPrev(DLLNode* prev)
    {
        this->prev = prev;
    }
};

template <typename T>
class DoublyLinkedList : public LinkedListADT<T> {
private:
    DLLNode<T>* head;
    DLLNode<T>* tail;
    int size;

public:
    DoublyLinkedList()
    {
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }

    T get(int index) override
    {
        if (this->head == NULL)
        {
            throw new invalid_argument("List is empty");
        }
        if (index >= size)
        {
            throw out_of_range("Index out of range");
        }
        DLLNode<T>* temp = this->head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->getNext();
        }
        return temp->getData();
    }

    T getFirst() override
    {
        if (this->head == NULL)
        {
            throw new invalid_argument("List is empty");
        }
        return this->head->getData();
    }

    T getLast() override
    {
        if (this->head == NULL)
        {
            throw new invalid_argument("List is empty");
        }
        return this->tail->getData();
    }

    int getSize() override
    {
        return this->size;
    }

    void clear() override
    {
        DLLNode<T>* processing = this->head;
        this->head = NULL;
        this->tail = NULL;
        for (int i = 0; i < size; i++)
        {
            DLLNode<T>* temp = processing;
            processing = temp->getNext();
            free(temp);
        }
        free(processing);
        size = 0;
    }

    void insertToFirst(T data) override
    {
        if (this->head == NULL)
        {
            this->head = new DLLNode<T>(NULL, data, NULL);
            this->tail = this->head;
        }
        else
        {
            DLLNode<T>* newNode = new DLLNode<T>(NULL, data, this->head);
            this->head->setPrev(newNode);
            this->head = this->head->getPrev();
        }
        size++;
    }

    void append(T data) override
    {
        if (this->head == NULL)
        {
            this->head = new DLLNode<T>(NULL, data, NULL);
            this->tail = this->head;
        }
        else
        {
            DLLNode<T>* newNode = new DLLNode<T>(this->tail, data, NULL);
            this->tail->setNext(newNode);
            this->tail = this->tail->getNext();
        }
        size++;
    }

    void insertAfter(T data, int index) override
    {
        if (index >= size)
        {
            throw out_of_range("Index out of range");
        }
        if (this->head == NULL)
        {
            throw new invalid_argument("List is empty");
        }
        DLLNode<T>* temp = this->head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->getNext();
        }
        DLLNode<T>* newNode = new DLLNode<T>(temp, data, temp->getNext());
        temp->getNext()->setPrev(newNode);
        temp->setNext(newNode);
        size++;
    }

    void remove(T data) override
    {
        if (this->head == NULL)
        {
            throw new invalid_argument("List is empty");
        }
        if (this->size == 1)
        {
            this->clear();
            return;
        }
        DLLNode<T>* temp = this->head;
        for (int i = 0; i < size; i++)
        {
            if (temp->getNext()->getData() == data)
            {
                if (temp == NULL)
                {
                    this->removeFirst();
                    return;
                }
                if (temp->getNext()->getNext() == NULL)
                {
                    this->removeLast();
                    return;
                }
                DLLNode<T>* removeNode = temp->getNext();
                temp->setNext(removeNode->getNext());
                temp->getNext()->setPrev(temp);
                free(removeNode);
                size--;
                return;
            }
            temp = temp->getNext();
        }
        cout << "Element not found" << endl;
    }

    void removeAt(int index) override
    {
        if (index >= size)
        {
            throw out_of_range("Index out of range");
        }
        if (this->size == 1)
        {
            this->clear();
            return;
        }
        if (this->head == NULL)
        {
            throw new invalid_argument("List is empty");
        }
        if (index == 0)
        {
            DLLNode<T>* temp = this->head;
            this->head = temp->getNext();
            this->head->setPrev(NULL);
            free(temp);
            size--;
            return;
        }
        DLLNode<T>* temp = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->getNext();
        }
        if (temp == NULL)
        {
            this->removeFirst();
            return;
        }
        if (temp->getNext()->getNext() == NULL)
        {
            this->removeLast();
            return;
        }
        DLLNode<T>* itemNeededToBeRemoved = temp->getNext();
        temp->setNext(itemNeededToBeRemoved->getNext());
        if (itemNeededToBeRemoved->getNext() != NULL)
        {
            itemNeededToBeRemoved->getNext()->setPrev(temp);
        }
        free(itemNeededToBeRemoved);
        size--;
    }

    void removeFirst() override
    {
        if (this->head == NULL)
        {
            throw new invalid_argument("List is empty");
        }
        if (this->size == 0)
        {
            this->head = NULL;
            this->tail = NULL;
        }
        else if (this->size == 1)
        {
            this->clear();
            return;
        }
        else
        {
            DLLNode<T>* temp = this->head;
            this->head = temp->getNext();
            this->head->setPrev(NULL);
            free(temp);
        }
        this->size--;
    }

    void removeLast() override
    {
        if (this->head == NULL)
        {
            throw new invalid_argument("List is empty");
        }
        DLLNode<T>* temp = this->tail;
        if (this->size == 0)
        {
            this->head = NULL;
            this->tail = NULL;
        }
        else if (this->size == 1)
        {
            this->clear();
            return;
        }
        else
        {
            this->tail->getPrev()->setNext(NULL);
            this->tail = this->tail->getPrev();
            free(temp);
        }
        this->size--;
    }

    int indexOf(T data) override
    {
        DLLNode<T>* temp = this->head;

        for (int i = 0; i < size; i++)
        {
            if (temp->getData() == data)
            {
                return i;
            }
            temp = temp->getNext();
        }
        return -1;
    }

    bool contains(T data) override
    {
        return this->indexOf(data) != -1;
    }

    void print() override
    {
        DLLNode<T>* temp = this->head;

        for (int i = 0; i < size; i++)
        {
            cout << temp->getData() << " ";
            temp = temp->getNext();
        }
        cout << endl;
    }
};
