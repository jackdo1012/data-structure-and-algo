#include "header.h"

class Sort {
public:
    /*
     * @param arr: an array of integers
     * @param n: length of the array
     * @param order: 1: ascending, 0: descending
     * @return: sorted array
     */
    int* bubbleSort(int arr[], int n, int order = 1)
    {
        if (order != -1 && order != 1)
        {
            order = 1;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (order == 1)
                {
                    if (arr[j] > arr[j + 1])
                    {
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
                else if (order == -1)
                {
                    if (arr[j] < arr[j + 1])
                    {
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
        }
        return arr;
    }

    /*
     * @param arr: an array of integers
     * @param n: length of the array
     * @param order: 1: ascending, 0: descending
     * @return: sorted array
     */
    int* selectionSort(int arr[], int n, int order = 1)
    {
        if (order != -1 && order != 1)
        {
            order = 1;
        }
        for (int i = 0; i < n; i++)
        {
            int minIndex = i;
            for (int j = i; j < n; j++)
            {
                if (arr[j] < arr[minIndex])
                {
                    minIndex = j;
                }
            }
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
        return arr;
    }

    /*
     * @param arr: an array of integers
     * @param n: length of the array
     * @param order: 1: ascending, 0: descending
     * @return: sorted array
     */
    int* insetionSort(int arr[], int n, int order = 1)
    {
        if (order != -1 && order != 1)
        {
            order = 1;
        }
        for (int i = 1; i < n; i++)
        {
            int temp = arr[i];
            for (int j = i; j >= 0; j--)
            {
                if (order == 1)
                {
                    if (j == 0 || arr[j - 1] < temp)
                    {
                        arr[j] = temp;
                        break;
                    }
                    else if (arr[j - 1] > temp)
                    {
                        arr[j] = arr[j - 1];
                    }
                }
                else if (order == -1)
                {
                    if (j == 0 || arr[j - 1] > temp)
                    {
                        arr[j] = temp;
                        break;
                    }
                    else if (arr[j - 1] < temp)
                    {
                        arr[j] = arr[j - 1];
                    }
                }
            }
        }
        return arr;
    }
};
