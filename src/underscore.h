
struct KeyValue {
	KeyValue(std::string k) : key(k) {
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

	Object operator= (Object a) {
		return a;
	}
};
Underscore _;

