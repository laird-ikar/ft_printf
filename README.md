# Summary

`ft_printf` is a project from 42 where we are asked to recreate a minimalist version of the `printf` function.

The mandatory part is limited to some conversions type without any flags.

The bonus part add some flags to that. ([see detail below](#flags-and-conversions))

# Usage

The project compile a static library `libftprintf.a` that you should compile with `-Lpath/to/libdir -lftprintf`.

You also have to include the `ft_printh.h` header.

The function is to be used as you would use the original `printf`, if needed, it will raise the same compilation warnings and errors as well.

```C
int ft_printf(const char *format, ...);
```

```C
/* main.c */
#include "ft_printf.h"

int main()
{
    ft_printf("string: %s\nchar: %c\nnumber: %d\n", "a string of char", '*', 42);
    return (0);
}
```

```bash
$ gcc -L. -lftprintf -o test main.c ; ./test | cat -e
string: a string of char$
char: *$
number: 42$
```

# Flags and conversions

Currently the project supports 9 conversions:
- `s`
	- prints `char *`
	- stops at the first `\0`
- `c`
	- prints `char`
	- also prints `\0` and other invisible chars
- `d`, `i`
	- prints `int`
	- standard decimal writing
- `u`
	- prints `unsigned int`
	- standard decimal writing
- `x`, `X`
	- prints `unsigned int`
	- hexadecimal conversion
		- lowercase letters for `x`
		- uppercase letters for `X`
- `p`
	- prints `void *`
	- address in hexadecimal preceded by `"0x"`
- `%`
	- prints a `"%"`

and 5 flags:
- `` ` ` `` (space)
	- add a space before positive number in place of `-` sign the negative would have
- `+`
	- add a `+` before positive number in place of `-` sign the negative would have
	- overrides `` ` ` ``
- `0`
	- add spaces via `0` instead of spaces
- `-`
	- align text to the left of the padding space 
	- overrides `0`
- `#`
	- activate "alternate forms" of some conversions

as well as minimal width and precision déclaration through `.` and numbers.