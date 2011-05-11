
#include "object.h"
#include "underscore.h"
#include "operators.h"
#include "constructors.h"

#define catch(e) catch(var e)
#define throw throw _=
#define this This
#define new New

int main()
{
	try {

#include "stdlib.h"
