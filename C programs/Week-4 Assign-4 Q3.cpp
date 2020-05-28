#include <iostream>
using namespace std;
struct emp {
    int a;
    emp ( int b): a(b){}
    ~emp(){ cout << " Destroyed " ;}
    void disp(){ cout << " In Display " ; }
};
int main(){
   emp e(20);
   cout << e.a ;
   e.disp(); 
}
