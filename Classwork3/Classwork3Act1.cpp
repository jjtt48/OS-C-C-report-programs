#include<iostream>

int main(){
	int numero = 45;

	std::cout << "Valor de la variable 'numero' : " << numero << std::endl;

	std::cout << "Direccion de memoria de 'numero' : " << &numero << std::endl;

	int* punteroNumero = &numero;
    *punteroNumero = 100;

    std::cout << "Nuevo valor de la variable 'numero' : " << numero << std::endl;
	return 0;
}
