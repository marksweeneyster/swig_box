cmake_minimum_required(VERSION 3.24)
project(swig_box)

set(CMAKE_CXX_STANDARD 20)

SET(SWIG_EXECUTABLE C:/tools/swig/swigwin-4.1.1/swig)
SET(SWIG_DIR C:/tools/swig/swigwin-4.1.1/Lib)

find_package(SWIG 4.1
        COMPONENTS python)

if(SWIG_FOUND)
    message("SWIG found: ${SWIG_EXECUTABLE}")
    if(NOT SWIG_python_FOUND)
        message(WARNING "SWIG Python bindings cannot be generated")
    endif()
endif()

include(UseSWIG)

FIND_PACKAGE(PythonLibs)

add_library(fubar src/Fubar.cpp)
target_include_directories(fubar PUBLIC inc)

add_executable(swig_box main.cpp)
target_include_directories(swig_box PUBLIC inc)
target_link_libraries(swig_box PUBLIC fubar)

SET_PROPERTY(SOURCE inc/fubar.i PROPERTY CPLUSPLUS ON)
SET_PROPERTY(SOURCE inc/fubar.i PROPERTY USE_TARGET_INCLUDE_DIRECTORIES TRUE)
SET_PROPERTY(SOURCE inc/fubar.i PROPERTY INCLUDE_DIRECTORIES
        "C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.35.32215/include")

swig_add_library(pyfubar LANGUAGE python SOURCES inc/fubar.i)
SWIG_LINK_LIBRARIES(pyfubar ${PYTHON_LIBRARIES} fubar)
target_include_directories(pyfubar
        PUBLIC
        ${PYTHON_INCLUDE_DIR}
        )
