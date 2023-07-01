#9) Codifique um programa correspondente ao seguinte código em c:
   
 #   int a = 3;
 #   int b = 4;
 #   int m = 10;
 #   m = a;
 #   if ( b < m )
 #       m = b;
   
#    printf("%i", m);
               
   
#Agora, teste a e b com outros valores.

.data
.text
main:

	li $t0, 3	#a=3
	li $t1, 4	#b=4
	li $t2, 10	#m=10
	
	blt $t1,$t2,muda
	move $a0, $t2
	
	li $v0,1
	syscall
	
	li $v0,10
	syscall
	
		
		
muda:
	move $t2,$t1
	move $a0, $t2
	
	li $v0,1
	syscall
	
	
	li $v0,10
	syscall
	


