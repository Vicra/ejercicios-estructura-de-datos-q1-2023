#include <iostream>
#include <string>

using namespace std;

void print(int array[], int size, int index){
    if(index != size) {
        cout << array [index];
        print(array, size, index + 1);
    }
}

int main(int argc, char const *argv[])
{
    int array[4] = {1, 2, 3, 4};
    print(array, 4, 0);
    return 0;
}
