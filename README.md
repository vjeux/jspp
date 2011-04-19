[js++]
====


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
