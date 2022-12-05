add_library(day01_lib day01_lib.cpp day01_lib.hpp)
set_target_properties(day01_lib PROPERTIES OUTPUT_NAME day01)
target_link_libraries(day01_lib PRIVATE range-v3::range-v3)

add_executable(day01 day01.cpp)
target_link_libraries(day01 PRIVATE day01_lib fmt::fmt)

add_executable(day01_test day01_test.cpp)
target_link_libraries(day01_test PRIVATE day01_lib Catch2::Catch2WithMain)
add_test(NAME day01_test COMMAND day01_test)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input.txt ${CMAKE_BINARY_DIR}/day01/input.txt)
