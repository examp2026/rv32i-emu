cmake_minimum_required(VERSION 3.10)
project(riscv_emulator C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

add_library(emu_core src/memory.c src/cpu.c)

add_executable(run_tests src/tests/cpu_test.c)
target_link_libraries(run_tests PRIVATE emu_core)

target_include_directories(emu_core PUBLIC src)
