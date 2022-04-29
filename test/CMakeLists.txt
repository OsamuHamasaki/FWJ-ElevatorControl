file(GLOB TestSources ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(ElevatorControlTest ${TestSources})

add_subdirectory(TestDouble)
add_subdirectory(googletest-release-1.11.0)

target_link_libraries(ElevatorControlTest PUBLIC
    Components
    IOforTest
    gtest_main
    pthread)

target_include_directories(ElevatorControlTest
    PRIVATE "googletest-release-1.11.0/googletest/include")

include(GoogleTest)
gtest_discover_tests(ElevatorControlTest)

