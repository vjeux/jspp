
var createObject = function (o) {
	var F = function () {};
	F["prototype"] = o;
	return new F();
};

var Person = {
  name: "Default",
  greet: function () {
    return "Hello world, my name is " + this.name;
  }
};

var vjeux = createObject(Person);
vjeux.name = "Vjeux";

var blog = createObject(Person);
blog.name = "Blog";

var def = createObject(Person);

console.log(vjeux.greet()); // Vjeux
console.log(blog.greet());  // Blog
console.log(def.greet());   // Default
