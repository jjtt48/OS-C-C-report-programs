#include<iostream>

int main(){
	int numero = 45;
	int* punteroNumero = &numero;

	std::cout << "Valor de 'numero' a travez del puntero : " << *punteroNumero << std::endl;

	*punteroNumero = 100;

	std::cout << "Nuevo valor de 'numero' : " << numero << std::endl;

	int& referenciaNumero = numero;
    referenciaNumero = 200;

    std::cout << "Nuevo valor de 'numero' a travez de la referencia : " << numero << std::endl;
	return 0;
}