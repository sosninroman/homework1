cmake_minimum_required(VERSION 3.2)

project(helloworld VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

configure_file(version.h.in ${PROJECT_SOURCE_DIR}/version.h)

add_executable(helloworld main.cpp)

add_library(helloworld_lib lib.cpp)

set(CMAKE_CXX_STANDARD 17)
set(BUILD_GMOCK OFF)

set_target_properties(helloworld helloworld_lib PROPERTIES
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

target_link_libraries(helloworld helloworld_lib)

install(TARGETS helloworld RUNTIME DESTINATION bin)

add_subdirectory("${PROJECT_SOURCE_DIR}/extern/googletest")

add_subdirectory(./test)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT sosninroman92@gmail.com)

include (CPack)

enable_testing()

add_test(NAME test_cli COMMAND test_cli)
