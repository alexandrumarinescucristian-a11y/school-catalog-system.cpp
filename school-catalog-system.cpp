#include <iostream>
#include <string>
#include <limits>

int main() {
    std::string numeMaterie;
    int nota;
    int numarMaterii = 0;
    double sumaNote = 0;
    int corijent = 0;

    std::cout << "SISTEM GESTIONARE NOTE - CATALOG\n";
    std::cout << "--------------------------------\n";
    std::cout << "Instructiune: Introduceti numele materiei sau tastati 'stop' pentru finalizare.\n\n";

    while (true) {
        std::cout << "Materie: ";
        std::getline(std::cin, numeMaterie);

        if (numeMaterie == "stop" || numeMaterie == "Stop" || numeMaterie == "STOP") {
            break;
        }

        std::cout << "Nota acordata: ";
        if (!(std::cin >> nota)) {
            std::cout << "[EROARE] Ai introdus un caracter invalid, nu un numar!\n\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue; 
        }

        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (nota >= 5 && nota <= 10) {
            sumaNote += nota;
            numarMaterii++;
        }
        else if (nota < 5 && nota >= 1) {
            corijent++;
            sumaNote += nota;
            numarMaterii++;
        }
        else {
            std::cout << "[EROARE] Nota invalida (trebuie sa fie între 1 si 10). Reintroduceti.\n\n";
        }
    }

    std::cout << "\n================================\n";
    std::cout << "        SITUATIE FINALA         \n";
    std::cout << "================================\n";

    if (numarMaterii > 0) {
        double medie = sumaNote / numarMaterii;
        std::cout << "Total materii evaluate: " << numarMaterii << "\n";
        std::cout << "Numar corigente:        " << corijent << "\n";
        std::cout << "Media generala:         " << medie << "\n";

        if (corijent > 3) {
            std::cout << "Stare: RISC DE REPETARE A ANULUI (> 3 corigente).\n";
        }
        else if (corijent > 0) {
            std::cout << "Stare: CONDITIONAL (Sesiune de corigente).\n";
        }
        else {
            std::cout << "Stare: PROMOVAT INTEGRAL.\n";
        }
    }
    else {
        std::cout << "Nu au fost înregistrate date.\n";
    }

    std::cout << "================================\n";
    return 0;
}
