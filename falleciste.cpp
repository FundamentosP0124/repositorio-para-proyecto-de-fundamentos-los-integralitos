#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main() {
    string mensaje = "\033[31mFalleciste\033[0m\n";
    int retardo = 100; // Retardo en milisegundos entre cada carácter

    for (char c : mensaje) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(retardo));
    }

    return 0;
}
