/*
 * pista.h
 *
 *  Created on: Apr 26, 2015
 *  Copyright 2015 Joelder Maragno Arcaro e Thomas Feijo
 */

#ifndef PISTA_H_
#define PISTA_H_
#include "../Estruturas/FilaEnc.hpp"

class Pista: private FilaEnc {

private:
	int tamanho;
	int velocidade;
	bool semaforo;
	bool pista_cheia;
	Lista<Pista>* pistas_conectadas;


public:
	Pista();
	virtual ~Pista();
	// implementar os gets
	// implemente set do semaforo
	// implementar tirar da pista
	// implementar adicionar na pista
	// passar parametros na sua criação
	// interconectar as pistas, popular a lista
	// condicao para transferencia de carro: semaforo true e pista cheia false(da proxima pista)
	// implementar metodo que diz espaço restante
	// adicionar atributos fonte e sumidouro e identificador
	// implementar metodo que adicione pistas conectadas
	// pistas sumidouro o semaforo é sempre true
};

#endif /* PISTA_H_ */
