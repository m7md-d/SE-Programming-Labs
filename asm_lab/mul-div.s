.global _sum
.global _mul
.text

_sum:
    add x0, x0, x1
    ret
_mul:
    mul x0, x0, x1
    ret
