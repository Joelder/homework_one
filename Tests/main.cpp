#ifndef MAIN_CPP
#define MAIN_CPP
#include <iostream>
#include <stdlib.h>
#include "../Pista/Pista.cpp"


int main(int argc, char** argv) {


       Carro* car = new Carro(50);
       Carro* car1 = new Carro(50);
       Carro* car2 = new Carro(50);
       Carro* car3 = new Carro(50);
       Carro* car4 = new Carro(50);
       Pista* pista = new Pista(1000,1000);


       pista->adicionarCarroPista(car);
       pista->adicionarCarroPista(car1);
       pista->adicionarCarroPista(car2);
       pista->adicionarCarroPista(car3);
       pista->adicionarCarroPista(car4);
       int tamanho = pista->getEspacoRestante();

   std::cout << tamanho;
   std::cout << std::endl;
   return 0;
}
#endif /* MAIN_CPP */

