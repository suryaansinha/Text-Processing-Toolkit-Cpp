#include <cctype>
#include <iostream>
#include <limits>
#include <stack>
#include <string>
#include <utility>
#include <vector>

const std::size_t MAX_WORDS = 50;

/*
Testing checklist summary:
- Add several words, then search for both existing and missing words.
- Sort mixed-case words and confirm the case-insensitive alphabetical order.
- Reverse a stored mixed-case word and confirm the characters are reversed.
- Count vowels in stored words containing uppercase vowels, lowercase vowels, and no vowels.
- Calculate factorial for 0, 1, 5, and a negative number that should be rejected.
- Enter letters for menu choices and factorial input to confirm validation works.
- Run search, sort, reverse, vowel count, and display before storing words to confirm
  graceful "No words stored yet" messages.
*/

// Displays the main application menu.
void showMenu() {
    std::cout << "\n===== Text Processing Toolkit =====\n";
    std::cout << "1. Add / Store Words\n";
    std::cout << "2. Search for a Word (Linear Search)\n";
    std::cout << "3. Sort Words Alphabetically (Bubble Sort)\n";
    std::cout << "4. Reverse a Word (Stack)\n";
    std::cout << "5. Count Vowels in a Word\n";
    std::cout << "6. Calculate Factorial (Recursive)\n";
    std::cout << "7. Display All Stored Words\n";
    std::cout << "8. Exit\n";
    std::cout << "Enter your choice: ";
}

// Reads a whole-number menu or numeric value without crashing on bad input.
bool readInteger(int& value) {
    std::cin >> value;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return true;
}

// Converts a string to lowercase so searches and sorting are case-insensitive.
std::string toLowercase(const std::string& text) {
    std::string lowered = text;

    for (char& character : lowered) {
        character = static_cast<char>(std::tolower(static_cast<unsigned char>(character)));
    }

    return lowered;
}

