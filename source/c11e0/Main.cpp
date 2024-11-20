#include <iostream>
#include "Time.h"
using namespace std;

int main() {
    Time current_time(9, 14, 3);    
    current_time.increment(500.0);
    current_time.print();
    cout << endl;

    Time bread_time(3, 35, 0.0);
    Time done_time = current_time.add(bread_time);
    done_time.print();
    cout << endl;

    if (done_time.after(current_time)) {
        cout << "The bread will be done after it starts." << endl;
    }
    return 0;
}
