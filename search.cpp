#include "header.h"

class Search {
public:
    /*
     * @param arr: an array of integers
     * @param x: search value
     * @param n: length of the array
     * @return: index of the search value
     */
    int linearSearch(int arr[], int x, int n)
    {
        // loop through the array and find the index of the search value
        int result = -1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == x)
            {
                result = i;
                break;
            }
        }
        return result;
    }

    /*
     * @param arr: an array of integers
     * @param x: search value
     * @param right: length of the array
     * @return: index of the search value
     */
    int binarySearch(int arr[], int x, int right, int left = 0)
    {
        /* divide the array into two parts. If the search value is in the middle, return the index. If the search value is in the left part, perform the binarySearch in the left part. If the search value is in the right part, perform the binarySearch in the right part */
        int mid = (left + right) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] < x)
        {
            return this->binarySearch(arr, x, right, mid + 1);
        }
        else if (arr[mid] > x)
        {
            return this->binarySearch(arr, x, mid, 0);
        }
        return -1;
    }

    /*
     * @param arr: an array of integers
     * @param x: search value
     * @param n: length of the array
     * @return: index of the search value
     */
    int jumpSearch(int arr[], int x, int n)
    {
        /*
           find the index range of the searchValue by increasing the index by sqrt(length) while the value is smaller than the search value, which is the lower bound. Then specify the upper bound by adding sqrt(length) to the lower bound
        */
        int steps = sqrt(n);
        int prev = 0;
        while (arr[prev + steps] < x)
        {
            prev += steps;
        }
        int next = prev + steps;

        for (int i = prev; i < next; i++)
        {
            if (arr[i] == x)
            {
                return i;
            }
        }
        return -1;
    }
};
