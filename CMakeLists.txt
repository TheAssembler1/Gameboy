# setting minimum cmake
cmake_minimum_required(VERSION 3.16.3)  

# show compiler where to find headers
include_directories(include
					dep/plog-1.1.9/include)

# here we specify that the project is C language only, so the default
# C compiler on the system will be used
project(Gameboy CXX)

# recursively grab c files 
file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cpp")

# we only target 64 bit arch
set(CPU_ARCH "x64")

if(WIN32)
	# set windows dependencies here
elseif(UNIX)
	# set linux dependencies here
endif()


set(CMAKE_BINARY_DIR       ${CMAKE_CURRENT_LIST_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR}/build/bin/${CPU_ARCH})

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME})