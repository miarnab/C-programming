#include <iostream>
using namespace std;
inline int SQUARE(int x) { return (x*x); }
int main() {
    int a , b, c;

    cin >> a ;
    b = SQUARE(a);
    cout << "Square = " << b << ", ";
    c = SQUARE(++a);
    cout << "++ Square = " << c ;
    return 0;
}
