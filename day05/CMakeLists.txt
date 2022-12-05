add_library(day05_lib day05_lib.cpp day05_lib.hpp)
set_target_properties(day05_lib PROPERTIES OUTPUT_NAME day05)
target_link_libraries(day05_lib PRIVATE range-v3::range-v3)

add_executable(day05 day05.cpp)
target_link_libraries(day05 PRIVATE day05_lib fmt::fmt)

add_executable(day05_test day05_test.cpp)
target_link_libraries(day05_test PRIVATE day05_lib Catch2::Catch2WithMain)
add_test(NAME day05_test
         COMMAND day05_test)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input.txt ${CMAKE_BINARY_DIR}/day05/input.txt)
