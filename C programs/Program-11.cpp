#include <iostream>
 using namespace std;
 double Ref_const(const double &param) {
    return (param * 3.14);
 }
 int main() {
    double x = 8, y;
    y = Ref_const(x);
    cout << x << " "<< y;
    return 0;
 }
