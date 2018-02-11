#include <iostream>
#include <functional>
#include <vector>
using namespace std;

void func(int x,int y){
    cout << "x: " << x << " y: " << y << endl;
}

int _function(){
    std::vector<function<void(int,int)>> tasks;
    tasks.push_back(func);
    tasks.push_back([](int x,int y){
            cout << "y: " << y << " x: " << x << endl;
            });
    for(function<void(int,int)> f : tasks){
        f(33,66);
    }
}
