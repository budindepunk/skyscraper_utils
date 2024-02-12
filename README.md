A few utility functions I wrote for a group project. The overall goal was making a program that solved [skyscraper puzzles](https://www.conceptispuzzles.com/index.aspx?uri=puzzle/skyscrapers/rules) given _all_ the possible clues, passed as an argument in the form of a single long string.

In **handle_arguments** and **handle_arguments_grid** I parse this string into something more manageable: 4 one-dimensional arrays and one 4x4 2-dimensional array, respectively.
In **latin_square** I wrote:
- a ultimately useless function that creates [latin squares](https://en.wikipedia.org/wiki/Latin_square), although it will always create the same one when given the same size argument. I didn't work on this further.
- a complementary function that checks whether a given grid is a latin square. this would be used to quickly rule out incorrect solutions for the puzzle.

In **one_line** there are a few more things:
- a function that takes a filled row and its two relevant clues and checks whether the clues are fulfilled;
- a function that takes a grid and an index number to turn that column into a row, to be able to check its solution with the same function above.

Finally in main I just played around with example clues and solutions to test all of that out and never removed it :).

Anyway, we ran out of time. I might try to finish this on my own eventually because it was a lot of fun.
