/*
 * Sistema.cpp
 *
 *  Created on: May 1, 2015
 *      Author: home
 */

#ifndef SISTEMA_CPP
#define SISTEMA_CPP
#include "Sistema.h"
#include <iostream>

#include <cstdlib>
#include <ctime>

Sistema::Sistema(int tempo) {
	this->tempo = tempo;
	this->entradaCarros = 0;
	this->saidaCarros = 0;
	criaPistas();
	this->clock = new Clock();
}

Sistema::~Sistema() {
	// TODO Auto-generated destructor stub
}

void Sistema::criaPistas() {
	this->gerador = new GeradorPistas();
}

Carro* Sistema::criaCarro(int tamanho) {
	Carro* carro = new Carro(tamanho);
	return carro;
}

void Sistema::geraEventosIniciais() {

	geraSemaforos(this->tempo);
	geraNovosCarros(this->tempo);
}

void Sistema::run() {
	int answer = 1;
	while (this->clock->getEventos()->size > 0 && answer == 1) {
		Evento* evento = retiraEventoClock();
		std::cout << "id do evento: " << evento->getId() << std::endl;
		std::cout << "timestamp: " << evento->getTimeStamp() << std::endl;
		consomeEvento(evento);
		//std::cout << "continuar? (1|0)";
		//cin >> answer;
	}
	std::cout << "Entrada de carros sistema: " << this->entradaCarros << std::endl;
	std::cout << "Saida de carros sistema: " << this->saidaCarros << std::endl;
}

void Sistema::consomeEvento(Evento* ev) {
	switch (ev->getId()) {
	case 1:
		consomeEventoNovoCarro(ev);
		break;
	case 2:
		consomeEventoChegadaCarro(ev);
		break;
	case 3:
		consomeChegadaSemaforo(ev);
		break;
	case 4:
		consomeEventoMudancaSemaforo(ev);
		break;
	case 5:
		consomeChegadaFinalFila(ev);
		break;
	}
}

void Sistema::consomeEventoNovoCarro(Evento* ev) {
	int timeEvento = ev->getTimeStamp();
	Carro* carro = criaCarro(ev->getTamanhoCarrro());
	Pista* pistaOrigem = ev->getPistaOrigem();
	carro->setDestino(ev->getPistaDestino());
	pistaOrigem->adicionarCarroPista(carro);
	this->entradaCarros++;
	std::cout << "Novo carro entrou no sistema, pista: "
			<< pistaOrigem->getNome() << std::endl;
	if (pistaOrigem->size == 1) {
		geraEventoChegadaSemaforo(carro, pistaOrigem, timeEvento);
	} else {
		geraEventoChegadaFila(carro, pistaOrigem, timeEvento);
	}

}

void Sistema::geraEventoChegadaFila(Carro* carro, Pista* pistaOrigem,
		int time) {
	int velocidade = (int) (pistaOrigem->getVelocidade() / 3.6);
	int tempo = (int) (pistaOrigem->getEspacoRestante() / velocidade);
	int tamanhofila = pistaOrigem->getTamanho()
			- pistaOrigem->getEspacoRestante();
	int timestamp = tempo + time;
	std::cout << "O carro da pista: " << pistaOrigem->getNome()
			<< " chega no final da fila as " << timestamp << std::endl;
	Evento* evento = new Evento(timestamp, 5, tamanhofila, pistaOrigem, NULL,
			carro);
	incluiEventoClock(evento);
}

void Sistema::consomeChegadaFinalFila(Evento* ev) {
	Pista* pistaOrigem = ev->getPistaOrigem();
	Carro* carro = ev->getCarro();
	int velocidade = (int) (pistaOrigem->getVelocidade() / 3.6);
	// POG By Thomas Feijoo
	int time = (int) (ev->getTamanhoCarrro() / velocidade);
	int timestamp = time + ev->getTimeStamp();
	if (pistaOrigem->size == 1) {
		geraEventoChegadaSemaforo(carro, pistaOrigem, timestamp);
	} else {
		carro->setCarroChegou();
		std::cout << "Carro chegou no semaforo da pista: "
				<< pistaOrigem->getNome() << std::endl;
	}
}

