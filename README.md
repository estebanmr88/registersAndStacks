# C Stack-based Buffer Overflow and Flow Hijacking demonstration

This repository contains a classic, educational C program designed to demonstrate memory corruption vulnerabilities—specifically a **Stack-based Buffer Overflow** and a controlled **Format String information leak**. The code illustrates how unsafe memory operations can allow an attacker to overwrite local variables, corrupt the saved frame pointer, and hijack the return address to redirect execution flow to an uncalled function (`bar`).

### Vulnerability and mechanics breakdown

1. **Unvalidated Format String Leak:**
   * The program executes `printf("...\n%p\n%p\n%p...")` without providing corresponding arguments. Due to the C calling convention (`cdecl`), `printf` blindly reads consecutive 4-byte or 8-byte slots directly off the stack frame, serving as a rudimentary "stack dump" to view active memory layouts.

2. **Unsafe Memory Copy:**
   * A fixed-size local buffer is allocated on the stack. 
   * The program invokes `strcpy(buf, input)`, which is unsafe because it performs no bounds checking. It continues writing bytes into memory until it encounters a null-terminator.

3. **The exploit:**
   * By supplying an input string significantly larger, an operator can deliberately overrun `buf`, plow through the saved frame pointer, and overwrite the **saved return address** of the `foo` function.
   * When `foo` encounters its `ret` instruction, instead of returning cleanly to `main`, it jumps directly to the memory address of `bar()`, successfully hijacking the program's intended execution flow.

### ⚠️ Security Mitigation Note
This repository demonstrates legacy code weaknesses. Modern compilers mitigate these exploits using defenses such as **Stack Canaries (`-fstack-protector`)**, **ASLR (Address Space Layout Randomization)**, and the deprecation of legacy functions like `strcpy` in favor of bounds-checked alternatives like `strncpy` or `strlcpy`.
