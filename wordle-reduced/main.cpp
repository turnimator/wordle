#include "wordle.h"

int main()
{
  Wordle wordle("../dict.txt");
    std::string my_guess;
    
    for (int i = 0; i < 6; i++){
        std::cout << "Guess word: ";
        std::cin >> my_guess;
        std::cout << "\nYou guessed " << my_guess << "\n";
        GuessResponse response = wordle.guess(my_guess);
        if (response.first){
            std::cout << "YOU WIN!!!\n";
            break;
        } else {
            std::cout << 5 - i << " tries left.\n";
        }
    }
}
