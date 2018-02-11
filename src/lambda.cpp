#include <iostream>

using namespace std;

int _lam(){
    auto plus10 = [](int i){
        return i + 10;
    };
    cout << "+10: " << plus10(7) << endl;

    auto plus10times2 = [](int i){
        return (i+10)*2;
    };
    cout << "+10 *2: " << plus10times2(7) << endl;
    auto binder = bind(multiplies<int>(), bind(plus<int>(), placeholders::_1, 10), 2);
    cout << "binder +10 *2: " << binder(7) << endl;
}
