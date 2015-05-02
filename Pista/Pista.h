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

class Pista: private FilaEnc<Carro*> {

private:
	int tamanho;
	int velocidade;
	bool semaforo;
	bool pistaCheia;
	Lista<Pista>* pistasConectadas;


public:
	Pista();
	virtual ~Pista();

	int getTamanho();

	int getVelocidade();

	bool getSemaforo();

	void setSemaforo();

	bool getPistaCheia();

	void setPistaCheia();

	Lista<Pista>* getPistasConectadas();

	void adicionarCarroPista();

	void retirarCarroPista();

	void conectarPistas(Pista* pista1, Pista* pista2, Pista* pista3);

	bool transferirCarro();


	// interconectar as pistas, popular a lista
	// condicao para transferencia de carro: semaforo true e pista cheia false(da proxima pista)
	// implementar metodo que diz espaço restante
	// adicionar atributos fonte e sumidouro e identificador
	// implementar metodo que adicione pistas conectadas
	// pistas sumidouro o semaforo é sempre true
};

#endif /* PISTA_H_ */
