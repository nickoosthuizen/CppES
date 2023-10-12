#ifndef NES_MEMORY_HPP
#define NES_MEMORY_HPP

#include "NesComponent.hpp"

#include "stdint.h"

const int NES_MEMORY_SIZE = 65536;

class NesMemory {
  public:
    NesMemory();
    ~NesMemory();
    uint8_t getByte(uint16_t addr);
    void writeByte(uint16_t addr, uint8_t byte);
    uint16_t getTwoByteLittleEndian(uint16_t addr);

  private:
    uint8_t *memory;
    int size;
    
};

#endif