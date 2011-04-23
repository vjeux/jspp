#include "../src/javascript_start.h"

var Utils = {
    _["map"] = function (var array, var func) {
        for (var i = 0; i < array["length"]; ++i) {
            array[i] = func(i, array[i]);
        }
		return undefined;
    }
};

var a = {"a", "b", "c"};
std::cout << a << std::endl;
// [a, b, c]

Utils["map"](a, function (var key, var value) {
    return "(" + key + ":" + value + ")";
});
std::cout << a << std::endl;
// [(0:a), (1:b), (2:c)]

#include "../src/javascript_end.h"
