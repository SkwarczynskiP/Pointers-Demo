#include <iostream>
#include <cstdlib>
using namespace std;

int* generate(unsigned int);
int* duplicate(int *, unsigned int);
void display(int *, unsigned int);

int main() {
    unsigned int n;
    cout << "Enter the size of the dynamic array: ";
    cin >> n;

    int* dynamicArray = generate(n);
    int* duplicatedDynamicArray = duplicate(dynamicArray, n);
    display(duplicatedDynamicArray, n*2);

    delete []dynamicArray;
    delete []duplicatedDynamicArray;
    return 0;
}

int* generate(unsigned int n) {
    int* dynamicArray = new int[n];

    srand(time(0));

    for(int i = 0; i < n; i++) {
        dynamicArray[i] = rand() % 101;
    }
    return dynamicArray;
}

int* duplicate(int *originalDynamicArray, unsigned int n) {
    int* duplicatedDynamicArray = new int[n*2];

    for(int i = 0; i < n; i++) {
        duplicatedDynamicArray[i] = originalDynamicArray[i];
        duplicatedDynamicArray[i + n] = originalDynamicArray[i];
    }

    return duplicatedDynamicArray;
}

void display(int *duplicatedDynamicArray, unsigned int size){
    cout << "\nContents of the duplicated dynamic array:" << endl;
    for(int i = 0; i < size; i++) {
        cout << duplicatedDynamicArray[i] << " ";
        if( (i+1) % 8 == 0) {
            cout << endl;
        }
    }
}
