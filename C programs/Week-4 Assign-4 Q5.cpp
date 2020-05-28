#include<iostream>
     using namespace std;
     class Test { static int x;
         public:
         void get() { x = 15; }
         void print() {
         x = x + 20;
         cout << "x =" << x << endl;
         }
     };
      int Test::x=0;
     int main() {
         Test o1, o2;
         o1.get(); o2.get();
         o1.print(); o2.print();
         return 0;
}
