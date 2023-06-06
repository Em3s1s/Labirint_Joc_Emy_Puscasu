#include "Labirint.h"
#include <stack>
#include <ctime>

Labirint::Labirint(int linii_, int coloane_)
    : linii(linii_), coloane(coloane_), player(0, 0)
{
    initializareGrid();
}

int Labirint::getLinii()
{return linii;}

int Labirint::getColoane()
{return coloane;}

void Labirint::actualizare()
{
    if(linii%2==0)
        for (int col = 0; col < coloane; ++col)
            grid[linii - 1][col] = ' ';


    if(coloane%2==0)
        for (int lin = 0; lin < linii; ++lin)
            grid[lin][coloane-1] = ' ';

}
void Labirint::initializareGrid()
{
    grid.resize(linii, vector<char>(coloane, '#'));

    // Setarea spatiilor in grid
    for (int i = 1; i < linii - 1; i++)
    {
        for (int j = 1; j < coloane - 1; j++)
        {
            grid[i][j] = '#';
        }
    }
}

void Labirint::generare()
{
    srand(time(nullptr));
    // Incepem cu o celula aleatorie in cadrul labirintului si care sa nu fie margine
    int start_linie = 2 * (rand() % ((linii - 3) / 2)) + 1;
    int start_coloana = 2 * (rand() % ((coloane - 3) / 2)) + 1;

    stack<pair<int, int>> cellStack;  // Stack-ul casutelor visitate
    cellStack.push(make_pair(start_linie, start_coloana));
    grid[start_linie][start_coloana] = ' ';

    // Parcurgerea tuturor casutelor in mod recursiv
    while (!cellStack.empty())
    {
        pair<int, int> current = cellStack.top();
        int lin = current.first;
        int col = current.second;

        // Verificarea casutelor vecine neparcurse
        vector<pair<int, int>> neighbors;
        if (lin >= 3 && grid[lin - 2][col] == '#')
        {
            neighbors.push_back(make_pair(lin - 2, col));
        }
        if (col >= 3 && grid[lin][col - 2] == '#')
        {
            neighbors.push_back(make_pair(lin, col - 2));
        }
        if (lin <= linii - 4 && grid[lin + 2][col] == '#')
        {
            neighbors.push_back(make_pair(lin + 2, col));
        }
        if (col <= coloane - 4 && grid[lin][col + 2] == '#')
        {
            neighbors.push_back(make_pair(lin, col + 2));
        }

        if (!neighbors.empty())
        {
            // Alegerea unui vecin aleatoriu
            int index = rand() % neighbors.size();
            pair<int, int> next = neighbors[index];

            // Eliberarea unei casute din grid
            int next_lin = next.first;
            int next_col = next.second;
            grid[(lin + next_lin) / 2][(col + next_col) / 2] = ' ';
            grid[next_lin][next_col] = ' ';

            // Marcarea vecinului visitat prin adaugarea acestuia in stack
            cellStack.push(next);
        }
        else
        {
            // Parcurgere înapoi dacă nu există vecini nevizitați
            cellStack.pop();
        }
    }
    actualizare();
    setStartEnd();
}


void Labirint::print() const
{
    for (int i = 0; i < linii; i++)
    {
        for (int j = 0; j < coloane; j++)
        {
            if (i == getPlayerLinie() && j == getPlayerColoana())
            {
                cout << 'P' << ' ';
            }
            else
            {
                cout << grid[i][j] << ' ';
            }
        }
        cout << endl;
    }
}

const vector<vector<char>>& Labirint::getGrid() const
{
    return grid;
}

int Labirint::getPlayerLinie() const
{
    return player.getLinie();
}

int Labirint::getPlayerColoana() const
{
    return player.getColoana();
}

void Labirint::setPlayerPozitie(int linie, int coloana)
{
    player.setLinie(linie);
    player.setColoana(coloana);
}

bool Labirint::mutareJucator(char directie)
{
    int linie = getPlayerLinie();
    int coloana = getPlayerColoana();

    switch (directie)
    {
    case 'w':  // Sus
    case 'W':
        if (linie > 0 && grid[linie - 1][coloana] != '#')
        {
            setPlayerPozitie(linie - 1, coloana);
            return true;
        }
        break;

    case 'a':  // Stanga
    case 'A':
        if (coloana > 0 && grid[linie][coloana - 1] != '#')
        {
            setPlayerPozitie(linie, coloana - 1);
            return true;
        }
        break;

    case 's':  // Jos
    case 'S':
        if (linie < linii - 1 && grid[linie + 1][coloana] != '#')
        {
            setPlayerPozitie(linie + 1, coloana);
            return true;
        }
        break;

    case 'd':  // Dreapta
    case 'D':
        if (coloana < coloane - 1 && grid[linie][coloana + 1] != '#')
        {
            setPlayerPozitie(linie, coloana + 1);
            return true;
        }
        break;
    }

    return false;
}
void Labirint::setStartEnd()
{
    int n=getLinii();
    int m=getColoane();
    grid[1][1]='S';
    if(n%2==0 && m%2==0)
        grid[n-3][m-3]='E';
    if(n%2==1 && m%2==1)
        grid[n-2][m-2]='E';
    if(n%2==1 && m%2==0)
        grid[n-2][m-3]='E';
    if(n%2==0 && m%2==1)
        grid[n-3][m-2]='E';
}
