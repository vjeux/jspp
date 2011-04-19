==== [js++]


=== JSON ===

	var json = {
		_["number"] = 42,
		_["string"] = "kikoo",
		_["array"] = {1, 2, "lol"},
		_["nested"] = {
			_["first"] = 1
		}
	};


=== Prototypal Inheritance

	var parent = { _["x"] = 42 };
	var child = { };

	std::cout << child["x"] << std::endl;
	// 42

	child["x"] = "js++";
	std::cout << child["x"] << std::endl;
	// "js++"
