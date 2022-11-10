cmake_minimum_required(VERSION 3.10)
project("bstvis")

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(BSTVIS_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/include")

# treat warnings as errors
add_compile_options(-Wall -Wextra -pedantic -Werror)

# ignore some warnings
add_compile_options(
    -Wno-unused-parameter
    -Wno-unused-result
)

# without this flag the fucking piece of shit gdb refuses to debug the program despite
# it already being compiled in debug mode :skull:
add_compile_options(-g)

# library
add_subdirectory("lib")

# visualiser
add_subdirectory("visualiser")
