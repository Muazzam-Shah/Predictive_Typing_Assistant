# Predictive Typing Assistant (Word Predictor)

## Overview

The Word Predictor is a C++ application designed to help users build sentences interactively by providing word suggestions based on previous input. It creates and updates a word transition dictionary (mapping words to their likely successors) by processing an initial dataset from a file and then continuously learning as the user builds sentences.

## Features

- **Dictionary Initialization:**  
  Loads an initial set of word pairs from a `sentences.txt` file. Each pair is counted to establish word transition frequencies.

- **Real-Time Learning:**  
  Updates the internal dictionary with new word pairs as the user inputs words during the interactive session.

- **Word Suggestions:**  
  For every new word entered, the program provides up to four suggestions for the next word based on the frequency of occurrence after the previous word.

- **Interactive Mode:**  
  Users can build sentences by either entering a new word or selecting a suggestion by its corresponding number. The system continuously refines its predictions.

## Files

- **word_predictor.cpp:**  
  The main source code file containing all the logic for building and updating the dictionary, generating suggestions, and handling user input.

- **sentences.txt:**  
  A text file containing pre-written sentences used to initially populate the word transition dictionary. (Ensure this file is in the same directory as the executable.)

- **README.md:**  
  This file provides an overview, compilation instructions, and usage guidelines for the project.

## Prerequisites

- A C++ compiler that supports C++11 or later (e.g., g++, clang++).
- Standard C++ libraries: `<iostream>`, `<fstream>`, `<sstream>`, `<unordered_map>`, `<vector>`, `<algorithm>`, and `<cctype>`.

## Compilation

To compile the program, open your terminal in the project directory and run:

```bash
g++ word_predictor.cpp -o word_predictor
```

This command compiles the source code and produces an executable named `word_predictor`.

## Usage

1. **Prepare the Dictionary:**  
   Ensure that a file named `sentences.txt` exists in the same directory. This file should contain sentences from which the program will build the initial word transition dictionary.

2. **Run the Program:**

   - On Linux/macOS:
     ```bash
     ./word_predictor
     ```
   - On Windows:
     ```bash
     word_predictor.exe
     ```

3. **Interactive Sentence Building:**  
   - The program enters an interactive mode prompting you to build a sentence.
   - It displays suggestions for the next word based on the last word entered.
   - You can type a new word or enter the number corresponding to one of the suggestions.
   - Type `exit` to end the session.

4. **Dictionary Update:**  
   Each word you add updates the dictionary immediately, so the suggestions become more tailored as your sentence grows.


