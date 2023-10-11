#ifndef NES_CPU_INSTRUCTION_HPP
#define NES_CPU_INSTRUCTION_HPP

#include "stdint.h"
#include "NesCpuRegisters.hpp"
#include "NesMemory.hpp"

// Address Modes: https://www.masswerk.at/6502/6502_instruction_set.html#ASL
enum class AddressMode {
  Accumulator,
  Absolute,
  AbsoluteX,
  AbsoluteY,
  Immediate,
  Implied,
  Indirect,
  IndirectX,
  IndirectY,
  Relative,
  ZeroPage,
  ZeroPageX,
  ZeroPageY
};



class NesCpuInstruction {
  public:
    NesCpuInstruction(AddressMode mode);
    virtual int execute(NesMemory &mem, NesCpuRegisters regs) = 0;
    int getInstructionSize();
    uint8_t getOperand(NesMemory &mem, NesCpuRegisters regs);
  private:
    AddressMode m_mode;
};

class ORA: public NesCpuInstruction {
  public:
    int execute(NesMemory &mem, NesCpuRegisters regs);
};

#endif