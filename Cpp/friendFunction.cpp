#include<iostream>
using namespace std;

class complex{
    int a,b;
    public:
    void setnumber(int n1,int n2){
        a=n1;
        b=n2;
    }
    void printnumber(){
        cout<<"Your number is "<<a<<"+"<<b<<"i"<<endl;
    }

    friend complex sump(complex o1,complex o2);

};

complex sump(complex o1,complex o2){
    complex o3;
    o3.setnumber((o1.a+o2.a),(o1.b+o2.b));
    return o3;
}


int main(){
    complex c1,c2,sum;
    c1.setnumber(10,3);
    c2.setnumber(14,6);
    c1.printnumber();
    c2.printnumber();

    sum=sump(c1,c2);
    sum.printnumber();
    return 0;
}
