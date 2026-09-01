global _sum, _mul
section .text

_sum:
    push rbp
    mov rbp, rsp

    mov eax, edi
    add eax, esi

    mov rsp, rbp
    pop rbp
    ret

_mul:
    push rbp
    mov rbp, rsp

    mov eax, edi
    imul eax, esi

    mov rsp, rbp
    pop rbp
    ret