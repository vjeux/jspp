
#include <limits>
double NaN = std::numeric_limits<double>::quiet_NaN();

Object Object::operator()() {
		if (s->type != FUNCTION) { throw _("Object is not a function"); }
		if (s->f == 0) return s->f0(*self);
		if (s->f == 1) return s->f1(*self, undefined);
		if (s->f == 2) return s->f2(*self, undefined, undefined);
		if (s->f == 3) return s->f3(*self, undefined, undefined, undefined);
		if (s->f == 4) return s->f4(*self, undefined, undefined, undefined, undefined);
		if (s->f == 5) return s->f5(*self, undefined, undefined, undefined, undefined, undefined);
		throw _("Too many arguments");
	}

Object Object::operator()(Object a) {
		if (s->type != FUNCTION) { throw _("Object is not a function"); }
		if (s->f == 0) return s->f0(*self);
		if (s->f == 1) return s->f1(*self, a);
		if (s->f == 2) return s->f2(*self, a, undefined);
		if (s->f == 3) return s->f3(*self, a, undefined, undefined);
		if (s->f == 4) return s->f4(*self, a, undefined, undefined, undefined);
		if (s->f == 5) return s->f5(*self, a, undefined, undefined, undefined, undefined);
		throw _("Too many arguments");
	}

Object Object::operator()(Object a, Object b) {
		if (s->type != FUNCTION) { throw _("Object is not a function"); }
		if (s->f == 0) return s->f0(*self);
		if (s->f == 1) return s->f1(*self, a);
		if (s->f == 2) return s->f2(*self, a, b);
		if (s->f == 3) return s->f3(*self, a, b, undefined);
		if (s->f == 4) return s->f4(*self, a, b, undefined, undefined);
		if (s->f == 5) return s->f5(*self, a, b, undefined, undefined, undefined);
		throw _("Too many arguments");
	}

Object Object::operator()(Object a, Object b, Object c) {
		if (s->type != FUNCTION) { throw _("Object is not a function"); }
		if (s->f == 0) return s->f0(*self);
		if (s->f == 1) return s->f1(*self, a);
		if (s->f == 2) return s->f2(*self, a, b);
		if (s->f == 3) return s->f3(*self, a, b, c);
		if (s->f == 4) return s->f4(*self, a, b, c, undefined);
		if (s->f == 5) return s->f5(*self, a, b, c, undefined, undefined);
		throw _("Too many arguments");
	}

Object Object::operator()(Object a, Object b, Object c, Object d) {
		if (s->type != FUNCTION) { throw _("Object is not a function"); }
		if (s->f == 0) return s->f0(*self);
		if (s->f == 1) return s->f1(*self, a);
		if (s->f == 2) return s->f2(*self, a, b);
		if (s->f == 3) return s->f3(*self, a, b, c);
		if (s->f == 4) return s->f4(*self, a, b, c, d);
		if (s->f == 5) return s->f5(*self, a, b, c, d, undefined);
		throw _("Too many arguments");
	}

Object Object::operator()(Object a, Object b, Object c, Object d, Object e) {
		if (s->type != FUNCTION) { throw _("Object is not a function"); }
		if (s->f == 0) return s->f0(*self);
		if (s->f == 1) return s->f1(*self, a);
		if (s->f == 2) return s->f2(*self, a, b);
		if (s->f == 3) return s->f3(*self, a, b, c);
		if (s->f == 4) return s->f4(*self, a, b, c, d);
		if (s->f == 5) return s->f5(*self, a, b, c, d, e);
		throw _("Too many arguments");
	}


Object operator >>(Object a, Object b) {
	if (a.s->type == NUMBER && b.s->type == NUMBER) {
		return (int)a.s->n >> (int)b.s->n;
	}
	throw Object("Unfinished operator>>");
}


Object operator +(Object a, Object b) {
	if (a.s->type == NUMBER && b.s->type == NUMBER) {
		return a.s->n + b.s->n;
	}
	return a.toString() + b.toString();
}

