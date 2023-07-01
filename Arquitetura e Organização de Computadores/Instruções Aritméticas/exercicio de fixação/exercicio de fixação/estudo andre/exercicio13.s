.data
    vetor:  .word 3, 0, 1, 2, -6, -2, 4, 10, 3, 7, 8, -9, -15, -20, -87, -100
    msg1:   .asciiz "Seja bem vindo!\nPor favor entre com um valor inteiro para pesquisar no vetor:\n\n"
    msg2:   .asciiz "Elemento encontrado: "
    msg3:   .asciiz "Elemento não encontrado\n\n"

.text
main:
    li $v0, 4
    la $a0, msg1
    syscall
    
    li $v0, 5
    syscall
    move $t0, $v0   # Salva o valor digitado em $t0
    
    la $t1, vetor    # Endereço inicial do vetor
    li $t2, 0       # Inicializa o índice
    
loop:
    lw $t3, ($t1)    # Carrega o valor do vetor[$t1] em $t3
    
    beq $t3, -100, not_found   # Verifica se o valor é -100, se for, não encontrado
    
    beq $t3, $t0, found   # Verifica se o valor é igual ao elemento pesquisado
    
    addi $t1, $t1, 4   # Atualiza o endereço do vetor
    addi $t2, $t2, 1   # Atualiza o índice
    j loop
    
found:
    li $v0, 4
    la $a0, msg2
    syscall
    
    li $v0, 1
    move $a0, $t0
    syscall
    
    li $v0, 10
    syscall
    
not_found:
    li $v0, 4
    la $a0, msg3
    syscall
    
    li $v0, 10
    syscall

