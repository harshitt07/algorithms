#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#define all(c) c.begin(),c.end()
using namespace std;

int main() {
    int a[] = {1,12,3,4,6,7,8};
    int b[] = {1,4,8,3,4};
    
    vector <int> A(a,a+sizeof(a)/sizeof(a[0]));
    vector <int> B(b,b+sizeof(b)/sizeof(b[0]));
    vector <int> tmp(max(A.size(),B.size())); // size must be define 
    //create vector <int> res to store intersection value
    vector <int> res = vector <int> (tmp.begin(),set_intersection(all(A),all(B),tmp.begin()));
    for(int i=0;i<res.size();i++) {
        cout << res[i] << " ";
    }
    cout << set_intersection(all(A),all(B),tmp.begin())-tmp.begin();
    cout << endl;
    // use to find sum in any of the container like vector , set , map etc...
    int sum = accumulate(all(A),0);// use #include <numeric> for it
    // result always store in 3rd parameter so if result is long so typecast the 3rd parameter
    cout << sum << endl;
    // for multiply
    double product = accumulate(all(B),double(1),multiplies<double> ());
    cout << product << endl;
    // & inner_product is use to find scalar product!
    
    // to dispose of the extra memory after creating V
    // vector <int> V;
    vector <int> (all(A)).swap(A);
    
    //Implementing real algorithm with STL;
    // 1. Depth First Search
    
        

}
