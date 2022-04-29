add_library(IOforTest STATIC IO.cpp)

target_include_directories(IOforTest
    PUBLIC ${PROJECT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR})

