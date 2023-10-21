#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Segmento {
    int base;
    int limite;
};

struct Proceso {
    int id;
    std::vector<Segmento> segmentos;
};

class SimuladorSegmentacion {
private:
    int tamanoMemoria;
    std::vector<Segmento> memoriaSegmentada;
    std::vector<Proceso> procesos;

public:
    SimuladorSegmentacion(int tamano) : tamanoMemoria(tamano) {
        Segmento segmento;
        segmento.base = 0;
        segmento.limite = tamano;
        memoriaSegmentada.push_back(segmento);
    }

    bool asignarMemoria(int procesoID, int tamano) {
        for (auto& segmento : memoriaSegmentada) {
            if (segmento.limite - segmento.base >= tamano) {
                Segmento nuevoSegmento;
                nuevoSegmento.base = segmento.base;
                nuevoSegmento.limite = nuevoSegmento.base + tamano;
                segmento.base = nuevoSegmento.limite;

                Proceso proceso;
                proceso.id = procesoID;
                proceso.segmentos.push_back(nuevoSegmento);
                procesos.push_back(proceso);

                return true;
            }
        }
        return false; // No se pudo asignar memoria al proceso
    }

    void liberarMemoria(int procesoID) {
        auto it = std::remove_if(procesos.begin(), procesos.end(),
            [procesoID](const Proceso& p) { return p.id == procesoID; });

        if (it != procesos.end()) {
            procesos.erase(it, procesos.end());
        }
    }

    void imprimirEstadoMemoria() {
        std::cout << "Estado de la memoria segmentada:" << std::endl;
        for (const auto& segmento : memoriaSegmentada) {
            std::cout << "Base: " << segmento.base << ", Limite: " << segmento.limite << std::endl;
        }

        std::cout << "Procesos en memoria:" << std::endl;
        for (const auto& proceso : procesos) {
            std::cout << "Proceso ID: " << proceso.id << ", Segmentos: ";
            for (const auto& segmento : proceso.segmentos) {
                std::cout << "[Base: " << segmento.base << ", Limite: " << segmento.limite << "] ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    SimuladorSegmentacion simulador(100); // Crear un simulador con memoria de tamaño 100
    simulador.asignarMemoria(1, 20);
    simulador.asignarMemoria(2, 15);
    simulador.imprimirEstadoMemoria();

    simulador.liberarMemoria(1);
    simulador.imprimirEstadoMemoria();

    return 0;
}
