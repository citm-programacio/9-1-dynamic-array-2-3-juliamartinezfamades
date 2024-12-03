
#include <iostream>
using namespace std;


void insertInOrder(int*& array, int& size, int newNumber) {
    
    int* newArray = new int[size + 1];
    int i = 0, j = 0;
    
    while (i < size && array[i] < newNumber) {
        newArray[j++] = array[i++];
    }

    newArray[j++] = newNumber;
    
    while (i < size) {
        newArray[j++] = array[i++];
    }

    delete[] array;

    array = newArray;

    size++;
}

void printArray(int* array, int size) {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << array[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    int* array = nullptr; 
    int size = 0;
    int number;

    cout << "Ingresa numeros uno por uno (ingresa -1 para terminar):" << endl;
    while (true) {
        cout << "Numero: ";
        cin >> number;

        if (number == -1) break;

        insertInOrder(array, size, number);

        printArray(array, size);
    }
    delete[] array;

    return 0;
}
