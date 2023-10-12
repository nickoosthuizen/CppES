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

// TODO: Check for what to do with overflow in indexed addressing
int NesCpuInstruction::getOperand(NesMemory &mem, NesCpuRegisters regs) {
  switch(m_mode) {
    case AddressMode::Implied: {
      return 0; // implied instructions don't use an operand
    }
    case AddressMode::Immediate: {
      return mem.getByte(regs.PC+1);
    }
    case AddressMode::Absolute: {
      uint16_t addr = mem.getTwoByteLittleEndian(regs.PC+1);
      return mem.getByte(addr);
    }
    case AddressMode::ZeroPage: {
      uint16_t addr = mem.getByte(regs.PC+1);
      return mem.getByte(addr);
    }
    case AddressMode::AbsoluteX: {
      uint16_t addr = mem.getTwoByteLittleEndian(regs.PC+1) + regs.X;
      return mem.getByte(addr);
    }
    case AddressMode::AbsoluteY: {
      uint16_t addr = mem.getTwoByteLittleEndian(regs.PC+1) + regs.Y;
      return mem.getByte(addr);
    }
    case AddressMode::ZeroPageX: {
      // in zero page addressing, if the instruction would overflow, it rather wraps around
      uint8_t addr = mem.getByte(regs.PC+1) + regs.X;
      return mem.getByte((uint16_t)addr);
    }
    case AddressMode::ZeroPageY: {
      uint8_t addr = mem.getByte(regs.PC+1) + regs.Y;
      return mem.getByte((uint16_t)addr);
    }
    case AddressMode::IndirectX: {
      uint8_t addr = mem.getByte(regs.PC+1) + regs.X;
      uint16_t effectiveAddr = mem.getTwoByteLittleEndian((uint16_t)addr);
      return mem.getByte(effectiveAddr);
    }
    case AddressMode::IndirectY: {
      uint8_t addr = mem.getByte(regs.PC+1);
      uint16_t effectiveAddr = mem.getTwoByteLittleEndian(addr) + regs.Y;
      return mem.getByte(effectiveAddr);
    }
    case AddressMode::Relative: {
      // in relative addressing, the operand is actualy a signed byte
      return (int8_t)mem.getByte(regs.PC+1);
    }
  }
}

int ORA::execute(NesMemory &mem, NesCpuRegisters regs) {
  int numCycles = 0;
}