void Sistema::geraEventoTrocaPista(Carro* carro, Pista* pistaOrigem,
		int timestamp) {
	EventoTrocaPista* evento = new EventoTrocaPista(carro);
	consomeEventoTrocaPista(evento, pistaOrigem, timestamp);
}

void Sistema::consomeEventoTrocaPista(EventoTrocaPista* evento,
		Pista* pistaOrigem, int time) {
	Pista* pistaDestino = evento->getCarro()->getDestino();
	pistaOrigem->transferirCarro(pistaDestino);
	std::cout << "Carro transferido da pista: " << pistaOrigem->getNome()
					<< " para pista: " << pistaDestino->getNome() << std::endl;
	std::cout << "A pista: " << pistaOrigem->getNome() << "ficou com: " << pistaOrigem->getEspacoRestante() << "metros" << std::endl;
	std::cout << "A pista: " << pistaDestino->getNome() << "ficou com: " << pistaDestino->getEspacoRestante() << "metros" << std::endl;

	if (pistaOrigem->size > 0 && pistaOrigem->primeiro()->getCarroChegou()) {
		std::cout << "Gerou Deslocamento: " << std::endl;
		geraEventoDeslocamentoChegadaSemaforo(pistaOrigem->primeiro(),
				pistaOrigem, time);
	}
	if (pistaDestino->getTamanho() == 300) {
		int proporcao = pistaDestino->getPistaConectadaProporcao();
		Lista<Pista*>* pistas = pistaDestino->getPistasConectadas();
		Pista* pista = pistas->getPosicao(proporcao);
		pistaDestino->ultimo()->setDestino(pista);
		if (pistaDestino->size == 1) {
			geraEventoChegadaSemaforo(pistaDestino->ultimo(), pistaDestino,
					time);
		} else {
			geraEventoChegadaFila(pistaDestino->ultimo(), pistaDestino, time);
		}
	} else {
		std::cout << "Gerou evento chegada final carro na pista: " << pistaDestino->getNome() << std::endl;
		geraEventoChegadaCarro(pistaDestino, time);
	}
}

void Sistema::geraEventoChegadaCarro(Pista* pista, int timestamp) {
	int velocidade = (int) (pista->getVelocidade() / 3.6);
	int tempo = (int) (pista->getTamanho() / velocidade);
	int time = timestamp + tempo;
	Evento* evento = new Evento(time, 2, 0, NULL, pista, NULL);
	incluiEventoClock(evento);
}

void Sistema::geraEventoDeslocamentoChegadaSemaforo(Carro* carro,
		Pista* pistaOrigem, int time) {
	Evento* evento = new Evento(time + 2, 3, 0, pistaOrigem, NULL, carro);
	incluiEventoClock(evento);
}

void Sistema::geraEventoChegadaSemaforo(Carro* carro, Pista* pistaOrigem,
		int time) {
	int velocidade = (int) (pistaOrigem->getVelocidade() / 3.6);
	int tempo = (int) (pistaOrigem->getTamanho() / velocidade);
	int timestamp = tempo + time;
	std::cout << "O carro da pista: " << pistaOrigem->getNome()
					<< " chega no semaforo as " << timestamp << std::endl;
	Evento* evento = new Evento(timestamp, 3, 0, pistaOrigem, NULL, carro);
	incluiEventoClock(evento);
}

void Sistema::consomeEventoMudancaSemaforo(Evento* ev) {
	Pista* pista = ev->getPistaOrigem();
	pista->setSemaforo();
	std::cout << "Semaforo da pista: " << pista->getNome() << " mudou"
			<< std::endl;


	if(pista->getSemaforo()){
		if (pista->size != 0) {
				if (pista->primeiro()->getCarroChegou()) {
					geraEventoTrocaPista(pista->primeiro(), pista, ev->getTimeStamp());
				}
			}
	}


}

