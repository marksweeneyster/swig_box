cmake_minimum_required(VERSION 3.24)
project(swig_box)

set(CMAKE_CXX_STANDARD 20)

set(SWIG_EXECUTABLE C:/tools/swig/swigwin-4.1.1/swig)
set(SWIG_DIR C:/tools/swig/swigwin-4.1.1/Lib)

find_package(SWIG 4.1
        COMPONENTS python)

if(SWIG_FOUND)
    message("SWIG found: ${SWIG_EXECUTABLE}")
    if(NOT SWIG_python_FOUND)
        message(WARNING "SWIG Python bindings cannot be generated")
    endif()
endif()

include(UseSWIG)

find_package(PythonLibs)

add_library(fubar src/Fubar.cpp)
target_include_directories(fubar PUBLIC inc)

add_executable(swig_box main.cpp)
target_include_directories(swig_box PUBLIC inc)
target_link_libraries(swig_box PUBLIC fubar)

set_property(SOURCE inc/fubar.i PROPERTY CPLUSPLUS ON)

# With current project structure, the following is not needed
#set_property(SOURCE inc/fubar.i PROPERTY USE_TARGET_INCLUDE_DIRECTORIES TRUE)

swig_add_library(pyfubar LANGUAGE python SOURCES inc/fubar.i)
target_link_libraries(pyfubar PUBLIC ${PYTHON_LIBRARIES} fubar)
target_include_directories(pyfubar
        PUBLIC
        ${PYTHON_INCLUDE_DIR}
        )

