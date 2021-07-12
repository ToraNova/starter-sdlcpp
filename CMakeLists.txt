cmake_minimum_required(VERSION 3.5)

# TODO: rename project and versioning
project(starter-gamecpp VERSION 0.0.1 LANGUAGES CXX)

# TODO: when compiling on windows, specify SDL2 location
IF (WIN32)
	set(SDL2_PATH "D:/CodeLibraries/SDL2/SDL2-2.0.9")
ENDIF()

find_package(PkgConfig REQUIRED)
#find_package(SDL2 REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)
include_directories(${SDL2_INCLUDE_DIRS})

# TODO: indicate source files
set(SOURCE_FILES
	"src/main.cpp"
)

add_executable(${PROJECT_NAME}
	${SOURCE_FILES}
)

target_link_libraries(${PROJECT_NAME}
	${SDL2_LIBRARIES}
)

target_include_directories(${PROJECT_NAME} PUBLIC ${SDL2_INCLUDE_DIRS})
target_compile_options(${PROJECT_NAME} PUBLIC ${SDL2_CFLAGS_OTHER})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O1 -march=native")

# TODO: enable cross compilation
set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_C_COMPILER i686-w64-mingw32-gcc)
set(CMAKE_CXX_COMPILER i686-w64-mingw32-g++)
set(CMAKE_FIND_ROOT_PATH /usr/i686-w64-mingw32)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
