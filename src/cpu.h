#ifndef CPU_H
#define CPU_H

#include "memory.h"
#include <stdint.h>

typedef struct RISCVCPU {
  uint32_t x [32];
  uint32_t pc;
  SystemMemory *mem;
}RISCVCPU;

uint32_t cpu_get_x (RISCVCPU *cpu, int reg);
void cpu_set_x (RISCVCPU *cpu, int reg, uint32_t value);

uint32_t cpu_get_pc (RISCVCPU *cpu);
void cpu_set_pc (RISCVCPU *cpu, uint32_t pointer);

void cpu_init(RISCVCPU *cpu, SystemMemory *mem);

uint32_t cpu_fetch(RISCVCPU *cpu);

#endif
