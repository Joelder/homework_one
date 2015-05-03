#ifndef MAIN_CPP
#define MAIN_CPP
#include <iostream>
#include <stdlib.h>
//#include "../Pista/Sumidouro.cpp"
#include "../util/GeradorAleatorios.cpp"

int main(int argc, char** argv) {
	GeradorAleatorios* gerador = new GeradorAleatorios();
	srand(time(NULL));
	for (int i = 0; i < 100; i++) {
		std::cout << "tamanho: " << gerador->gerarTamanhoCarro() << std::endl;
	}
	/* testes validados
	 Sumidouro* pista = new Sumidouro(1000, 100, false);
	 Pista* pista2 = new Pista(1000, 100, false);
	 Pista* pista3 = new Pista(1000, 100, false);
	 Pista* pista4 = new Pista(1000, 100, false);
	 pista->conectarPistas(pista2, pista3, pista4);

	 Carro* car = new Carro(50);
	 Carro* car1 = new Carro(50);
	 Carro* car2 = new Carro(50);
	 Carro* car3 = new Carro(50);
	 Carro* car4 = new Carro(50);

	 car->setDestino(pista2);
	 car1->setDestino(pista3);
	 car2->setDestino(pista4);
	 car3->setDestino(pista2);
	 car4->setDestino(pista3);

	 pista->adicionarCarroPista(car);
	 pista->adicionarCarroPista(car1);
	 pista->adicionarCarroPista(car2);
	 pista->adicionarCarroPista(car3);
	 pista->adicionarCarroPista(car4);

	 int tamanho = pista->getEspacoRestante();
	 int tamanho2 = pista2->getEspacoRestante();
	 int tamanho3 = pista3->getEspacoRestante();
	 int tamanho4 = pista4->getEspacoRestante();

	 //pista->setSemaforo();
	 pista->transferirCarro(car->getDestino());
	 int tamanhoNovo = pista->getEspacoRestante();
	 int tamanhoNovo2 = pista2->getEspacoRestante();
	 int tamanhoNovo3 = pista3->getEspacoRestante();
	 int tamanhoNovo4 = pista4->getEspacoRestante();
	 bool semaforo2 = pista->getSemaforo();

	 std::cout << "tamanho restante pista 1: " << tamanho << std::endl;
	 std::cout << "tamanho restante pista 2: " << tamanho2 << std::endl;
	 std::cout << "tamanho restante pista 3: " << tamanho3 << std::endl;
	 std::cout << "tamanho restante pista 4: " << tamanho4 << std::endl;
	 std::cout << "tamanho pista 1 apos transferencia: " << tamanhoNovo
	 << std::endl;
	 std::cout << "tamanho pista 2 apos transferencia: " << tamanhoNovo2
	 << std::endl;
	 std::cout << "tamanho pista 3 apos transferencia: " << tamanhoNovo3
	 << std::endl;
	 std::cout << "tamanho pista 4 apos transferencia: " << tamanhoNovo4
	 << std::endl;
	 std::cout << "semaforo apos troca: " << semaforo2 << std::endl;
	 */
	/* Testes validados
	 Pista* pista = new Pista(1000, 100);
	 Pista* pista2 = new Pista(1000, 100);
	 Pista* pista3 = new Pista(1000, 100);
	 Pista* pista4 = new Pista(1000, 100);
	 pista->conectarPistas(pista2, pista3, pista4);

	 Carro* car = new Carro(50);
	 Carro* car1 = new Carro(50);
	 Carro* car2 = new Carro(50);
	 Carro* car3 = new Carro(50);
	 Carro* car4 = new Carro(50);

	 car->setDestino(pista2);
	 car1->setDestino(pista3);
	 car2->setDestino(pista4);
	 car3->setDestino(pista2);
	 car4->setDestino(pista3);

	 pista->adicionarCarroPista(car);
	 pista->adicionarCarroPista(car1);
	 pista->adicionarCarroPista(car2);
	 pista->adicionarCarroPista(car3);
	 pista->adicionarCarroPista(car4);

	 int tamanho = pista->getEspacoRestante();
	 int tamanho2 = pista2->getEspacoRestante();
	 int tamanho3 = pista3->getEspacoRestante();
	 int tamanho4 = pista4->getEspacoRestante();

	 pista->setSemaforo();
	 pista->transferirCarro(car->getDestino());
	 int tamanhoNovo = pista->getEspacoRestante();
	 int tamanhoNovo2 = pista2->getEspacoRestante();
	 int tamanhoNovo3 = pista3->getEspacoRestante();
	 int tamanhoNovo4 = pista4->getEspacoRestante();
	 bool semaforo2 = pista->getSemaforo();

	 std::cout << "tamanho restante pista 1: " << tamanho << std::endl;
	 std::cout << "tamanho restante pista 2: " << tamanho2 << std::endl;
	 std::cout << "tamanho restante pista 3: " << tamanho3 << std::endl;
	 std::cout << "tamanho restante pista 4: " << tamanho4 << std::endl;
	 std::cout << "tamanho pista 1 apos transferencia: " << tamanhoNovo
	 << std::endl;
	 std::cout << "tamanho pista 2 apos transferencia: " << tamanhoNovo2
	 << std::endl;
	 std::cout << "tamanho pista 3 apos transferencia: " << tamanhoNovo3
	 << std::endl;
	 std::cout << "tamanho pista 4 apos transferencia: " << tamanhoNovo4
	 << std::endl;
	 std::cout << "semaforo apos troca: " << semaforo2 << std::endl;
	 */

	/* Testes validados
	 int tamanho = pista->getEspacoRestante();
	 int tamanho2 = pista2->getEspacoRestante();
	 pista->setSemaforo();
	 pista->transferirCarro(pista2);
	 int tamanhoNovo = pista->getEspacoRestante();
	 int tamanhoNovo2 = pista2->getEspacoRestante();
	 bool semaforo2 = pista->getSemaforo();


	 std::cout << "tamanho restante pista 1: " << tamanho << std::endl;
	 std::cout << "tamanho restante pista 2: " << tamanho2 << std::endl;
	 std::cout << "tamanho pista 1 apos transferencia: " << tamanhoNovo << std::endl;
	 std::cout << "tamanho pista 2 apos transferencia: " << tamanhoNovo2 << std::endl;
	 std::cout << "semaforo apos troca: " << semaforo2 << std::endl;
	 */
	return 0;
}
#endif /* MAIN_CPP */

