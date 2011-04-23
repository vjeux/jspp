#include "../src/javascript_start.h"

var repeat = function (var str, var times) {
    var ret = "";
    for (var i = 0; i < times; ++i) {
        ret += str + i;
    }
    return ret;
};

std::cout << repeat(" js++", 3) << std::endl;
// " js++0 js++1 js++2"

#include "../src/javascript_end.h"
