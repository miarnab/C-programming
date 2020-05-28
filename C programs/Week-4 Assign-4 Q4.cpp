#include <iostream>
using namespace std ;
namespace Ex { int x = 10; }
namespace Ex { int y = 10; }
int main(){
    using namespace Ex ;
    x = y = 50;
    cout << x << " " << y;
}
