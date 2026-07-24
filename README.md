# Double Dicer

A C utility for inspecting and reconstructing IEEE 754 `double` floating-point values.
---
## SUMMARY

A C program designed to inspect and provide a deeper understanding of IEEE 754 `double` floating-point representation. 
Using raw memory access and bitwise operations, it decodes the sign, exponent, and mantissa fields defined by the IEEE 754 standard.
The program identifies special cases by classifying each value as **normal**, **subnormal**, **zero**, **infinity**, or **NaN**.
Based on classification, DD follows the appropriate reconstruction algorithm to manually rebuild the floating-point value, demonstrating how the original Double is represented and interpreted by the compiler.
---

## FEATURES
- `Scanf` implementation to take user input for evaluation
- Inspection of a `double` according to IEEE 754 format.
- Reveals Sign Exponet and Mantissa values
- Prints initial 64 bit representation in binary, 
- Reconstructs the `double` mimicing compiler behavior
- Classifies `double` as normal, subnormal, NAN, 0, or inf

---

## EXAMPLE OUTPUT

<img width="754" height="499" alt="Live Demo" src="https://github.com/user-attachments/assets/bfd8932d-7bc7-4011-aa7e-a66bbb1414b6" />

---

## Concepts Demonstrated

- C Programming
- Low-Level Memory Representation
- Bitwise Operations and Bit Manipulation
- IEEE 754 Floating-Point Standard
- Binary Number Representation
- Floating-Point Arithmetic
- Data Type Encoding and Decoding
- Memory Inspection Using `memcpy()`
- Handling Numerical Edge Cases

---

## Building

Compile with GCC

```bash
gcc -Wall -Wextra -Wpedantic -std=c11 doubledicer.c -o doubledicer -lm
```

Run

```bash
./doubledicer
```
---

## Future Improvements 
 Automatic reset withot restarting program for repeated use 
 More user-friendly scanf implementation
 

