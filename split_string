#include <iostream>  
#include <cstring>  
using namespace std;  
  
int main()  
{  
    char str[100]; // declare the size of string      
    cout << " Enter a string: " <<endl;  
    cin.getline(str, 100); // use getline() function to read a string from input stream  
      
    char *ptr; // declare a ptr pointer  
    ptr = strtok(str, " , "); // use strtok() function to separate string using comma (,) delimiter.  
    cout << " \n Split string using strtok() function: " << endl;  
    // use while loop to check ptr is not null  
    while (ptr != NULL)  
    {  
        cout << ptr  << endl; // print the string token  
        ptr = strtok (NULL, " , ");  
    }  
    return 0;  
}  
