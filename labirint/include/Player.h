#ifndef PLAYER_H
#define PLAYER_H


class Player
{
public:
    Player(int linie_, int coloana_) : linie(linie_), coloana(coloana_) {} //constructor
    int getLinie() const;     //functiile get
    int getColoana() const;
    void setLinie(int linie_);  //functiile de setare
    void setColoana(int coloana_);
private:
    int linie;
    int coloana;
};

#endif // PLAYER_H
