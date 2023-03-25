# Reverse-Polish-Notation-Converter

## General Information
This program converts an expression from RPN (Reverse Polish Notation) to infix notation (i.e., 'normal' notation) or vice versa. <br/>
Each variable and operator should be separated by a single space. At the end of the expression there should be the word "STOP". <br/>

## Available operators and their priorities
- "||" - "or" operator, priority=1
- "&&" - "and" operator, priority=2
- "==" and "!=" - comparisions, priority=3
- ">", ">=", "<", "<=" - comparisions, priority=4
- "+" and "-" - addition and subtraction, priority=5
- "*", "/", "%" - multiplication, division and modulo, priority=6
- "^" - exponentiation, priority=7
- bracket symbols "(" and ")" are also available (only in the infix notation). Each bracket should have its matching bracket.
- any input part other than the symbols above will be treated as a variable

## Example
Let's say you want to convert ((a+b)*12-b^(c/d))%8+37 to RPN. <br/>
Correct input: `( ( a + b ) * 12 - b ^ ( c / d ) ) % 8 + 37 STOP` <br/>
Output: `a b + 12 * b c d / ^ - 8 % 37 +` <br/><br/>
If you want to convert a b c * d e - f g ^ ^ / + from RPN to infix notation: <br/>
Correct input: `a b c * d e - f g ^ ^ / + STOP` <br/>
Output: `a + b * c  / ( d - e  ) ^ f ^ g`
