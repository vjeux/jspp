#include "../src/javascript_start.h"

var f = function (var x, var y) {
    std::cout << "this: " << this << std::endl;
    this["x"] = x;
    this["y"] = y;

    return this;
};

// new creates a new object this
var a = new (f)(1, 2); // this: <function 0x005240d0>
var b = new (f)(3, 4); // this: <function 0x005248e0>

// Unbound call, 
var c = f(5, 6); // this: undefined

// Bound call
var obj = {42};
obj["f"] = f;

var d = obj["f"](1, 2); // this: [42]

// Call
var e = f["call"](obj, 1, 2); // this: [42]

#include "../src/javascript_end.h"
