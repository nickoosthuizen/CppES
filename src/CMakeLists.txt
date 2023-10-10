set(BINARY ${CMAKE_PROJECT_NAME})

set(SOURCES 
  main.cpp
)

add_compile_options(-Wall -Wextra)

add_executable(${BINARY} ${SOURCES})
