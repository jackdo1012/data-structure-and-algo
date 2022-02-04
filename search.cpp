#include "header.h"

class Search {
public:
    int linearSearch(int arr[], int x, int n)
    {
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
    int binarySearch(int arr[], int x, int right, int left = 0)
    {
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
        cout << mid << endl;
        return -1;
    }
    int jumpSearch(int arr[], int x, int n)
    {
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
