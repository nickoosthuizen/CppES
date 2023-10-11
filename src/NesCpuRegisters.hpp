#ifndef NES_CPU_REGISTERS_HPP
#define NES_CPU_REGISTERS_HPP

#include "stdint.h"

// https://www.nesdev.org/wiki/CPU_registers
struct NesCpuRegisters {
  uint8_t A; // Accumulator: with ALU supports using status reg for carrying, overflow detection and such
  uint8_t X; // Index: can be used as loop counters easily, using INC/DEC and branch instructions
  uint8_t Y; // Index: same as X
  uint16_t PC; // Program Counter
  uint8_t S; // Stack Pointer
  uint8_t P; // Status Register 
};

#endif