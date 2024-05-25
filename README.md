# DPDA (Pushdown Automaton) Word Acceptance
## Overview
This project implements a deterministic pushdown automaton (DPDA) to determine whether a given word is accepted based on a set of predefined rules and transitions. The program reads PDA configurations from an input file and processes words to check their acceptance.

## Files
+ **PDA.h**: Header file defining the PDA class and its member functions.
+ **PDA.cpp**: Implementation file for the PDA class.
+ **main.cpp**: Main program logic for reading PDA configurations and testing word acceptance.
+ **date.in**: Input file containing PDA configurations.

## Input File Format (date.in)
The input file should follow this format:

+ **Number of States**: An integer N representing the number of states.
+ **States**: A list of N state identifiers.
+ **Alphabet Length**: An integer M representing the length of the input alphabet.
+ **Alphabe**t: A list of M characters representing the input alphabet.
+ **Initial State**: The initial state of the PDA.
+ **Number of Final States**: An integer F representing the number of final states.
+ **Final States**: A list of F state identifiers representing the final states.
+ **Number of Productions**: An integer P representing the number of productions (transitions).
+ **Productions**: P productions of the form (initial_state, input_symbol, stack_symbol) -> (final_state, stack_string).
+ **Stack Alphabet Length**: An integer K representing the length of the stack alphabet.
+ **Stack Alphabet**: A list of K characters representing the stack alphabet.
+ **Initial Stack Symbol**: The initial symbol on the stack.

# Code Explanation
## PDA Class
### Member Variables
+ **nrStari**: Number of states.
+ **stari**: Vector of states.
+ **lgAlfabetIntrare**: Length of the input alphabet.
+ **alfabetIntrare**: Vector of input alphabet characters.
+ **stareInit**: Initial state.
+ **nrStariFinale**: Number of final states.
+ **stariFinale**: Vector of final states.
+ **nrProductii**: Number of productions.
+ **leftProd**: Vector of tuples representing the left side of productions.
+ **rightProd**: Vector of pairs representing the right side of productions.
+ **lgAlfabetStiva**: Length of the stack alphabet.
+ **alfabetStiva**: Vector of stack alphabet characters.
+ **simbolInitial**: Initial stack symbol.
  
### Member Functions
+ **citestePDA()**: Reads PDA configuration from the input file.
+ **acceptaCuvant(std::string cuvant)**: Checks if a given word is accepted by the PDA.
+ **Cauta(int stare, char litCuvant, char simbolStiva)**: Searches for a production based on the current state, input symbol, and stack symbol.
+ **adaugaCuvant(std::stack<char>& stiva, std::string& cuvant)**: Adds a string to the stack.
+ **eFinala(int stare)**: Checks if a given state is a final state.
+ **lambdaTranzitie(int stare, char simbolStiva)**: Searches for a lambda transition based on the current state and stack symbol.
