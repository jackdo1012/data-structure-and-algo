#include "./linkedList.cpp"
#include "./search.cpp"
#include "./sort.cpp"
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

    cout << "Singly Linked List" << endl;
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

    cout << "Doubly Linked List" << endl;
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

    return 0;
}
