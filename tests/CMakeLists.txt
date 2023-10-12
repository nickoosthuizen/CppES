set(BINARY ${CMAKE_PROJECT_NAME}_test)

set(SOURCES 
  NesCpuInstructionModeTests.cpp
  NesMemoryTests.cpp
  ../src/NesMemory.cpp
)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  ${BINARY}
  ${SOURCES}
)
target_link_libraries(
  ${BINARY}
  GTest::gtest_main
)
include_directories(../src)

include(GoogleTest)
gtest_discover_tests(${BINARY})
