#include <iostream>
#include <unistd.h> // Para usleep en sistemas Unix-like (Linux, macOS)

using namespace std;

void mostrarBarraDeCarga(int progreso, int total) {
    float percent = (float)progreso / total;
    int barWidth = 70;

    cout << "[";
    int pos = barWidth * percent;
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos) cout << "=";
        else if (i == pos) cout << ">";
        else cout << " ";
    }
    cout << "] " << int(percent * 100.0) << " %\r";
    cout.flush();
}

int main() {
    int total = 100;
    
    for (int i = 0; i <= total; ++i) {
        mostrarBarraDeCarga(i, total);
        // Simulación de trabajo
        usleep(100000); // Espera 100000 microsegundos (0.1 segundos)
    }
    cout << endl;

    return 0;
}
