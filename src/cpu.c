#include "cpu.h"
#include <stdio.h>

uint32_t cpu_get_x (RISCVCPU *cpu, int reg) {
  if(reg == 0) {
    return 0;
  }

  return (*cpu).x[reg];
}

void cpu_set_x (RISCVCPU *cpu, int reg, uint32_t value) {
  if(reg == 0) {
    return;
}

  (*cpu).x[reg] = value;
}

uint32_t cpu_get_pc(RISCVCPU *cpu) {
  return (*cpu).pc;
}

void cpu_set_pc(RISCVCPU *cpu, uint32_t pointer) {
  (*cpu).pc = pointer;
}

void cpu_init(RISCVCPU *cpu, SystemMemory *mem) {
  (*cpu).pc = 0;
  (*cpu).mem = mem;
  for(int i = 0; i < 32; i++){
    (*cpu).x[i] = 0;
  }
}

uint32_t cpu_fetch(RISCVCPU *cpu) {
  uint32_t instruction = mem_read32((*cpu).mem, (*cpu).pc);
  (*cpu).pc += 4;

  return instruction;
}
