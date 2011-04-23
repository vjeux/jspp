
CPP | Javascript
-----------------:
```javascript
var repeat = function (var str, var times) {
    var ret = "";
    for (var i = 0; i < times; ++i) {
        ret += str + i;
    }
    return ret;
};

std::cout << repeat(" js++", 3) << std::endl;
// " js++0 js++1 js++2"
``` |
```javascript
var repeat = function (str, times) {
    var ret = "";
    for (var i = 0; i < times; ++i) {
        ret += str + i;
    }
    return ret;
};

console.log(repeat(" js++", 3));
// " js++0 js++1 js++2"
```
-----------------