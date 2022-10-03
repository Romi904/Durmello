#include<iostream>
using namespace std;
bool isPalindrome(string str);
int main()
{    string str;
    cout<<"Enter the String ::";
    cin>>str;
    bool check=isPalindrome(str);
    if(check==true)
    {
        cout<<"Palindrome";
    }
    else{
        cout<<"Not Palindrome";
    }
}
bool isPalindrome(string str){
    for (int i = 0; i < str.length() / 2; i++) {
        if (str[i] != str[str.length() - i - 1]) {
            return false;
        }
    }
    return true;
}