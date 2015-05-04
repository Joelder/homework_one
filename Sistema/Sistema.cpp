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
	Evento* evento = new Evento(8, 1, geradorAleatorio->gerarTamanhoCarro(), origem, destino, NULL);
	incluiEventoClock(evento);
}

void Sistema::consomeEvento(Evento* ev) {
	switch(ev->getId()) {
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
	}
}

void Sistema::consomeEventoNovoCarro(Evento* novoCarro) {
	Carro* carro = criaCarro(novoCarro->getTamanhoCarrro());
	carro->setDestino(novoCarro->getPistaDestino());
	novoCarro->getPistaOrigem()->adicionarCarroPista(carro);
}

void Sistema::consomeEventoTrocaPista() {

}

void Sistema::consomeEventoMudancaSemaforo(Evento* ev){

}

void Sistema::consomeEventoChegadaCarro(Evento* ev){
	Pista* pista = ev->getPistaDestino();
	pista->retirarCarroPista();
}

void Sistema::consomeChegadaSemaforo(Evento* ev){

}

void Sistema::geraEventoNovoCarro() {

}

void Sistema::geraEventoChegadaSemaforo(){

}

void Sistema::geraEventoChegadaCarro(){

}

void Sistema::geraEventoTrocaPista() {

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
