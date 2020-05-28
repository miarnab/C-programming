#include <iostream>
#include <vector>
using namespace std;
int main() {
cout << "Enter the no. of elements: ";
int count, j, sum=0;
cin >> count;
vector<int>arr(count);
arr.resize(count);
for(int i = 0; i < arr.size(); i++) {
arr[i] = i;
sum+=arr[i];
}
cout << "Array Sum: " << sum << endl;
return 0;
}
