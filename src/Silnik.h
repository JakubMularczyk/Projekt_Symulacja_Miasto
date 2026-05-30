    #pragma once
    

    #include "Miasto.h"

    class Silnik {
    private:
        Miasto miasto;
        int aktualnaTura;
        bool czyDzialaSymulacja;


        
        void wykonajTure();
        void wyswietlRaport() const;
        void pokazMenu();

    public:
        Silnik();
        void uruchom();
    };

    
