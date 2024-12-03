#include <iostream>
using namespace std;


int* ordenar(int* array, int size, int newNumber, int& newSize) {
    newSize = size + 1; 
    int* newArray = new int[newSize]; 
    int i = 0, j = 0;

    
    while (i < size && array[i] < newNumber) {
        newArray[j++] = array[i++];
    }

    
    newArray[j++] = newNumber;

    while (i < size) {
        newArray[j++] = array[i++];
    }

    return newArray;
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

       
        int newSize;
        int* newArray = ordenar(array, size, number, newSize);

        
        delete[] array;

        array = newArray;
        size = newSize;

        printArray(array, size);
    }

    delete[] array;

    return 0;
}
