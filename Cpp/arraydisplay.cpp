#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    
    cin >> n;
    
    vector<int> arr(n);
    
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        arr[i] = temp;
    }
    
    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }
    
    return 0;
}
