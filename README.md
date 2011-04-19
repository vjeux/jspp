[js++]
====

**This is in early development**

C++0x, the new specification of C++ adds features such as lambda, foreach and list construction. It is therefore possible to write C++ in a Javascript fashion.

All the code below is written in C++ and works.

JSON
--------

	var json = {
		_["number"] = 42,
		_["string"] = "kikoo",
		_["array"] = {1, 2, "lol"},
		_["nested"] = {
			_["first"] = 1
		}
	};


Prototypal Inheritance
--------

	var parent = { _["x"] = 42 };
	var child = { };
	child["prototype"] = parent;

	std::cout << child["x"] << std::endl;
	// 42

	child["x"] = "js++";
	std::cout << child["x"] << std::endl;
	// "js++"


Dynamic Typing
---------

	function repeat(var str, var times) {
		var ret = "";
		for (var i = 0; i < times; ++i) {
			ret += str;
		}
		return str;
	}

	std::cout << repeat("js++ ", 3) << std::endl;
	// "js++ js++ js++ "


Iteration
-------------

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
	

Lambda
--------------

	var Utils = {
		_["map"] = lambda (var array, var func) {
			for (var i : array) {
				array[i] = func(array[i]);
			}
		}
	}

	var a = {1, 2, 3};
	Utils["map"](a, lambda (var i) {
		return i += 1;
	});

	std::cout << a << std::endl;
	// {2, 3, 4}
