#include<iostream>

using namespace std;

int find_min_index(int* arr, int n, int start) {
    int min_index = start;
    for(int i=start+1; i<n; i++) {
        min_index = arr[min_index] > arr[i] ? i : min_index;
    }

    return min_index;
}

void swap(int &a, int &b) {
    if (&a != &b) {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
}

void selection_sort(int* arr, int n) {
    for(int i=0; i < n; i++) {
        int min_index = find_min_index(arr, n, i);
        swap(arr[i], arr[min_index]);
    }
}

void print_array(int* arr, int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void test_sort() {
    int arr[] = { 1, 34, 65, 23, 45, 12, 3, 54 };
    int n = sizeof(arr) / sizeof(int);
    cout << "Array before sort: ";
    print_array(arr, n);
    selection_sort(arr, n);
    cout << "Array after sort: ";
    print_array(arr, n);
}

void test_swap() {
    // int arr[] = {1_}
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