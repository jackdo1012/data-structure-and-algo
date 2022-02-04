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
    return 0;
}