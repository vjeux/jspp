#include "../src/javascript_start.h"

var createObject = function (var o) {
	var F = function () {return This;};
	F["prototype"] = o;
	return New(F)();
};

var Person = {
  _["name"] = "Default",
  _["greet"] = function () {
    return "Hello world, my name is " + This["name"];
  }
};

var vjeux = createObject(Person);
vjeux["name"] = "Vjeux";

var blog = createObject(Person);
blog["name"] = "Blog";

var def = createObject(Person);

std::cout << vjeux["greet"]() << std::endl; // Vjeux
std::cout << blog["greet"]() << std::endl;  // Blog
std::cout << def["greet"]() << std::endl;   // Default

#include "../src/javascript_end.h"
