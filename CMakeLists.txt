cmake_minimum_required(VERSION 3.5)

# TODO: rename project and versioning
project(starter-sdlcpp VERSION 0.0.1 LANGUAGES CXX)


# TODO: when compiling on windows, specify SDL2 location
if (WIN32)
	set(SDL2_PATH "D:/CodeLibraries/SDL2/SDL2-2.0.9")
endif ()

# TODO: indicate source files
set(SOURCE_FILES
	"src/main.cpp"
)

find_package(PkgConfig REQUIRED)
#find_package(SDL2 REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
set(CMAKE_CXX_STANDARD 11)

# TODO compiler flags if necessary
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O1 -march=native")
if (CMAKE_CROSSCOMPILE_WINDOWS)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lmingw32 -lSDL2main")
endif()
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
