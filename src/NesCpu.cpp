#include "NesCpu.hpp"
#include "NesCpuRegisters.hpp"


NesCpu::NesCpu() {

}

NesCpu::~NesCpu() {

}

/*
* Initialize the CPU
* Details for initial values at: https://www.nesdev.org/wiki/CPU_power_up_state
*/
void NesCpu::powerOn() {
  P() = 0x34;
  A() = 0;
  X() = 0;
  Y() = 0;
  S() = 0xFD;
}
