# asm_lab

Calling assembly functions (`sum`, `mul`) from C on macOS, implemented for both ARM64 and x86-64.

`sub` and `div` stay in C; `sum` and `mul` are written in assembly to exercise the calling convention and linking process across architectures.

## Files

| File | Role |
|---|---|
| `main.c` | Shared C driver — declares `sum`/`mul` as extern, implements `sub`/`div`, calls all four |
| `mul-div.s` | ARM64 assembly — `sum` and `mul` via `x0`/`x1` registers |
| `mul-div.asm` | x86-64 assembly — `sum` and `mul` via `edi`/`esi` registers |

## Build & Run

**ARM64:**

```sh
gcc mul-div.s main.c -o asm
./asm
```

**x86-64:**

```sh
nasm -f macho64 mul-div.asm -o asm_64bit.o
gcc -arch x86_64 -c main.c -o main.o
gcc -arch x86_64 main.o asm_64bit.o -o program_64
./program_64
```

## What differs between the two assembly files

The C interface is identical. The assembly differs in:

- **Assembler**: GAS (`.s`) vs NASM (`.asm`) — different directive syntax (`.global` vs `global`, `.text` vs `section .text`)
- **Registers**: ARM64 passes args in `x0`/`x1`; x86-64 uses `edi`/`esi`
- **Stack frame**: ARM64 leaf functions need no frame setup; x86-64 uses `rbp` prologue/epilogue
- **Instructions**: `add`/`mul` on ARM64 are 3-operand; x86-64 uses 2-operand `add`/`imul`
