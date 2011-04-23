
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

