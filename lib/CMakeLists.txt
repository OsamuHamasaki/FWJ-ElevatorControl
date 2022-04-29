#add the library
add_library(IO STATIC IO.cpp)

target_include_directories(IO PUBLIC ${PROJECT_SOURCE_DIR}/include)

