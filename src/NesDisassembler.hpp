#ifndef NES_DISASSEMBLER_HPP
#define NES_DISASSEMBLER_HPP

#include "NesMemory.hpp"

#include "stdint.h"

class NesDisassembler {
  public:
    NesDisassembler(NesMemory *mem);

    std::string memBytesToHexStr(uint16_t pc, int numBytes);

    // disassemble the instructions over range startByte to endByte
    int disassemble6052(uint16_t pc);

  private:
    NesMemory *mem;
  
};

#endif