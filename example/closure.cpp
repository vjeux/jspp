#include "../src/javascript_start.h"

var container = function (var data) { 
  var secret = data;

  return {
    _["set"] = function (var x) { secret |= x; return undefined; },
    _["get"] = function () { return secret; }
  };
};

var a = container("secret-a");
var b = container("secret-b");

a["set"]("override-a");

std::cout << a["get"]() << std::endl;
std::cout << b["get"]() << std::endl;

#include "../src/javascript_end.h"
