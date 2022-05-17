#include "wordle.h"

GuessResponse Wordle::guess(const std::string& word)
{
    bool is_correct = true;
    for ( int i = 0 ; i < word.length(); i++){
        if (secret_word[i] == word[i]){
            std::cout << exact_print(word[i]);
        } else if (secret_word.find(word[i], 0) != std::string::npos){
                std::cout << contains_print(word[i]);
                is_correct = false;
        } else {
            is_correct = false;
        }
    }
    return {is_correct, word};
}

std::string Wordle::get_word(const std::string& filename)
{
    std::srand(/*std::*/time(nullptr));

    std::vector<std::string> result;
    std::ifstream file(filename);
    std::string word;

    if (!file.is_open())
    {
        std::cout << "Can not open: " << filename << std::endl;
        return {};
    }

    while (std::getline(file, word))
        result.push_back(word);

    return result[std::rand() % result.size()];
}

std::string Wordle::exact_print(char c)
{
    std::stringstream ss;
    ss << "\033[1;32m" << c << "\033[0m";

    return ss.str();
}

std::string Wordle::contains_print(char c)
{
    std::stringstream ss;
    ss << "\033[1;33m" << c << "\033[0m";

    return ss.str();
}
