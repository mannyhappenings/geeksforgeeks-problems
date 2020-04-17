#include<iostream>

using namespace std;

void print_array(int*, int, int, int);

void swap(int &a, int &b) {
    if (&a != &b) {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
}

void insertion_sort(int* arr, int n) {
    for(int i=1; i < n; i++) {
        int j = i;
        for(; j > 0; j--) {
            if (arr[j] < arr[j-1]) {
                swap(arr[j], arr[j-1]);
            } else {
                break;
            }
        }
        print_array(arr, n, i, j);
    }
}

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

void test_sort() {
    int arr[] = { 1, 34, 65, 23, 45, 12, 3, 54 };
    int n = sizeof(arr) / sizeof(int);
    cout << "Array before sort: ";
    print_array(arr, n);
    insertion_sort(arr, n);
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