Object operator -(Object a, Object b) {
	if (a.s->type == NUMBER && b.s->type == NUMBER) {
		return a.s->n - b.s->n;
	}
	return NaN;
}

bool operator ==(Object a, Object b) {
	if (a.s->type == UNDEFINED && b.s->type == UNDEFINED) {
		return true;
	}
	if (a.s->type == NUMBER && b.s->type == NUMBER) {
		return a.s->n == b.s->n;
	}
	if (a.s->type == STRING && b.s->type == STRING) {
		return a.s->s == b.s->s;
	}
	return a.s == b.s;
}

bool operator !=(Object a, Object b) {
	return !(a == b);
}

Object operator *(Object a, Object b) {
	if (a.s->type == NUMBER && b.s->type == NUMBER) {
		return a.s->n * a.s->n;
	}
	return NaN;
}

Object operator /(Object a, Object b) {
	if (a.s->type == NUMBER && b.s->type == NUMBER) {
		return a.s->n / a.s->n;
	}
	return NaN;
}

Object& operator -=(Object& a, Object b) {
	a = a - b;
	return a;
}

Object& operator +=(Object& a, Object b) {
	a = a + b;
	return a;
}

Object& operator /=(Object& a, Object b) {
	a = a / b;
	return a;
}

Object& operator *=(Object& a, Object b) {
	a = a * b;
	return a;
}

Object& operator ++(Object& a) {
	a += 1;
	return a;
}

Object& operator --(Object& a) {
	a -= 1;
	return a;
}

Object& operator --(Object& a, int) {
	a -= 1;
	return a;
}

Object& operator ++(Object& a, int) {
	a += 1;
	return a;
}
/*
bool operator !(Object a) {
	if (a.s->type == NUMBER) {
		return a.s->n == 0;
	}
	return a.toString() == "";
}
*/

bool operator <(Object a, Object b) {
	if (a.s->type == NUMBER && b.s->type == NUMBER) {
		return a.s->n < b.s->n;
	}
	return a.toString() < b.toString();
}

bool operator <=(Object a, Object b) {
	if (a.s->type == NUMBER && b.s->type == NUMBER) {
		return a.s->n <= b.s->n;
	}
	return a.toString() <= b.toString();
}

bool operator >(Object a, Object b) {
	return !(a <= b);
}

bool operator >=(Object a, Object b) {
	return !(a < b);
}


std::string Object::toString() {
	if (s->type == STRING) {
		return s->s;
	}

	if (s->type == NUMBER) {
		std::ostringstream stream;
		stream << s->n;
		return stream.str();
	}

	if (s->type == UNDEFINED) {
		return "undefined";
	}

	if (s->type == NULLL) {
		return "null";
	}

	if (s->type == FUNCTION) {
		std::ostringstream stream;
		stream << "<function " << s << ">";
		return stream.str();
	}

	if (s->type == OBJECT) {
		std::ostringstream stream;
		stream << "{";

		bool first = true;
		for (auto it = this->s->map.begin(); it != this->s->map.end(); ++it) {
			if (it->second != undefined) {
				if (!first) {
					stream << ", ";
				}
				first = false;
				stream << it->first << ": " << it->second;
			}
		}

		stream << "}";
		return stream.str();
	}

	if (s->type == ARRAY) {
		var length = (*this)["length"];
		std::ostringstream stream;
		stream << "[";

		for (var i = 0; i < length; ++i) {
			stream << (*this)[i];
			if (i != length - 1) {
				stream << ", ";
			}
		}

		stream << "]";
		return stream.str();
	}


	throw _("Unknown type");
}


Object& Object::get_key(std::string key) {
	Object& ret = s->map[key];
	if (ret == undefined && s->map["__proto__"] != undefined) {
		return s->map["__proto__"].get_key(key);
	}
	return ret;
}

Object& Object::operator[](Object key) {
	std::string key_str = key.toString();
	Object& ret = get_key(key_str);
	ret.self = this;
	ret.write = &s->map[key_str];
	return ret;
}

