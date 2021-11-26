cmake_minimum_required(VERSION 3.10)

project (ghostbusters)

set (CMAKE_CXX_STANDARD 14)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set (LIB_FILES
    lib/conio.h    
)

set (SOURCE_FILES
    src/main.cpp
    src/ability.cpp
    src/bomb.cpp
    src/button.cpp
    src/character.cpp
    src/end-game.cpp
    src/enemy.cpp
    src/engine.cpp
    src/entity.cpp
    src/game-over.cpp
    src/game.cpp
    src/interface.cpp
    src/level.cpp
    src/main-menu.cpp
    src/menu.cpp
    src/moveable.cpp
    src/next-level.cpp
    src/normal.cpp
    src/player.cpp
    src/power-up.cpp
    src/smart.cpp
    src/stable.cpp
    src/stats.cpp
    src/tile.cpp
    )

set (HEADER_FILES
    include/ability.h
    include/basic.h
    include/bomb.h
    include/button.h
    include/character.h
    include/end-game.h
    include/enemy.h
    include/engine.h
    include/entity.h
    include/game-over.h
    include/game-over.h
    include/game.h
    include/player.h
    include/interface.h
    include/level.h
    include/main-menu.h
    include/menu.h
    include/moveable.h
    include/next-level.h
    include/normal.h
    include/power-up.h
    include/smart.h
    include/stable.h
    include/stats.h
    include/tile.h
)

add_executable (program ${SOURCE_FILES} ${LIB_FILES} ${HEADER_FILES})

