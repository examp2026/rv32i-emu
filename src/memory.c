#include "memory.h"
#include <stdlib.h>
#include <stdio.h>

bool mem_init(SystemMemory *mem, size_t size) {
  (*mem).data = (uint8_t *)malloc(size);
  if((*mem).data == NULL) {
    return false;
  }
  
  (*mem).size = size;
  return true;
}

uint32_t mem_read32(SystemMemory *mem, uint32_t addr) {
  if(addr + 4 > (*mem).size) {
    fprintf(stderr, "Memory out of bounds at address: 0x08X\n");
    return 0;
  }

  if(addr % 4 != 0) {
    fprintf(stderr, "Misaligned memory read address: 0x%08X\n", addr);
    return 0;
  }

  return *(uint32_t *)&mem->data[addr];
}

void mem_write32(SystemMemory *mem, uint32_t addr, uint32_t value) {
  if(addr + 4 > (*mem).size) {
    fprintf(stderr, "Memory out of bounds at address: 0x08X\n");
    return;
  }

  if(addr % 4 != 0) {
    fprintf(stderr, "Misaligned memory read address: 0x%08X\n", addr);
    return;
  }

  *(uint32_t *)&mem->data[addr] = value;
}

void mem_free(SystemMemory *mem) {
  if(mem->data != NULL) {
    free(mem->data);
    mem->data = NULL;
    mem->size = 0;
  }
}
