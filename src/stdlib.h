
// Initialize with a dummy value first or it'll go into an infinite loop
global["Function"] = "Function";
global["Function"] = function(var s) {
	throw _("Cannot eval in C++ sorry :(");
};
global["Function"]["prototype"] = 0;
global["Function"]["prototype"]["call"] = function (var self, var a, var b, var c, var d) {
	This.self = &self;
	return This(a, b, c, d);
};
var Function = global["Function"];

global["typeof"] = function (Object o) {
	if (o.s->type == NUMBER) {
		return "number";
	}
	if (o.s->type == STRING) {
		return "string";
	}
	if (o.s->type == UNDEFINED) {
		return "undefined";
	}
	if (o.s->type == NULLL) {
		return "null";
	}
	if (o.s->type == OBJECT) {
		return "object";
	}
	return undefined;
};
var Typeof = global["typeof"];
