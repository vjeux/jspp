
var go_die = function () {
    throw "Exception!";
};

try {
    go_die();
} catch (e) {
    console.log("Error:", e);
}
// Error: Exception!

