#pragma once
#include <iostream>

#define PR(...) printf(__VA_ARGS__)
#define LOG(...) {\
    fprintf(stderr, "%s:Line %d:\t", __FILE__, __LINE__);\
    fprintf(stderr, __VA_ARGS__);\
    fprintf(stderr, "\n");\
}

void test_LOG(){
    int x = 6;
    LOG("x = %d", x);
}

struct TestStructFun {
    TestStructFun():name(__func__) {}
    const char* name;
};

void test_Fun() {
    TestStructFun ts;
    std::cout << ts.name << std::endl;
}

void get_std_define() {
    std::cout << "Standard Clib: " << __STDC_HOSTED__ << std::endl;
    std::cout << "Standard C: " << __STDC__ << std::endl;
//    std::cout << "ISO/IEC " << __STDC_ISO_10646__ << std::endl;
}
