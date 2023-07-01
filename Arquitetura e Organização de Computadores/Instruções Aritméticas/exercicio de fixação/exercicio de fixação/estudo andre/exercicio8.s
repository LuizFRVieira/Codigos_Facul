#8) Faça um programa, em assembly do MIPS, que receba e multiplique dois inteiros sem usar a instrução de multiplicação do MIPS. Imprima o resultado na tela.

.data
	msg: .asciiz "Digite o primeiro número: "
	msg2: .asciiz "Digite o segundo número inteiro: "

.text
main:
	li $t0, 0            # Variável para armazenar o primeiro número
	li $t1, 0            # Variável para armazenar o segundo número
	li $t2, 0            # Variável auxiliar para multiplicação

	li $v0, 4            # Código da syscall para imprimir string
	la $a0, msg          # Carrega o endereço da primeira mensagem para imprimir
	syscall

	li $v0, 5            # Código da syscall para ler um número inteiro
	syscall
	move $t0, $v0        # Armazena o primeiro número em $t0

	li $v0, 4            # Código da syscall para imprimir string
	la $a0, msg2         # Carrega o endereço da segunda mensagem para imprimir
	syscall

	li $v0, 5            # Código da syscall para ler um número inteiro
	syscall
	move $t1, $v0        # Armazena o segundo número em $t1

	li $t3, 0            # Variável para armazenar o resultado da multiplicação

	loop:
		beq $t2, $t1, imprime  # Se $t2 for igual a $t1, imprime o resultado
		add $t3, $t3, $t0      # Soma $t0 em $t3 para multiplicação
		addi $t2, $t2, 1       # Incrementa o contador
		j loop

	imprime:
		move $a0, $t3        # Move o resultado da multiplicação para $a0 para imprimir
		li $v0, 1            # Código da syscall para imprimir inteiro
		syscall

	li $v0, 10             # Código da syscall para encerrar o programa
	syscall

