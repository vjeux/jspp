
#include <iostream>
#include <sstream>
#include <string>
#include <functional>
#include <map>
#include <initializer_list>


enum Types {
	NUMBER,
	STRING,
	FUNCTION,
	UNDEFINED,
	NULLL,
	OBJECT,
	ARRAY,
	KEYVALUE
};

class Object;
class KeyValue;

class State
{
public:
	State() : refcount(1) {}
	int refcount;

	std::map<std::string, Object> map;
	int type;

	double n;
	std::string s;
	int f;
	std::function<Object (Object)> f0;
	std::function<Object (Object, Object)> f1;
	std::function<Object (Object, Object, Object)> f2;
	std::function<Object (Object, Object, Object, Object)> f3;
	std::function<Object (Object, Object, Object, Object, Object)> f4;
	std::function<Object (Object, Object, Object, Object, Object, Object)> f5;
	KeyValue* kv;
};


class Object {
public:

	~Object() {
		if (s->refcount == 1) {
			delete s;
		} else {
			s->refcount -= 1;
		}
	}

	// Constructors

	
	Object& operator= (Object o);
	Object& operator|= (Object o);
	Object(const Object& o);
	Object();
	Object(double n);
	Object(int n);
	Object(bool b);
	Object(const char* str);
	Object(std::string str);
	Object(std::initializer_list<Object> list);
	Object(std::pair<const std::basic_string<char>, Object> it);
	Object(KeyValue& kv);
	template<typename F> Object(F f);


	// Methods

	Object operator()();
	Object operator()(Object);
	Object operator()(Object, Object);
	Object operator()(Object, Object, Object);
	Object operator()(Object, Object, Object, Object);
	Object operator()(Object, Object, Object, Object, Object);

	std::string toString();
	Object& get_key(std::string key);
	Object& operator[](Object key);

	Object* self;
	Object* write;
	State* s;


	std::map<std::string, Object>::iterator begin() {
		return s->map.begin();
	}

	std::map<std::string, Object>::iterator end() {
		return s->map.end();
	}

protected:

/* Functions */
	// http://stackoverflow.com/questions/4170201/c0x-overloading-on-lambda-arity

	/* 0 param */
	template<typename F>
	void set_func(F& f, Object (F::*mf)(Object))
	{ s->f = 0; s->f0 = f; }

	/* 1 param */
	template<typename F>
	void set_func(F& f, Object (F::*mf)(Object, Object))
	{ s->f = 1; s->f1 = f; }

	/* 2 param */
	template<typename F>
	void set_func(F& f, Object (F::*mf)(Object, Object, Object))
	{ s->f = 2; s->f2 = f; }

	/* 3 param */
	template<typename F>
	void set_func(F& f, Object (F::*mf)(Object, Object, Object, Object))
	{ s->f = 3; s->f3 = f; }

	/* 4 param */
	template<typename F>
	void set_func(F& f, Object (F::*mf)(Object, Object, Object, Object, Object))
	{ s->f = 4; s->f4 = f; }

	/* 5 param */
	template<typename F>
	void set_func(F& f, Object (F::*mf)(Object, Object, Object, Object, Object, Object))
	{ s->f = 5; s->f5 = f; }
};

std::ostream& operator<<(std::ostream& stream, Object o) {
	stream << o.toString();
	return stream;
}

typedef Object var;

Object undefined;
Object global;
