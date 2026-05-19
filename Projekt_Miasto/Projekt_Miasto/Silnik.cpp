#include "Silnik.h"
#include <iostream>

Silnik::Silnik() : aktualnaTura(0), czyDziałaSymulacja(false) {
    miasto.getMenedzerZasobow().dodajZasob(TypZasobu::FOOD, 20);
    miasto.getMenedzerZasobow().dodajZasob(TypZasobu::GOLD, 15);
    miasto.getMenedzerZasobow().dodajZasob(TypZasobu::WOOD, 10);
    miasto.getMenedzerZasobow().dodajZasob(TypZasobu::STONE, 5);
}

void Silnik::uruchom() {
    czyDziałaSymulacja = true;
    std::cout << "--- WITAJ W SYMULACJI SREDNIOWIECZNEGO MIASTA ---" << std::endl;
    
    while (czyDziałaSymulacja) {
        pokazMenu();
    }
}

void Silnik::pokazMenu() {
    std::cout << "\n[1] Nastepna tura | [2] Zakoncz symulacje\nWybor: ";
    int wybor;
    std::cin >> wybor;

    if (wybor == 1) {
        wykonajTure();
    } else if (wybor == 2) {
        czyDziałaSymulacja = false;
        std::cout << "Symulacja zakonczona przez uzytkownika." << std::endl;
    } else {
        std::cout << "Niepoprawny wybor!" << std::endl;
    }
}

void Silnik::wykonajTure() {
    aktualnaTura++;
    std::cout << "\n--- ROZPOCZECIE TURY " << aktualnaTura << " ---" << std::endl;

    miasto.getMenedzerZasobow().zuzyjZasob(TypZasobu::FOOD, 10);
    miasto.getMenedzerZasobow().zuzyjZasob(TypZasobu::GOLD, 5);

    if (miasto.sprawdzWarunkiUpadku()) {
        wyswietlRaport();
        std::cout << "\n=========================================" << std::endl;
        std::cout << "             MIASTO UPADLO!              " << std::endl;
        std::cout << "=========================================" << std::endl;
        czyDziałaSymulacja = false;
        return;
    }

    wyswietlRaport();
}

void Silnik::wyswietlRaport() const {
    MenedzerZasobow mz = const_cast<Miasto&>(miasto).getMenedzerZasobow();

    std::cout << "=========================================" << std::endl;
    std::cout << " RAPORT Z TURY: " << aktualnaTura << std::endl;
    std::cout << " FOOD: " << mz.pobierzIloscZasobu(TypZasobu::FOOD)
              << " | GOLD: " << mz.pobierzIloscZasobu(TypZasobu::GOLD)
              << " | WOOD: " << mz.pobierzIloscZasobu(TypZasobu::WOOD)
              << " | STONE: " << mz.pobierzIloscZasobu(TypZasobu::STONE) << std::endl;
    std::cout << " SECURITY: " << miasto.getBezpieczenstwo() << std::endl;
    std::cout << "=========================================" << std::endl;
}
