#include <iostream>
#include <ctime>


class Battleship{
    bool board[5][5] {0};
    int guesses;
    int maxGueses;
    int locationX , locationY;

    public:
        Battleship() = default;
        Battleship(int maxGueses):maxGueses(maxGueses) , guesses(maxGueses){
           
            std::srand(time(nullptr));
            locationX = rand() % 5;
            locationY = rand() % 5;
            board[locationX][locationY] = true;

            std::cout << "Welcome to Battleship Game!" << std::endl;
            std::cout << "You have " << maxGueses << " guesses to find the battleship hidden in a 5x5 grid" << std::endl;
        }
        ~Battleship() = default;
        bool guess(int x , int y){
            if (board[x][y] == true){
                 std::cout << "You Hit the Battleship!" << std::endl;
                return true;
            }
            else if ( x == locationX || y == locationY){
                if(x == locationX)
                    std::cout << "You are in the same Row" << std::endl;
                else
                    std::cout << "You are in the same Column" << std::endl;
            }
            else if ( x == locationX - 1 || y == locationY - 1){
                std::cout << "You are so near,Try Harder!" << std::endl ;
            }
            else{
                std::cout << "You missed ...." ;
            }
            guesses--;
            return false;
        }
        bool gameOver()const {
            if(guesses == maxGueses)
                return true;
            return false;
        }
        int getGuesses()const {
            return guesses;
        }
};

int main(){
   Battleship myBattle(5);
   int x , y ;
   bool result = false;
   while(true){
   std::cout << "Enter your Guess (row and column): ";
        std::cin >> x >> y ;
        result = myBattle.guess(x , y);
        if(result == true){
            std::cout << "You won in " << myBattle.getGuesses() << " guesses!" << std::endl;
            break;
        }
        else{
            if(myBattle.gameOver() == true){
                std::cout << "Game Over!" << std::endl;
                break;
            }else{
                std::cout<< "You have " << myBattle.getGuesses() << " guesses left."<<std::endl;
            }

        }    

   }

}