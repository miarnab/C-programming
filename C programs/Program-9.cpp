#include<iostream>
 using namespace std;
 int main() {
    typedef struct Complex {
        double re;
        double im;
    } Complex;
    const Complex c = {2,4} ;
    c.re = 5.9;
    cout << c.re;
    return 0;
 }
