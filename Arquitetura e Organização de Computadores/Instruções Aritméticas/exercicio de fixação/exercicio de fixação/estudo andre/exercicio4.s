#4) Salve na memória o valor 100, na posição 20 usando como base o registrador $zero. Depois salve 200 na posição 40.

.data
	array:
	.align 2
	.space 160
	
.text
main:
	li $t0, 100	#valor 100
	li $t1, 200	#valor 200
	
	li $t2, 80	#posição 20 do array
	li $t3, 160	#posição 40 do array
	move $t4, $zero #indice do array
	
		
loop:
		beq $t4,$t2, salva1
		addi $t4,$t4,4 #aumenta o contador
	j loop
	
salva1:
	sw, $t0,array($t4)
	
loop2:
	beq $t4, $t3, salva2
	addi $t4,$t4,4 #aumenta o contador
	j loop2
		

salva2:
	sw,$t1,array($t4)
	
	li $v0,10
	syscall

