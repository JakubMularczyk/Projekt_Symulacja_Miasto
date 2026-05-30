Projekt – Symulacja Średniowiecznego Miasta
Wersja robocza 
C++
	
Cel:	Celem jest stworzenie przykładowej symulacji średniowiecznego miasta przy wykorzystaniu programowania obiektowego. Aplikacja modeluje interakcje pomiędzy agentami(mieszkańcy), infrastrukturą(budynkami),  oraz zasobami. System jest bardzo łatwo rozszerzalny dzięki zastosowaniu klas abstrakcyjnych.
Warunek upadku miasta:
Jeśli FOOD <= 0 przez 3 kolejne tury, miasto upada.
Jeśli GOLD <= 0 przez 3 kolejne tury, miasto upada.
Jeśli SECURITY <= 0 przez 3 kolejne tury, miasto upada.
Jeśli wartość wróci powyżej 0, licznik dla danego parametru resetuje się.
Przebieg tury:
1. Silnik rozpoczyna nową turę.
2. Każdy mieszkaniec wykonuje swoją akcję.
3. Budynki modyfikują efektywność mieszkańców.
4. Miasto zużywa jedzenie na utrzymanie populacji.
5. Losowo może wystąpić wydarzenie.
6. Aktualizowane są zdrowie, głód i bezpieczeństwo.
7. Sprawdzane są warunki upadku miasta.
8. Wyświetlany jest raport z tury.

Zasady działania:
Użytkownik wprowadza dane przed rozpoczęciem symulacji (np.: ilość złota, drewna jedzenia) aplikacja w systemie turowym pozwala wyświetlać informacje na temat rozwoju naszego miasta, stanu zasobów, zdrowia mieszkańców itp. Bada również zależności pomiędzy mieszkańcami a infrastruktura.
