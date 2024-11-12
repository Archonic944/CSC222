#include <string>
#include <vector>
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