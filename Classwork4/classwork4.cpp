#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
const int MAX_INT = 2147483647;

class GestorMemoria{
private:
        int tamanoMemoria;
        std::vector<int> memoria;

public:
        GestorMemoria (int tamano): tamanoMemoria(tamano), memoria(tamano,-1) {
                //inicializar la memoria con valores negativos (-1) para indicar que esta vacia.
        }
        //implementacion del algoritmo First-fit para asignar memoria.
        bool asignarMemoriaFirstFit(int procesoID, int tamano){
        	 for (int i = 0; i < tamanoMemoria; ++i) {
                if (memoria[i] == -1 && i + tamano <= tamanoMemoria) {
                    // Espacio suficiente encontrado, asignar memoria al proceso.
                    for (int j = i; j < i + tamano; ++j) {
                        memoria[j] = procesoID;
                    }
                    return true;
                }
            }
            // No se encontró espacio adecuado para el proceso.
            return false;
        
        }

        bool asignarMemoriaBestFit(int procesoID, int tamano){
            int mejorEspacio = MAX_INT;
            int mejorIndice = -1;

            for (int i = 0; i < tamanoMemoria; ++i) {
                int espacioLibre = 0;
                while (i < tamanoMemoria && memoria[i] == -1) {
                    ++espacioLibre;
                    ++i;
                }

                if (espacioLibre >= tamano && espacioLibre < mejorEspacio) {
                    mejorEspacio = espacioLibre;
                    mejorIndice = i - espacioLibre;
                }
            }

            if (mejorIndice != -1) {
                // Espacio adecuado encontrado, asignar memoria al proceso.
                for (int i = mejorIndice; i < mejorIndice + tamano; ++i) {
                    memoria[i] = procesoID;
                }
                return true;
            }
            // No se encontró espacio adecuado para el proceso.
            return false;
        }

        bool asignarMemoriaWorstFit(int procesoID, int tamano){
            int peorEspacio = -1;
            int peorIndice = -1;

            for (int i = 0; i < tamanoMemoria; ++i) {
                int espacioLibre = 0;
                while (i < tamanoMemoria && memoria[i] == -1) {
                    ++espacioLibre;
                    ++i;
                }

                if (espacioLibre >= tamano && espacioLibre > peorEspacio) {
                    peorEspacio = espacioLibre;
                    peorIndice = i - espacioLibre;
                }
            }

            if (peorIndice != -1) {
                // Espacio adecuado encontrado, asignar memoria al proceso.
                for (int i = peorIndice; i < peorIndice + tamano; ++i) {
                    memoria[i] = procesoID;
                }
                return true;
            }
            // No se encontró espacio adecuado para el proceso.
            return false;
        }

        void liberarMemoria(int procesoID){
                for (int i=0; i < tamanoMemoria; i++){
                        if(memoria[i] == procesoID){
                                memoria[i] = -1;
                        }
                }
        }

        void imprimirEstadoMemoria(){
        	std::cout << "Estado de la memoria: ";
        	for (int i = 0; i< tamanoMemoria; i++){
        		std::cout<<memoria[i]<< " ";
        	}
        	std::cout << std::endl;
        }
}; 

int main() {
    int tamanoMemoria = 100;
    GestorMemoria gestor (tamanoMemoria);
    if (gestor.asignarMemoriaFirstFit(1,20)){
    	std::cout << "asignado proceso 1 de tamaño 20" << std::endl;
    } else{
    	std::cout << "No se pudo asignar memoria para proceso 1" << std::endl;
    }

    gestor.imprimirEstadoMemoria();

    gestor.liberarMemoria(1);
    std::cout<<"proceso 1 liberado" << std::endl;

    gestor.imprimirEstadoMemoria();
    return 0;
}
