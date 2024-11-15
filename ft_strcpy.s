section .text
	global ft_strcpy

ft_strcpy:
    lea rax, [rdi]
    xor rcx, rcx

_loop:
    mov bl, [rsi + rcx]
    mov [rdi + rcx], bl

    test bl, bl
    je _exit

    inc rcx

    jmp _loop

_exit:
    ret
