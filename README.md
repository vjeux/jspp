
JSPP
=====

Pro / Cons
----------
Pros
	- 


Dynamic Typing
--------
There is only one class called <code>var</code>. All the operators <code>+</code>, <code>+=</code>, <code>++</code>, <code>&lt;</code>, <code>*</code> ... are overloaded in order to make the right behavior. Since this is only a prototype, all of them are not working properly nor following the ECMAScript standard.

<table><tr><td><strong>C++</strong><pre>
var repeat = function (var str, var times) {
    var ret = "";
    for (var i = 0; i &lt; times; ++i) {
        ret += str + i;
    }
    return ret;
};

std::cout &lt;&lt; repeat(" js++", 3) &lt;&lt; std::endl;
// " js++0 js++1 js++2"
</pre></td><td><strong>Javascript</strong><pre>
var repeat = function (str, times) {
    var ret = "";
    for (var i = 0; i &lt; times; ++i) {
        ret += str + i;
    }
    return ret;
};

console.log(repeat(" js++", 3));
// " js++0 js++1 js++2"
</pre></td></tr></table>



Exception
--------
Javascript exception mechanism is directly borrowed from C++, therefore we can use the native one.

We need to throw a Javascript object. We can either throw a new instance of a Javascript function or use <code>_()</code> to cast a string into an object.
<table><tr><td><strong>C++</strong><pre>
var go_die = function () {
    throw _("Exception!");
};

try {
    go_die();
} catch (var e) {
    std::cout &lt;&lt; "Error: " &lt;&lt; e &lt;&lt; std::endl;
}
// Error: Exception!
</pre></td><td><strong>Javascript</strong><pre>
var go_die = function () {
    throw "Exception!";
};

try {
    go_die();
} catch (e) {
    console.log("Error:", e);
}
// Error: Exception!
</pre></td></tr></table>



Function
--------
C++0x added lambda to the language with the following syntax: <code>\[capture\] (arguments) { body }</code>. <code>function</code> is a macro that transforms <code>function (var i)</code> into <code>\[=\] (var This, var arguments, var i)</code>. This allows to use the Javascript syntax and let us sneakily add the <code>this</code> and <code>arguments</code> magic variables.

C++ is strongly typed and even lambdas have types. We can overload the Object constructor on
[lambda arity](http://stackoverflow.com/questions/4170201/c0x-overloading-on-lambda-arity/4196447#4196447) and have a typed container for each one. Then, we overload the <code>() operator</code> that will call the stored lambda. We we carefully add <code>undefined</code> values for unspecified arguments and fill the <code>This</code> and <code>arguments</code> variables.

In Javascript, when a function does not return a value, it returns undefined. Sadly, we cannot have a default return value in C++, you have to write it yourself.

Since everything must be typed in C++, we have to add <code>var</code> before the argument name.

<table><tr><td><strong>C++</strong><pre>
var Utils = {
    _["map"] = function (var array, var func) {
        for (var i = 0; i &lt; array["length"]; ++i) {
            array[i] = func(i, array[i]);
        }
        return undefined;
    }
};

var a = {"a", "b", "c"};
std::cout &lt;&lt; a &lt;&lt; std::endl;
// [a, b, c]

Utils["map"](a, function (var key, var value) {
    return "(" + key + ":" + value + ")";
});
std::cout &lt;&lt; a &lt;&lt; std::endl;
// [(0:a), (1:b), (2:c)]
</pre></td><td><strong>Javascript</strong><pre>
var Utils = {
    "map": function (array, func) {
        for (var i = 0; i &lt; array["length"]; ++i) {
            array[i] = func(i, array[i]);
        }

    }
};

var a = ["a", "b", "c"];
console.log(a);
// [a, b, c]

Utils["map"](a, function (key, value) {
    return "(" + key + ":" + value + ")";
});
console.log(a);
// [(0:a), (1:b), (2:c)]
</pre></td></tr></table>



Iteration
--------
We use the new iteration facility of C++0x to deal with <code>for(var in)</code> Javascript syntax. As this is a prototype, it currently loops over all the keys of the object. However, it is possible to implement the <code>isEnumerable</code> functionnality.
<table><tr><td><strong>C++</strong><pre>
var array = {10, 42, 30};
for (var i : array) {
    std::cout &lt;&lt; i &lt;&lt; " - " &lt;&lt; array[i] &lt;&lt; std::endl;
}
// 0 - 10
// 1 - 42
// 2 - 30
// length - 3
// prototype - undefined

var object = {
    _["a"] = 1,
    _["b"] = 2,
    _["c"] = 3
};
for (var i : object) {
    std::cout &lt;&lt; i &lt;&lt; " - " &lt;&lt; object[i] &lt;&lt; std::endl;
}
// a - 1
// b - 2
// c - 3
// prototype - undefined
</pre></td><td><strong>Javascript</strong><pre>
var array = [10, 42, 30];
for (var i in array) {
    console.log(i, array[i]);
}
// 0 - 10
// 1 - 42
// 2 - 30



var object = {
    "a": 1,
    "b": 2,
    "c": 3
};
for (var i in object) {
    console.log(i, object[i]);
}
// a - 1
// b - 2
// c - 3

</pre></td></tr></table>



JSON
--------
The Javascript Object notation can be emulated thanks to C++0x initialization lists and a bit of operator overload hackery. <code>_</code> as an operator <code>[]</code> that returns a <code>KeyValue</code> object, that has an operator <code>=</code> overload that fills both keys and values. For each value of the initialization listL If that's an objet, it is treated like an <code>Array</code> (add one to the lenght and use the length as key). If that's a <code>KeyValue</code>, both key and value are set.

There is an ambiguity with nested initialization lists, we use <code>_()</code> to cast the list into an Object. It is probably possible to fix it.

<table><tr><td><strong>C++</strong><pre>
var json = {
    _["number"] = 42,
    _["string"] = "kikoo",
    _["array"] = {1, 2, "lol"},

    _["nested"] = _({
        _["first"] = 1
    })
};

std::cout &lt;&lt; json &lt;&lt; std::endl;
// {array: [1, 2, lol], nested: {first: 1},
    number: 42, string: kikoo}
