#include <iostream>
#include <vector>
#include "Player.h"

using namespace std;
#ifndef LABIRINT_H
#define LABIRINT_H


class Labirint
{
public:
    Labirint(int linii_, int coloane_);  // Constructor
    void print() const;  // Afisare Labirint
    void generare();  // Generarea unui nou labirint
    void actualizare();
    int getLinii();
    int getColoane();
    const vector<vector<char>>& getGrid() const;  // Obține grid-ul labirintului
    int getPlayerLinie() const;  // Obține linia jucătorului
    int getPlayerColoana() const;  // Obține coloana jucătorului
    void setPlayerPozitie(int linie, int coloana);  // Setează poziția jucătorului
    bool mutareJucator(char directie);  // Mută jucătorul în labirint
    void setStartEnd();
private:
    int linii;
    int coloane;
    vector<vector<char>> grid;
    Player player;  // Membru pentru jucător
    void initializareGrid();  // Initializare grid cu pereti si spatii
};

#endif // LABIRINT_H
