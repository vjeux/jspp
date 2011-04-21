[js++]
====

**!!This is in early development!!**

C++0x, the new specification of C++ adds features such as lambda, foreach and list construction. It is therefore possible to write C++ in a Javascript fashion.

All the code below is written in C++ and (will) works.

JSON
--------

<table><tr><td><strong>C++</strong><pre>
var json = {
	_["number"] = 42,
	_["string"] = "kikoo",
	_["array"] = {1, 2, "lol"},
	_["nested"] = {
		_["first"] = 1
	}
};
</pre></td><td><strong>Javascript</strong><pre>
var json = {
	"number": 42,
	"string": kikoo,
	"array": [1, 2, "lol"],
	"nested": {
		"first": 1
	}
};
</pre></td></tr></table>



Prototypal Inheritance
--------

```javascript
var parent = { _["x"] = 42 };
var child = { };
child["prototype"] = parent;

std::cout << child["x"] << std::endl;
// 42

child["x"] = "js++";
std::cout << child["x"] << std::endl;
// "js++"
```


Dynamic Typing
---------

```javascript
function repeat(var str, var times) {
	var ret = "";
	for (var i = 0; i < times; ++i) {
		ret += str;
	}
	return str;
}

std::cout << repeat("js++ ", 3) << std::endl;
// "js++ js++ js++ "
```

Iteration
-------------

```javascript
var array = {10, 42, 30};
for (var i : array) {
	std::cout << i << " - " << array[i] << std::endl;
}
// 0 - 10
// 1 - 42
// 2 - 30


var object = {
	_["a"] = 1,
	_["b"] = 2,
	_["c"] = 3
};
for (var i : object) {
	std::cout << i << " - " << object[i] << std::endl;
}
// a - 1
// b - 2
// c - 3
```

Lambda
--------------

```javascript
var Utils = {
	_["map"] = function (var array, var func) {
		for (var i : array) {
			array[i] = func(array[i]);
		}
	}
}

var a = {1, 2, 3};
Utils["map"](a, function (var i) {
	return i += 1;
});

std::cout << a << std::endl;
// {2, 3, 4}


_(function () {
	// New scope !
)();
```

Everything is a reference
-----------------

```javascript
var a = 0;
a["key"] = "old";

var b = a;
b["key"] = "new";

std::cout << a["key"] << " - " << b["key"] << std::endl;
// new - new 
```

This 
-------

<table><tr><td><strong>C++</strong><pre>
var f = function (var x, var y) {
	std::cout &lt;&lt; "This: " &lt;&lt; This &lt;&lt; std::endl;
	This["x"] = x;
	This["y"] = y;

	return This;
};

// New creates a new object this
var a = New(f)(1, 2); // This: &lt;function 005240d0>
var b = New(f)(3, 4); // This: &lt;function 005248e0>

// Unbound call, This is undefined
var c = f(5, 6);

// Bound call
var obj = 42;
obj["f"] = f;

var d = obj["f"](1, 2); // This: 42

// Call
var e = f["call"](obj, 1, 2); // This: 42
</pre></td><td><strong>Javascript</strong><pre>
var f = function (x, y) {
	console.log("This: ", this);
	this["x"] = x;
	this["y"] = y;

	return this;
};

// New creates a new object this
var a = new f(1, 2); // This: &lt;function 005240d0>
var b = new f(3, 4); // This: &lt;function 005248e0>

// Unbound call
var c = f(5, 6); // This: window

// Bound call
var obj = new Number(42);
obj["f"] = f;

var d = obj["f"](1, 2); // This: 42

// Call
var e = f["call"](obj, 1, 2); // This: 42
</pre></td></tr></table>



Exception Handling 
-------


<table><tr><td><strong>C++</strong><pre>
var go_die = function () {
	throw _("Exception!");
};

try {
	go_die();
} catch (var e) {
	std::cout << "Error: " << e << std::endl;
}
// Error: Exception
</pre></td><td><strong>Javascript</strong><pre>
var go_die = function () {
	throw "Exception!";
};

try {
	go_die();
} catch (e) {
	console.log("Error:", e);
}
// Error: Exception
</pre></td></tr></table>
