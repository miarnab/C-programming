#include <iostream>                 // ---1
using namespace std;                // ---2
class Base { protected:              // ---3
    int var_;                        // ---4
    public:                          // ---5
    Base():var_(0){}                 // ---6
};                                   // ---7
class Derived: public Base { public: // ---8
   int varD_;                        // ---9
   void print () { cout << var_; }   // ---10
};                                   // ---11
int main() {                         // ---12
   Derived d;                        // ---13
   
   d.var_ = 1;                       // ---14
   d.varD_ = 1;                      // ---15
   
   cout << d.var_ <<" " << d.varD_;  // ---16
   
   return 0;                         // ---17
} 
