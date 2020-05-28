#include <iostream>
using namespace std;
class Test {
    int i; 
 public:
    Test(int ii) : i(ii) {}
    const Test operator+(const Test& rv) const {
        cout << "Executes +" << endl;
        return Test(i + rv.i);
    }
    Test& operator+=(const Test& rv) {
       cout << "Executes +=" << endl;
       i += rv.i;
       return *this;
} };
int main() {
    int i = 1, j = 2, k = 3;
    k += i + j;
    Test ii(1), jj(2), kk(3);
    kk += ii + jj;
}
