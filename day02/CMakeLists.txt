add_library(day02_lib day02_lib.cpp day02_lib.hpp)
set_target_properties(day02_lib PROPERTIES OUTPUT_NAME day02)
target_link_libraries(day02_lib PRIVATE range-v3::range-v3)

add_executable(day02 day02.cpp)
target_link_libraries(day02 PRIVATE day02_lib fmt::fmt)

add_executable(day02_test day02_test.cpp)
target_link_libraries(day02_test PRIVATE day02_lib Catch2::Catch2WithMain)
add_test(NAME day02_test
         COMMAND day02_test)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input.txt ${CMAKE_BINARY_DIR}/day02/input.txt)
