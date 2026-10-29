#include "cpu.h"
#include "memory.h"
#include <assert.h>
#include <stdio.h>
#include <stdint.h>

void test_memory_operations() {
  SystemMemory mem;
  mem_init(&mem, MEMORY_SIZE);

  uint32_t test_addr = 0x100;
  uint32_t test_value = 0xDEADBEEF;

  mem_write32(&mem, test_addr, test_value);
  uint32_t read_value = mem_read32(&mem, test_addr);

  assert(read_value == test_value);

  assert(mem_read32(&mem, 0x104) == 0);

  mem_free(&mem);

  assert(mem.data == NULL);
  assert(mem.size == 0);
}

void test_cpu_get_x() {
  RISCVCPU cpu;

  uint8_t test_reg = 0x01;
  uint32_t test_value = 0xDEADBEEF;
  
  cpu_set_x(&cpu, test_reg, test_value);
  uint32_t cpu_get_x_value = cpu_get_x(&cpu, 0x01);

  assert(cpu_get_x_value == test_value);
}

void test_cpu_fetch() {
  SystemMemory mem;
  mem_init(&mem, MEMORY_SIZE);

  RISCVCPU cpu;
  cpu_init(&cpu, &mem);

  uint32_t test_addr = 0x100;
  uint32_t test_value = 0xDEADBEEF;

  mem_write32(&mem, test_addr, test_value);

  cpu_set_pc(&cpu, test_addr);

  uint32_t actual = cpu_fetch(&cpu);

  assert(actual == test_value);
  assert(cpu.pc == test_addr + 4);
}

int main() {
  test_cpu_get_x();
  test_memory_operations();
  test_cpu_fetch();
  
  return 0;
}
