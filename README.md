
JSPP
=====

Dynamic Typing
--------
<table><tr><td><strong>C++</strong><pre>
var repeat = function (var str, var times) {
    var ret = "";
    for (var i = 0; i &lt; times; ++i) {
        ret += str + i;
    }
    return ret;
};

std::cout &lt;&lt; repeat(" js++", 3) &lt;&lt; std::endl;
// " js++0 js++1 js++2"
</pre></td><td><strong>Javascript</strong><pre>
var repeat = function (str, times) {
    var ret = "";
    for (var i = 0; i &lt; times; ++i) {
        ret += str + i;
    }
    return ret;
};

console.log(repeat(" js++", 3));
// " js++0 js++1 js++2"
</pre></td></tr></table>



Exception
--------
<table><tr><td><strong>C++</strong><pre>
var go_die = function () {
    throw _("Exception!");
};

try {
    go_die();
} catch (var e) {
    std::cout &lt;&lt; "Error: " &lt;&lt; e &lt;&lt; std::endl;
}
// Error: Exception!
</pre></td><td><strong>Javascript</strong><pre>
var go_die = function () {
    throw "Exception!";
};

try {
    go_die();
} catch (e) {
    console.log("Error:", e);
}
// Error: Exception!
</pre></td></tr></table>



Function
--------
<table><tr><td><strong>C++</strong><pre>
var Utils = {
    _["map"] = function (var array, var func) {
        for (var i = 0; i &lt; array["length"]; ++i) {
            array[i] = func(i, array[i]);
        }
		return undefined;
    }
};

var a = {"a", "b", "c"};
std::cout &lt;&lt; a &lt;&lt; std::endl;
// [a, b, c]

Utils["map"](a, function (var key, var value) {
    return "(" + key + ":" + value + ")";
});
std::cout &lt;&lt; a &lt;&lt; std::endl;
// [(0:a), (1:b), (2:c)]
</pre></td><td><strong>Javascript</strong><pre>
var Utils = {
    "map": function (array, func) {
        for (var i = 0; i &lt; array["length"]; ++i) {
            array[i] = func(i, array[i]);
        }

    }
};

var a = ["a", "b", "c"];
console.log(a);
// [a, b, c]

Utils["map"](a, function (key, value) {
    return "(" + key + ":" + value + ")";
});
console.log(a);
// [(0:a), (1:b), (2:c)]
</pre></td></tr></table>



Iteration
--------
<table><tr><td><strong>C++</strong><pre>
var array = {10, 42, 30};
for (var i : array) {
    std::cout &lt;&lt; i &lt;&lt; " - " &lt;&lt; array[i] &lt;&lt; std::endl;
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
for (var i : object) {
    std::cout &lt;&lt; i &lt;&lt; " - " &lt;&lt; object[i] &lt;&lt; std::endl;
}
// a - 1
// b - 2
// c - 3
// prototype - undefined
</pre></td><td><strong>Javascript</strong><pre>
var array = [10, 42, 30];
for (var i in array) {
    console.log(i, array[i]);
}
// 0 - 10
// 1 - 42
// 2 - 30



var object = {
    "a": 1,
    "b": 2,
    "c": 3
};
for (var i in object) {
    console.log(i, object[i]);
}
// a - 1
// b - 2
// c - 3

</pre></td></tr></table>



JSON
--------
<table><tr><td><strong>C++</strong><pre>
var json = {
    _["number"] = 42,
    _["string"] = "kikoo",
    _["array"] = {1, 2, "lol"},

	_["nested"] = _({
        _["first"] = 1
	})
};

std::cout &lt;&lt; json &lt;&lt; std::endl;
// {array: [1, 2, lol], nested: {first: 1},
    number: 42, string: kikoo}
</pre></td><td><strong>Javascript</strong><pre>
var json = {
    "number": 42,
    "string": "kikoo",
    "array": [1, 2, "lol"],

	"nested": {
        "first": 1
	}
};

console.log(json);
// {number: 42, string: 'kikoo',
    array: [1, 2, lol], nested: {first: 1}}
</pre></td></tr></table>



Reference
--------
<table><tr><td><strong>C++</strong><pre>
var a = {};
a["key"] = "old";

var b = a;
b["key"] = "new";

std::cout &lt;&lt; a["key"] &lt;&lt; " " &lt;&lt; b["key"] &lt;&lt; std::endl;
// new new 
</pre></td><td><strong>Javascript</strong><pre>
var a = {};
a["key"] = "old";

var b = a;
b["key"] = "new";

console.log(a["key"], b["key"]);
// new new 
</pre></td></tr></table>



Scope
--------
<table><tr><td><strong>C++</strong><pre>
var global = "global";
var $ = "prototype";
var jQuery = "jQuery";

_(function (var $) {
	var global = "local";

	std::cout &lt;&lt; "Inside:      $ = " &lt;&lt; $ &lt;&lt; std::endl;
	std::cout &lt;&lt; "Inside: global = " &lt;&lt; global &lt;&lt; std::endl;

	// Inside:      $ = jQuery
	// Inside: global = local

	return undefined;
})(jQuery);

std::cout &lt;&lt; "Outside:      $ = " &lt;&lt; $ &lt;&lt; std::endl;
std::cout &lt;&lt; "Outside: global = " &lt;&lt; global &lt;&lt; std::endl;

// Outside:      $ = prototype
// Outside: global = global
</pre></td><td><strong>Javascript</strong><pre>
var global = "global";
var $ = "prototype";
var jQuery = "jQuery";

(function ($) {
	var global = "local";

	console.log("Inside:      $ = ", $);
	console.log("Inside: global = ", global);

	// Inside:      $ = jQuery
	// Inside: global = local

	return undefined;
})(jQuery);

console.log("Outside:      $ = ", $);
console.log("Outside: global = ", global);

// Outside:      $ = prototype
// Outside: global = global
</pre></td></tr></table>



This
--------
<table><tr><td><strong>C++</strong><pre>
var f = function (var x, var y) {
    std::cout &lt;&lt; "this: " &lt;&lt; This &lt;&lt; std::endl;
    This["x"] = x;
    This["y"] = y;
    return This;
};

// New creates a new object this
var a = New(f)(1, 2); // this: <function 0x005240d0>
var b = New(f)(3, 4); // this: <function 0x005248e0>

// Unbound call, 
var c = f(5, 6); // this: undefined

// Bound call
var obj = {42};
obj["f"] = f;

var d = obj["f"](1, 2); // this: [42]

// Call
var e = f["call"](obj, 1, 2); // this: [42]
</pre></td><td><strong>Javascript</strong><pre>
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
</pre></td></tr></table>

