#include "../src/javascript_start.h"

var json = {
    _["number"] = 42,
    _["string"] = "kikoo",
    _["array"] = {1, 2, "lol"},

	_["nested"] = _({
        _["first"] = 1
	})
};

std::cout << json << std::endl;
// {array: [1, 2, lol], nested: {first: 1}, number: 42, string: kikoo}

#include "../src/javascript_end.h"
