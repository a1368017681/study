
#include <iostream>

using namespace std;

void Throw() { 
    throw 1;
}
void NoBlockThrow() { 
    Throw(); 
}
void BlockThrow() noexcept {
    Throw();
}

void test_exception() {
    try {
        Throw();
    } catch (...) {
        cout << "Found throw." << endl;
    }

    try {
        NoBlockThrow();
    } catch (...) {
        cout << "throw is not blocked" << endl;
    }

    try {
        BlockThrow();
    } catch (...) {
        cout << "Found throw 1" << endl;
    }
}
