.data

.text
main:
	li $t0, 0   # fat = 0
	li $t1, 5   # n = 5

	li $t2, 1   # Inicializa fat com 1

loop:
	beqz $t1, end       # Verifica se n é igual a 0 (fim do loop)

	li $t3, 0   # Variável auxiliar para a soma

	add $t4, $t0, $t2   # Soma fat + 1 e armazena em $t4

loop2:
	add $t3, $t3, $t0   # Soma fat + fat e armazena em $t3
	subi $t1, $t1, 1     # Decrementa n por 1

	bnez $t1, loop2     # Verifica se n é diferente de 0 (continua o loop)

	add $t2, $t2, $t3   # Soma a variável auxiliar $t3 a fat e armazena em $t2

	move $t0, $t4       # Move o valor atualizado de $t4 para $t0 (fat)

	j loop

end:
	move $a0, $t2        # Move o resultado (fat) para $a0 para ser impresso
	li $v0, 1
	syscall

	li $v0, 10
	syscall

