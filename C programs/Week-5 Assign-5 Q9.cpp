#include<iostream>
using namespace std;
	class Test {
int x;
public:
    Test(int a):x(a){}
    virtual void show() = 0;
    int getX() { /* Function definition */ }
};
int main(void){
    Test t(5);
    t.getX();
    return 0;
}
