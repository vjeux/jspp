
var container = function (data) {
  var secret = data;

  return {
    set: function (x) { secret = x; },
    get: function () { return secret; }
  };
};

var a = container("secret-a");
var b = container("secret-b");

a.set("override-a");

console.log(a.get()); // override-a
console.log(b.get()); // secret-b
