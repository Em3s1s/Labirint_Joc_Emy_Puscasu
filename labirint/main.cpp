#include <iostream>
#include "Labirint.h"
#include "Game.h"
using namespace std;
int main()
{
    char v;
    int n, m;
    do
    {
    system("clear");
    cout << "Dati numarul de linii si coloane: ";
    cin >> n >> m;
    while(n<5 || m<5)
    {
        system("clear");
        cout<<"Numar prea mic de linii/coloane!\n";
        cout<<"Dati numarul de linii si coloane (linii>4,coloane>4):";
        cin>> n >> m;
    }
    while(n>50 || m>85)
    {
        system("clear");
        cout<<"Numar prea mare de linii/coloane!\n";
        cout<<"Dati numarul de linii si coloane (linii<51,coloane<86):";
        cin>> n >> m;
    }

    Labirint maze(n, m);
    maze.generare();

    // Setarea coordonatelor jucătorului
    int playerLinie=1   , playerColoana=1;

    maze.setPlayerPozitie(playerLinie, playerColoana);

    Game game(maze);

    game.run();
    cout<<"Doriti sa incercati un alt nivel? Y/N:";
    cin>>v;

    }while(v=='Y' || v=='y');
    cout<<"\n========La revedere!========\n";

    return 0;
}
