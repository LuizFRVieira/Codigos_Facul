#3) Faça um programa, em assembly do MIPS, para colocar o valor 5 na posição 10 da memória. Agora coloque o valor 20 na posição 40 da memória.  Some os conteúdos que estão na memória (5+20), e coloque o #resultado na posição 100 da memória.

.data 
	array:
	.align 2
	.space 400
.text
main:
	li $t0, 5
	li $t1, 20
	
	li $t2, 40
	li $t3, 160
	li $t4, 400
	
	sw $t0,array($t2)
	sw $t1,array($t3)
	
	add $t5,$t0,$t1
	
	
	sw $t5,array($t4)
	
	move $a0, $t5
	li $v0, 1
	syscall
	
	li $v0,10
	syscall
