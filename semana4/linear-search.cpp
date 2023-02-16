int main(int argc, char const *argv[])
{    
    int c = 0;
    while(c > 10) {
        c++;
    }
    return 0;
}

// arr = [1, 2, 3, 4]
// x = 5
// index = 3
bool search(int arr[], int x, int index) {
    // tamano del arreglo
    int size = sizeof(arr)/sizeof(arr[0]);
    if (index > size - 1) {
        return false;
    }
    // caso base
    //     X
    if(arr[index] == x) {
        return true;
    }

    // caso extremo
    if (index == -1) {
        return false;
    }

    // caso recursivo
    // arr = [1, 2, 3, 4]
    // x = 5
    // index = 2
    return search(arr, x, index--);
}