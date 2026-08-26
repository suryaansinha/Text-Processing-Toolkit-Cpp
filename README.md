# Text Processing Toolkit - C++

Text Processing Toolkit is a menu-driven C++ console app showcasing core CS fundamentals: word storage with a fixed-capacity vector, linear search, bubble sort, stack-based word reversal, vowel counting, and recursive factorial calculation.

## Build

```bash
g++ -std=c++11 -Wall -Wextra -pedantic text_processing_toolkit.cpp -o text_processing_toolkit
```

## Run

```bash
./text_processing_toolkit
```

## Menu Options

1. **Add / Store Words** - adds words one at a time, asking whether to continue after each entry, until the user stops or the 50-word capacity is reached.
2. **Search for a Word (Linear Search)** - searches stored words from first to last and reports the 1-based position when found.
3. **Sort Words Alphabetically (Bubble Sort)** - sorts the stored list in place and displays the sorted result.
4. **Reverse a Word (Stack)** - displays stored words, asks for a word position, and reverses that stored word with `std::stack<char>`.
5. **Count Vowels in a Word** - displays stored words, asks for a word position, and counts uppercase and lowercase English vowels in that stored word.
6. **Calculate Factorial (Recursive)** - recursively calculates factorial for a non-negative integer from 0 through 20.
7. **Display All Stored Words** - prints stored words with 1-based position numbers.
8. **Exit** - prints a goodbye message and ends the menu loop.

## Implementation Notes

- Stores up to 50 words in `std::vector<std::string>` and prevents overflow.
- Uses case-insensitive comparisons for searching and sorting.
- Reverse and vowel-count operations intentionally use stored words selected by position so empty lists are handled consistently.
- Uses `std::stack<char>` for reversal to demonstrate stack push/pop behavior.
- Counts vowels by normalizing each character to lowercase before comparing with `a`, `e`, `i`, `o`, and `u`.
- Calculates factorial recursively for integers from 0 through 20 to avoid `long long` overflow.
- Validates menu choices, stored-word positions, and factorial input so invalid entries do not crash the program.

## Testing Checklist

- Add several words, then search for one that exists and one that does not.
- Sort a mixed-case list and confirm case-insensitive alphabetical order.
- Reverse a stored word with mixed case and confirm correctness.
- Count vowels on stored words with both uppercase/lowercase vowels and zero vowels.
- Compute factorial for 0, 1, a typical positive number, a negative number, and a value greater than 20.
- Enter invalid menu input, invalid stored-word positions, and letters instead of numbers to confirm the program does not crash.
- Run search, sort, reverse, vowel-count, and display operations when no words are stored yet, and confirm graceful messages appear instead of crashes.
# **Text-Processing-Toolkit-Cpp**
Text Processing Toolkit is a menu-driven C++ app showcasing core CS fundamentals: word storage with arrays, linear search, bubble sort, stack-based word reversal, vowel counting, and recursive factorial calculation — all wrapped in an interactive, input-validated console interface.
