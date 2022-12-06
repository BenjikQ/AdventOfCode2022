add_library(day03_lib day03_lib.cpp day03_lib.hpp)
set_target_properties(day03_lib PROPERTIES OUTPUT_NAME day03)
target_link_libraries(day03_lib PRIVATE range-v3::range-v3)

add_executable(day03 day03.cpp)
target_link_libraries(day03 PRIVATE day03_lib fmt::fmt)

add_executable(day03_test day03_test.cpp)
target_link_libraries(day03_test PRIVATE day03_lib Catch2::Catch2WithMain)
add_test(NAME day03_test COMMAND day03_test)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input.txt ${CMAKE_BINARY_DIR}/day03/input.txt)
