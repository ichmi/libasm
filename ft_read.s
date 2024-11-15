extern __errno_location

section .text
    global ft_read

ft_read:
    mov rax, 0
    syscall
    test rax, rax
    js _on_error
    ret

_on_error:
    mov r8, rax
    call __errno_location wrt ..plt
    mov [rax], r8
    mov rax, -1
    ret
