
var a = {};
a["key"] = "old";

var b = a;
b["key"] = "new";

console.log(a["key"], b["key"]);
// new - new 
