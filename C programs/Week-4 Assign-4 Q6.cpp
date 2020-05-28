#include<iostream>
using namespace std;
class Test { int x;
    public:
    Test(int i) : x(i) {}
    friend void print(const Test& a);
};
void print(const Test& a) {
    cout << "x = " << a.x;
}
int main(){
    Test t(10);
    print(t);
    return 0; 
} 
