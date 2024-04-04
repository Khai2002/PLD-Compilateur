# PLD Compilateur



## Description
A compiler for a subset of C written in C++ using ANTLR4 for parsing.


## Table of Contents
- [Installation](#installation)
- [Usage](#usage)
- [Supported functionalities](#supported-functionalities)
- [License](#license)

## Installation

- ANTLR4: This is used for generating the parser for the C compiler. You can install it using your distribution's package manager or by running the provided shell script: `install-antlr.sh.`

- A C++ compiler: This is used to compile the C++ code in the project. The project has been tested with GCC on Linux.

## Usage
To use the C compiler, follow these steps:

Build the project by running make in the `compiler/` directory. This will generate the parser using ANTLR and compile the C++ code.

Run the compiler on a C file by using the following command:

` ./ifcc <filename>`

Replace `<filename>` with the path to the C file you want to compile. The C file should contain a main function that returns an integer.

For example, if you have a file `test.c` in the `compiler/` directory that contains the following code:

You can compile it by running:
`./ifcc test.c`

This will generate assembly code for the C program.

Please note that the compiler currently only supports a minimal subset of the C language. 

## Supported functionalities

- Declaration of variables of type INT and CHAR
- Basic arithmetic operations with priorities
    - Add
    - Subtract
    - Multiply
    - Divide 
    - Modulus
    - Unary not
    - Negation
- Return value

## License
MIT license

## note 

For those who are on WSL : please run this command before running all the tests : 

dos2unix ifcc-wrapper.sh

python3 ifcc-test.py testfiles/*