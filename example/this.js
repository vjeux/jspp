
var f = function (x, y) {
    console.log("this:", this);
    this["x"] = x;
    this["y"] = y;
};

// New creates a new object this
var a = new f(1, 2); // this: <object 0x005240d0>
var b = new f(3, 4); // this: <object 0x005248e0>

// Unbound call, 
var c = f(5, 6); // this: global object

// Bound call
var obj = [42];
obj["f"] = f;

var d = obj["f"](1, 2); // this: [42]

// Call
var e = f["call"](obj, 1, 2); // this: [42]

