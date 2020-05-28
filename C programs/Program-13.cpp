#include <iostream>
 using namespace std;
 int Add(int a, int b) { return (a + b); }
 double Add(double c) {
    return (c + 1);
 }
 int main() {

    int x = 1, y = 2, z;
    z = Add(x, y);
    cout << z;
    double s = 4.5, u;
    u = Add(s);
    cout << " " << u << endl;
    return 0;
 }
