cmake_minimum_required(VERSION 3.12)
project(SymulacjaMiasto CXX)

# Ustawienie standardu C++ (np. C++17 lub C++20)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Definiowanie pliku wykonywalnego i wskazanie wszystkich plików źródłowych (.cpp)

add_executable(SymulacjaMiasto
    src/main.cpp
    src/Engine.h
    src/Engine.cpp
    src/City.h
    src/City.cpp
    src/Citizen.h
    src/Citizen.cpp
    src/Farmer.h
    src/Farmer.cpp
    src/Merchant.h
    src/Merchant.cpp
    src/Guard.h
    src/Guard.cpp
    src/ResourceManager.h
    src/ResourceManager.cpp
    src/Resources.h
)
    


# Wskazanie, gdzie kompilator ma szukać plików nagłówkowych (.h)
target_include_directories(SymulacjaMiasto PRIVATE src)