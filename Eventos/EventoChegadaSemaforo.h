/*
 * EventoChegadaSemaforo.h
 *
 *  Created on: May 1, 2015
 *      Author: home
 */

#ifndef EVENTOS_EVENTOCHEGADASEMAFORO_H_
#define EVENTOS_EVENTOCHEGADASEMAFORO_H_

class EventoChegadaSemaforo {
public:
	EventoChegadaSemaforo();
	virtual ~EventoChegadaSemaforo();

	// ponteiro carro (pista destino pega pelo carro)
	// Pista de origem do carro
	// timestamp

	//Processa pelo sistema

	// verificar se tem carro na frente
	// Pode gerar um novo EventoChegadaSemaforo
	// verificar o espaço ocupado pista destino
	// verificar o semaforo da pista origem
	// pode gerar troca pista
};

#endif /* EVENTOS_EVENTOCHEGADASEMAFORO_H_ */
