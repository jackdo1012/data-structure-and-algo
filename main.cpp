#include "./array.cpp"
#include "./binaryTree.cpp"
#include "./queue.cpp"
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

    sorted = sort.bubbleSort(testArr, size, 1);
    cout << "Bubble sort array: ";
    printArray(sorted, size);

    sorted = sort.selectionSort(testArr, size, 1);
    cout << "Selection sort array: ";
    printArray(sorted, size);

    sorted = sort.insetionSort(testArr, size, 1);
    cout << "Insertion sort array: ";
    printArray(sorted, size);

    index = search.linearSearch(testArr, searchValue, size);
    cout << "Linear search index: " << index << endl;

    index = search.binarySearch(sorted, searchValue, size);
    cout << "Binary search index: " << index << endl;

    index = search.jumpSearch(sorted, searchValue, size);
    cout << "Jump search index: " << index << endl;

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

    cout << "---Array Based Queue---" << endl;
    CircularArrayBasedQueue<string>* newArrayBasedQueue = new CircularArrayBasedQueue<string>(10);
    newArrayBasedQueue->enqueue("Hello1");
    newArrayBasedQueue->enqueue("Hello2");
    newArrayBasedQueue->enqueue("Hello3");
    newArrayBasedQueue->enqueue("Hello4");
    newArrayBasedQueue->enqueue("Hello5");
    newArrayBasedQueue->enqueue("Hello6");
    newArrayBasedQueue->enqueue("Hello7");
    newArrayBasedQueue->enqueue("Hello8");
    newArrayBasedQueue->enqueue("Hello9");
    newArrayBasedQueue->enqueue("Hello10");
    while (!newArrayBasedQueue->isEmpty())
    {
        cout << newArrayBasedQueue->peek() << endl;
        newArrayBasedQueue->dequeue();
    }

    cout << "---Linked List Based Queue---" << endl;
    LinkedListBasedQueue<string>* newLinkedListBasedQueue = new LinkedListBasedQueue<string>();
    newLinkedListBasedQueue->enqueue("Hello1");
    newLinkedListBasedQueue->enqueue("Hello2");
    newLinkedListBasedQueue->enqueue("Hello3");
    newLinkedListBasedQueue->enqueue("Hello4");
    newLinkedListBasedQueue->enqueue("Hello5");
    newLinkedListBasedQueue->enqueue("Hello6");
    newLinkedListBasedQueue->enqueue("Hello7");
    newLinkedListBasedQueue->enqueue("Hello8");
    newLinkedListBasedQueue->enqueue("Hello9");
    newLinkedListBasedQueue->enqueue("Hello10");
    while (!newLinkedListBasedQueue->isEmpty())
    {
        cout << newLinkedListBasedQueue->peek() << endl;
        newLinkedListBasedQueue->dequeue();
    }
    cout << "---Binary Search Tree---" << endl;
    BinarySearchTree<int>* newBinarySearchTree = new BinarySearchTree<int>();
    newBinarySearchTree->add(0);
    newBinarySearchTree->add(100);
    newBinarySearchTree->add(70);
    newBinarySearchTree->add(80);
    newBinarySearchTree->add(50);
    newBinarySearchTree->add(150);
    newBinarySearchTree->remove(0);
    DynamicArray<int>* binarySearchTree = newBinarySearchTree->traverse(TraverseType::IN_ORDER);
    binarySearchTree->print();

    return 0;
}
