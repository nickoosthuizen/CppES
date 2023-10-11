#include "NesDisassembler.hpp"
#include "NesMemory.hpp"

#include <iostream>
#include <sstream>

NesDisassembler::NesDisassembler(NesMemory *mem) {
  this->mem = mem;
}

// only accepts 1 or two bytes
std::string NesDisassembler::memBytesToHexStr(uint16_t pc, int numBytes) {
  std::stringstream stream;
  stream << "0x";
  if (numBytes == 1) {
    stream << std::hex << this->mem->getByte(pc);
  }
  else if (numBytes == 2) {
    stream << std::hex << this->mem->getByte(pc+1) << std::hex << this->mem->getByte(pc);
  }
  return stream.str();
}

int NesDisassembler::disassemble6052(uint16_t pc) {    
  std::cout << memBytesToHexStr(pc, 1) << ": ";

  uint8_t opCode = this->mem->getByte(pc);
  int opBytes = 1;

  // information on  6052 opcodes: https://www.masswerk.at/6502/6502_instruction_set.html#ORA
  // some instructions use multiple bytes
  // instructions can also use two or three bytes, if one does get those next bytes
  // for now only adding the legal instructions
  switch(opCode) {
    case 0x00: std::cout << "BRK"; break;
    case 0x01: std::cout << "ORA(i,x) " << memBytesToHexStr(pc+1, 1) << ", X"; opBytes = 2; break;
    case 0x05: std::cout << "ORA(zpg) " << memBytesToHexStr(pc+1, 1); opBytes = 2; break;
    case 0x06: std::cout << "ASL(zpg) " << memBytesToHexStr(pc+1, 1); opBytes = 2; break;
    case 0x08: std::cout << "PHP(impl)"; break;
    case 0x09: std::cout << "ORA(#) " << memBytesToHexStr(pc+1, 1); opBytes = 2; break;
    case 0x0A: std::cout << "ASL(A)"; break;
    case 0x0D: std::cout << "ORA(abs) " << memBytesToHexStr(pc+1, 2); opBytes = 3; break;
    case 0x0E: std::cout << "ASL(abs) " << memBytesToHexStr(pc+1, 2); opBytes = 3; break;
    case 0x10: std::cout << "BPL(rel) " << memBytesToHexStr(pc+1, 1); opBytes = 2; break;
    case 0x11: std::cout << "ORA(ind,y) " << memBytesToHexStr(pc+1, 1); opBytes = 2; break;
    case 0x15: std::cout << "ORA(zpg,x) " << memBytesToHexStr(pc+1, 1); opBytes = 2; break;
    case 0x16: std::cout << "ASL(zpg,x) " << memBytesToHexStr(pc+1, 1); opBytes = 2; break;
    case 0x18: std::cout << "CLC(impl)"; break;
    case 0x19: std::cout << "ORA(abs,y) " << memBytesToHexStr(pc+1, 2); opBytes = 3; break;
    case 0x1D: std::cout << "ORA(abs,x) " << memBytesToHexStr(pc+1, 2); opBytes = 3; break;
    case 0x1E: std::cout << "ASL(abs,x) " << memBytesToHexStr(pc+1, 2); opBytes = 3; break;
    case 0x20: std::cout << "JSR(abs) " << memBytesToHexStr(pc+1, 2); opBytes = 3; break;
  }
  std::cout << std::endl;
 
  return opBytes;
}
