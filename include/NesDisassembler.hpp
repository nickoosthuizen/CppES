#ifndef NES_DISASSEMBLER_HPP
#define NES_DISASSEMBLER_HPP

#include "NesMemory.hpp"

#include "stdint.h"

class NesDisassembler {
  public:
  // dissamble the instructions over range startByte to endByte
  int disassemble6052(NesMemory &mem, uint16_t startByte, uint16_t endByte);
};

#endif