include(CTest)

find_package(GTest REQUIRED)

add_custom_target(build-tests)
add_custom_target(test COMMAND ctest -L UnitTests --output-on-failure DEPENDS build-tests)

# Function: cppa_add_test test_name
# Add a test to the test suite.
# There must be a source file with the name test_name.cpp in the src/ directory.
function (cppa_add_test test_name)
    add_executable(${test_name} "${test_name}.cpp")
    target_link_libraries(${test_name} PUBLIC cppa GTest::GTest GTest::Main)
    add_test(NAME ${test_name} COMMAND ${test_name})
    set_tests_properties(${test_name} PROPERTIES LABELS UnitTests)
    add_dependencies(build-tests ${test_name})
endfunction()

cppa_add_test(test_first_version)
cppa_add_test(test_second_version)
