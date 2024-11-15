section .text
	global ft_strcmp

ft_strcmp:
	xor rax, rax
	xor rbx, rbx
	xor rcx, rcx

__loop:
	mov al, [rdi + rcx]
	mov bl, [rsi + rcx]

	cmp al, 0
	jz __check_s2

	cmp bl, 0
	jz __check_s1

	cmp al, bl
	jnz __get_diff

	inc rcx
	jmp __loop

__check_s2:
	cmp bl, 0
	jz __exit

	jmp __get_diff

__check_s1:
	cmp al, 0
	jz __exit

	jmp __get_diff

__get_diff:
	sub al, bl
	movsx rax, al
	jmp __exit

__exit:
	ret
