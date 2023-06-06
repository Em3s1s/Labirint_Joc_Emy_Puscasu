#include "Game.h"
#include <cstring>
Game::Game(Labirint& maze)
    : maze(maze)
{
}
bool Game::endGame()
{
    int n=maze.getLinii();
    int m=maze.getColoane();
    int pn=maze.getPlayerLinie();
    int pm=maze.getPlayerColoana();
    if(pn==n-2 && pm==m-2)
        return true;
    if(n%2==0 && m%2==0 && pn==n-3 && pm==m-3)
        return true;
    else
        if(n%2==1 && m%2==0 && pn==n-2 && pm==m-3)
            return true;
        else
            if(n%2==0 && m%2==1 && pn==n-3 && pm==m-2)
                return true;
    return false;
}

void Game::printLabirint()
{
    cout << "Duceti jucatorul la punctul E din Labirint:" << endl;
    maze.print();
    cout << endl;
}


void Game::printMenu() const
{
    cout << "\n==================================" << endl;
    cout << "Comenzi disponibile:" << endl;
    cout << "W/w - Muta jucatorul in sus" << endl;
    cout << "A/a - Muta jucatorul in stanga" << endl;
    cout << "S/s - Muta jucatorul in jos" << endl;
    cout << "D/d - Muta jucatorul in dreapta" << endl;
    cout << "Q/q - Iesire din joc" << endl;
    cout << "==================================" << endl;
}


void Game::run()
{
    char command;
    bool gameOver = false;

    printMenu();
    printLabirint();

    while (!gameOver)
    {

        cout << "Introduceti o comanda: ";
        cin>>command;
        if (command == 'q' || command == 'Q')
        {
            gameOver = true;
        }
        else
        {
            if (maze.mutareJucator(command)==true)
            {
                system("clear");
                printMenu();
                printLabirint();
            }
            else
                {system("clear");
                printMenu();
                printLabirint();
                cout<<"Comanda gresita sau invalida! \n";}

            if(endGame())
                {cout<<"======Felicitari, ati terminat jocul!======"<<endl;
                gameOver=true;}
        }
    }
}

