find_package(benchmark REQUIRED)

add_executable(benchmark secondVersion.cpp)
add_executable(thirdbench thirdVersion.cpp)

target_link_libraries(benchmark PUBLIC benchmark::benchmark cppa)
target_link_libraries(thirdbench PUBLIC benchmark::benchmark cppa)

add_custom_target(bench COMMAND benchmark && ./thirdbench DEPENDS benchmark thirdbench)
