enable_testing()
include(GoogleTest)
include(CTest)


function(add_test_executable name)
    add_executable(
            ${name}
            ${name}.cpp
    )

    target_link_libraries(
            ${name} PUBLIC GTest::gtest_main engine game
    )

    gtest_discover_tests(${name})
endfunction()


add_test_executable(test_move)
