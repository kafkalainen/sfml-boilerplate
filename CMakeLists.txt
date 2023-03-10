cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
project(SFMLBoilerplate VERSION 0.1)

include(FetchContent)

FetchContent_Declare(sfml
        GIT_REPOSITORY "https://github.com/SFML/SFML.git"
        GIT_TAG "origin/master"
        SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/sfml"
        )

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug
            CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

### Dependency population ###
set(BUILD_SHARED_LIBS OFF)
set(SFML_BUILD_EXAMPLES OFF)
set(SFML_BUILD_DOC OFF)

set(SFML_BUILD_NETWORK OFF)

set(SFML_BUILD_AUDIO ON)
set(SFML_BUILD_GRAPHICS ON)
set(SFML_BUILD_WINDOW ON)

FetchContent_GetProperties(sfml)
if(NOT sfml_POPULATED)
    FetchContent_Populate(sfml)
    add_subdirectory(${sfml_SOURCE_DIR})
endif()


### Project headers ###
include_directories(include)

### Project sources ###
file(GLOB_RECURSE SRCS ./srcs/*)

add_executable(SFMLBoilerplate ${SRCS} include/boilerplate.h)

target_link_libraries(
        SFMLBoilerplate
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio
)

install(TARGETS SFMLBoilerplate)