add_library(day04_lib day04_lib.cpp day04_lib.hpp)
set_target_properties(day04_lib PROPERTIES OUTPUT_NAME day04)
target_link_libraries(day04_lib PRIVATE range-v3::range-v3)

add_executable(day04 day04.cpp)
target_link_libraries(day04 PRIVATE day04_lib fmt::fmt)

add_executable(day04_test day04_test.cpp)
target_link_libraries(day04_test PRIVATE day04_lib Catch2::Catch2WithMain)
add_test(NAME day04_test
         COMMAND day04_test)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input.txt ${CMAKE_BINARY_DIR}/day04/input.txt)
