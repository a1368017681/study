#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
void print(T para){
    for(auto elem : para){
        cout << elem << " ";
    }
    cout << endl;
}

int square(int val){
    return val * val;
}

int _foreach(){
    vector<int> coll = {2,5,4,1,6,3};
    std::vector<int> coll2;

    for_each(coll.begin(), coll.end(), [&](int& a){
            a *= 2;
            });
    transform(coll.cbegin(), coll.cend(), back_inserter(coll2), square);
    transform(coll.cbegin(), coll.cend(), back_inserter(coll2), [](int val) -> int{
            return val * val;
            });
    print(coll);
    print(coll2);
}
