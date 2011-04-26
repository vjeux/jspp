#include "../src/javascript_start.h"

var array = {10, 42, 30};
for (var i in array) {
    std::cout << i << " - " << array[i] << std::endl;
}
// 0 - 10
// 1 - 42
// 2 - 30
// length - 3
// prototype - undefined

var object = {
    _["a"] = 1,
    _["b"] = 2,
    _["c"] = 3
};
for (var i in object) {
    std::cout << i << " - " << object[i] << std::endl;
}
// a - 1
// b - 2
// c - 3
// prototype - undefined

#include "../src/javascript_end.h"
