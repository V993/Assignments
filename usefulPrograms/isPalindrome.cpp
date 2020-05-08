#include <iostream>
using namespace std;

bool isPalindrome(string const& word, int first, int last) {
    //base case: a string with 0 or 1 characters is a palindrome.
    if(last - first <= 1)
        return true; 
    if(word[first] != word[last])
        return false;
    return isPalindrome(word, first+1, last-1);
}