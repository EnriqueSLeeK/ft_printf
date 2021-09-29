# ft_printf

[Intro](https://github.com/EnriqueSLeeK/ft_printf/blob/main/README.md#introduction)    [Mandatory Part](https://github.com/EnriqueSLeeK/ft_printf/blob/main/README.md#mandatory-part) []()
## Introduction:
The project was proposed by the 42 school, consist in a partial reimplementation of the function printtf present in the standart libC, used to print a formatted string to the terminal using flags

## Mandatory part:

### The following are flags implemented:
- %d print a number in decimal number format

- %i print a number in decimal number format
- %u print a unsigned number in decimal format
- %p print a address in hexadecimal format
- %s print a string
- %c print a char
- %x print a number in hexadecimal format (lowercase)
- %X print a number in hexadecimal format (Uppercase)
- %% print the percent

## Bonus part:

### Bonus flag implementation:
- width        specify the width of the formatted output

- \#            put a 0x(for %x and %p) or 0X(for %X) in front of hexadecimal number
- 0\<quant\>     the formatted string (for %d, %i, %u, %x, %X, %p) is padded with zero's specified by the "quant"
- -\<quant\>     the formatted string will have extra spaces after printing the contents of the format specified by the "quant"
- \<space\>      the formatted string (for %d and %i) will be prefixed by a space if the argument is positive and by a minus if the argument is negative
- \+            similar to the <space> flag but instead of prefixing a space when the argument is positive, it will prefix a "+"
- .\<quant\>     this flag will define the precision of the formatted string
