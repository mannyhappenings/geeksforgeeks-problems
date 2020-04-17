#include<iostream>

using namespace std;

void print_array(int*, int);

void swap(int &a, int &b) {
    if (&a != &b) {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
}

void bubble_sort(int* arr, int n) {
    for(int i=0; i < n-1; i++) {
        bool swap_done = false;
        print_array(arr, n);
        for(int j=0; j<n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swap_done = true;
            }
        }
        if (!swap_done) {
            break;
        }
    }
}

void print_array(int* arr, int n) {
    cout << "[";
    for(int i=0; i<n; i++) {
        cout << "\e[1m" << arr[i] << "\e[0m";
        if (i != n-1) {
            cout << ", ";
        }
    }
    cout << "]\n";
}

void test_sort() {
    int arr[] = { 1, 34, 65, 23, 45, 12, 3, 54 };
    int n = sizeof(arr) / sizeof(int);
    cout << "Array before sort: ";
    print_array(arr, n);
    bubble_sort(arr, n);
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