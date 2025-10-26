# PDA String Validator

This C++ project implements a **Pushdown Automaton (PDA)** that validates strings as part of a language with **matching characters**.  

## Alphabet

The PDA handles the following characters:  

- Lowercase letters: `a-z`  
- Space: `␢`  
- Parentheses: `(` and `)`  
- Brackets: `[` and `]`  
- End-of-string marker: `.`  

## Features

- Validates proper nesting of parentheses `()` and brackets `[]`.  
- Uses a **stack** to track opening symbols.  
- Implements **state transitions with enums and switch-case**.  
- **Accepts strings only if they follow the defined rules and end with `.`.**

## Example
- [coding]. is accepted
- ]coding[. is rejected
