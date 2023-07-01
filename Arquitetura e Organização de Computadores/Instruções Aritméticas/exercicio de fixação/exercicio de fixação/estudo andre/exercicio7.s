.data
	msg: .asciiz "Digite o primeiro número inteiro: "
	msg2: .asciiz "Digite o segundo número inteiro: "

.text
main:
	li $v0, 4             # Código da syscall para imprimir string
	la $a0, msg           # Carrega o endereço da primeira mensagem para imprimir
	syscall

	li $v0, 5             # Código da syscall para ler um número inteiro
	syscall
	move $t0, $v0         # Move o valor lido para o registrador $t0

	li $v0, 4             # Código da syscall para imprimir string
	la $a0, msg2          # Carrega o endereço da segunda mensagem para imprimir
	syscall

	li $v0, 5             # Código da syscall para ler um número inteiro
	syscall
	move $t1, $v0         # Move o valor lido para o registrador $t1

	beq $t0, $t1, igual   # Compara se os valores são iguais. Se sim, pula para a etiqueta 'igual'
	bgt $t0, $t1, primeiro_maior # Compara se o primeiro valor é maior que o segundo. Se sim, pula para a etiqueta 'primeiro_maior'

	move $a0, $t1         # Move o segundo valor para imprimir no registrador $a0
	li $v0, 1             # Código da syscall para imprimir um número inteiro
	syscall

	li $v0, 10            # Código da syscall para encerrar o programa
	syscall


igual:
	li $t2, -111

	move $a0, $t2         # Move o valor -111 para imprimir no registrador $a0
	li $v0, 1             # Código da syscall para imprimir um número inteiro
	syscall

	li $v0, 10            # Código da syscall para encerrar o programa
	syscall

primeiro_maior:
	move $a0, $t0         # Move o primeiro valor para imprimir no registrador $a0
	li $v0, 1             # Código da syscall para imprimir um número inteiro
	syscall
	
	li $v0, 10            # Código da syscall para encerrar o programa
	syscall