</pre></td><td><strong>Javascript</strong><pre>
var json = {
    "number": 42,
    "string": "kikoo",
    "array": [1, 2, "lol"],

    "nested": {
        "first": 1
    }
};

console.log(json);
// {number: 42, string: 'kikoo',
    array: [1, 2, lol], nested: {first: 1}}
</pre></td></tr></table>



Reference
--------
As in Javascript, everything is passed by reference. The current implementation uses a simple reference count to handle garbage collection.
<table><tr><td><strong>C++</strong><pre>
var a = {};
a["key"] = "old";

var b = a;
b["key"] = "new";

std::cout &lt;&lt; a["key"] &lt;&lt; " " &lt;&lt; b["key"] &lt;&lt; std::endl;
// new new 
</pre></td><td><strong>Javascript</strong><pre>
var a = {};
a["key"] = "old";

var b = a;
b["key"] = "new";

console.log(a["key"], b["key"]);
// new new 
</pre></td></tr></table>



Scope
--------
Scope management is done with lambdas. Since they are implemented in C++0x, it works without pain.

<table><tr><td><strong>C++</strong><pre>
var global = "global";
var $ = "prototype";
var jQuery = "jQuery";

_(function (var $) {
    var global = "local";

    std::cout &lt;&lt; "Inside:      $ = " &lt;&lt; $ &lt;&lt; std::endl;
    std::cout &lt;&lt; "Inside: global = " &lt;&lt; global &lt;&lt; std::endl;

    // Inside:      $ = jQuery
    // Inside: global = local

    return undefined;
})(jQuery);

std::cout &lt;&lt; "Outside:      $ = " &lt;&lt; $ &lt;&lt; std::endl;
std::cout &lt;&lt; "Outside: global = " &lt;&lt; global &lt;&lt; std::endl;

// Outside:      $ = prototype
// Outside: global = global
</pre></td><td><strong>Javascript</strong><pre>
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
</pre></td></tr></table>



This
--------
There are [four ways](http://bonsaiden.github.com/JavaScript-Garden/#function.this) to set the <code>this</code> value.
  - **Function call**: <code>foo()</code>. <code>this</code> is set to the global object. As this is not a proper way to do things, I set it to undefined.
  - **Method call**: <code>object.foo()</code>. <code>this</code> is set to <code>object</code>.
  - **Constructor**: <code>new foo()</code>. <code>foo</code> is called with a new instance of <code>this</code>.
  - **Explicit**: <code>foo.call(this, arguments...)</code>. We explicitely set the this value.

All four ways are implemented in jspp but in a different way than Javascript. In Javascript, the language knows the construction and therefore can deduce what <code>this</code> is going to be. In C++, on the other hand, have a local view of what is going on. We have to develop another strategy for setting <code>this</code> that works for usual usage patterns.

We associate a <code>this</code> value for every object, by default being <code>undefined</code>. If we obtain the object through another object(<code>test.foo()</code>), <code>this</code> is set to be the base object. <code>New</code> creates a new function object with <code>this</code> set to itself. Therefore it can be called to initialize the object. Contrary to Javascript, the constructor function has to return <code>this</code>.



<table><tr><td><strong>C++</strong><pre>
var f = function (var x, var y) {
    std::cout &lt;&lt; "this: " &lt;&lt; This &lt;&lt; std::endl;
    This["x"] = x;
    This["y"] = y;
    return This;
};

// New creates a new object this
var a = New(f)(1, 2); // this: &lt;function 0x005240d0>
var b = New(f)(3, 4); // this: &lt;function 0x005248e0>

// Unbound call, 
var c = f(5, 6); // this: undefined

// Bound call
var obj = {42};
obj["f"] = f;

var d = obj["f"](1, 2); // this: [42]

// Call
var e = f["call"](obj, 1, 2); // this: [42]
</pre></td><td><strong>Javascript</strong><pre>
var f = function (x, y) {
    console.log("this:", this);
    this["x"] = x;
    this["y"] = y;

};

// New creates a new object this
var a = new f(1, 2); // this: &lt;object 0x005240d0>
var b = new f(3, 4); // this: &lt;object 0x005248e0>

// Unbound call, 
var c = f(5, 6); // this: global object

// Bound call
var obj = [42];
obj["f"] = f;

var d = obj["f"](1, 2); // this: [42]

// Call
var e = f["call"](obj, 1, 2); // this: [42]
</pre></td></tr></table>

