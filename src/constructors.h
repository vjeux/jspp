
	
Object& Object::operator= (Object o) {
	write->s = o.s;
	write->s->refcount += 1;
	return *write;
}
	
Object& Object::operator|= (Object o) {
	write->s->refcount += 1;
	
	write->s->type = o.s->type;
	write->s->s = o.s->s;
	write->s->n = o.s->n;
	write->s->map = o.s->map;
	write->s->kv = o.s->kv;

	write->s->f = o.s->f;
	write->s->f0 = o.s->f0;
	write->s->f1 = o.s->f1;
	write->s->f2 = o.s->f2;
	write->s->f3 = o.s->f3;
	write->s->f4 = o.s->f4;
	write->s->f5 = o.s->f5;

	return *write;
}

Object::Object(const Object& o) : self(o.self), write(this), s(o.s) {
	s->refcount += 1;
}

Object::Object() : self(&undefined), write(this), s(new State) {
	s->type = UNDEFINED;
}
	
Object::Object(double n) : self(&undefined), write(this), s(new State)  {
	s->n = n;
	s->type = NUMBER;
}

Object::Object(int n) : self(&undefined), write(this), s(new State)  {
	s->n = n;
	s->type = NUMBER;
}
	
Object::Object(bool b) : self(&undefined), write(this), s(new State)  {
	s->n = b ? 1 : 0;
	s->type = NUMBER;
}
	
Object::Object(const char* str) : self(&undefined), write(this), s(new State)  {
	s->s = str;
	s->type = STRING;
}

Object::Object(std::string str) : self(&undefined), write(this), s(new State)  {
	s->s = str;
	s->type = STRING;
}

template<typename F> // Function
Object::Object(F f) : self(&undefined), write(this), s(new State) 
{
	set_func(f, &F::operator());
	s->type = FUNCTION;
	s->map["prototype"] = global["Function"];
}


Object::Object(std::pair<const std::basic_string<char>, Object> it) : self(&undefined), write(this), s(new State) {
	s->s = it.first;
	s->type = STRING;
}


Object::Object(std::initializer_list<Object> list) : self(&undefined), write(this), s(new State) {
	int length = 0;

	for (auto elem : list)
		if (elem.s->type == KEYVALUE) {
			(*this)[elem.s->kv->key] = elem.s->kv->value;
		} else {
			(*this)[length++] = elem;
		}

	if (length > 0) {
		(*this)["length"] = length;
		s->type = ARRAY;
	} else {
		s->type = OBJECT;
	}
}

Object::Object(KeyValue& kv) : self(&undefined), write(this), s(new State) {
	s->type = KEYVALUE;
	s->kv = &kv;
}

Object New(Object o) {
	Object n;

	n.s->type = FUNCTION;
	n.s->f = o.s->f;
	n.s->f0 = o.s->f0;
	n.s->f1 = o.s->f1;
	n.s->f2 = o.s->f2;
	n.s->f3 = o.s->f3;
	n.s->f4 = o.s->f4;
	n.s->f5 = o.s->f5;

	n.self = &n;
	n["__proto__"] = o["prototype"];

	return n;
}
