#include <stdio.h>
#include <iostream>

template<typename T>
void f(T& para){
    std::cout << para << std::endl;
}

template<typename T, std::size_t N>
constexpr std::size_t arraySize(T (&)[N]) noexcept{
    return N;
}

template<typename T>
T operator+(T a,T b){
    return a+b;                                                        
}

// template<typename T>
// T operator-(T a,T b){
// 	return a + b;
// }

template<typename T>
class foo{
    public:
        foo(T a):_a(a){}
        // T operator+(const foo& rhs){
        // 	return _a - rhs._a;
        // }
        T _a;
};

int _tem(){
    int x = 27;
    const int cx = x;
    const int& rx = x;
    f(x);
    f(cx);
    f(rx);
    int keyVals[] = {1,3,7,9,11,22,35};
    int mappedVals[arraySize(keyVals)];
    int a = 2;
    int b = 3;
    std::cout << a+b << std::endl;
    foo<int> lhs(1);
    foo<int> rhs(2);
    lhs + rhs;
}
