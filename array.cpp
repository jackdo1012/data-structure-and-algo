#include "header.h"

template <typename T>
class DynamicArray {
private:
    T* arr;
    int size;
    int capacity;
    int defaultCapacity = 10;

public:
    DynamicArray()
    {
        this->capacity = this->defaultCapacity;
        this->arr = new T[this->capacity];
    };

    DynamicArray(int capacity)
    {
        if (capacity <= 0)
        {
            throw invalid_argument("Capacity must be greater than 0");
        }
        this->capacity = capacity;
        this->arr = new T[capacity];
    }

    T* getArr()
    {
        return this->arr;
    }

    // get value at index
    T get(int index)
    {
        return this->arr[index];
    }

    // set value at index
    void set(int index, T data)
    {
        this->arr[index] = data;
    }

    // clear array
    void clear()
    {
        delete[] this->arr;
        this->size = 0;
    }

    // add value to the end of the array
    void push(T data)
    {
        if (this->size >= this->capacity - 1)
        {
            this->capacity *= 2;
            T* newArr = new T[this->capacity];
            for (int i = 0; i < this->size; i++)
            {
                newArr[i] = this->arr[i];
            }
            delete[] this->arr;
            this->arr = newArr;
        }
        this->arr[this->size++] = data;
    }

    // remove value from the beginning of the array
    void pop()
    {
        if (this->size == 0)
        {
            throw out_of_range("Array is empty");
        }
        T* newArr = new T[this->capacity];
        for (int i = 1; i < this->size; i++)
        {
            newArr[i - 1] = this->arr[i];
        }

        this->size--;
    }

    // remove value at index in the array
    void removeAt(int index)
    {
        if (index < 0 || index >= this->size)
        {
            throw out_of_range("Index out of range");
        }

        T* newArr = new T[this->size - 1];
        for (int i = 0; i < this->size; i++)
        {
            if (i >= index)
            {
                newArr[i] = this->arr[i + 1];
            }
            else
            {
                newArr[i] = this->arr[i];
            }
        }
        delete[] this->arr;
        this->arr = newArr;
        this->capacity = --this->size;
    }

    // remove value at index in the array without shifting the rest of the array
    void removeAtWithoutMoving(int index)
    {
        if (index < 0 || index >= this->size)
        {
            throw out_of_range("Index out of range");
        }
        this->arr[index] = NULL;
        this->capacity = --this->size;
    }

    // remove by value
    void remove(T data)
    {
        this->removeAt(this->indexOf(data));
    }

    // find index of value
    int indexOf(T data)
    {
        for (int i = 0; i < this->size; i++)
        {
            if (this->arr[i] == data)
            {
                return i;
            }
        }
        return -1;
    }

    // find size of the array
    int getSize()
    {
        return this->size;
    }

    bool isEmpty()
    {
        return this->size() == 0;
    }

    bool contains(T data)
    {
        return this->indexOf(data) != -1;
    }

    void print()
    {
        for (int i = 0; i < this->size; i++)
        {
            cout << this->arr[i] << " ";
        }
        cout << endl;
    }
};
