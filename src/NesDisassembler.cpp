#include "NesDisassembler.hpp"
#include "NesMemory.hpp"

#include <iostream>

int NesDisassembler::disassemble6052(NesMemory &mem, uint16_t pc) {    
  std::cout << "0x" << std::hex << pc << ": ";

  uint8_t opCode = mem.getByte(pc);
  int opBytes = 1;

  // information on  6052 opcodes: https://www.masswerk.at/6502/6502_instruction_set.html#ORA
  // some instructions use multiple bytes
  // instructions can also use two or three bytes, if one does get those next bytes
  // for now only adding the legal instructions
  switch(opCode) {
    case 0x00: std::cout << "BRK"; break;
    case 0x01: std::cout << "ORA(i,x) " << std::hex << mem.getByte(pc+1) << ", X"; opBytes = 2; break;
    case 0x05: std::cout << "ORA(zpg) " << std::hex << mem.getByte(pc+1); opBytes = 2; break;
    case 0x06: std::cout << "ASL(zpg) " << std::hex << mem.getByte(pc+1); opBytes = 2; break;
    case 0x08: std::cout << "PHP(impl)"; break;
    case 0x09: std::cout << "ORA(#) " << std::hex << mem.getByte(pc+1); opBytes = 2; break;
    case 0x0A: std::cout << "ASL(A)"; break;
    case 0x0D: std::cout << "ORA(abs)" << std::hex << mem.getByte(pc+2) << std::hex << mem.getByte(pc+1); opBytes = 3; break;
    
  }
  std::cout << std::endl;
 
  return opBytes;
}
