JSPP
=====

C++ has a new standard called C++0x ([Wikipedia](http://en.wikipedia.org/wiki/C%2B%2B0x), [Bjarne Stroustrup](http://www2.research.att.com/~bs/C++0xFAQ.html)) that includes many interesting features such as Lambda, For Each, List Initialization ... Those features are so powerful that they allow to write C++ as if it was Javascript.

The goal of this project is to transform C++ into Javascript. We want to be able to copy & paste Javascript into C++ and be able to run it. While this is not 100% feasible, the result is quite amazing.

**This is only a prototype**. In about 600 lines of code we manage to make the core of the Javascript language.

  >> [Read the full description on my blog](http://blog.vjeux.com/2011/javascript/jspp-morph-cpp-into-javascript.html)
==============

ChangeLog
------

* May 11 2011 - Removed `var` in `catch(var e)`. Removed `_()` in `throw _("e")`. `This` and `New` can be written in lowercase. 
* April 26 2011 - `for (var key : obj)` is now `for (var key in obj)`. Thanks [Rip-Rip](https://github.com/Rip-Rip/)