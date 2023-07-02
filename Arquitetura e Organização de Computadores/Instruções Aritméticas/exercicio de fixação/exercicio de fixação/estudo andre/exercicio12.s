#12) A partir do código assembly do mips, ao qual implementa o programa a seguir:


#    int fat = 0;
#    int n = 5;
         
#    for(fat = 1; n > 1; n = n - 1)
#        fat = fat * n;
     
 #   printf("%d", fat);

#OBS: Não utilize a instrução MUL, faça a partir de sucessivas somas.


.data
.text
main:
    li $t0, 1     # Inicializa fat com 1
    li $t1, 5     # n = 5

fatorial:
    addi $t1, $t1, -1    # Decrementa n
    beqz $t1, imprime    # Se n = 0, imprime o resultado
    move $t2, $t0        # Salva o valor atual de fat em $t2
    move $t3, $t1        # Salva o valor atual de n em $t3

    loop:
    beqz $t3, fatorial   # Se n = 0, sai do loop
    add $t0, $t0, $t2    # Soma fat com o valor salvo em $t2
    addi $t3, $t3, -1    # Decrementa n
    j loop

imprime:
    move $a0, $t0    # Move fat para o argumento de impressão
    li $v0, 1        # Carrega o código de syscall para impressão
    syscall

    li $v0, 10       # Carrega o código de syscall para finalizar o programa
    syscall
