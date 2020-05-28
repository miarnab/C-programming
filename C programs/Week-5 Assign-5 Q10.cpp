#include<iostream>
using namespace std;
class Shape { 
public:
    int x, y;

    Shape(int a = 0, int b = 0): x(a), y(b) {}

    void draw()

    { cout << x << " " << y << " "; }

};

class Rectangle : public Shape {

public:

    int w, h;

    Rectangle(int a = 5, int b = 6): w(a), h(b), Shape(7, 8) {}    

    void draw()

    { Shape::draw(); cout << w << " " << h ; }

};

int main() {

    Rectangle *r = new Rectangle(1,2);
    r-> draw();
    return 0;
}
