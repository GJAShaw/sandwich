# sandwich

Generates number combinations valid for sandwich sudoku puzzles

It's an Eclipse C project, so if you're using some other build tool then you may have to adapt it.

# Sandwich Sudoku
Here's a page which explains the game: [Clarity Media explanation](http://www.clarity-media.co.uk/puzzleblog/sandwich-sudoku-puzzles). This application helps with the 9x9 grid version.

# Usage
## standalone
The executable is called `sandwich`. There are no command-line parameters: just enter

`sandwich`

The terminal output is a list of all valid digit runs from the set 2 to 8 inclusive. Each line of output comprises

1. the set of digits in the run, in ascending order. Entry into the puzzle grid could be in any order, not necessarily ascending.
2. the number of digits in the set
3. the sum of the digits

Here's an excerpt of three lines, as an example:

`{ 2 3 4 5 6 } 5 20`

`{ 7 } 1 7`

`{ 2 7 } 2 9`

The third line reports that { 2 7 } is a 2-digit run summing to 9.

The lines of output may not appear to be in any particular order - but see "Design" below, if you want to know more.

## with grep
You can use `grep` to filter the output for combinations useful in gameplay, e.g. to display combinations summing to 17, you would enter

`sandwich | grep ' 17$'`

# Design
You don't need to know this to use the program, but it does explain why the output is in the order in which you see it.

The program generates all possible combinations of the digits 2 to 8 inclusive by using the lowest 7 bits of a byte as a selection mask for the elements of the array {8 7 6 5 4 3 2}, and letting the value of that byte run from 0 = 0b00000000 to 63 = 0b01111111. For example, when the byte has value 23:

- 23 = 0b00010111
- lowest seven bits are 0010111
- use bits to mask {8 7 6 5 4 3 2}, giving {0 0 6 0 4 3 2}
- we have 4 bits set to 1, and the digit sum is 6 + 4 + 3 + 2 = 15
- the line eventually printed to stdout is `{ 2 3 4 6 } 4 15`

The output lines are printed in the order of the byte values which generate them.