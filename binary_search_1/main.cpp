/**
 * @file main.cpp
 * @Synopsis  Example for binary search in CPP.
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.2
 * @date 2013-07-10
 */

#include <iostream>

using namespace std;

/// O(lg(n))
int binary_search(int arr[], int low, int high, int key) {
    if(low > high) {
        return -1;
    }
    int mid = (low + high)/2;
    if(key == arr[mid]) {
        return mid;
    } else if(key >= mid) {
        return binary_search(arr, mid, high-1, key);
    } else {
        return binary_search(arr, low+1, mid, key);
    }
}

int main(int argc, char *argv[]) {
    int array[20] = {1,2,3,4,5,6,7,8,9,10,
                     11,12,13,14,15,16,17,18,19,20
                    };
    int index = binary_search(array, 0, sizeof(array)/sizeof(array[0]), 11);
    cout<<index<<endl;
    cout<<"--Done.--"<<endl;
    return 0;
}
