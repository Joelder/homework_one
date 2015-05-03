/*
 * Sistema.h
 *
 *  Created on: May 1, 2015
 *      Author: home
 */

#ifndef SISTEMA_SISTEMA_H_
#define SISTEMA_SISTEMA_H_

class Sistema {
public:
	Sistema();

	virtual ~Sistema();

	void criaPistas();

	void criaCarro();

	void relacionaPistas();

	void geraEventosIniciais();

	void consomeNovoCarro();

	void consomeTrocaPista();

	void consomeMudancaSemaforo();

	void consomeChegadaCarro();

	void consomeChegadaSemaforo();

	void geraEventoNovoCarro();

	void geraEventoChegadaSemaforo();

	void geraEventoChegadaCarro();

	void geraEventoTrocaPista();

	void incluiEventoClock();

};

#endif /* SISTEMA_SISTEMA_H_ */
