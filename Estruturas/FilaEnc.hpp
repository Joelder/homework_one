// Copyright 2015 Joelder Maragno Arcaro

#ifndef FILAENC_HPP
#define FILAENC_HPP


#include "ListaEnc.hpp"

template <typename T>
class FilaEnc : public ListaEnc<T> {
 private:
    Elemento<T>* tail;

 public:
 	/*!
 	* Chamando o Construtor/Destrutor da classe Lista encadeada  
 	* 
	*/
	FilaEnc<T>() {}

	~FilaEnc() {}


	/*!
 	* Método inclui um elemento no final da fila  
 	* 
	*/
	void inclui(const T& dado) {
		if(filaVazia()) {
			this->adicionaNoInicio(dado);
			this->tail = this->head;
		} else {
			Elemento<T>* pointer_transfer = new Elemento<T>(dado, NULL);
			this->tail->setProximo(pointer_transfer);
			this->tail = pointer_transfer;
		}
		this->size++;
	}


	/*!
 	* Método retira o primeiro da fila  
 	* 
	*/
	T retira() {
		T obj = this->retiraDoInicio();
		if(filaVazia()) {
			this->tail = NULL;
		}
		return obj;
	}

	/*!
 	* Método retorna  obj do ultimo elemento da fila  
 	* 
	*/
	T ultimo() {
		if(filaVazia()) {
			throw "fila vazia";
		}
		return this->tail->getInfo();
	}

	/*!
 	* Método retorna obj do primeiro elemento da fila  
 	* 
	*/
	T primeiro() {
		if(filaVazia()) {
			throw "fila vazia";
		}
		return this->head->getInfo();
	}

	/*!
 	* Verifica se a fila está vazia  
 	* 
	*/
	bool filaVazia() {
		return this->listaVazia();
	}

	/*!
 	* UFSC semi-direto hehe papa fila  
 	* 
	*/
	void limparFila() {
		this->destroiLista();
    }
};
#endif
