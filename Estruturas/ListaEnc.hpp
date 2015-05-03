// Copyright 2015 Joelder Maragno Arcaro

#ifndef LISTAENC_HPP
#define LISTAENC_HPP


#include "Elemento.hpp"
#include <stdio.h>

template<typename T>
class ListaEnc {
 protected:
	Elemento<T>* head;
	int size;

 public:
 	/*!
 	* Construtor lista encadeada
	* 
	*/
	ListaEnc() {
		this->size = 0;
		this->head = NULL;
	}

 	/*!
 	* Destrutor lista encadeada
	* 
	*/
	~ListaEnc() {
	    this->destroiLista();
	}

	/*!
 	* Método responsável por adicionar um elemento
 	* no inicio da lista.
 	* 
	* @param dado
	*/
	virtual void adicionaNoInicio(const T& dado) {
		Elemento<T>* pointer_transfer = this->head;
		this->head = new Elemento<T>(dado, pointer_transfer);
		this->size++;
	}

	/*!
 	* Método responsável por retirar um elemento 
 	* do inicio da lista.
	* @return T obj
	*/
	T retiraDoInicio() {
		if(listaVazia()) {
			throw "Exception lista vazia";
		} else {
			Elemento<T>* pointer_transfer = this->head;
			T obj = pointer_transfer->getInfo();
			this->head = pointer_transfer->getProximo();
			this->size--;
			delete pointer_transfer;
			return obj;
		}
	}

	/*!
 	* Método responsável por retirar um elemento 
 	* do inicio da lista.
	* 
	*/
	void eliminaDoInicio() {
		if(listaVazia()) {
			throw "Exception lista vazia";
		} else {
			Elemento<T>* pointer_transfer = this->head;
    		Elemento<T>* atual = pointer_transfer->getProximo();
    		this->head = atual;
    		this->size--;
    		delete pointer_transfer;
	    }
	}

	/*!
 	* Método responsável por adicionar um elemento 
 	* em uma determinada posição
	* @param dado
	* @param pos
	*/
	void adicionaNaPosicao(const T& dado, int pos) {
		if(pos > this->size || pos < 0) {
			throw "Erro na posição";
		} else if (pos == 0) {
			adicionaNoInicio(dado);
		} else {
			Elemento<T>* pointer_transfer = this->head;
			for(int i = 1; i < pos; i++) {
				pointer_transfer = pointer_transfer->getProximo();
			}
			Elemento<T>* novo = pointer_transfer->getProximo();
			pointer_transfer->setProximo(new Elemento<T>(dado, novo));
			this->size++;
		}
	}

	/*!
 	* Método responsável por retorna a posição 
 	* de um determinado elemento dentro da lista
	* @param dado
	* @return int
	*/
	int posicao(const T& dado) const {
		Elemento<T>* pointer_transfer = this->head;
		for (int i = 0; i < this->size; i++) {
			if(dado == pointer_transfer->getInfo()) {
				return i;
			}
			pointer_transfer = pointer_transfer->getProximo();
		}
		throw "Elemento não pertence a lista";
	}

	/*!
 	* Método responsável por retornar a posição
 	* da memoria de um determinado elemento da lista
	* @param dado
	* @return pointer
	*/
	T* posicaoMem(const T& dado) const {
		Elemento<T>* pointer_transfer = this->head;
		for(int i = 0; i < this->size; i++) {
			if(this->igual(dado, pointer_transfer->getInfo())) {
				T obj = pointer_transfer->getInfo();
				return &obj;
			}
			pointer_transfer = pointer_transfer->getProximo();
		}
	}

	/*!
 	* Método responsável por vereficar se um determinado 
 	* elemento pertence a uma lista
	* @param dado
	* @return bool
	*/
	bool contem(const T& dado) {
		Elemento<T>* pointer_transfer = this->head;
		for(int i = 0; i < this->size; i++) {
			if(pointer_transfer == NULL) {
				throw "Erro";
			} else if (this->igual(dado, pointer_transfer->getInfo())) {
				return true;
			}
			pointer_transfer = pointer_transfer->getProximo();
		}
		return false;
	}

	/*!
 	* Método responsável por retirar um elemento 
 	* de uma determinada posição
	* @param pos
	* @return T obj
	*/
	T retiraDaPosicao(int pos) {
		if(pos >= this->size || pos < 0) {
			throw "Erro na posição";
		} else if (pos == 0) {
			return this->retiraDoInicio();
		} else {
			Elemento<T>* pointer_transfer = this->head;
			for(int i = 1; i < pos; i++) {
				pointer_transfer = pointer_transfer->getProximo();
			}
			Elemento<T>* elemento = pointer_transfer->getProximo();
			T obj = elemento->getInfo();
			pointer_transfer->setProximo(elemento->getProximo());
			delete elemento;
			this->size--;
			return obj;
		}
	}

	/*!
 	* Método responsável por adicionar um elemento 
 	* no final da lista
	* @param dado
	* 
	*/
	void adiciona(const T& dado) {
		adicionaNaPosicao(dado, this->size);
	}

	/*!
 	* Método responsável por retirar um elemento 
 	* do final da lista
	* @return  T obj
	* 
	*/
	T retira() {
		return this->retiraDaPosicao(this->size-1);
	}

	/*!
 	* Método responsável por retirar um elemento 
 	* especifico da lista
	* @param dado
	* @return T obj
	*/
	T retiraEspecifico(const T& dado) {
		return this->retiraDaPosicao(this->posicao(dado));
	}

	/*!
 	* Método responsável por adicionar em ordem 
	* @param data
	* 
	*/
	void adicionaEmOrdem(const T& data) {
		if (listaVazia()) {
			adicionaNoInicio(data);
		} else {
			Elemento<T>* pointer_transfer = this->head;
			int count = 0;
			while (count < this->size-1 && data > pointer_transfer->getInfo()) {
				pointer_transfer = pointer_transfer->getProximo();
				count++;
			}
			if (this->maior(data, pointer_transfer->getInfo())) {
				this->adicionaNaPosicao(data, count+1);
			} else {
				this->adicionaNaPosicao(data, count);
			}
		}
	}

	/*!
 	* Método responsável por verificar se a lista  
 	* está vazia.
	*/
	bool listaVazia() const {
		return this->size == 0;
	}

	/*!
 	* Método responsável por verificar se dois elementos  
 	* são iguais.
	*/
	bool igual(T dado1, T dado2) {
		return dado1 == dado2;
	}

	/*!
 	* Método verifica qual elemento é maior  
 	*
	*/
	bool maior(T dado1, T dado2) {
		return dado1 > dado2;
	}

	/*!
 	* Método verifica qual elemento é menor  
 	*
	*/
	bool menor(T dado1, T dado2) {
		return dado1 < dado2;
	}

	/*!
 	* Método destrutor da lista.  
 	*
	*/
	void destroiLista() {
		Elemento<T>* pointer_transfer = this->head;
		for(int i = 0; i < this->size; i++) {
			Elemento<T>* anterior = pointer_transfer;
			pointer_transfer = pointer_transfer->getProximo();
			delete anterior;
		}
		this->head = NULL;
		this->size = 0;
	}
};
#endif
