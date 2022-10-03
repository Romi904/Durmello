#include <iostream>

using namespace std;

class BloomFilter
{
public:
    bool arr[100];
    int filter_size;
    int filter;
    BloomFilter(int n)
    {
        filter_size = n;
        for(int i=0;i<filter_size;i++)
        {
            arr[i] = false;
        }
        filter = 0;
    }

    int hash1(string s)
    {
        int hash_val=0;
        for(unsigned int i=0;i<s.length();i++)
        {
            hash_val = hash_val+(int)s[i];
        }
        hash_val = hash_val%filter_size;
        return hash_val;
    }

    int hash2(string s)
    {
        int hash_val=0;
        for(unsigned int i=0;i<s.length();i++)
        {
            hash_val = hash_val+((int)s[i] * 3);
        }
        hash_val = hash_val%filter_size;
        return hash_val;
    }

    int hash3(string s)
    {
        int hash_val=0;
        for(unsigned int i=0;i<s.length();i++)
        {
            hash_val = hash_val+((int)s[i] * 5);
        }
        hash_val = hash_val%filter_size;
        return hash_val;
    }

    int hash4(string s)
    {
        int hash_val=0;
        for(unsigned int i=0;i<s.length();i++)
        {
            hash_val = hash_val+((int)s[i] * 7);
        }
        hash_val = hash_val%filter_size;
        return hash_val;
    }

    void search_data(string s)
    {
        int hv1 = hash1(s);
        int hv2 = hash2(s);
        int hv3 = hash3(s);
        int hv4 = hash4(s);

        cout<<"\n Using array \n";
        cout<<"\n Hash1 : "<<hv1<<"     Hash2 : "<<hv2<<"     Hash3 : "<<hv3<<"     Hash4 :"<<hv4;

        cout<<endl;
        for(int i=0; i<filter_size;i++)
        {
            cout<<"   "<<i;
        }

        cout<<endl;
        for(int i=0; i<10;i++)
        {
            cout<<"   "<<arr[i];
        }
        for(int i=10; i<filter_size;i++)
        {
            cout<<"    "<<arr[i];
        }

        if(arr[hv1] == true && arr[hv2] == true && arr[hv3] == true && arr[hv4] == true)
        {
            cout<<"\nThe data " <<s<<" may be present";
        }
        else
        {
            cout<<"\nThe data " <<s<<" is not present.  It is inserted in the filter";
            arr[hv1] = true;
            arr[hv2] = true;
            arr[hv3] = true;
            arr[hv4] = true;

            cout<<endl;
            for(int i=0; i<filter_size;i++)
            {
                cout<<"   "<<i;
            }

            cout<<endl;
            for(int i=0; i<10;i++)
            {
                cout<<"   "<<arr[i];
            }
            for(int i=10; i<filter_size;i++)
            {
                cout<<"    "<<arr[i];
            }
        }
    }

    void search_data1(string s)
    {
        int hv1 = hash1(s);
        int hv2 = hash2(s);
        int hv3 = hash3(s);
        int hv4 = hash4(s);

        cout<<"\n\n\n Using variable \n";
        int shift_val1 = 1 << (hv1 - 1);
        int shift_val2 = 1 << (hv2 - 1);
        int shift_val3 = 1 << (hv3 - 1);
        int shift_val4 = 1 << (hv4 - 1);

        cout<<"\n Hash1 : "<<hv1<<"     Hash2 : "<<hv2<<"     Hash3 : "<<hv3<<"     Hash4 :"<<hv4;

        cout<<endl;
        for(int i=filter_size; i>9;i--)
        {
            cout<<"   "<<i;
        }
        for(int i=9; i>0;i--)
        {
            cout<<"    "<<i;
        }

        cout<<endl;

        int temp_val = filter;
        int ctr = 32;
        //cout<<endl;
        while(ctr>0)
        {
            int t = temp_val;
            t = t >> (ctr - 1);
            t = t & 1;
            cout<<"    "<<t;
            ctr--;
        }

        if(((filter & shift_val1) >0) && ((filter & shift_val2) >0) && ((filter & shift_val3) >0) && ((filter & shift_val4) >0))
        {
            cout<<"\nThe data " <<s<<" may be present";
        }
        else
        {
            cout<<"\nThe data " <<s<<" is not present.  It is inserted in the filter";
            filter = filter | shift_val1;
            filter = filter | shift_val2;
            filter = filter | shift_val3;
            filter = filter | shift_val4;

            cout<<endl;
            for(int i=filter_size; i>9;i--)
            {
                cout<<"   "<<i;
            }
            for(int i=9; i>0;i--)
            {
                cout<<"    "<<i;
            }

            cout<<endl;
            ctr = 32;
            while(ctr>0)
            {
                int t = filter;
                t = t >> (ctr - 1);
                t = t & 1;
                cout<<"    "<<t;
                ctr--;
            }
        }
    }
};
int main()
{
    BloomFilter b(32);
    string s;
    int ch;

    cout<<"\n The size of integer is : "<<sizeof(int);
    while(1)
    {
        cout<<"\n Enter the data : ";
        cin>>s;
        b.search_data1(s);
        //b.search_data1(s);
        cout<<"\n\n\n Do you want to enter other data(1/0) :";
        cin>>ch;
        if(ch==0)
            break;
    }
    return 0;
}
