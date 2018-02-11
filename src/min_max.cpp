#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int min_max(){
    typedef pair<int,int> PII;
    PII p = minmax(3,2);
    cout << p.first << "," << p.second << endl;
    PII p1 = minmax(1,3,[](int a,int b){
            return a > b;
            });
    cout << p1.first << "," << p1.second << endl;
    swap(p,p1);
    cout << p1.first << "," << p1.second << endl;
    return 0;
}
