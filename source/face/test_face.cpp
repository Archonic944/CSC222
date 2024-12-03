#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include "Face.h"
using namespace std;

TEST_CASE("Test can create and render a neutral face") {
    Face myobj = Face(5);
    CHECK(myobj.to_string() == ":|");
}