# sandwich

Generates number combinations valid for sandwich sudoku puzzles

It's an Eclipse C project, so if you're using some other build tool then you may have to adapt it.

# Sandwich Sudoku
Here's a link which explains the game: [Clarity Media explanation](http://www.clarity-media.co.uk/puzzleblog/sandwich-sudoku-puzzles). This application helps with the 9x9 grid version.

# Usage
## standalone
The executable is called `sandwich`. There are no command-line parameters: just enter

`sandwich`

The terminal output is a list, which may not seem to be in any particular order (although see "design" below), of valid sandwich sudoku runs between the 1 and the 9. Each line of output comprises

1. the set of digits in the run
2. the number of digits in the set
3. the sum of the digits

## with grep
You can use `grep` to filter the output for combinations useful in gameplay, e.g. to display combinations summing to 17, you would enter

`sandwich | grep ' 17$'`

# Design
The program generates all possible combinations of the digits 2 to 8 inclusive by using the lowest 7 bits of a byte as a mask for the digits {8 7 6 5 4 3 2}, and letting the value of that byte run from 0 = 0b00000000 to 63 = 0b01111111. For example, when the byte has value 23:

- 23 = 0x00010111
- lowest seven bits are 0010111
- use bits to mask {8 7 6 5 4 3 2}, giving {0 0 6 0 4 3 2}
- we have 4 bits set to 1, and the digit sum is 6 + 4 + 3 + 2 = 15
- the line eventually printed to terminal is "{2 3 4 6} 4 15"

You don't need to know this to use the program, but it does explain why the output is in the order in which you see it.
