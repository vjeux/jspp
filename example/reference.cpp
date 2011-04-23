#include "../src/javascript_start.h"


var a = 0;
a["key"] = "old";

var b = a;
b["key"] = "new";

std::cout << a["key"] << " - " << b["key"] << std::endl;
// new - new 


#include "../src/javascript_end.h"
