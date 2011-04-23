
class KeyValue {
public:
	KeyValue(std::string k) : key(k), value(undefined) {
	}

	KeyValue& operator=(Object v) {
		this->value = v;
		return *this;
	}

	Object key;
	Object value;
};

class Underscore {
public:
	Object operator() (Object a) {
		return a;
	}
	KeyValue& operator[] (Object key) {
		KeyValue* kv = new KeyValue(key.toString());
		return *kv;
	}

	Object* key;
	Object* value;
};
Underscore _;

