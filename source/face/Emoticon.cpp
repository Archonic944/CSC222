#include "Emoticon.h"
#include <string>

using namespace std;

vector<string> Emoticon::FACE_LIST = {
    "(╯'□')╯︵ ┻━┻", 
    "(｡·́︿·̀｡)", 
    "(ᵕ—_—)", 
    "(｡• ‸ •｡)", 
    "(•_•)", 
    "(˶ᵔ ᵕ ᵔ˶)",
    "◝(ᵔᵕᵔ)◜"
    "ദ്ദി(ᵔᗜᵔ)",
    "✧｡٩(ˊᗜˋ )و✧*｡",
};

string Emoticon::to_string(){
    cout << FACE_LIST[happiness] << endl;
    return FACE_LIST[happiness];
}

Emoticon::Emoticon(int happiness){
    this->happiness = happiness;
}

void Emoticon::make_happier(){
    this->happiness++;
    if(this->happiness > 9) this->happiness = 9;
}