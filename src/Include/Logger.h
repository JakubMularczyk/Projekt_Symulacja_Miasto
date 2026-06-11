#pragma once
#define LOGGER_H

#include <fstream>
#include <string>

// zapisujemy logi
inline void logMessage(const std::string& message) {
    std::ofstream file("simulation_logs.txt", std::ios::app);
    if (file.is_open()) {
        file << message << std::endl;
    }
}

// czyscimy, zeby plik na poczatku byl pusty
inline void clearLogFile() {
    std::ofstream file("simulation_logs.txt", std::ios::trunc);
    if (file.is_open()) {
        file << "=========================================" << std::endl;
        file << "       ROZPOCZĘTO NOWĄ SYMULACJĘ        " << std::endl;
        file << "=========================================\n" << std::endl;
    }
}


