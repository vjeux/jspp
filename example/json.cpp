#include "../src/javascript_start.h"

var json = {
    _["number"] = 42,
    _["string"] = "vjeux",
    _["array"] = {1, 2, "three"},

	_["nested"] = _({
        _["first"] = 1
	})
};

std::cout << json << std::endl;
// {array: [1, 2, three], nested: {first: 1}, number: 42, string: vjeux}

#include "../src/javascript_end.h"
