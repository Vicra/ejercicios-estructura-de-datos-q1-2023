#include <iostream>
#include <cctype>
#include <string>

using namespace std;

bool isPalindromeRecursion(string cadena, int startPos, int endPos){
    if(startPos == endPos) return true;
    if(cadena[startPos] != cadena[endPos]) return false;
    if(startPos < endPos + 1)
        return isPalindromeRecursion(cadena, startPos + 1, endPos - 1);

    return true;
}

bool isPalindrome(string cadena){
    // quitar espacios
    cadena.erase(
        std::remove_if(cadena.begin(), cadena.end(), ::isspace),
        cadena.end());
    if(cadena.length() <= 1){
        return true;
    }
    return isPalindromeRecursion(cadena, 0, cadena.length() - 1);
}

int main(int argc, char const *argv[])
{
    string palabras [4] = 
    {
        "anita lava la tina",
        "bob",
        "amo la pacifica paloma",
        "oir a darioo"
    };

    for (int i = 0; i < 4; i++)
    {
        cout << palabras[i] << ": "
            << boolalpha 
            << isPalindrome(palabras[i]) 
            << endl;
    }
    
    return 0;
}