void Sistema::consomeEventoChegadaCarro(Evento* ev) {
	Pista* pista = ev->getPistaDestino();
	std::cout << "O carro chegou no final da pista: " << pista->getNome()
			<< " no tempo:" << ev->getTimeStamp() << std::endl;
	pista->retirarCarroPista();
	this->saidaCarros++;
}

void Sistema::consomeChegadaSemaforo(Evento* ev) {
	Pista* pista = ev->getPistaOrigem();
	Carro* carro = ev->getCarro();
	carro->setCarroChegou();
	std::cout << "Carro chegou no semaforo da pista: " << pista->getNome()
			<< " no tempo: " << ev->getTimeStamp() << std::endl;
	if (pista->getSemaforo()
			&& carro->getDestino()->getEspacoRestante() > carro->getTamanho()) {
		std::cout << "Gerou o evento troca pista" << std::endl;
		geraEventoTrocaPista(carro, pista, ev->getTimeStamp());
	}
}

void Sistema::geraNovosCarros(int tempo) {
	int timestamp = 0;
	Pista* O1Leste = this->gerador->getPistaO1Leste();
	Pista* S1Norte = this->gerador->getPistaS1Norte();
	Pista* C1Oeste = this->gerador->getPistaC1Oeste();
	Pista* N1Sul = this->gerador->getPistaN1Sul();
	Pista* C1Leste = this->gerador->getPistaC1Leste();
	Pista* S2Norte = this->gerador->getPistaS2Norte();
	Pista* L1Oeste = this->gerador->getPistaL1Oeste();
	Pista* N2Sul = this->gerador->getPistaN2Sul();
	GeradorAleatorios* geradorAleatorio = new GeradorAleatorios();
	srand(time(NULL));
	// Entre 8 e 12 := 8+(rand()%5)
	// Entre 15 e 25 := 15+(rand()%11)
	// Entre 23 e 37 := 23+(rand()%15)
	// Entre 45 e 75 := 45+(rand()%31)

	while (timestamp < tempo) {
		timestamp = timestamp + (8 + (rand() % 5));
		int proporcao = O1Leste->getPistaConectadaProporcao();
		Lista<Pista*>* pistas = O1Leste->getPistasConectadas();
		Pista* pista = pistas->getPosicao(proporcao);
		geraEventoNovoCarro(geradorAleatorio->gerarTamanhoCarro(), O1Leste,
				pista, timestamp);

	}

	timestamp = 0;
	while (timestamp < tempo) {
		timestamp = timestamp + (23 + (rand() % 15));
		int proporcao = S1Norte->getPistaConectadaProporcao();
		Lista<Pista*>* pistas = S1Norte->getPistasConectadas();
		Pista* pista = pistas->getPosicao(proporcao);
		geraEventoNovoCarro(geradorAleatorio->gerarTamanhoCarro(), S1Norte,
				pista, timestamp);
	}

	timestamp = 0;
	while (timestamp < tempo) {
		timestamp = timestamp + (45 + (rand() % 31));
		int proporcao = S2Norte->getPistaConectadaProporcao();
		Lista<Pista*>* pistas = S2Norte->getPistasConectadas();
		Pista* pista = pistas->getPosicao(proporcao);
		geraEventoNovoCarro(geradorAleatorio->gerarTamanhoCarro(), S2Norte,
				pista, timestamp);
	}

	timestamp = 0;
	while (timestamp < tempo) {
		timestamp = timestamp + (8 + (rand() % 5));
		int proporcao = L1Oeste->getPistaConectadaProporcao();
		Lista<Pista*>* pistas = L1Oeste->getPistasConectadas();
		Pista* pista = pistas->getPosicao(proporcao);
		geraEventoNovoCarro(geradorAleatorio->gerarTamanhoCarro(), L1Oeste,
				pista, timestamp);
	}

	timestamp = 0;
	while (timestamp < tempo) {
		timestamp = timestamp + (15 + (rand() % 11));
		int proporcao = N2Sul->getPistaConectadaProporcao();
		Lista<Pista*>* pistas = N2Sul->getPistasConectadas();
		Pista* pista = pistas->getPosicao(proporcao);
		geraEventoNovoCarro(geradorAleatorio->gerarTamanhoCarro(), N2Sul, pista,
				timestamp);
	}

	timestamp = 0;
	while (timestamp < tempo) {
		timestamp = timestamp + (15 + (rand() % 11));
		int proporcao = N1Sul->getPistaConectadaProporcao();
		Lista<Pista*>* pistas = N1Sul->getPistasConectadas();
		Pista* pista = pistas->getPosicao(proporcao);
		geraEventoNovoCarro(geradorAleatorio->gerarTamanhoCarro(), N1Sul, pista,
				timestamp);
	}
}

