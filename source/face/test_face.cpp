#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include "Face.h"
using namespace std;

TEST_CASE("Test can create and render Face") {
    Face myobj = Face(1);
    CHECK(myobj.to_string() == "");
}