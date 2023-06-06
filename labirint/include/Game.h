#ifndef GAME_H
#define GAME_H
#include "Labirint.h"

class Game
{
public:
    Game(Labirint& maze);  // Constructor
    void run(); //rularea jocului
    void printMenu() const; //afisarea meniului 'wasd'
    void printLabirint(); //afisarea labirintului
    bool endGame(); //control sfarsit joc

private:
    Labirint maze;  // Obiect Labirint
};

#endif // GAME_H
