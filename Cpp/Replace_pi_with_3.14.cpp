# include <iostream>
# include <string>
using namespace std;

void replacePi(string str)
{
    //base condition
    if(str.length() == 0)
    {
        return;
    }
    if(str[0] == 'p'&& str[1] == 'i')
    {
        cout<<"3.14";
        replacePi(str.substr(2));
    }
    else
    {
        cout<<str[0];
        replacePi(str.substr(1));
    }
}
int main()
{
    replacePi("pixxxfpispiiipi");
    return 0;
}
