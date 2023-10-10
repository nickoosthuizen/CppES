#include "NesMemory.hpp"

#include "stdint.h"

NesMemory::NesMemory() {
  this->memory = new uint8_t[NES_MEMORY_SIZE];
}

NesMemory::~NesMemory() {
  delete this->memory;
}

uint8_t NesMemory::getByte(uint16_t pc) {
  return this->memory[pc];
}