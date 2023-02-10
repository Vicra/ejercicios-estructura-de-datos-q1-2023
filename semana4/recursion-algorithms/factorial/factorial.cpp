#include <iostream>

using namespace std;

// O(n)
int factorial(int n){
    int producto = 1;
    for (int i = 1; i <= n; i++)
    {
        producto *= i;
    }
    return producto;
}

// O(n)
int factorialRecursive(int n){
    if(n > 1){
        return n * factorialRecursive(n - 1);
    }
    else 
        return 1;
}


int fibonacci(int x) {
    // 0 1 1 2 3 5 8 13 21 34 55 89 144 233 377
    if (x == 0 || x == 1){
        return (x);
    }
    else {
        return fibonacci(x-2) + fibonacci(x-1);
    }
}

// no hay mejor 
int main(int argc, char const *argv[])
{
    cout << "iterative: " << factorial(5) << "\n";
    cout << "recursive: " << factorialRecursive(5) << "\n"; 

    for (int i = 0; i < 5; i++)
    {
        cout  << fibonacci(i) << " ";
    }

    return 0;
}