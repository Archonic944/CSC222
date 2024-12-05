#include "Emoticon.h"
#include <string>
#pragma once

using namespace std;

vector<string> FACE_LIST = {
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
    string a = "";
    return a;
}

Emoticon::Emoticon(int happiness){
    this->happiness = happiness;
}