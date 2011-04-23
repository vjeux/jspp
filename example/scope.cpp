#include "../src/javascript_start.h"

var global = "global";
var $ = "prototype";
var jQuery = "jQuery";

_(function (var $) {
	var global = "local";

	std::cout << "Inside:      $ = " << $ << std::endl;
	std::cout << "Inside: global = " << global << std::endl;

	// Inside:      $ = jQuery
	// Inside: global = local

	return undefined;
})(jQuery);

std::cout << "Outside:      $ = " << $ << std::endl;
std::cout << "Outside: global = " << global << std::endl;

// Outside:      $ = prototype
// Outside: global = global

#include "../src/javascript_end.h"
