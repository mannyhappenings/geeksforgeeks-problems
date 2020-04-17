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

void merge(int* arr, int start, int mid, int end) {
    cout << "start: " << start << ", mid: " << mid << ", end: " << end << endl;
    int size = end - start + 1;
    int aux_array[size];
    int i = start, j = mid + 1, k=0;
    while (i<=mid && j<=end) {
        if (arr[i] <= arr[j]) {
            aux_array[k++] = arr[i++];
        } else {
            aux_array[k++] = arr[j++];
        }
    }
    while (i<=mid) {
        aux_array[k++] = arr[i++];
    }
    while (j<=end) {
        aux_array[k++] = arr[j++];
    }
    for(int i=0; i<size; i++) {
        arr[i+start] = aux_array[i];
    }
}

void merge_sort(int* arr, int start, int end) {
    if (start >= end) {
        return;
    }

    int mid = start + (end - start) / 2;
    print_array(arr+start, end-start+1, mid-start);
    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);
    merge(arr, start, mid, end);
    print_array(arr+start, end-start+1, mid-start);
}

void test_sort() {
    int arr[] = { 1, 34, 65, 23, 45, 12, 3, 54 };
    int n = sizeof(arr) / sizeof(int);
    cout << "Array before sort: ";
    print_array(arr, n);
    merge_sort(arr, 0, n-1);
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