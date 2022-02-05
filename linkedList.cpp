#include "header.h"

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node()
    {
    }

    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }

    Node(T data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

template <typename T>
class SinglyLinkedList {
public:
    Node<T>* head;
    int size;

    SinglyLinkedList()
    {
        head = NULL;
        size = 0;
    }

    // get size
    int getSize()
    {
        return this->size;
    }

    // clear the linked list
    void clear()
    {
        Node<T>* temp = head;
        head = NULL;
        for (int i = 0; i < size; i++)
        {
            temp = temp->next;
            free(temp);
        }
        size = 0;
    }

    // add a node to the beginning of the linked list
    void insertToFirst(T data)
    {
        if (head == NULL)
        {
            head = new Node<T>(data);
        }
        else
        {
            Node<T>* newNode = new Node<T>(data, head);
            head = newNode;
        }
        size++;
    }

    // add a node after the index of a node in the linked list
    void insertAfter(T data, int index)
    {
        if (index >= size)
        {
            cout << "Index out of bounds" << endl;
            return;
        }
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node<T>* temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        Node<T>* newNode = new Node<T>(data, temp->next);
        temp->next = newNode;
        size++;
    }

    // add a node to the end of the linked list
    void append(T data)
    {
        if (head == NULL)
        {
            head = new Node<T>(data);
        }
        else
        {
            Node<T>* temp = head;
            for (int i = 1; i < size; i++)
            {
                temp = temp->next;
            }
            Node<T>* newNode = new Node<T>(data);
            temp->next = newNode;
        }
        size++;
    }

    // remove a node from the linked list by its data
    void remove(T data)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node<T>* temp = head;
        for (int i = 0; i < size; i++)
        {
            if (temp->next->data == data)
            {
                free(temp->next);
                temp->next = temp->next->next;
                size--;
                return;
            }
            temp = temp->next;
        }
        cout << "Element not found" << endl;
    }

    // remove the node at the index of the linked list
    void removeAt(int index)
    {
        if (index >= size)
        {
            cout << "Index out of bounds" << endl;
            return;
        }
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        if (index == 0)
        {
            Node<T>* temp = head;
            head = head->next;
            free(temp);
            size--;
            return;
        }
        Node<T>* temp = head;
        for (int i = 1; i < index; i++)
        {
            temp = temp->next;
        }
        Node<T>* temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
        size--;
    }

    // find the index of a node data in the linked list
    int indexOf(T data)
    {
        Node<T>* temp = head;
        for (int i = 0; i < size; i++)
        {
            if (temp->data == data)
            {
                return i;
            }
            temp = temp->next;
        }
        return -1;
    }

    // specify if the linked list contains the data
    bool contains(T data)
    {
        return this->indexOf(data) != -1;
    }

    // print the linked list
    void print()
    {
        Node<T>* temp = head;

        for (int i = 0; i < size; i++)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
