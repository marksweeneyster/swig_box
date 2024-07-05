cmake_minimum_required(VERSION 3.24)
project(swig_box)

set(CMAKE_CXX_STANDARD 20)

message(STATUS "SWIG executable: ${SWIG_EXECUTABLE}")

find_package(SWIG 4.1
        COMPONENTS python)

if(SWIG_FOUND)
    if(NOT SWIG_python_FOUND)
        message(WARNING "SWIG Python bindings cannot be generated")
    endif()
else()
    message(WARNING "SWIG NOT found")
endif()

include(UseSWIG)

find_package (Python3 COMPONENTS Interpreter Development)
MESSAGE(STATUS "EXECUTABLE     : " ${Python3_EXECUTABLE})
MESSAGE(STATUS "INCLUDE        : " ${Python3_INCLUDE_DIRS})
MESSAGE(STATUS "LIBRARIES      : " ${Python3_LIBRARIES})


find_package(fmt CONFIG REQUIRED)

add_library(fubar src/Fubar.cpp)
target_include_directories(fubar PUBLIC inc)
set_property(TARGET fubar PROPERTY POSITION_INDEPENDENT_CODE ON)

#####################

add_executable(swig_box main.cpp)
target_include_directories(swig_box PUBLIC inc)
target_link_libraries(swig_box PUBLIC fubar fmt::fmt-header-only)


set_property(SOURCE inc/fubar.i PROPERTY CPLUSPLUS ON)

# With current project structure, the following is not needed
#set_property(SOURCE inc/fubar.i PROPERTY USE_TARGET_INCLUDE_DIRECTORIES TRUE)

swig_add_library(pyfubar LANGUAGE python SOURCES inc/fubar.i)
target_link_libraries(pyfubar PUBLIC ${Python3_LIBRARIES} fubar)
target_include_directories(pyfubar
        PUBLIC
        ${Python3_INCLUDE_DIRS}
        )

find_package(benchmark REQUIRED)

add_executable(fubar_benchmark fubar_benchmark.cpp)

target_link_libraries(fubar_benchmark PUBLIC benchmark::benchmark fubar)

include(FetchContent)
FetchContent_Declare(googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG 64e0945546ec8c331af27ebffcca44a4006e9e35  # release v1.13.x
        )

FetchContent_MakeAvailable(googletest)
