#11) Codifique em assembly do mips um programa correspondente a:


    #int i = 0;
    #int j = 10;
    #int k = 0;

   # while (i < j){

   #    i++;
   #     k +=10;

   # }


   # printf("%i", i);
    #printf("%i", k);
    
    
.data
.text
main:
	li $t0, 0	#i=0
	li $t1, 10	#j=10
	li $t2, 0	#k= 0

	
loop:
	beq $t0,$t1,saiLoop
	addi $t0,$t0, 1
	addi $t2,$t2,10	
	j loop
	
saiLoop:
	move $a0, $t0
	li $v0, 1
	syscall
	
	move $a0, $t2
	li $v0, 1
	syscall
	
	li $v0, 10
	syscall
	
	