void Sistema::geraSemaforos(int tempo) {
	int valorCiclos = (int) (tempo / 117);
	int a = 1;
	Pista* O1Leste = this->gerador->getPistaO1Leste();
	Pista* S1Norte = this->gerador->getPistaS1Norte();
	Pista* C1Oeste = this->gerador->getPistaC1Oeste();
	Pista* N1Sul = this->gerador->getPistaN1Sul();
	Pista* C1Leste = this->gerador->getPistaC1Leste();
	Pista* S2Norte = this->gerador->getPistaS2Norte();
	Pista* L1Oeste = this->gerador->getPistaL1Oeste();
	Pista* N2Sul = this->gerador->getPistaN2Sul();
	for (int i = 0; i <= valorCiclos; i++) {
		geraEventoTrocaSemaforo(O1Leste, a);
		geraEventoTrocaSemaforo(C1Leste, a);
		a += 90;
		geraEventoTrocaSemaforo(O1Leste, a);
		geraEventoTrocaSemaforo(C1Leste, a);

		geraEventoTrocaSemaforo(S1Norte, a);
		geraEventoTrocaSemaforo(S2Norte, a);
		a += 25;
		geraEventoTrocaSemaforo(S1Norte, a);
		geraEventoTrocaSemaforo(S2Norte, a);

		geraEventoTrocaSemaforo(C1Oeste, a);
		geraEventoTrocaSemaforo(L1Oeste, a);
		a += 90;
		geraEventoTrocaSemaforo(C1Oeste, a);
		geraEventoTrocaSemaforo(L1Oeste, a);

		geraEventoTrocaSemaforo(N1Sul, a);
		geraEventoTrocaSemaforo(N2Sul, a);
		a += 45;
		geraEventoTrocaSemaforo(N1Sul, a);
		geraEventoTrocaSemaforo(N2Sul, a);
	}

}

void Sistema::geraEventoTrocaSemaforo(Pista* pista, int timestamp) {
	Evento* evento = new Evento(timestamp, 4, 0, pista, NULL, NULL);
	incluiEventoClock(evento);
}

void Sistema::geraEventoNovoCarro(int tamanhoCarro, Pista* pistaOrigem,
		Pista* pistaDestino, int timestamp) {
	Evento* evento = new Evento(timestamp, 1, tamanhoCarro, pistaOrigem,
			pistaDestino, NULL);
	incluiEventoClock(evento);
}

void Sistema::incluiEventoClock(Evento* evento) {
	this->clock->adicionaEvento(evento);
}

Evento* Sistema::retiraEventoClock() {
	return this->clock->retiraEvento();
}

Clock* Sistema::getClock() {
	return this->clock;
}

GeradorPistas* Sistema::getGerador() {
	return this->gerador;
}
#endif
