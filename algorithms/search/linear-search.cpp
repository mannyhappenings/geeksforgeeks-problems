#include<iostream>

using namespace std;

int lenear_search(int *arr, int n, int el) {
    int pos = -1;

    for (int i=0; i<n; i++) {
        if (arr[i] == el) {
            pos = i;
        }
    }

    return pos;
}

void test_linear_search(int test_el) {
    int arr[] = { 1, 4, 65, 3, 54, 6, 56, 45 };
    int n = sizeof(arr) / sizeof(int);
    cout << "position for " << test_el << " is " << lenear_search(arr, n, test_el) << endl;
}

void test() {
    test_linear_search(65);
    test_linear_search(3);
    test_linear_search(6);
    test_linear_search(47);
}

int main() {

    test();

    return 0;
}