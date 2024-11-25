extern malloc

section .text
	global ft_list_push_front

ft_list_push_front:
	push rdi
	push rsi

	mov rdi, 16
    call malloc wrt ..plt
	test rax, rax
	jz _on_error

	pop rsi
	mov [rax], rsi
	xor rsi, rsi

	pop rdi
	mov rdx, [rdi]
	mov [rax + 8], rdx
	mov [rdi], rax
	ret

_on_error:
	xor rax, rax
    ret
