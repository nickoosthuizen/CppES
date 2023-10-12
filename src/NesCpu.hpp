#ifndef NES_CPU_HPP
#define NES_CPU_HPP

#include "stdint.h"

#include "NesComponent.hpp"
#include "NesMemory.hpp"
#include "NesCpuInstruction.hpp"
#include "NesCpuRegisters.hpp"

class NesCpu : public NesComponent {
  public:
    NesCpu();
    ~NesCpu();

    virtual void powerOn();

    // Register getter functions by reference
    uint8_t &A() { return m_registers.A; }
    uint8_t &X() { return m_registers.X; }
    uint8_t &Y() { return m_registers.Y; }
    uint16_t &PC() { return m_registers.PC; }
    uint8_t &S() { return m_registers.S; }
    uint8_t &P() { return m_registers.P; }


  private:
    NesCpuRegisters m_registers;
};

#endif