#include <iostream>
using namespace std;
class sample {
    public:
    int x, y;
    sample() {};
    sample(int, int);
    sample operator + (sample);
};
sample::sample (int a, int b) {
x = a;
y = b; }
sample sample::operator+ (sample param) {
    sample temp;
    temp.x = x + param.x;
    temp.y = y + param.y;
    return (temp);
}
int main () {
    sample a (4,1);
    sample b (3,2);
    sample c;
    c = a + b;
    cout << c.x << " " << c.y;
    return 0; 
} 
