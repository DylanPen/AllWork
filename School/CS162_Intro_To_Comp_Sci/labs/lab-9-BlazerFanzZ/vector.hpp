#ifndef VECTOR_HPP
#define VECTOR_HPP

template<typename T>
class vector {
private:
	T* data = nullptr;
	int num_data = 0;
public:
	vector() = default;

	~vector() {
		// TODO
		delete [] data;
		data = nullptr;
	}

	vector(const vector<T>& other) {
		// TODO
		num_data = other.num_data;
        if (num_data > 0) {
            data = new T[num_data];
            for (int i = 0; i < num_data; ++i) {
                data[i] = other.data[i];
            }
        }
	}

	vector<T>& operator=(const vector<T>& other) {
		// TODO
		if (this == &other) {
            return *this;
        }

        delete[] data;

        num_data = other.num_data;
        if (num_data > 0) {
            data = new T[num_data];
            for (int i = 0; i < num_data; ++i) {
                data[i] = other.data[i];
            }
        } else {
            data = nullptr;
        }

        return *this;
	}

	void push_back(const T& value) {
		T* new_data = new T[this->num_data + 1];
		for (int i = 0; i < this->num_data; i++) {
			new_data[i] = this->data[i];
		}
		new_data[this->num_data] = value;
		delete [] this->data;
		this->data = new_data;
		this->num_data++;
	}

	int size() const {
		return this->num_data;
	}

	// TODO Implement an operator[] function. I've written the header for
	// you. The parameter is the index supplied to the square brackets when
	// indexing a vector. For example, in the context of my_vector[i], i is
	// the argument to this [] operator overload.
	T& operator[](int index) {
		// TODO Fix the below line of code. It's incorrect; it's just provided
		// as a placeholder to make the program compile.
  		return data[index];
	}

	// The insert() function receives a value to insert and the index at which
	// to insert it in the vector. It should then insert the value at that
	// index, moving other elements over to make room for it (hint: much like
	// the push_back function, the insert function will need to create a new,
	// bigger array to make room for the new value)
	void insert(int index, const T& value) {
		T* new_data = new T[num_data + 1];
		for (int i = 0; i < index; ++i) {
			new_data[i] = data[i];
		}
		new_data[index] = value;
		for (int i = index + 1; i < num_data + 1; ++i) {
			new_data[i] = data[i - 1];
		}

		delete[] data;
		data = new_data;
		num_data++;
	}
};

#endif
