cmake_minimum_required(VERSION 3.15)
project("FNF-FanGame")

#Raylib
set(RAYLIB_VESION "5.0.0")
find_package(raylib ${RAYLIB_VESION} QUIET)

if (NOT raylib_FOUND)
	message(STATUS "Raylib not found lol, wait bro i install this shit for you")

	include(FetchContent)
	
	FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG ${RAYLIB_VERSION}
    )

    FetchContent_MakeAvailable(raylib)
endif()

#set(FILE_SHIT "src/main.cpp" "src/Game.cpp" "src/include/Game.cpp")
file(GLOB FILE_SHIT 
    "src/*.cpp" 
    "src/states/*.cpp"
    
    "src/include/*.hpp" 
    "src/include/states/*.hpp"
)

set(CMAKE_CXX_STANDARD 17)
add_executable(${PROJECT_NAME} ${FILE_SHIT})

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")

target_link_libraries(${PROJECT_NAME} raylib)
