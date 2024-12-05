#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include "Emoticon.h"

using namespace std;

TEST_CASE("Test can create and render all emoticons"){
    for(int i = 0; i<FACE_LIST.size(); i++){
        Emoticon face = Emoticon(i);
        CHECK(face.to_string() == FACE_LIST[i]);
    }
}