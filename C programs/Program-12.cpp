#include <iostream>
 using namespace std;
 void func(int n1 = 10, int n2) {
    cout <<n1 << " "<< n2;
 }
 int main() {
    func(1);
    func(3, 4);
    return 0;
 }
