cmake_minimum_required(VERSION 3.12)

project (ghostbusters)

set (CMAKE_CXX_STANDARD 14)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std::c++14")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -03")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set (LIB_FILES
    lib/conio.h    
)

set (SOURCE_FILES
    src/main.cpp
    )

set (HEADER_FILES
    include/ability.h
    include/basic.h
    include/bomb.h
    include/button.h
    include/character.h
    include/end-game.h
    include/enemy.h
    include/.h
    include/.h
    include/.h
    include/.h
    include/.h
    include/.h
    include/.h
    include/.h
    include/.h
    include/.h
    include/.h
    include/.h
    include/.h
    include/.h
    include/.h
)

add_executable (program ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(program ${LIB_FILES})