#include<iostream>
using namespace std;
	class B {
public:
    B() { cout << "B "; }
    ~B() { cout << "~B "; }
};
class C : public B {
public:
    C() { cout << "C "; }
    ~C() { cout << "~C "; }
};
class D : private C {
    B data_;
public:
    D() { cout << "D " << endl; }
    ~D() { cout << "~D "; }
};
int main() {
    {D d; }
    return 0;
}
