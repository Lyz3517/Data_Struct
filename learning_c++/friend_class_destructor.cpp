#include <iostream>
#include <string>
using namespace std;

class A {
public:
    A() { cout << "A的构造函数调用了" << endl; }
    ~A() { cout << "A的析构函数调用了" << endl; }
};

class B:public A {
public:
    ~B() { cout << "B的析构函数调用了" << endl; }
    B() { cout << "B的构造函数调用了" << endl; }
};


int main(int argc, char ** argv) {
    B b;
    return 0;
}

/**
 * 可见：构造函数的调用严格地按照先调用基类的构造函数，后调用派生类的构造u函数的顺序执行
 * 析构函数的调用顺序与构造函数的调用顺序hn正好相反，先调用派生类的i析构函数，后调用基类
 * 析构函数。
*/