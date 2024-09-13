#include <iostream>

using namespace std;
int main ()
{
float a;
int i = 0;
for (a = .009; a < 1e2; a *= 1e1) {
   cout << a << ' ' << endl;
   i++;
}
cout << i << endl;
return 0;
}
