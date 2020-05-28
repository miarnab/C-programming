#include <iostream>
using namespace std;
class Complex { double re, im; public:
    explicit Complex(double r = 0, double i = 0) : re(r), im(i) { }
    void disp() { cout << re << " +j " << im << endl; }
    friend Complex operator+ (const Complex &a, const Complex &b) {
        return Complex(a.re + b.re, a.im + b.im);
    }
    friend Complex operator+ (const Complex &a, double d) {
        Complex b(d); return a + b;
    }
    friend Complex operator+ (double d, const Complex &b)    {
        Complex a(d); return a + b;
   }
}; 

 int main(){
    Complex d1(2.5, 3.2), d2(1.6, 3.3), d3;
    d3 = d1 + d2; d3.disp();
    d3 = d1 + 6.2; d3.disp();
   d3 = 4.2 + d2; d3.disp();
   return 0; 
} 
