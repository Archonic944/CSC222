#include <iostream>
using namespace std;

namespace hello {
    int i = 5;
}

int fun(int p) {
    int cnt = 0;
    for (p = 2 * p; p > 0; p >>= 2)
        cnt++;
    return cnt;
}

void foon(int p) {
    for (int cnt = fun(p); cnt > 0; cnt--) {
        cout << "*";
        cout << " " << cnt;
    }
}

namespace hello {
    int m = 6;
}

int main(void) {
    foon(2);
    cout << "\n";
    cout << hello::i << endl;
    cout << hello::m << endl;
    return 0;
}