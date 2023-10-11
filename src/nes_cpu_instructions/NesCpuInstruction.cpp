#include "NesCpuInstruction.hpp"

NesCpuInstruction::NesCpuInstruction(AddressMode mode) {
  m_mode = mode;
}

int NesCpuInstruction::getInstructionSize() {
  switch(m_mode) {
    case AddressMode::Implied: return 1;
    case AddressMode::Immediate: return 2;
    case AddressMode::Absolute: return 3;
    case AddressMode::ZeroPage: return 2;
    case AddressMode::AbsoluteX: return 3;
    case AddressMode::AbsoluteY: return 3;
    case AddressMode::ZeroPageX: return 2;
    case AddressMode::ZeroPageY: return 2;
    case AddressMode::Indirect: return 3;
    case AddressMode::IndirectX: return 2;
    case AddressMode::IndirectY: return 2;
    case AddressMode::Relative: return 2;
  }
}

uint8_t NesCpuInstruction::getOperand(NesMemory &mem, NesCpuRegisters regs) {
  
}

int ORA::execute(NesMemory &mem, NesCpuRegisters regs) {
  int numCycles = 0;
}
