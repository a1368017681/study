#include <iostream>
#include <utility>

template<typename T1, typename T2>
std::ostream& operator << (std::ostream& strm, const std::pair<T1, T2>& p){
    return strm << "[" << p.first << "," << p.second << "]";
}

int _pair(){
    std::pair<int,char> p(1,'c');
    std::cout << p << std::endl;

    typedef std::pair<int,float> IntFloatPair;
    IntFloatPair p1(42,3.14);

    auto fi = std::get<0>(p);
    auto se = std::get<1>(p);
    std::cout << fi << "," << se << std::endl;
    std::cout << std::tuple_size<IntFloatPair>::value << ","  << std::endl;

    IntFloatPair p3{2,3.5};
}
