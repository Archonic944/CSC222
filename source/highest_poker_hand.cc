#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(){
    cout << "Please enter a list of card ranks separated by spaces,\nthen a list of suits separated by spaces." <<endl;
    string line;
    getline(cin, line);
    istringstream iss(line);
    vector<int> ranks;
    string current;
    while(getline(iss, current, ' ')){
        ranks.push_back(stoi(current));
    }
    string line2;
    getline(cin, line2);
    istringstream iss2(line2);
    vector<string> suits;
    string current2;
    while(getline(iss2, current2, ' ')){
        suits.push_back(current2);
    }
    /*
        1. "Flush": Five cards of the same suit.
        2. "Three of a Kind": Three cards of the same rank.
        3. "Pair": Two cards of the same rank.
        4. "High Card": Any single card.
    */

    //Check flush
    flush: {
        for(string suit : suits){
            if(suit != suits[0]){
                goto three_and_pair;
            }
        }
        cout << "Flush" << endl;
        return 0;
    }
    three_and_pair: {
        int max_occurences = 0;
        for(int t = 0; t<ranks.size(); t++){
            int occurences = 0;
            int target = ranks[t];
            for(int i = 0; i<ranks.size(); i++){
                if(ranks[i] == target) occurences++;
            }
            if(occurences > max_occurences){
                max_occurences = occurences;
            }
        }
        if(max_occurences >= 3){
            cout << "Three of a kind" << endl;
            return 0;
        }
        if(max_occurences == 2){
            cout << "Pair" << endl;
            return 0;
        }
    }
    cout << "High card" << endl;
    return 0;
}