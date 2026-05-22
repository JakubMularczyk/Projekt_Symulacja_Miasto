#include "Silnik.h"
#include <iostream>
#include "Miasto.h"
// walczyłem godzine zeby zznalezc ze czydzialasymulacja miała polski znak...
Silnik::Silnik() : aktualnaTura(0), czyDzialaSymulacja(false) {
    miasto.getMenedzerZasobow().dodajZasob(TypZasobu::FOOD, 20);
    miasto.getMenedzerZasobow().dodajZasob(TypZasobu::GOLD, 15);
    miasto.getMenedzerZasobow().dodajZasob(TypZasobu::WOOD, 10);
    miasto.getMenedzerZasobow().dodajZasob(TypZasobu::STONE, 5);
}
void Silnik::nazwaMiasta() {

}


void Silnik::uruchom() {
    czyDzialaSymulacja = true;
    std::cout << "--- WITAJ W SYMULACJI SREDNIOWIECZNEGO MIASTA ---" << std::endl;
    
    while (czyDzialaSymulacja) {
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
        czyDzialaSymulacja = false;
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
        czyDzialaSymulacja = false;
        return;
    }

    wyswietlRaport();
}

void Silnik::wyswietlRaport() const {
    const MenedzerZasobow& mz = miasto.getMenedzerZasobow();

    std::cout << "=========================================" << std::endl;
    std::cout << " RAPORT Z TURY: " << aktualnaTura << std::endl;
    std::cout << " FOOD: " << mz.pobierzIloscZasobu(TypZasobu::FOOD)
              << " | GOLD: " << mz.pobierzIloscZasobu(TypZasobu::GOLD)
              << " | WOOD: " << mz.pobierzIloscZasobu(TypZasobu::WOOD)
              << " | STONE: " << mz.pobierzIloscZasobu(TypZasobu::STONE) << std::endl;
    std::cout << " SECURITY: " << miasto.getBezpieczenstwo() << std::endl;
    std::cout << "=========================================" << std::endl;
}
