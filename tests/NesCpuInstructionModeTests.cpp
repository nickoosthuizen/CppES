#include <gtest/gtest.h>

#include "NesCpuInstruction.hpp"
#include "NesMemory.hpp"
#include "NesCpuRegisters.hpp"

class NesCpuInstructionGetOperandsTest: public ::testing::Test {
  protected:
    void SetUp() override {
      mem = new NesMemory();
      regs.X = 0;
      regs.Y = 0;
      regs.A = 0;
      regs.PC = 0;
      

    }
    void TearDown() override {
      delete mem;
    }

  NesMemory *mem;
  NesCpuRegisters regs;
};

TEST_F(NesCpuInstructionGetOperandsTest, ImpliedMode) {
  EXPECT_EQ(0, 0);
}