from tkinter import *
from tkinter import filedialog
import sys

class MIPSProcessorSimulator:
    def __init__(self):
        # Inicialização dos registradores, memória de dados, memória de instruções e contador de programa
        self.registers = [0] * 32
        self.data_memory = [0] * 1024
        self.instruction_memory = []
        self.pc = 0

        # Configuração da interface gráfica com tkinter
        self.window = Tk()
        self.window.title("MIPS Processor Simulator")

        # Configuração dos frames para registradores, memória e controles
        self.register_frame = Frame(self.window)
        self.register_frame.pack(side="left")

        self.memory_frame = Frame(self.window)
        self.memory_frame.pack(side="right")

        self.controls_frame = Frame(self.window)
        self.controls_frame.pack(side="bottom")

        # Configuração dos campos de texto para registradores e memória
        self.register_text = Text(self.register_frame, width=20)
        self.register_text.pack()

        self.memory_text = Text(self.memory_frame, width=40)
        self.memory_text.pack()

        # Configuração dos botões para executar, passar para o próximo passo e carregar programa
        self.run_button = Button(self.controls_frame, text="Run", command=self.run)
        self.run_button.pack(side="left")

        self.step_button = Button(self.controls_frame, text="Step", command=self.step)
        self.step_button.pack(side="left")

        self.load_button = Button(self.controls_frame, text="Load", command=self.load_program)
        self.load_button.pack(side="left")

    def load_program(self):
        # Função para carregar um programa em linguagem Assembly a partir de um arquivo
        filename = filedialog.askopenfilename(initialdir="./", title="Select a file", filetypes=(("Assembly files", ".asm"), ("All files", ".*")))
        
        with open(filename, 'r') as file:
            for line in file:
                line = line.strip()
        # Ignorar linhas de comentários ou em branco
                if line.startswith('#') or line == '':
                    continue
        # Substituir as vírgulas por espaços em branco
                line = line.replace(',', '')
        # Dividir a linha em tokens e adicionar à memória de instruções
                instruction = line.split()
                self.instruction_memory.append(instruction)

                

    def update_registers(self):
        # Atualiza o campo de texto para exibir os valores dos registradores
        self.register_text.delete(1.0, "end")
        for i, value in enumerate(self.registers):
            self.register_text.insert("end", f"$t{i}: {value}\n")

    def update_memory(self):
        # Atualiza o campo de texto para exibir os valores da memória de dados
        self.memory_text.delete(1.0, "end")
        for i, value in enumerate(self.data_memory):
            self.memory_text.insert("end", f"mem[{i}]: {value}\n")

    def run(self):
        # Executa o simulador até o final do programa
        while self.pc < len(self.instruction_memory):
            self.step()

    def step(self):
        # Executa uma instrução e atualiza o estado dos registradores e da memória
        if self.pc >= len(self.instruction_memory):
            return

        instruction = self.instruction_memory[self.pc]
        self.execute_instruction(instruction)
        self.pc += 1

        self.update_registers()
        self.update_memory()

    def execute_instruction(self, instruction):
        # Executa uma instrução específica com base no opcode
        opcode = instruction[0]
        
        if opcode == 'add':
            # Instrução ADD: Soma o valor de dois registradores e armazena no terceiro
            rd = int(instruction[1][2:])
            rs = int(instruction[2][2:])
            rt = int(instruction[3][2:])
            self.registers[rd] = self.registers[rs] + self.registers[rt]
            
        elif opcode == 'addi':
            # Instrução ADDI: Soma um valor imediato a um registrador
            rt = int(instruction[1][2:])
            rs = int(instruction[2][2:])
            immediate = int(instruction[3])
            self.registers[rt] = self.registers[rs] + immediate
            
        elif opcode == 'sub':
            # Instrução SUB: Subtrai o valor de dois registradores e armazena no terceiro
            rd = int(instruction[1][2:])
            rs = int(instruction[2][2:])
            rt = int(instruction[3][2:])
            self.registers[rd] = self.registers[rs] - self.registers[rt]
            
        elif opcode == 'subi':
            # Instrução SUBI: Subtrai um valor imediato de um registrador
            rt = int(instruction[1][2:])
            rs = int(instruction[2][2:])
            immediate = int(instruction[3])
            self.registers[rt] = self.registers[rs] - immediate
            
        elif opcode == 'mul':
            # Instrução MUL: Multiplica o valor de dois registradores e armazena no terceiro
            rd = int(instruction[1][2:])
            rs = int(instruction[2][2:])
            rt = int(instruction[3][2:])
            self.registers[rd] = self.registers[rs] * self.registers[rt]
            
        elif opcode == 'div':
            # Instrução DIV: Divide o valor de dois registradores e armazena no terceiro
            rd = int(instruction[1][2:])
            rs = int(instruction[2][2:])
            rt = int(instruction[3][2:])
            self.registers[rd] = self.registers[rs] // self.registers[rt]
            
        elif opcode == 'and':
            # Instrução AND: Realiza uma operação de AND bit a bit entre dois registradores e armazena no terceiro
            rd = int(instruction[1][2:])
            rs = int(instruction[2][2:])
            rt = int(instruction[3][2:])
            self.registers[rd] = self.registers[rs] & self.registers[rt]
            
        elif opcode == 'or':
            # Instrução OR: Realiza uma operação de OR bit a bit entre dois registradores e armazena no terceiro
            rd = int(instruction[1][2:])
            rs = int(instruction[2][2:])
            rt = int(instruction[3][2:])
            self.registers[rd] = self.registers[rs] | self.registers[rt]
            
        elif opcode == 'xor':
            # Instrução XOR: Realiza uma operação de XOR bit a bit entre dois registradores e armazena no terceiro
            rd = int(instruction[1][2:])
            rs = int(instruction[2][2:])
            rt = int(instruction[3][2:])
            self.registers[rd] = self.registers[rs] ^ self.registers[rt]
            
        elif opcode == 'nor':
            # Instrução NOR: Realiza uma operação de NOR bit a bit entre dois registradores e armazena no terceiro
            rd = int(instruction[1][2:])
            rs = int(instruction[2][2:])
            rt = int(instruction[3][2:])
            self.registers[rd] = ~(self.registers[rs] | self.registers[rt])
            
        elif opcode == 'slt':
            # Instrução SLT: Compara dois registradores e armazena 1 em rd se o primeiro for menor que o segundo, caso contrário, armazena 0
            rd = int(instruction[1][2:])
            rs = int(instruction[2][2:])
            rt = int(instruction[3][2:])
            self.registers[rd] = 1 if self.registers[rs] < self.registers[rt] else 0
            
        elif opcode == 'sll':
            # Instrução SLL: Desloca para a esquerda o valor de um registrador de acordo com o valor de shamt
            rd = int(instruction[1][2:])
            rs = int(instruction[2][2:])
            shamt = int(instruction[3])
            self.registers[rd] = self.registers[rs] << shamt
            
        elif opcode == 'sra':
            # Instrução SRA: Deslocard = int(instruction[1][2:])
            rs = int(instruction[2][2:])
            shamt = int(instruction[3])
            self.registers[rd] = self.registers[rs] >> shamt
            
        elif opcode == 'li':
        # Instrução LI: Carrega um valor imediato em um registrador
            rt = int(instruction[1][2:])
            immediate = int(instruction[2])
            self.registers[rt] = immediate
            
        elif opcode == 'lw':
        # Instrução LW: Carrega uma palavra da memória
            rt = int(instruction[1][2:])
            offset = int(instruction[2].split('(')[0])
            base = int(instruction[2].split('(')[1][2:-1])
            address = self.registers[base] + offset
            self.registers[rt] = self.data_memory[address]
            
        elif opcode == 'sw':
        # Instrução SW: Armazena uma palavra na memória
            rt = int(instruction[1][2:])
            offset = int(instruction[2].split('(')[0])
            base = int(instruction[2].split('(')[1][2:-1])
            address = self.registers[base] + offset
            self.data_memory[address] = self.registers[rt]
            
        elif opcode == 'lb':
        # Instrução LB: Carrega um byte da memória
            rt = int(instruction[1][2:])
            offset = int(instruction[2].split('(')[0])
            base = int(instruction[2].split('(')[1][2:-1])
            address = self.registers[base] + offset
            self.registers[rt] = self.data_memory[address]
            
        elif opcode == 'sb':
        # Instrução SB: Armazena um byte na memória
            rt = int(instruction[1][2:])
            offset = int(instruction[2].split('(')[0])
            base = int(instruction[2].split('(')[1][2:-1])
            address = self.registers[base] + offset
            self.data_memory[address] = self.registers[rt] & 0xFF
            
        elif opcode == 'beq':
            # Instrução BEQ: Pula para o rótulo indicado se o conteúdo de dois registradores forem iguais
            rs = int(instruction[1][2:])
            rt = int(instruction[2][2:])
            label = instruction[3]
            if self.registers[rs] == self.registers[rt]:
                jump_address = self.labels[label]
                self.program_counter = jump_address
                
        elif opcode == 'bne':
            # Instrução BNE: Pula para o rótulo indicado se o conteúdo de dois registradores forem diferentes
            rs = int(instruction[1][2:])
            rt = int(instruction[2][2:])
            label = instruction[3]
            if self.registers[rs] != self.registers[rt]:
                jump_address = self.labels[label]
                self.program_counter = jump_address
                
        elif opcode == 'bgt':
            # Instrução BGT: Pula para o rótulo indicado se o conteúdo de um registrador for maior que o conteúdo de outro registrador
            rs = int(instruction[1][2:])
            rt = int(instruction[2][2:])
            label = instruction[3]
            if self.registers[rs] > self.registers[rt]:
                jump_address = self.labels[label]
                self.program_counter = jump_address
                
        elif opcode == 'bez':
            # Instrução BEZ: Pula para o rótulo indicado se o conteúdo de um registrador for igual a zero
            rs = int(instruction[1][2:])
            label = instruction[2]
            if self.registers[rs] == 0:
                jump_address = self.labels[label]
                self.program_counter = jump_address
        
        elif opcode == 'j':
            # Instrução J: Salto incondicional para o rótulo indicado
            label = instruction[1]
            jump_address = self.labels[label]
            self.program_counter = jump_address
            
        elif opcode == 'jr':
            # Instrução JR: Salto incondicional para o endereço contido em um registrador
            rs = int(instruction[1][2:])
            jump_address = self.registers[rs]
            self.program_counter = jump_address
            
        elif opcode == 'ja':
            # Instrução JA: Salto incondicional para o endereço absoluto
            address = int(instruction[1])
            self.program_counter = address
            
        elif opcode == 'syscall':
            # Instrução SYSCALL: Executa uma chamada de sistema
            call_number = self.registers[2]  # Registrador $v0 contém o número da chamada de sistema
            if call_number == 1:
                # Print integer
                value_to_print = self.registers[4]  # Registrador $a0 contém o valor a ser impresso
                print(value_to_print)
            elif call_number == 10:
                # Exit the program
                sys.exit()
        else:
            print("Invalid instruction!")    
        

    def simulate(self):
        # Inicia o loop de eventos da interface gráfica
        self.window.mainloop()

# Cria uma instância do simulador e inicia a simulação
simulator = MIPSProcessorSimulator()
simulator.simulate()
