#include "./search.cpp"
#include "./sort.cpp"
#include "./stack.cpp"
#include <iostream>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    cout << "-----------------Algorithm-----------------" << endl;
    Sort sort;
    Search search;

    int testArr[] = { 2345, 12, 45, 10, 54, 65, 99, 35, 9190, -12 };
    int size = sizeof(testArr) / sizeof(testArr[0]);
    int searchValue = 99;

    int index;
    int* sorted;

    /* sorted = sort.bubbleSort(testArr, size, -1); */
    /* sorted = sort.selectionSort(testArr, size); */
    sorted = sort.insetionSort(testArr, size, 1);

    /* index = search.linearSearch(testArr, searchValue, size); */
    /* index = search.binarySearch(sorted, searchValue, size); */
    index = search.jumpSearch(sorted, searchValue, size);

    cout << "Sorted array: ";
    printArray(sorted, size);
    cout << "Index: " << index << endl;

    cout << "-----------------Data Structure-----------------" << endl;
    cout << "---Singly Linked List---" << endl;
    SinglyLinkedList<string>* newLinkedList = new SinglyLinkedList<string>();
    newLinkedList->append("world");
    newLinkedList->append("Jack");
    newLinkedList->append("Do");
    newLinkedList->insertToFirst("hello");
    newLinkedList->insertAfter("from", 1);
    newLinkedList->append("wrong value");
    newLinkedList->append("wrong value 2");
    newLinkedList->remove("wrong value");
    newLinkedList->removeAt(5);
    newLinkedList->print();
    cout << newLinkedList->indexOf("hello") << endl;
    cout << newLinkedList->getSize() << endl;

    cout << "---Doubly Linked List---" << endl;
    DoublyLinkedList<string>* newLinkedList2 = new DoublyLinkedList<string>();
    newLinkedList2->append("world");
    newLinkedList2->append("Jack");
    newLinkedList2->append("Do");
    newLinkedList2->insertToFirst("hello");
    newLinkedList2->insertAfter("from", 1);
    newLinkedList2->append("wrong value");
    newLinkedList2->append("wrong value 2");
    newLinkedList2->remove("wrong value");
    newLinkedList2->removeAt(5);
    newLinkedList2->print();
    cout << newLinkedList2->indexOf("hello") << endl;
    cout << newLinkedList2->getSize() << endl;

    cout << "---Dynamic Array---" << endl;
    DynamicArray<string>* newDynamicArray = new DynamicArray<string>();
    newDynamicArray->push("temp");
    newDynamicArray->push("world");
    newDynamicArray->push("from");
    newDynamicArray->push("Jack");
    newDynamicArray->push("Do");
    newDynamicArray->push("wrong value");
    newDynamicArray->push("wrong value 2");
    newDynamicArray->remove("wrong value");
    newDynamicArray->removeAt(5);
    newDynamicArray->set(0, "Hello");
    newDynamicArray->print();

    cout << "---Array Based Stack---" << endl;
    ArrayBasedStack<string>* newArrayBasedStack = new ArrayBasedStack<string>(10);
    newArrayBasedStack->push("Hello");
    newArrayBasedStack->push("World");
    newArrayBasedStack->push("from");
    newArrayBasedStack->push("Jack");
    newArrayBasedStack->push("Do");
    while (!newArrayBasedStack->isEmpty())
    {
        cout << newArrayBasedStack->top() << endl;
        newArrayBasedStack->pop();
    }

    cout << "---LinkedList Based Stack---" << endl;
    LinkedListBasedStack<string>* newLinkedListBasedStack = new LinkedListBasedStack<string>();
    newLinkedListBasedStack->push("Hello");
    newLinkedListBasedStack->push("World");
    newLinkedListBasedStack->push("from");
    newLinkedListBasedStack->push("Jack");
    newLinkedListBasedStack->push("Do");

    while (!newLinkedListBasedStack->isEmpty())
    {
        cout << newLinkedListBasedStack->top() << endl;
        newLinkedListBasedStack->pop();
    }

    return 0;
}
