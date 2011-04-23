
var Utils = {
    "map": function (array, func) {
        for (var i = 0; i < array["length"]; ++i) {
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

