#6) Faça um programa, em assembly do mips, que receba um valor inteiro do teclado, se esse valor for igual a 10 imprima-o na tela e saia do programa. Senão imprima 0 e saia do programa

.data
	msg: .asciiz "Digite um número: "

.text
main:
	li $t0, 10 #valor a ser comparado
	li $t2, 0 # valor para imprimir caso sera diferente de 10
	
	li $v0,4	#codigo syscall
	la $a0,msg	#carrega a mensagen
	syscall
	
	li $v0, 5 #codigo syscall para recber valor
	syscall
	
	move $t1, $v0	#carega o valor pro t1
	
	beq $t1,$t0,imprime
	
	li $v0, 1
	move $a0, $t2
	syscall
	
	li $v0, 10
	syscall
	
	
imprime:
	li $v0, 1
	move $a0, $t0
	syscall
	
	li $v0, 10
	syscall
	
