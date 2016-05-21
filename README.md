This project consists of creating a program that can perform arithmetic operations on numbers whose order of size is not fixed and in any base.

### Usage
```
./calc base operators size_read
```

### Examples

```
echo "3+6" | ./calc 0123456789 "()+-*/%" 3

echo "3v6" | ./calc 0123456789 "{}vwxyz" 3

echo "-(12-(4*32))" | ./calc 0123456789 "()+-*/%" 12

echo "-(e@-(;*!@))" | ./calc "~^@!;ie& ]" "()+-*/%" 13
```
