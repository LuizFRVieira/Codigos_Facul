12) A partir do código assembly do mips, ao qual implementa o programa a seguir:


#    int fat = 0;
#    int n = 5;
         
#    for(fat = 1; n > 1; n = n - 1)
#        fat = fat * n;
     
 #   printf("%d", fat);

#OBS: Não utilize a instrução MUL, faça a partir de sucessivas somas.

.data
.text
main:
	li $t0,0	#fat=0
	li $t1,5	#n=5
	li $t2,0	#auxiliar
	
	addi $t0,$t0, 1 
	
loop:
	bgt $t1,$t2, imprime
	
	
	
	addi , $t1, -1		#faz a decrementção do
jloop:
	
	
imprime:

