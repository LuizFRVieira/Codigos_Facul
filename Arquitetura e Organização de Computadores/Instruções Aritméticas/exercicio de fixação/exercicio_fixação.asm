
#Faça um programa, em assembly do mips, para somar dois vetores (V1 e V2) onde:
#        v1 = {10,20,30,40,50,60}
#        v2 = {0,10,-15, 16, 20, 30}
# O programa deverá percorrer os dois vetores somando cada elemento e colocando os mesmos no vetor resultante.
# A saída desejada é apresentada a seguir:
#  A soma dos vetores v0 e v1 é:
#   10, 30, 15, 56, 70, 90

.data
str: .asciiz "A soma dos vetores é \n \n"
spc: .asciiz ", "
v1: .word 1 2 3 4 5 6 
v2: .word 7 8 9 10 11 12



.text

    main:

    la		$s0, $v1
    la		$s1, $v2		
    la		$s2, $v3		
    li		$t0,  6 	#j
    li		$t1,  0	    #i
    
    while:
    beq		$t0, $zero, imprimir
    sll		$t2, $t1, 2			

    add		$t3, $s0, $t2		# &v1[i]
    lw		$t4, 0($t3)		    #t4 = v1[i]

    add		$t3, $s1, $t2		# &v2[i]
    lw		$t5, 0($t3)		    #t5 = v2[i]

    add		$t4, $t4, $t5		

    add		$t3, $s2, $t2		#&v3[i]
    sw		$t4, 0($t3)		
    
    addi	$t1, $t1, 1	
    addi    $t0, $t0, -1

    j while
    

    imprimir:

        la		$a0, str	
        li		$v0, 4		#codigo syscall
        syscall

        
imprimirVetorResul:
    beq		$t1, $zero, sair	
    sll		$t2, $t1, 2	

    add		$t3, $s2, $t2	# &v3[i]
    lw		$t4, 0($t3)		 
    
    move 	$a0, $t4
    li		$v0, 	1	    # codigo syscall 
    syscall

    la		$a0, spc		# 
    li		$v0, 	4	    # codigo syscall
    syscall
    
    addi	$t1, $t1, -1			
    addi	$t0, $t0, 1			
    

    j		imprimirVetorResul	
    
    

sair:    
li		$v0, 10		# codigo syscall pra sair do programa
syscall
    