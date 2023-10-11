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

uint16_t NesMemory::getTwoByteLittleEndian(uint16_t pc) {
  uint8_t lo = this->memory[pc];
  uint8_t hi = this->memory[pc+1];
  return ((uint16_t)hi << 8) | lo;
}