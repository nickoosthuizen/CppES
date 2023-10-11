#ifndef NES_MEMORY_HPP
#define NES_MEMORY_HPP

#include "NesComponent.hpp"

#include "stdint.h"

const int NES_MEMORY_SIZE = 65536;

class NesMemory: public NesComponent {
  public:
    NesMemory();
    ~NesMemory();
    uint8_t getByte(uint16_t pc);
    uint16_t getTwoByteLittleEndian(uint16_t pc);

  private:
    uint8_t *memory;
    
};

#endif