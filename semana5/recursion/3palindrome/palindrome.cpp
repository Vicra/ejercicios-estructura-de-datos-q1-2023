#include <iostream>
#include <cctype>

using namespace std;

bool isPalindromeRecursive(string word, int startPos, int endPos){
    
    // cout << "\n" << "startPos: " << startPos << " endPos:" << endPos << endl;
    // caso base: llegue al final
    if(endPos <= startPos){
        return true;
    }

    // continue la recursion
    if (tolower(word[startPos]) == tolower(word[endPos])){
        return isPalindromeRecursive(word, startPos + 1, endPos - 1);
    } else {
        return false;
    }
}

bool isPalindrome(string word){
    if(word == ""){
        return false;
    } else {
        int startPos = 0;
        int endPos = word.length()-1;
        return isPalindromeRecursive(word, startPos, endPos);
    }
}

int main(int argc, char const *argv[])
{
    // string word = "anita lava la tina";
    string word = "Anita lava la tina";
    cout << word << " isPalindrome: " << boolalpha << isPalindrome(word);
    return 0;
}
