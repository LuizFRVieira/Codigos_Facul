#Faça um programa, em assembly do mips, para somar dois vetores (V1 e V2) onde:

       # v1 = {10,20,30,40,50,60}

      #  v2 = {0,10,-15, 16, 20, 30}

#O programa deverá percorrer os dois vetores somando cada elemento e colocando os mesmos no vetor resultante.

#A saída desejada é apresentada a seguir:

   #A soma dos vetores v0 e v1 é:

   #10, 30, 15, 56, 70, 90


.data
	msg: .asciiz "A soma dos vetores v0 e v1 é:\n"
	virgula: .asciiz ", "
	v1: .word 10, 20, 30, 40, 50, 60
	v2: .word 0, 10, -15, 16, 20, 30
	v3: .word 0, 0, 0, 0, 0, 0
.text
main:
	la $t0, v1	#joga o vetor 1 no lugar do t0
	la $t1, v2	#joga o votero 2 no lugar de t1
	la $t2, v3	#joga o resultado no t2
	li $t3, 0	
	li $t4, 6
loop:
	lw $s0, 0($t0)
	lw $s1, 0($t1)
	add $s2, $s0,$s1
	sw $s2,0($t2)
 
	addi, $t0, $t0,4
	addi, $t1, $t1,4
	addi, $t2, $t2,4
	addi $t3, $t3,1 
	
blt $t3,$t4, loop

	li $v0,4
	la $a0, msg
	syscall
	
	li $t3, 0
	la $t2, v3

imprime:
	lw $s0,0($t2)
	li $v0,1
	move $a0, $s0
	syscall

	li $v0,4
	la $a0, virgula
	syscall

	addi $t2, $t2, 4
	addi $t3, $t3, 1
	
blt $t3,$t4,imprime
	
	li $v0,10
	syscall



	
