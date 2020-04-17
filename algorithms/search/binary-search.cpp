#include<iostream>

using namespace std;

int binary_search(int *arr, int start, int end, int el) {
    if (start > end) {
        return -1;
    }
    int mid = start + (end - start) / 2;

    if (el == arr[mid]) {
        return mid;
    } else if (el > arr[mid]) {
        return binary_search(arr, mid + 1, end, el);
    } else {
        return binary_search(arr, start, mid - 1, el);
    }
}

int binary_search_iterative(int *arr, int size, int el) {
    int start = 0, end = size - 1;
    int pos = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (el == arr[mid]) {
            pos = mid;
            break;
        } else if (el > arr[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return pos;
}

void test_binary_search(int test_el) {
    // int arr[] = { 1, 4, 65, 3, 54, 6, 56, 45 };
    int arr[] = { 1, 3, 4, 6, 45, 54, 56, 65};
    int n = sizeof(arr) / sizeof(int);
    cout << "position for " << test_el << " is " << binary_search_iterative(arr, n, test_el) << endl;
}

void test() {
    test_binary_search(65);
    test_binary_search(3);
    test_binary_search(6);
    test_binary_search(47);
}

int main() {

    test();

    return 0;
}