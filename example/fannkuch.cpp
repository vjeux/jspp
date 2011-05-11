#include "../src/javascript_start.h"

// www.webkit.org/perf/sunspider-0.9/access-fannkuch.html

var fannkuch = function (var n) {
   var check = 0;
   var perm = Array(n);
   var perm1 = Array(n);
   var count = Array(n);
   var maxPerm = Array(n);
   var maxFlipsCount = 0;
   var m = n - 1;
 
   for (var i = 0; i < n; i++) perm1[i] = i;
   var r = n;
 
   while (true) {
      while (r != 1) { count[r - 1] = r; r--; }
      if (!(perm1[0] == 0 || perm1[m] == m)) {
         for (var i = 0; i < n; i++) perm[i] = perm1[i];
 
         var flipsCount = 0;
         var k;
 
         while (!((k = perm[0]) == 0)) {
            var k2 = (k + 1) >> 1;
            for (var i = 0; i < k2; i++) {
               var temp = perm[i]; perm[i] = perm[k - i]; perm[k - i] = temp;
            }
            flipsCount++;
         }
 
         if (flipsCount > maxFlipsCount) {
            maxFlipsCount = flipsCount;
            for (var i = 0; i < n; i++) maxPerm[i] = perm1[i];
         }
      }
 
      while (true) {
         if (r == n) return maxFlipsCount;
         var perm0 = perm1[0];
         var i = 0;
         while (i < r) {
            var j = i + 1;
            perm1[i] = perm1[j];
            i = j;
         }
         perm1[r] = perm0;
 
         count[r] = count[r] - 1;
         if (count[r] > 0) break;
         r++;
      }
   }
};

var n = 7;
var ret = fannkuch(n);
std::cout << fannkuch(n) << std::endl;

#include "../src/javascript_end.h"
