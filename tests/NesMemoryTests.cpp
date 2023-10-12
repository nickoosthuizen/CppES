#include <gtest/gtest.h>

#include "NesMemory.hpp"
#include <iostream>

class NesMemoryTests: public ::testing::Test {
  protected:
    void SetUp() override {
      mem = new NesMemory();
      mem->writeByte(0, 5);
      mem->writeByte(2, 10);
      mem->writeByte(3, 1);
      mem->writeByte(4, 6);
    }
    void TearDown() override {
      delete mem;
    }

  NesMemory *mem;
};

TEST_F(NesMemoryTests, GetByte) {
  EXPECT_EQ(mem->getByte(0), 5);
  EXPECT_EQ(mem->getByte(3), 1);
}

TEST_F(NesMemoryTests, WriteByte) {
  mem->writeByte(0, 4);
  EXPECT_EQ(mem->getByte(0), 4);
}

TEST_F(NesMemoryTests, GetTwoByteLittleEndian) {
  EXPECT_EQ(mem->getTwoByteLittleEndian(2), 0x010A);
  EXPECT_EQ(mem->getTwoByteLittleEndian(3), 0x0601);
}
