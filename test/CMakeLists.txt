enable_testing()

add_executable(
  test_move
  test_move.cpp
)

target_link_libraries(
  test_move PUBLIC GTest::gtest_main
  
  # link against libs
  
)

include(GoogleTest)
gtest_discover_tests(test_move)

