#include<iostream>

using namespace std;

void print_array(int*, int, int, int);
void swap(int &, int &);
void print_array(int* arr, int n, int marked_1 = -1, int marked_2 = -1) {
    cout << "[";
    for(int i=0; i<n; i++) {
        if (i == marked_1 || i == marked_2) {
            cout << "\e[1m" << arr[i] << "\e[0m";
        } else {
            cout << arr[i];
        }
        if (i != n-1) {
            cout << ", ";
        }
    }
    cout << "]\n";
}

void swap(int &a, int &b) {
    if (&a != &b) {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
}

int partition(int *arr, int start, int end) {
    int pivot = arr[start];
    int smaller = start;
    for(int i=start+1; i<=end; i++) {
        if (pivot > arr[i]) {
            swap(arr[++smaller], arr[i]);
        }
    }
    swap(arr[smaller], arr[start]);
    
    return smaller;
}

void quick_sort(int* arr, int start, int end) {
    if (start >= end) {
        return;
    }

    int partition_index = partition(arr, start, end);
    print_array(arr+start, end - start + 1, partition_index-start, -1);
    quick_sort(arr, start, partition_index - 1);
    quick_sort(arr, partition_index + 1, end);
}

void test_sort() {
    int arr[] = { 1, 34, 65, 23, 45, 12, 3, 54 };
    int n = sizeof(arr) / sizeof(int);
    cout << "Array before sort: ";
    print_array(arr, n);
    quick_sort(arr, 0, n-1);
    cout << "Array after sort: ";
    print_array(arr, n);
}

void test_swap() {
    int a = 1;
    cout << "a = " << a << ", a = " << a << endl;
    swap(a, a);
    cout << "a = " << a << ", a = " << a << endl;
}

int main() {
    test_sort();
    // test_swap();

    return 0;
}