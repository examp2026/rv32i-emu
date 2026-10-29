#ifndef MEMORY_H
#define MEMORY_H

#define MEMORY_SIZE (8 * 1024 * 1024)

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct SystemMemory{
  uint8_t *data;
  size_t size;
} SystemMemory;

bool mem_init(SystemMemory *mem, size_t size);
uint32_t mem_read32(SystemMemory *mem, uint32_t addr);
void mem_write32(SystemMemory *mem, uint32_t addr, uint32_t value);
void mem_free(SystemMemory *mem);

#endif
