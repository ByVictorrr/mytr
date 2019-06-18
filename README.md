# mytr
## Description
This program “translates” characters based on a user-specified mapping. This can be used, for instance, to translate every ‘-’ into a ‘_’ (the full-featured program allows for more advanced translations).
## Translation
If given two sets (SET1 and SET2), then mytr copies its standard input to standard output while replacing each
occurrence of a character in SET1 with the corresponding (by position) character in SET2. For example, mytr "abc"
"def" with input cxbyaz gives output fxeydz (replacing each ‘a’ with ‘d’, each ‘b’ with ‘e’, and each ‘c’ with ‘f’).
If too few or too many sets are given, then the execution is in error. If SET1 is longer than SET2, then SET2 is
extended by repeating its last character as necessary (i.e., if SET1 is “abcdef” and SET2 is “xyz”, then ‘c’, ‘d’, ‘e’, and ‘f’ are all replaced with ‘z’). Excess characters in SET2 are ignored.
If the first set contains repeats of the same character, then that character is translated based on its last
occurrence in the set (i.e., with sets “abcad” and “12345”, ‘a’ characters will translate to “4”).
##  Deletion
If mytr is given the -d switch and a single set, then it copies its standard input to standard output while deleting
those characters that appear in the set. Only a single set may be specified with the -d switch, otherwise an error is
reported.
## Sets
In addition to the typical single character entries, your program must also support the following escaped
characters in the argument sets.
\\ (backslash)
\n (new line)
\t (horizontal tab)
A \ followed by any other character maps to that character (this is particularly useful to escape a - at the beginning
of the first set to prevent that set being treated as a command-line switch).
Each of these escaped characters is written as a two-character sequence, but represents only a single character
in the set. If you have any doubt about what your program is doing relative to what it should do, check its output against the output of the tr program. They should do the same thing for those features that they share in common.

## Features
The mytr program takes a number of command-line arguments. At a minimum the program must be given a “set”
of characters. This set is simply a quoted string of characters specified on the command-line. The number of sets
required depends on the operation desired.

## Usage
make
./mytr [-d] 'set1' ['set2'] 
