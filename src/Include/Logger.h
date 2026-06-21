#pragma once
#define LOGGER_H

#include <fstream>
#include <string>
#include <iostream> 

inline void logMessage(const std::string& message) {
    std::ofstream file("simulation_logs.txt", std::ios::app);
    if (file.is_open()) {
        file << message << std::endl;
    } else {
        std::cout << ">>> BLAD LOGGERA: Nie mozna otworzyc pliku do zapisu! <<<" << std::endl;
    }
}

// czyscimy, zeby plik na poczatku byl pusty
inline void clearLogFile() {
    std::ofstream file("simulation_logs.txt", std::ios::trunc);
    if (file.is_open()) {
        file << "=========================================" << std::endl;
        file << "       ROZPOCZETO NOWA SYMULACJE         " << std::endl;
        file << "=========================================\n" << std::endl;
    } else {
        std::cout << ">>> BLAD LOGGERA: Nie mozna wyczyscic/utworzyc pliku! <<<" << std::endl;
    }
}
