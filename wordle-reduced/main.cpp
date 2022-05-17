#include "wordle.h"

int main()
{
  Wordle wordle("../dict.txt");
    std::string my_guess;
    
    for (int i = 0; i < 6; i++){
        std::cout << "\nGuess word: ";
        std::cin >> my_guess;
        std::cout << "\nYou guessed " << my_guess << "\n";
        GuessResponse response = wordle.guess(my_guess);
        if (response.first){
            std::cout << "\nYOU WIN!!!\n";
            break;
        } else {
            std::cout << "\nHmm ..." << 5 - i << " tries left.\n";
        }
    }
}