// Adds words one at a time until the user stops or the fixed capacity is reached.
void addWords(std::vector<std::string>& words) {
    char addAnother = 'y';

    while ((addAnother == 'y' || addAnother == 'Y') && words.size() < MAX_WORDS) {
        std::string word;
        std::cout << "Enter a word to store: ";
        std::getline(std::cin, word);

        if (word.empty()) {
            std::cout << "Empty words are not stored.\n";
        } else {
            words.push_back(word);
            std::cout << "Stored \"" << word << "\". (" << words.size() << "/" << MAX_WORDS << ")\n";
        }

        if (words.size() == MAX_WORDS) {
            std::cout << "Word storage is full. No more words can be added.\n";
            break;
        }

        std::cout << "Add another word? (y/n): ";
        std::cin >> addAnother;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

// Searches linearly from first word to last; comparison is case-insensitive.
int linearSearch(const std::vector<std::string>& words, const std::string& target) {
    const std::string loweredTarget = toLowercase(target);

    for (std::size_t index = 0; index < words.size(); ++index) {
        if (toLowercase(words[index]) == loweredTarget) {
            return static_cast<int>(index);
        }
    }

    return -1;
}

// Prompts for a word and reports whether linear search finds it.
void searchForWord(const std::vector<std::string>& words) {
    if (words.empty()) {
        std::cout << "No words stored yet. Add words before searching.\n";
        return;
    }

    std::string target;
    std::cout << "Enter the word to search for: ";
    std::getline(std::cin, target);

    const int foundIndex = linearSearch(words, target);
    if (foundIndex == -1) {
        std::cout << "Word not found.\n";
    } else {
        std::cout << "Found at position " << (foundIndex + 1) << ".\n";
    }
}

// Sorts words in place using bubble sort and case-insensitive comparisons.
void bubbleSort(std::vector<std::string>& words) {
    if (words.size() < 2) {
        return;
    }

    for (std::size_t pass = 0; pass + 1 < words.size(); ++pass) {
        for (std::size_t index = 0; index + 1 < words.size() - pass; ++index) {
            if (toLowercase(words[index]) > toLowercase(words[index + 1])) {
                std::swap(words[index], words[index + 1]);
            }
        }
    }
}

// Prints all stored words with 1-based positions for beginner-friendly output.
void displayWords(const std::vector<std::string>& words) {
    if (words.empty()) {
        std::cout << "No words stored yet.\n";
        return;
    }

    std::cout << "Stored words:\n";
    for (std::size_t index = 0; index < words.size(); ++index) {
        std::cout << (index + 1) << ". " << words[index] << '\n';
    }
}

// Sorts the stored words and immediately displays the sorted list.
void sortAndDisplayWords(std::vector<std::string>& words) {
    if (words.empty()) {
        std::cout << "No words stored yet. Add words before sorting.\n";
        return;
    }

    bubbleSort(words);
    std::cout << "Words sorted alphabetically.\n";
    displayWords(words);
}

// Gets a valid 0-based index for a stored word selected by the user.
bool chooseStoredWordIndex(const std::vector<std::string>& words, std::size_t& selectedIndex) {
    if (words.empty()) {
        std::cout << "No words stored yet. Add words before using this option.\n";
        return false;
    }

    displayWords(words);
    std::cout << "Enter the position number of the word to use: ";

    int position = 0;
    if (!readInteger(position)) {
        std::cout << "Invalid input. Please enter a whole-number position.\n";
        return false;
    }

    if (position < 1 || position > static_cast<int>(words.size())) {
        std::cout << "Invalid position. Please choose a number from 1 to " << words.size() << ".\n";
        return false;
    }

    selectedIndex = static_cast<std::size_t>(position - 1);
    return true;
}

// Builds a reversed copy of a word by pushing and popping characters on a stack.
std::string reverseWithStack(const std::string& word) {
    std::stack<char> characters;
    std::string reversed;

    for (char character : word) {
        characters.push(character);
    }

    while (!characters.empty()) {
        reversed += characters.top();
        characters.pop();
    }

    return reversed;
}

// Reverses a stored word selected by position to reuse the toolkit word list.
void reverseStoredWord(const std::vector<std::string>& words) {
    std::size_t selectedIndex = 0;
    if (!chooseStoredWordIndex(words, selectedIndex)) {
        return;
    }

    std::cout << "Original word: " << words[selectedIndex] << '\n';
    std::cout << "Reversed word: " << reverseWithStack(words[selectedIndex]) << '\n';
}

// Counts uppercase and lowercase English vowels in a word.
int countVowels(const std::string& word) {
    int vowelCount = 0;

    for (char character : word) {
        const char lowered = static_cast<char>(std::tolower(static_cast<unsigned char>(character)));
        if (lowered == 'a' || lowered == 'e' || lowered == 'i' || lowered == 'o' || lowered == 'u') {
            ++vowelCount;
        }
    }

    return vowelCount;
}

// Counts vowels in a stored word selected by position, matching the reverse option.
void countVowelsInStoredWord(const std::vector<std::string>& words) {
    std::size_t selectedIndex = 0;
    if (!chooseStoredWordIndex(words, selectedIndex)) {
        return;
    }

    std::cout << "Word: " << words[selectedIndex] << '\n';
    std::cout << "Vowel count: " << countVowels(words[selectedIndex]) << '\n';
}

// Recursively calculates n! with base cases for 0! and 1!.
long long factorial(int number) {
    if (number == 0 || number == 1) {
        return 1;
    }

    return number * factorial(number - 1);
}

// Validates factorial input before calling the recursive function.
void calculateFactorial() {
    int number = 0;
    std::cout << "Enter a non-negative integer for factorial: ";

    if (!readInteger(number)) {
        std::cout << "Invalid input. Please enter a whole number.\n";
        return;
    }

    if (number < 0) {
        std::cout << "Factorial is not defined for negative numbers.\n";
        return;
    }

    if (number > 20) {
        std::cout << "Values greater than 20 overflow a 64-bit signed integer. Please enter 20 or less.\n";
        return;
    }

    std::cout << number << "! = " << factorial(number) << '\n';
}

int main() {
    std::vector<std::string> words;
    bool keepRunning = true;

    while (keepRunning) {
        int choice = 0;
        showMenu();

        if (!readInteger(choice)) {
            std::cout << "Invalid menu choice. Please enter a number from 1 to 8.\n";
            continue;
        }

        switch (choice) {
            case 1:
                addWords(words);
                break;
            case 2:
                searchForWord(words);
                break;
            case 3:
                sortAndDisplayWords(words);
                break;
            case 4:
                reverseStoredWord(words);
                break;
            case 5:
                countVowelsInStoredWord(words);
                break;
            case 6:
                calculateFactorial();
                break;
            case 7:
                displayWords(words);
                break;
            case 8:
                std::cout << "Goodbye! Thanks for using the Text Processing Toolkit.\n";
                keepRunning = false;
                break;
            default:
                std::cout << "Invalid menu choice. Please enter a number from 1 to 8.\n";
                break;
        }
    }

    return 0;
}
