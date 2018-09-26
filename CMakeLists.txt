cmake_minimum_required(VERSION 3.2)

project(homeworkSkeleton VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

configure_file(version.h.in version.h)

add_executable(cpp_cli main.cpp)

add_library(cpp_lib lib.cpp)

include_directories(${CMAKE_BINARY_DIR})

set(CMAKE_CXX_STANDARD 14)

set_target_properties(cpp_cli cpp_lib PROPERTIES
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

target_link_libraries(cpp_cli cpp_lib)

install(TARGETS cpp_cli RUNTIME DESTINATION bin)

add_subdirectory("${PROJECT_SOURCE_DIR}/extern/googletest")

add_subdirectory(./test)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT vvz.otus@gmail.com)

include (CPack)

enable_testing()

add_test(test_version_valid test_cli)
