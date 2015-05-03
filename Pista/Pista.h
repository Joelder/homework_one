/*
 * pista.h
 *
 *  Created on: Apr 26, 2015
 *  Copyright 2015 Joelder Maragno Arcaro e Thomas Feijo
 */

#ifndef PISTA_H_
#define PISTA_H_
#include "../Estruturas/FilaEnc.hpp"
#include "../Estruturas/Lista.hpp"
#include "../Carro/Carro.cpp"

class Pista: public FilaEnc<Carro*> {

protected:
	int tamanho;
	int espacoRestante;
	int velocidade;
	bool semaforo;
	Lista<Pista*>* pistasConectadas;


public:
	Pista(int tamanho, int velocidade);
	virtual ~Pista();

	int getTamanho();

	int getVelocidade();

	bool getSemaforo();

	void setSemaforo();

	Lista<Pista*>* getPistasConectadas();

	void adicionarCarroPista(Carro* carro);

	void retirarCarroPista();

	void conectarPistas(Pista* pista1, Pista* pista2, Pista* pista3);

	bool transferirCarro(Pista* pista);

	int getEspacoRestante();

};

#endif /* PISTA_H_ */
