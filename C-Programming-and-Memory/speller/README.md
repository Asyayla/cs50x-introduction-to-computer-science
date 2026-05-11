# Speller (Hash Table Implementation)

This project is a high-performance spell-checker developed as part of Harvard's CS50x. It is designed to load a large dictionary into memory and check a given text for misspelled words in the shortest time possible.

## Technical Highlights

- **Data Structure:** Implemented a **Hash Table** with separate chaining (using Linked Lists) to resolve collisions.
- **Complexity:** Achieved $O(1)$ average time complexity for word lookups.
- **Memory Management:** Handled manual memory allocation and deallocation using `malloc` and `free` in C, ensuring a leak-free execution (verified with Valgrind).
- **Efficiency:** Utilized a custom hash function to distribute words evenly across the buckets.

## Files
- `dictionary.c`: The core logic for loading the dictionary, hashing words, checking spelling, and freeing memory.
- `dictionary.h`: Function prototypes and data structure definitions.
