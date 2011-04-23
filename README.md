
CPP                                           | Javascript
-------------------------------------------------------------------------------------:
```javascript				      |```javascript                                
var repeat = function (var str, var times) {  | var repeat = function (str, times) {         
    var ret = "";			      |    var ret = "";                            
    for (var i = 0; i < times; ++i) {	      |    for (var i = 0; i < times; ++i) {        
        ret += str + i;			      |        ret += str + i;                      
    }					      |    }                                        
    return ret;				      |    return ret;                              
};					      | };                                           
					      |                                             
std::cout << repeat(" js++", 3) << std::endl; | console.log(repeat(" js++", 3));             
// " js++0 js++1 js++2"			      | // " js++0 js++1 js++2"                      
```					      | ```                                          










