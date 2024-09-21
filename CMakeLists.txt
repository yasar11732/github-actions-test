cmake_minimum_required (VERSION 3.20)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

project ("github-actions-test" LANGUAGES C)

find_package(LibXml2 REQUIRED)
add_executable (github-actions-test main.c)
target_link_libraries(github-actions-test PRIVATE LibXml2::LibXml2)

option(BUILD_TESTS "Build Test Programs" OFF)

if(BUILD_TESTS)
	include(CTest)
	enable_testing()
	add_subdirectory(test)
endif()



