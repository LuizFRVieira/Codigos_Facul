from tkinter import *
from tkinter import filedialog
import sys

class MIPSProcessorSimulator:
    def __init__(self):
        # Inicializa registradores, memória de dados e memória de instruções
        self.registers = [0] * 32
        self.data_memory = [0] * 1024
        self.instruction_memory = []
        self.pc = 0  # contador de programa

        # Configura interface gráfica
        self.window = Tk()
        self.window.title("Simulador de Processador MIPS")

        # Frames para registradores, memória e controles
        self.register_frame = Frame(self.window)
        self.register_frame.pack(side="left")

        self.memory_frame = Frame(self.window)
        self.memory_frame.pack(side="right")

        self.controls_frame = Frame(self.window)
        self.controls_frame.pack(side="bottom")

        # Campos de texto para mostrar registradores e memória
        self.register_text = Text(self.register_frame, width=20)
        self.register_text.pack()

        self.memory_text = Text(self.memory_frame, width=40)
        self.memory_text.pack()

        # Botões para rodar, passo a passo e carregar programa
        self.run_button = Button(self.controls_frame, text="Run", command=self.run)
        self.run_button.pack(side="left")

        self.step_button = Button(self.controls_frame, text="Step", command=self.step)
        self.step_button.pack(side="left")

        self.load_button = Button(self.controls_frame, text="Load", command=self.load_program)
        self.load_button.pack(side="left")

    def load_program(self):
        # Carrega programa Assembly (.asm) para memória de instruções
        filename = filedialog.askopenfilename(
            initialdir="./", title="Selecionar arquivo",
            filetypes=(("Arquivos Assembly", ".asm"), ("Todos os arquivos", ".*"))
        )
        
        with open(filename, 'r') as file:
            for line in file:
                line = line.strip()
                if line.startswith('#') or line == '':  # ignora comentários e linhas vazias
                    continue
                line = line.replace(',', '')  # remove vírgulas
                instruction = line.split()  # separa tokens
                self.instruction_memory.append(instruction)

    def update_registers(self):
        # Atualiza display dos registradores
        self.register_text.delete(1.0, "end")
        for i, value in enumerate(self.registers):
            self.register_text.insert("end", f"$t{i}: {value}\n")

    def update_memory(self):
        # Atualiza display da memória de dados
        self.memory_text.delete(1.0, "end")
        for i, value in enumerate(self.data_memory):
            self.memory_text.insert("end", f"mem[{i}]: {value}\n")

    def run(self):
        # Executa todas as instruções
        while self.pc < len(self.instruction_memory):
            self.step()

    def step(self):
        # Executa uma instrução e atualiza registradores/memória
        if self.pc >= len(self.instruction_memory):
            return

        instruction = self.instruction_memory[self.pc]
        self.execute_instruction(instruction)
        self.pc += 1

        self.update_registers()
        self.update_memory()

    def execute_instruction(self, instruction):
        # Executa instrução com base no opcode
        opcode = instruction[0]
        
        if opcode == 'add':
            # Soma dois registradores
            rd = int(instruction[1][2:])
            rs = int(instruction[2][2:])
            rt = int(instruction[3][2:])
            self.registers[rd] = self.registers[rs] + self.registers[rt]
            
        elif opcode == 'addi':
            # Soma valor imediato a registrador
            rt = int(instruction[1][2:])
            rs = int(instruction[2][2:])
            immediate = int(instruction[3])
            self.registers[rt] = self.registers[rs] + immediate
            
        elif opcode == 'sub':
            # Subtração
            rd = int(instruction[1][2:])
            rs = int(instruction[2][2:])
            rt = int(instruction[3][2:])
            self.registers[rd] = self.registers[rs] - self.registers[rt]
            
        elif opcode == 'subi':
            # Subtração com imediato
            rt = int(instruction[1][2:])
            rs = int(instruction[2][2:])
            immediate = int(instruction[3])
            self.registers[rt] = self.registers[rs] - immediate
            
        elif opcode == 'mul':
            # Multiplicação
            rd = int(instruction[1][2:])
            rs = int(instruction[2][2:])
            rt = int(instruction[3][2:])
            self.registers[rd] = self.registers[rs] * self.registers[rt]
            
        elif opcode == 'div':
            # Divisão inteira
            rd = int(instruction[1][2:])
            rs = int(instruction[2][2:])
            rt = int(instruction[3][2:])
            self.registers[rd] = self.registers[rs] // self.registers[rt]
            
        elif opcode == 'and':
            # AND bit a bit
            rd = int(instruction[1][2:])
            rs = int(instruction[2][2:])
            rt = int(instruction[3][2:])
            self.registers[rd] = self.registers[rs] & self.registers[rt]
            
        elif opcode == 'or':
            # OR bit a bit
            rd = int(instruction[1][2:])
            rs = int(instruction[2][2:])
            rt = int(instruction[3][2:])
            self.registers[rd] = self.registers[rs] | self.registers[rt]
            
        elif opcode == 'xor':
            # XOR bit a bit
            rd = int(instruction[1][2:])
            rs = int(instruction[2][2:])
            rt = int(instruction[3][2:])
            self.registers[rd] = self.registers[rs] ^ self.registers[rt]
            
        elif opcode == 'nor':
            # NOR bit a bit
            rd = int(instruction[1][2:])
            rs = int(instruction[2][2:])
            rt = int(instruction[3][2:])
            self.registers[rd] = ~(self.registers[rs] | self.registers[rt])
            
        elif opcode == 'slt':
            # Set if less than (1 se rs < rt, senão 0)
            rd = int(instruction[1][2:])
            rs = int(instruction[2][2:])
            rt = int(instruction[3][2:])
            self.registers[rd] = 1 if self.registers[rs] < self.registers[rt] else 0
            
        elif opcode == 'sll':
            # Shift left lógico
            rd = int(instruction[1][2:])
            rs = int(instruction[2][2:])
            shamt = int(instruction[3])
            self.registers[rd] = self.registers[rs] << shamt
            
        elif opcode == 'sra':
            # Shift right aritmético
            rd = int(instruction[1][2:])
            rs = int(instruction[2][2:])
            shamt = int(instruction[3])
            self.registers[rd] = self.registers[rs] >> shamt
            
        elif opcode == 'li':
            # Load imediato
            rt = int(instruction[1][2:])
            immediate = int(instruction[2])
            self.registers[rt] = immediate
            
        elif opcode == 'lw':
            # Load word da memória
            rt = int(instruction[1][2:])
            offset = int(instruction[2].split('(')[0])
            base = int(instruction[2].split('(')[1][2:-1])
            address = self.registers[base] + offset
            self.registers[rt] = self.data_memory[address]
            
        elif opcode == 'sw':
            # Store word na memória
            rt = int(instruction[1][2:])
            offset = int(instruction[2].split('(')[0])
            base = int(instruction[2].split('(')[1][2:-1])
            address = self.registers[base] + offset
            self.data_memory[address] = self.registers[rt]
            
        elif opcode == 'lb':
            # Load byte
            rt = int(instruction[1][2:])
            offset = int(instruction[2].split('(')[0])
            base = int(instruction[2].split('(')[1][2:-1])
            address = self.registers[base] + offset
            self.registers[rt] = self.data_memory[address]
            
        elif opcode == 'sb':
            # Store byte
            rt = int(instruction[1][2:])
            offset = int(instruction[2].split('(')[0])
            base = int(instruction[2].split('(')[1][2:-1])
            address = self.registers[base] + offset
            self.data_memory[address] = self.registers[rt] & 0xFF
            
        elif opcode == 'beq':
            # Branch se igual
            rs = int(instruction[1][2:])
            rt = int(instruction[2][2:])
            label = instruction[3]
            if self.registers[rs] == self.registers[rt]:
                jump_address = self.labels[label]
                self.program_counter = jump_address
                
        elif opcode == 'bne':
            # Branch se diferente
            rs = int(instruction[1][2:])
            rt = int(instruction[2][2:])
            label = instruction[3]
            if self.registers[rs] != self.registers[rt]:
                jump_address = self.labels[label]
                self.program_counter = jump_address
                
        elif opcode == 'bgt':
            # Branch se maior
            rs = int(instruction[1][2:])
            rt = int(instruction[2][2:])
            label = instruction[3]
            if self.registers[rs] > self.registers[rt]:
                jump_address = self.labels[label]
                self.program_counter = jump_address
                
        elif opcode == 'bez':
            # Branch se zero
            rs = int(instruction[1][2:])
            label = instruction[2]
            if self.registers[rs] == 0:
                jump_address = self.labels[label]
                self.program_counter = jump_address
        
        elif opcode == 'j':
            # Jump incondicional
            label = instruction[1]
            jump_address = self.labels[label]
            self.program_counter = jump_address
            
        elif opcode == 'jr':
            # Jump para endereço em registrador
            rs = int(instruction[1][2:])
            jump_address = self.registers[rs]
            self.program_counter = jump_address
            
        elif opcode == 'ja':
            # Jump absoluto
            address = int(instruction[1])
            self.program_counter = address
            
        elif opcode == 'syscall':
            # Chamadas de sistema (print, exit)
            call_number = self.registers[2]  # $v0
            if call_number == 1:
                value_to_print = self.registers[4]  # $a0
                print(value_to_print)
            elif call_number == 10:
                sys.exit()
        else:
            print("Instrução inválida!")    

    def simulate(self):
        # Inicia loop do Tkinter
        self.window.mainloop()

# Cria simulador e inicia
simulator = MIPSProcessorSimulator()
simulator.simulate()