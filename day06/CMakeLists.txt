add_library(day06_lib day06_lib.cpp day06_lib.hpp)
set_target_properties(day06_lib PROPERTIES OUTPUT_NAME day06)
target_link_libraries(day06_lib PRIVATE range-v3::range-v3)

add_executable(day06 day06.cpp)
target_link_libraries(day06 PRIVATE day06_lib fmt::fmt)

add_executable(day06_test day06_test.cpp)
target_link_libraries(day06_test PRIVATE day06_lib Catch2::Catch2WithMain)
add_test(NAME day06_test COMMAND day06_test)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input.txt ${CMAKE_BINARY_DIR}/day06/input.txt)
