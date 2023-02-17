#include <iostream>
#include <string>

using namespace std;

int search (int array[], int size, int key, int index){
    cout << "searching index: " << index << endl;
    if(index == size){
        return -1;
    } else if(array[index] == key) {
        return index;
    } else {
        search(array, size, key, index + 1);
    }
}

int main(int argc, char const *argv[])
{
    int array [5] = {1, 2, 3, 4, 5};
    cout << search(array, 5, 3, 0) << endl;
    return 0;
}
