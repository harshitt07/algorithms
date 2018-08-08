#include <iostream>
#include <vector>
#include <algorithm>
#include <typeinfo>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(c) c.begin(),c.end()

using namespace std;

void f(vector <int> &A) {
    A[0]=45;
    vector <int> :: iterator it=A.begin();
    cout << (*it) << endl;
}

int main() {
    vector <int> A;
    for(int i=0;i<8;i++) {
        A.push_back(i*i);
    }
    
    vector <int> :: iterator it1=A.begin(),it2=A.begin();
    it1+=4;
    it2+=6;
//     int n=it2-it1; // subtract the position of iterators
//     cout << n << endl;
    
//     // min & max element 
//     int x = *max_element(A.begin(),A.end()); // use * to get element else get the position
//     it2 = max_element(all(A)); // return iterator of the max element
//     cout << it2-A.begin() << endl; // to find the position 
    // f(A); use of const
    A.insert(1,42); // shift every element after index 1 & insert 42 @ second position
    
    // also have erase funtion
    // erase (it);
    // erase (it begin,it end)
    
    
    
    
    
}
