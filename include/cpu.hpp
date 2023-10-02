#ifndef CPU_HPP
#define CPU_HPP

#include "component.hpp"

#include "stdint.h"

// https://www.nesdev.org/wiki/CPU_registers
struct cpu_registers {
  uint8_t A; // Accumulator: with ALU supports using status reg for carrying, overflow detection and such
  uint8_t X; // Index: can be used as loop counters easily, using INC/DEC and branch instructions
  uint8_t Y; // Index: same as X
  uint16_t PC; // Program Counter
  uint8_t S; // Stack Pointer
  uint8_t P; // Status Register 
};


class Cpu : public Component {
  public:
    Cpu();
    ~Cpu();

    virtual void powerOn();

    // Register getter functions by reference
    uint8_t &A() { return m_registers.A; }
    uint8_t &X() { return m_registers.X; }
    uint8_t &Y() { return m_registers.A; }
    uint16_t &PC() { return m_registers.PC; }
    uint8_t &S() { return m_registers.S; }
    uint8_t &P() { return m_registers.P; }


  private:

    cpu_registers m_registers;


};

#endif