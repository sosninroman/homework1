
include_directories("${SOURCE_DIR}/googletest/include"
        "${SOURCE_DIR}/googlemock/include")

file(GLOB_RECURSE test_SRC
        "./*.cpp"
        )

include_directories(./)
include_directories(../)

add_executable(test_cli gtest.cpp ${test_SRC} )

target_link_libraries(test_cli gtest cpp_lib)
