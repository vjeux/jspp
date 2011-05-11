#include "../src/javascript_start.h"

var go_die = function () {
    throw "Exception!";
};

try {
    go_die();
} catch (e) {
    std::cout << "Error: " << e << std::endl;
}
// Error: Exception!

#include "../src/javascript_end.h"
