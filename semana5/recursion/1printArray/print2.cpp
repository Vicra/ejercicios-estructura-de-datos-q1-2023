#include <iostream>
using namespace std;

string printRecursive(int array[], int size, int index){
    if(index < size){
        return to_string(array[index]) 
        + printRecursive(array, size, index + 1);   
    }
    return "";
}

int main(int argc, char const *argv[])
{
    int array[5] = {1,2,3,4,5};
    cout << printRecursive(array, 5, 0);
    cout << endl;
    return 0;
}
