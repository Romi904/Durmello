#include <bits/stdc++.h>
using namespace std;
 
//we find out the square root of a number by newton method.
double squareRoot(double n)
{
    // Assuming the sqrt of n as n only
    double x = n;
 
    // The closed guess will be stored in the root
    double root;
 
    while (true) {
 
        // Calculate more closed x
        root = 0.5 * (x + (n / x));
 
        // Check for closeness
        if (abs(root - x) < 0.00001)
            break;
 
        x = root;
    }
 
    return root;
}
int main()
{
    int n;
    cout<<"please enter the no:-";
    cin>>n;
    cout << squareRoot(n);
 
    return 0;
} 
