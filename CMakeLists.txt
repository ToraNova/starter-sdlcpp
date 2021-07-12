# This cmake file is currently made for compilation on linux only. for windows, please use other methods (i.e., codeblocks or visualc++)
cmake_minimum_required(VERSION 3.5)

# TODO: rename project and versioning
project(starter-sdlcpp VERSION 0.0.1 LANGUAGES CXX)

# Set a default build type if none was specified
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
	set(CMAKE_BUILD_TYPE "Debug")
endif()

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
	set(BIN_DIR windows)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lmingw32 -lSDL2main -static-libstdc++")
	#target_link_libraries(${PROJECT_NAME} /usr/i686-w64-mingw32/bin/libstdc++-6.dll)
	#target_link_libraries(${PROJECT_NAME} /usr/i686-w64-mingw32/bin/libgcc_s_dw2-1.dll)
	install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${BIN_DIR}/)
	set_target_properties(${PROJECT_NAME} PROPERTIES
		RUNTIME_OUTPUT_DIRECTORY_DEBUG ${BIN_DIR}/debug/
		RUNTIME_OUTPUT_DIRECTORY_RELEASE ${BIN_DIR}/release/ )

	add_custom_command( TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different
		${CMAKE_FIND_ROOT_PATH}/bin/SDL2.dll
		${BIN_DIR}/debug/SDL2.dll)
	add_custom_command( TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different
		${CMAKE_FIND_ROOT_PATH}/bin/SDL2.dll
		${BIN_DIR}/release/SDL2.dll)
	add_custom_command( TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different
		${CMAKE_FIND_ROOT_PATH}/bin/libwinpthread-1.dll
		${BIN_DIR}/debug/libwinpthread-1.dll)
	add_custom_command( TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different
		${CMAKE_FIND_ROOT_PATH}/bin/libwinpthread-1.dll
		${BIN_DIR}/release/libwinpthread-1.dll)
	add_custom_command( TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different
		${CMAKE_FIND_ROOT_PATH}/bin/libgcc_s_dw2-1.dll
		${BIN_DIR}/debug/libgcc_s_dw2-1.dll)
	add_custom_command( TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different
		${CMAKE_FIND_ROOT_PATH}/bin/libgcc_s_dw2-1.dll
		${BIN_DIR}/release/libgcc_s_dw2-1.dll)
endif()
message("CMAKE_CXX_FLAGS" ${CMAKE_CXX_FLAGS})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
