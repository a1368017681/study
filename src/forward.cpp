#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <array>

using namespace std;

struct A
{
    A(int&& n) { cout << "rvalue overload, n = " << n << endl;}
    A(int& n) { cout << "lvalue overload, n = " << n << endl;}
};

class B{
    public:
        template<typename T1, typename T2, typename T3>
            B(T1&& t1, T2&& t2, T3&& t3):a1_{forward<T1>(t1)},a2_{forward<T2>(t2)},a3_{forward<T3>(t3)}{}
    private:
        A a1_,a2_,a3_;
};

template<class T, class U>
unique_ptr<T> make_unque1(U&& u){
    return unique_ptr<T>(new T(forward<U>(u)));
}

template<class T, class... U>
unique_ptr<T> make_unque(U&&... u){
    return unique_ptr<T>(new T(forward<U>(u)...));
}

void foo(string s){
    cout << s << endl;
}

template<typename T>
void wrapper(T&& arg){
    foo(forward<T>(arg));
}

int _forward(){
    auto p1 = make_unque1<A>(2);	
    int i = 1;
    auto p2 = make_unque1<A>(i);

    cout << "B\n";
    auto t = make_unque<B>(2,i,3);

    cout << ("TEST"[0]) << endl;
}




