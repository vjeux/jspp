
#include "object.h"
#include "underscore.h"
#include "operators.h"
#include "constructors.h"

#define catch(e) catch(var e)
#define throw throw _=
#define this This
#define new New
#define in :
#define function(...) [=] (var This, ##__VA_ARGS__) mutable -> Object

int main()
{
	try {

#include "stdlib.h"
