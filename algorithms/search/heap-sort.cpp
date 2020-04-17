#include<iostream>

using namespace std;

void print_array(int*, int, int, int);
void swap(int &, int &);

class Heap {
    private:
        int * container;
        int size;

    void heapify(int root) {
        int left_child = root * 2, right_child = root * 2 + 1;
        int largest = root;
        // Check if left child is larger than root
        if (left_child < size && container[largest] > container[left_child]) {
            largest = left_child;
        }
        // Check if right child is larger than root
        if (right_child < size && container[largest] > container[right_child]) {
            largest = right_child;
        }
        if (largest != root) {
            swap(container[root], container[largest]);
            heapify(largest);
        }
    }

    public:
        Heap(int size) {
            this->container = new int[size];
            this->size = size;
        }
        Heap(int *contents, int size) {
            this->container = new int[size];
            for (int i=0; i<size; i++) {
                this->container[i] = contents[i];
            }
            this->size = size;
        }

        void set_container(int* container, int size) {
            this->container = container;
            this->size = size;
        }

        void heapify() {
            int i=1;
            while(2 * i < size) {
                i *= 2;
            }
            for(; i>=0; i--) {
                this->heapify(i);
            }
        }

        int pop() {
            int root = container[0];
            container[0] = container[size - 1];
            
            this->size--;
            this->heapify(0);

            return root;
        }

        int get_size() {
            return size;
        }

        bool is_empty() {
            return size <= 0;
        }
};

void swap(int &a, int &b) {
    if (&a != &b) {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
}

void heap_sort(int* arr, int n) {
    Heap heap(arr, n);
    heap.heapify();
    for(int i=0; i<n; i++) {
        int p = heap.pop();
        cout << "p = " << p << endl;
        if (!heap.is_empty()) {
            arr[i] = p;
        }
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
    heap_sort(arr, n);
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