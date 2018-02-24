#include <thread>
#include "define.h"

thread_local int g_n = 1;

void f() {
    g_n++;
    LOG("thread_id=%d, n=%d", std::this_thread::get_id(), g_n);
}

void foo() {
    thread_local int i = 0;
    LOG("thread_id=%d, i=%d", std::this_thread::get_id(), i);
    i++;
}

void f2() {
    foo();
    foo();
}

void test_thread_local() {
    g_n++;
    f();
    std::thread t1(f);
    std::thread t2(f);

    t1.join();
    t2.join();

    f2();
    std::thread t4(f2);
    std::thread t5(f2);

    t4.join();
    t5.join();
}
