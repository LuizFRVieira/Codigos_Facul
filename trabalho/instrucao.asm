# Test.asm

# Inicializando valores
ADDI $r1 $r1 5     # $r1 = 5
ADDI $r2 $r2 3     # $r2 = 3

# Realizando operações
ADD $r3 $r1 $r2      # $r3 = $r1 + $r2
SUB $r4 $r1 $r2      # $r4 = $r1 - $r2

# Imprimindo resultados
ADDI $v0 $v0 1     # Configura $v0 para a chamada de sistema de impressão
ADD $a0 $a0 $r3    # Coloca $r3 no registrador de argumento $a0
SYSCALL               # Chama o sistema para imprimir o valor em $a0

ADDI $v0 $v0 1     # Configura $v0 para a chamada de sistema de impressão
ADD $a0 $a0 $r4    # Coloca $r4 no registrador de argumento $a0
SYSCALL               # Chama o sistema para imprimir o valor em $a0

# Termina o programa
ADDI $v0 $v0 10    # Configura $v0 para a chamada de sistema de saída
SYSCALL               # Chama o sistema para encerrar o programa


