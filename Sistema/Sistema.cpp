/*
 * Sistema.cpp
 *
 *  Created on: May 1, 2015
 *      Author: home
 */

#ifndef SISTEMA_CPP
#define SISTEMA_CPP
#include "Sistema.h"

#include <cstdlib>
#include <ctime>

Sistema::Sistema() {
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
	GeradorAleatorios* geradorAleatorio = new GeradorAleatorios();
	srand(time(NULL));
	Pista* origem = this->gerador->getPistaO1Leste();
	int proporcao = origem->getPistaConectadaProporcao();
	Pista* destino = origem->getPistasConectadas()->getPosicao(proporcao);
	Evento* evento = new Evento(8, 1, geradorAleatorio->gerarTamanhoCarro(),
			origem, destino, NULL);
	incluiEventoClock(evento);
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
	if (pistaOrigem->size == 1) {
		geraEventoChegadaSemaforo(carro, pistaOrigem, timeEvento);
	} else {
		geraEventoChegadaFila(carro, pistaOrigem, timeEvento);
	}

}


void Sistema::geraEventoChegadaFila(Carro* carro, Pista* pistaOrigem, int time) {
	int velocidade = (int) (pistaOrigem->getVelocidade() / 3.6);
	int tempo = (int) (pistaOrigem->getEspacoRestante() / velocidade);
	int tamanhofila =  pistaOrigem->getTamanho() - pistaOrigem->getEspacoRestante();
	int timestamp = tempo + time;
	Evento* evento = new Evento(timestamp, 5, tamanhofila, pistaOrigem, NULL, carro);
	this->clock->adicionaEvento(evento);

}

void Sistema::consomeChegadaFinalFila(Evento* ev) {
	Pista* pistaOrigem = ev->getPistaOrigem();
	Carro* carro = ev->getCarro();
	int velocidade = (int) (pistaOrigem->getVelocidade() / 3.6);
	// POG By Thomas Feijoo
	int time = (int)(ev->getTamanhoCarrro()/velocidade);
	int timestamp =  time + ev->getTimeStamp();
	if (pistaOrigem->size == 1) {
		geraEventoChegadaSemaforo(carro, pistaOrigem, timestamp);
	} else {
		carro->setCarroChegou();
	}
}

void Sistema::geraEventoTrocaPista(Carro* carro, Pista* pistaOrigem, int timestamp) {
	EventoTrocaPista* evento = new EventoTrocaPista(carro);
	consomeEventoTrocaPista(evento, pistaOrigem, timestamp);
}

void Sistema::consomeEventoTrocaPista(EventoTrocaPista* evento, Pista* pistaOrigem, int time) {
	Pista* pistaDestino = evento->getCarro()->getDestino();
	pistaOrigem->transferirCarro(pistaDestino);
	geraEventoDeslocamentoChegadaSemaforo(pistaOrigem->primeiro(), pistaOrigem, time);
	geraEventoChegadaCarro(pistaDestino, time);
}


void Sistema::geraEventoChegadaCarro(Pista* pista, int timestamp) {
	int velocidade = (int) (pista->getVelocidade() / 3.6);
	int tempo = (int) (pista->getTamanho() / velocidade);
	int time = timestamp + tempo;
	Evento* evento = new Evento(time, 2, 0, NULL, pista, NULL);
}


void Sistema::geraEventoDeslocamentoChegadaSemaforo(Carro* carro, Pista* pistaOrigem, int time) {
		Evento* evento = new Evento(time+2, 3, 0, pistaOrigem, NULL, carro);
		this->clock->adicionaEvento(evento);
}

void Sistema::geraEventoChegadaSemaforo(Carro* carro, Pista* pistaOrigem, int time) {
		int velocidade = (int) (pistaOrigem->getVelocidade() / 3.6);
		int tempo = (int) (pistaOrigem->getTamanho() / velocidade);
		int timestamp = tempo + time;
		Evento* evento = new Evento(timestamp, 3, 0, pistaOrigem, NULL, carro);
		this->clock->adicionaEvento(evento);
}


void Sistema::consomeEventoMudancaSemaforo(Evento* ev) {
	Pista* pista = ev->getPistaOrigem();
	pista->setSemaforo();
	if (pista->primeiro()->getCarroChegou()) {
		geraEventoTrocaPista(pista->primeiro(), pista, ev->getTimeStamp());
	}
}

void Sistema::consomeEventoChegadaCarro(Evento* ev) {
	Pista* pista = ev->getPistaDestino();
	pista->retirarCarroPista();
}

void Sistema::consomeChegadaSemaforo(Evento* ev) {
	Pista* pista = ev->getPistaOrigem();
	Carro* carro = ev->getCarro();
	carro->setCarroChegou();
	if (pista->getSemaforo()
			&& carro->getDestino()->getEspacoRestante() > carro->getTamanho()) {
		geraEventoTrocaPista(carro, pista, ev->getTimeStamp());
	}
}



void Sistema::geraEventoNovoCarro() {

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
