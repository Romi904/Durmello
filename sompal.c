// Code By- Romijul Laskar
#include <iostream>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll b, c, d;
        cin >> b >> c >> d;
        int x = d / 2;
        if (c != d)
        {
            if (c <= x)
            {
                cout << abs(b - c) << endl;
            }
            else
            {
                if (c >= b)
                {
                    cout << abs(c - d) + 1 << endl;
                }
                else
                {
                    cout << abs(b - c) << endl;
                }
            }
        }
        else{
            cout<<c<<endl;
        }
    }
    return 0;
}
