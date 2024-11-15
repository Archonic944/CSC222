#include <string>
#include <vector>
#include <iostream>
using namespace std;

string render_num_vector(const vector<int>& vec) {
    string s = "";
    if(vec.size() == 0) return s;
    for(int i = 0; i<vec.size(); i++){
        s += to_string(vec[i]) + " ";
    }
    s.erase(s.size() - 1, 1); //erase the last space
    return s;
}

int num_vector_sum(const vector<int>& vec){
    int sum = 0;
    for(int i = 0; i<vec.size(); i++){
        sum += vec[i];
    }
    return sum;
}

int num_vector_product(const vector<int>& vec){
    int sum = 1;
    for(int i = 0; i<vec.size(); i++){
        sum *= vec[i];
    }
    return sum;
}

vector<int> only_evens(const vector<int>& vec){
    vector<int> vec2 = {};
    for(int i = 0; i<vec.size(); i++){
        if(vec[i] % 2 == 0) vec2.push_back(vec[i]);
    }
    return vec2;
}

vector<int> only_odds(const vector<int>& vec){
    vector<int> vec2 = {};
    for(int i = 0; i<vec.size(); i++){
        if(vec[i] % 2 == 1) vec2.push_back(vec[i]);
    }
    return vec2;
}

vector<int> nums_between(const vector<int>& vec, int low, int high){
    vector<int> vec2;
    for(int i = 0; i<vec.size(); i++){
        int num = vec[i];
        if(num >= low && num <= high){
            vec2.push_back(num);
        }
    }
    cout << render_num_vector(vec2) << endl;
    return vec2;
}

double mean(const vector<int>& nums) {
    if (nums.empty()) return 0.0;
    double sum = 0.0;
    for (int num : nums) {
        sum += num;
    }
    return sum / nums.size();
}

double median(const vector<int>& nums) {
    if (nums.empty()) return 0.0;
    vector<int> sorted_nums = nums;
    sort(sorted_nums.begin(), sorted_nums.end());
    size_t size = sorted_nums.size();
    if (size % 2 == 0) {
        return (sorted_nums[size / 2 - 1] + sorted_nums[size / 2]) / 2.0;
    } else {
        return sorted_nums[size / 2];
    }
}