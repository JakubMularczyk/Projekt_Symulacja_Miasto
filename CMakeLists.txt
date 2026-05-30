cmake_minimum_required(VERSION 3.12)
project(SymulacjaMiasto CXX)

# Ustawienie standardu C++ (np. C++17 lub C++20)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Definiowanie pliku wykonywalnego i wskazanie wszystkich plików źródłowych (.cpp)
add_executable(SymulacjaMiasto
    src/main.cpp
    src/Kupiec.cpp
    src/MenedzerZasobow.cpp
    src/Miasto.cpp
    src/Mieszkaniec.cpp
    src/Rolnik.cpp
    src/Silnik.cpp
    src/Straznik.cpp
    src/Zasoby.cpp
    
)

# Wskazanie, gdzie kompilator ma szukać plików nagłówkowych (.h)
target_include_directories(SymulacjaMiasto PRIVATE src)