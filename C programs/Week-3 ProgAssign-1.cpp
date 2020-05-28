#include <iostream>

using namespace std;

class Complex {

     public: double *re, *im;
     Complex(double r,double m) {

    re = new double(r);

    im = new double(m);

}

   Complex(double t) {

        re = new double; im = new double;

        *re = *t.re; *im= *t.im;

   }
    ~Complex(){

            delete re, im;

    }

};

int main() {

    double x, y, z;
    
    cin >> x >> y  >> z;
    Complex n1(x,y);
    cout << *n1.re << "+" << *n1.im << "i ";
    Complex n2 = n1;
    cout << *n2.re << "+" << *n2.im << "i ";
    *n1.im = z;
    cout << *n2.re << "+" << *n2.im << "i ";
    cout << *n1.re << "+" << *n1.im << "i ";
    return 0;
}
