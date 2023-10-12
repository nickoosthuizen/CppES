#include "NesMemory.hpp"

#include "stdint.h"

NesMemory::NesMemory() {
  this->memory = new uint8_t[NES_MEMORY_SIZE];
}

NesMemory::~NesMemory() {
  delete this->memory;
}

uint8_t NesMemory::getByte(uint16_t addr) {
  return this->memory[addr];
}

void NesMemory::writeByte(uint16_t addr, uint8_t byte) {
  this->memory[addr] = byte;
}

uint16_t NesMemory::getTwoByteLittleEndian(uint16_t addr) {
  uint8_t lo = this->memory[addr];
  uint8_t hi = this->memory[addr+1];
  return ((uint16_t)hi << 8) | lo;
}