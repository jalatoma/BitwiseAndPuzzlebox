# Bitwise and Puzzlebox
Project 2 in CSCI 2021 (UMN) completed Fall 2021. Completing bitwise shifts and familiarity with GDB. 

## Part 1 (Bitwise)
Based on an Assignment Originally from Randy Bryant and David O'Halloran

Read the material below and the comments at the top of bits.c to understand how to complete this part of the project.

The first part of the project focuses on the files in the bitwise directory. We recommend that you work within this subdirectory of the starter code for the duration of this part of the project (e.g., using cd in your terminal).

Your task is to fill in the skeleton code in the bits.c file with solutions to 13 bitwise puzzle problems.

You can use only straightline C code for the integer-related puzzles (i.e., no loops or conditionals) and a limited number of C arithmetic and logical operations. Specifically, you are only allowed to use the following eight operators:

! ~ & ^ | + << >>

A few of the problems further restrict this list. Also, you are not allowed to use any constants larger than 8 bits (e.g., you can use 0xFF but not 0xFFF).

For floating-point problems, you will implement some common single-precision (32-bit) floating point operations. For these puzzles, you are allowed to use standard control structures (conditionals, loops) and you may use both int and unsigned data types, including arbitrary integer and unsigned constants. You may not use any unions, structs, or arrays. Most significantly, you may not use any floating-point data types, operations, or constants. Instead, any floating-point operand will be passed to the function as having type unsigned, and any returned floating-point value will also be of type unsigned. Your code should perform the bit manipulations that implement the specified floating-point operations.

## Part 2 (Puzzlebox)
The file puzzlebox/puzzlebox.c contains source code that reads input from a file named on the command line (usually input.txt in this project). If the inputs are correct, points are awarded. If inputs are incorrect, error messages are printed.

The puzzlebox is arranged into a series of phases each of which has some points associated with it.

Each phase reads inputs from the file provided on the command line and performs calculations on them to see if they are "correct" according to various criteria specified in the source code.
The very first input is your UMN Internet ID like kolb0128 (the first part of your UMN email address). This input is used to add an element of randomness to the puzzle so that your answers will be different from most other students. You must use your own Internet ID, and we will be verifying this when manually grading project submissions.

**The purpose of this problem is to get familiar using a debugger.** This is a powerful tool that pauses program execution, allows internal values to be printed and inspected, and code to be stepped through line by line. It is nearly essential to use here as the code in puzzlebox is intentionally convoluted in places. Being able to pause execution and print values at various points makes it much easier to solve the puzzles.

**The main part is adding a .txt file and running it with the code & passing all the "phases"**
