#10) Codifique em assembly do mips um programa correspondente a :


    #int a = 2;
    #int b = 10;
    #x = 0;
    #if ( a >= 0 && b <= 50 )
      #   x = 1;
   # printf("%i", x);
#Agora, teste a e b com outros valores.

.data
.text
main:

	li $t0, 2	#a=2
	li $t1, 10	#b=10
	li $t2, 0	#x=0
	li $t3, 0	#auxiliar
	li $t4, 50	#auxiliar
	
	bge $t0,$t3 proximo
	li $v0, 1
	syscall
	
	li $v0, 10
	syscall
	
proximo:
	ble $t1,$4, troca
	li $v0, 1
	syscall
	
	li $v0, 10
	syscall
	
troca:
	addi $t2,$t2,1
	
	move $a0, $t2
	li $v0, 1
	syscall
	
	li $v0, 10
	syscall
