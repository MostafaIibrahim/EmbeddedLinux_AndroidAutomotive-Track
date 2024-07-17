#ifndef _BATTLESHIP_H__
#define _BATTLESHIP_H__

class Battleship{
    bool board[5][5];
    int guesses;
    int maxGueses;
    int locationX , locationY;

    public:
        Battleship() = default;
        Battleship(int maxGueses);
        ~Battleship() = default;
        bool guess(int x , int y);
        bool gameOver()const ;
        int getGuesses()const ;


};

#endif