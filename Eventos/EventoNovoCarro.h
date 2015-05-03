/*
 * EventoNovoCarro.h
 *
 *  Created on: May 1, 2015
 *      Author: home
 */

#ifndef EVENTOS_EVENTONOVOCARRO_H_
#define EVENTOS_EVENTONOVOCARRO_H_
#include "../Eventos/Evento.cpp"

class EventoNovoCarro: public Evento {
private:
	int tamanhoCarro;
	Pista* pistaOrigem;
	Pista* pistaDestino;

public:
	EventoNovoCarro(int tamanhoCarro, Pista* pistaOrigem, Pista* pistaDestino);

	virtual ~EventoNovoCarro();

	int getTamanhoCarrro();

	Pista* getPistaOrigem();

	Pista* getPistaDestino();

	//Tamanho do carro
	// Pista origem
	// Pista destino
	//timestamp


	// Processar pelo sistema
	// Criar o carro
	//colocar o carro na pista
	// Gerar evento chegada semaforo
	// gets


};

#endif /* EVENTOS_EVENTONOVOCARRO_H_ */
