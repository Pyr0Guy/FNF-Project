cmake_minimum_required(VERSION 3.16)
project("FNF-FanGame")

#Raylib
set(RAYLIB_VERSION 5.0)
find_package(raylib ${RAYLIB_VESION} QUIET)

# Dependencies
if (NOT raylib_FOUND) 

    include(FetchContent)
    FetchContent_Declare(
        raylib
        DOWNLOAD_EXTRACT_TIMESTAMP OFF
        URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )

    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED)
        set(FETCHCONTENT_QUIET NO)
        FetchContent_MakeAvailable(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    endif()

endif()

#set(FILE_SHIT "src/main.cpp" "src/Game.cpp" "src/include/Game.cpp")
file(GLOB FILE_SHIT 
    "src/*.cpp" 
    "src/**/*.cpp"
    
    "src/include/*.hpp" 
    "src/include/**/*.hpp"
)

set(CMAKE_CXX_STANDARD 17)
add_executable(${PROJECT_NAME} ${FILE_SHIT})

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")

target_link_libraries(${PROJECT_NAME} raylib)
target_precompile_headers(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/pch.hpp")

file(COPY "assets" DESTINATION ${CMAKE_BINARY_DIR})
