    #pragma once
    #ifndef SILNIK_H
    #define SILNIK_H

    #include "Miasto.h"

    class Silnik {
    private:
        Miasto miasto;
        int aktualnaTura;
        bool czyDzialaSymulacja;


        void nazwaMiasta();
        void wykonajTure();
        void wyswietlRaport() const;
        void pokazMenu();

    public:
        Silnik();
        void uruchom();
    };

    #endif
