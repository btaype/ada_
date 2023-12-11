#include <iostream>
#include <vector>
#include <algorithm>

struct Tarea {
    int indice;
    int beneficio;
    int plazo;
};

bool compararTareas(const Tarea& a, const Tarea& b) {
    return a.beneficio > b.beneficio;
}

std::vector<int> seleccionarTareas(std::vector<Tarea>& tareas) {
 
    std::sort(tareas.begin(), tareas.end(), compararTareas);

   
    std::vector<int> tiempos(tareas.size(), -1);
    std::vector<int> seleccionadas(tareas.size(), 0);

    for (int i = 0; i < tareas.size(); ++i) {
    
        for (int j = std::min(tareas.size(), (size_t)tareas[i].plazo) - 1; j >= 0; --j) {
            if (tiempos[j] == -1) {
                tiempos[j] = i;
                seleccionadas[i] = 1;
                break;
            }
        }
    }

    return seleccionadas;
}

int main() {
    
    std::vector<Tarea> tareas = { {1,50, 2}, {2,10, 1}, {3,15, 2}, {4,30, 1} };

 
    std::vector<int> tareasSeleccionadas = seleccionarTareas(tareas);

   
    int beneficioTotal = 0;
    
    for (int i = 0; i < tareas.size(); ++i) {
        if (tareasSeleccionadas[i]) {
            std::cout << "indice: " << tareas[i] .indice <<"  tiempo: "<< tareas[i].plazo<< "   beneficio: " << tareas[i].beneficio<< "\n";
            beneficioTotal += tareas[i].beneficio;
        }
    }
    std::cout << "\ntotla del beneficio: " << beneficioTotal << std::endl;

    return 0;
}

