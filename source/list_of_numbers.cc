#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(){
    cout << "Enter a list of numbers: " << endl;
    string line;
    getline(cin, line);
    istringstream iss(line);
    vector<int> nums;
    cout << "Your numbers: ";
    string current;
    while(getline(iss, current, ' ')){
        int num = stoi(current);
        cout << num << " ";
        nums.insert(nums.begin(), num);
    }
    cout << endl;
    cout << "Reversed: ";
    for(const int& num : nums){
        int element = num;
        cout << element << " ";
    }
    cout << endl;
}