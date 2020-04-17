#include<iostream>

using namespace std;

void tower_of_hanoi(int n, char from, char to, char aux1, char aux2) {
    if (n == 0) {
        return;
    }
    else if (n == 1) {
        cout << from << " -> " << to << endl;
    } else {
        tower_of_hanoi(n - 2, from, aux1, to, aux2);
        cout << from << " -> " << aux2 << endl;
        cout << from << " -> " << to << endl;
        cout << aux2 << " -> " << to << endl;
        tower_of_hanoi(n - 2, aux1, to, from, aux2);
    }
}

int tower_of_hanoi(int n) {
    tower_of_hanoi(n, 'A', 'D', 'B', 'C');
}

int main() {

    tower_of_hanoi(40);

    return 0;
}