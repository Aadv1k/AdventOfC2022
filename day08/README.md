# Day 8: Treetop Tree House

## part1

In main we first loop over every line and put it in a character array, this is because its easier to deal with character arrays in C than ints or structs

We loop over every line, and every character; Note that we add to the starting values for both of these and substract one from the end, this is to skip the "edges" since they can be calculated statically.

```C
for (int i = 1; i < lineNum-1; i++) {
  for (int j = 1; lines[i][j+1] != '\0'; j++) {
   ...
  }
```

we then use two functions, `bool YLineOfSight_clear(char lines[MAX_L][MAX_W], int length, int atY, int atX)` and `bool XLineOfSight_clear(char lines[MAX_L][MAX_W], int length, int atY, int atX)`, these essentially iterate over and under OR left and right to the given index and return true or false if the number at index is bigger than the iteration.

## part2

We essentially just convert `bool YLineOfSight_clear(char lines[MAX_L][MAX_W], int length, int atY, int atX)` to a function that returns the product of the "up" and "down" variables. We then on each iteration multiply the X score with the Y score and add append to to a integer array; we then use the `utl_max` function to find the MAX score
