
#ifndef MenedzerZasobow_h
#define MenedzerZasobow_h

#include <map>
#include "Zasoby.h"

class MenedzerZasobow {
private:
    std::map<TypZasobu, int> zasoby;

public:
    MenedzerZasobow();

    void dodajZasob(TypZasobu typ, int ilosc);

    bool zuzyjZasob(TypZasobu typ, int ilosc);

    int pobierzIloscZasobu(TypZasobu typ) const;
};

#endif


