# ft_printf

The objective of this project is to recode the printf function. My implementation is 70% of the printf speed

## Mandatory Part

### Converters
* s : ascii strings
* S : unicode strings
* p : pointers
* idD : signed decimal
* oO : octal conversion
* uU : unsigned decimal
* xX : hexadecimal conversion
* c : ascii character
* C : unicode character
### Flags
* # : add '0x' for hexadecimal or '0' for octal
* 0 : complete the indicated width with zeros
* - : apply width after the argument 
* + : add '+' sign for positive numbers
* ' ' : add a space before the argument
* hh : cast the argument in 
* h : cast the argument in  
* l : cast the argument in 
* ll : cast the argument in 
* j : cast the argument in intmax_t
* z : cast the argument in 
## Bonuses
* ft_dprintf
* ft_sprintf
* %n : number of characters read by printf
* %f : floats
* %k [+-#] : color option
* %b : binaire
* '*' : wildcards
