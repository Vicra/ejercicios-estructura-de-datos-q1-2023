#include <iostream>
using namespace std;

// arr needs to be sorted
void insertSorted(int array[], int size, int newValue){
    // primer caso , arreglo vacio
    if (array[0] == -1) {
        array[0] = newValue;
        return;
    }

    int positionToInsert = 0;
    for(int i = 0; i < size; i++)
    {
        // TODO: need more conditionals
        if(array[i] > newValue) {
            positionToInsert = i;
        }
        else if (array[i] == newValue) {
            positionToInsert = -1;
        }
    }

    // shift to right
    for (int i = size - 1; i >= 0; i--)
    {
        if (i+1 != size) {
            array[i+1] = array[i];
        }
    }
    
    // insert newValue in index i
    if(positionToInsert >= 0) {
        array[positionToInsert] = newValue;
    }
}

void printArray(int array[], int n){
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl << endl;
}

void initializeArray(int array[], int n){
    for (int i = 0; i < n; i++)
    {
        array[i] = -1;
    }
}

int binarySearch(int array[], int x) {

    int low = 0, high = 5;
    int mid;

    cout << "Low: " << low << endl;
    cout << "high: " << high << endl;

    while (low != high) {
        mid = (low + high)/2;
        cout << "mid: " << mid << endl;
        if(array[mid] == x){
            return mid;
        }
        else if (x > array[mid]){
            low = mid + 1;
            cout << endl << "Low: " << low << endl;
            cout << "high: " << high << endl;
        }
        else {
            high = mid - 1;
            cout << endl << "Low: " << low << endl;
            cout << "high: " << high << endl;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{

    int array[5] = {1, 2, 3, 5, 6};
    // initializeArray(array, 100);
    // insertSorted(array, 100, 3);
    // printArray(array, 100);
    // insertSorted(array, 100, 1);
    // printArray(array, 100);

    // insertSorted(array, 100, 4);
    // printArray(array, 100);
    cout << "Position BinSearch: " << binarySearch(array, 4) << endl << endl;
    cout << "Position BinSearch: " << binarySearch(array, 5) << endl;

    return 0;
}

