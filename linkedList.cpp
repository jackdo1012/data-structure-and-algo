#include "header.h"

template <typename T>
class LinkedList {
private:
    int size;

public:
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
class SinglyLinkedList : public LinkedList<T> {
private:
    SLLNode<T>* head;
    int size;

public:
    SinglyLinkedList()
    {
        head = NULL;
        size = 0;
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
            cout << "List is empty" << endl;
            return;
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
            cout << "List is empty" << endl;
            return;
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
            cout << "List is empty" << endl;
            return;
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
class DoublyLinkedList : public LinkedList<T> {
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

    int getSize() override
    {
        return this->size;
    }

    void clear() override
    {
        DLLNode<T>* processing = this->head;
        head = NULL;
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
            cout << "List is empty" << endl;
            return;
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
            cout << "List is empty" << endl;
            return;
        }
        DLLNode<T>* temp = this->head;
        for (int i = 0; i < size; i++)
        {
            if (temp->getNext()->getData() == data)
            {
                free(temp->getNext());
                temp->setNext(temp->getNext()->getNext());
                temp->getNext()->setPrev(temp);
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
            cout << "List is empty" << endl;
            return;
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
        DLLNode<T>* itemNeededToBeRemoved = temp->getNext();
        temp->setNext(itemNeededToBeRemoved->getNext());
        if (itemNeededToBeRemoved->getNext() != NULL)
        {
            itemNeededToBeRemoved->getNext()->setPrev(temp);
        }
        free(itemNeededToBeRemoved);
        size--;
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
