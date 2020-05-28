#include <iostream>
using namespace std;
class Base { public:
    int var_;
    void func(int){}
};
class Derived: public Base { public:
    int varD_;
    void func(int){}
};
int main() {
    Derived d;   
    d.func(1);   
    return 0;
}
