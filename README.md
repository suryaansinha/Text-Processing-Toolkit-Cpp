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

## Implementation Notes

- Stores up to 50 words in `std::vector<std::string>` and prevents overflow.
- Uses case-insensitive comparisons for searching and sorting.
- Reverses directly entered words with `std::stack<char>`.
- Counts vowels in directly entered words, including uppercase and lowercase vowels.
- Calculates factorial recursively for integers from 0 through 20 to avoid `long long` overflow.
- Validates menu and numeric input so invalid entries do not crash the program.

## Testing Checklist

- Add several words, then search for one that exists and one that does not.
- Sort a mixed-case list and confirm alphabetical order.
- Reverse a word with mixed case and confirm correctness.
- Count vowels on a word with both cases and on a word with zero vowels.
- Compute factorial for 0, 1, a typical positive number, and a negative number that should be rejected.
- Enter invalid menu input, such as letters instead of numbers, and confirm the program does not crash.
- Run search, sort, reverse, vowel-count, and display operations when no words are stored yet or no direct word is entered, and confirm graceful messages appear instead of crashes.
