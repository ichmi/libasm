extern __errno_location
extern ft_strlen
extern ft_strcpy
extern malloc

section .text
    global ft_strdup

ft_strdup:
    xor rcx, rcx

    call ft_strlen
    inc rax
    push rdi

    mov rdi, rax
    call malloc wrt ..plt
    cmp rax, 0
    jz _on_error

    pop rsi
    mov rdi, rax
    call ft_strcpy

    ret

_on_error:
    mov r8, rax
    call __errno_location wrt ..plt
    mov [rax], r8
    mov rax, -1
    ret
