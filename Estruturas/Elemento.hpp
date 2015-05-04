// Copyright 2015 Joelder Maragno Arcaro
#ifndef ELEMENTO_HPP
#define ELEMENTO_HPP

/*!
* Representa um elemento de uma lista encadeada. Estrutura na qual todo elemento
* está "ligado" com o seu próximo através de um ponteiros
*/

template<typename T>
class Elemento {
 private:
	T* info;
	Elemento<T>* _next;

 public:
Elemento(const T& info, Elemento<T>* next) {
	    this->info = new T(info);
	    this->_next = next;
	}

	~Elemento() {
		delete info;
	}

	Elemento<T>* getProximo() const {
		return _next;
	}

	T getInfo() const {
		return *info;
	}

	void setProximo(Elemento<T>* next) {
		_next = next;
	}
};


#endif
