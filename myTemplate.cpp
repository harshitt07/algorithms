#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(c) c.begin(),c.end()
#define present(container,element) (container.find(element)!=container.end())


using namespace std;

int main() {
    // vector <int> :: iterator it1=A.begin(),it2=A.begin();
    // it1+=4;
    // it2+=6;
//     int n=it2-it1; // subtract the position of iterators
//     cout << n << endl;
    
//     // min & max element 
//     int x = *max_element(A.begin(),A.end()); // use * to get element else get the position
//     it2 = max_element(all(A)); // return iterator of the max element
//     cout << it2-A.begin() << endl; // to find the position 
    // f(A); use of const
    // A.insert(1,42); // shift every element after index 1 & insert 42 @ second position
    
    // also have erase funtion
    // erase (it);
    // erase (it begin,it end)
    set <int> s;
    s.insert(2);
    s.insert(1);
    s.insert(8);
    // cout << int(s.size());
    
    // dont use global find instead use member function ::find()
    if(s.find(2)!=s.end()) cout << "Yes";
    else cout << "No";
    
    if(s.count(2)!=0) cout << "Yes"; ) //(log n) / O(n)
    else cout << "No"; // O(log n)
    
    
    // by creating vector from map we can use the indies as we cannot able to do in map!
    
    
    
    
}
