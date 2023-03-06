# Reverse-Polish-Notation-Converter

## General Information
This program reads algebraic expression and writes out its equivalent in Reverse Polish Notation. <br/>
Each variable and operator should be separated by a single space. At the end of the expression there should be the word "STOP". <br/>

## Available operators and their priorities
- "||" - "or" operator, priority=1
- "&&" - "and" operator, priority=2
- "==" and "!=" - comparisions, priority=3
- ">", ">=", "<", "<=" - comparisions, priority=4
- "+" and "-" - addition and subtraction, priority=5
- "*", "/", "%" - multiplication, division and modulo, priority=6
- "^" - exponentiation, priority=7
- "sqrt" - square root, priority=8
- "max", "min" - maximum and minimum, priority=9
- bracket symbols "(" and ")" are also available. Each bracket should have its matching bracket.
- any input part other than the symbols above will be treated as an expression variable

## Example
Let's say you want to convert sqrt(max(((a+b)*12-b^(c/d))%8, 2))+37 to RPN. <br/>
Incorrect input: `sqrt(max(((a+b)*12-b^(c/d))%8, 2))+37` <br/>
Also incorrect input: `sqrt(max(((a+b)*12-b^(c/d))%8, 2))+37STOP` <br/>
One more incorrect input: `sqrt max ((((a + b) * 12 - b ^ (c / d)) % 8) 2) + 37STOP` <br/>
Correct input: `sqrt ( max ( ( ( ( a + b ) * 12 - b ^ ( c / d ) ) % 8 ) 2 ) ) + 37 STOP` <br/>
Also correct input: `sqrt max ( ( ( a + b ) * 12 - b ^ ( c / d ) ) % 8 ) 2 + 37 STOP` <br/>
Output: `a b + 12 * b c d / ^ - 8 % 2 max sqrt 37 +`
