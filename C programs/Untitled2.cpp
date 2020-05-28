#include <iostream>
using namespace std;
class Box
{
private:
double length, breadth, height;
public:
Box(double a = 0, double b = 0, double c = 0) :
length(a), breadth(b), height(c) {};
double getDimension(){
return length + breadth + height;
}
Box ___________(const Box& x){ // Fill the name of the function
Box box;
___________________ // Fill the statement
___________________ // Fill the statement
___________________ // Fill the statement
return box;
}
};
int main(){
double l = 0, b = 0, h = 0;
cin >> l; cin >> b; cin >> h;
Box Box1(5.00, 6.00, 7.00), Box2(l, b, h), Box3;
Box3 = Box1 + Box2;
double dim = Box3.getDimension();
cout << dim;
return 0;
}