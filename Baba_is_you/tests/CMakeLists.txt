cmake_minimum_required(VERSION 3.5)

add_executable(Tests
    board_test.cpp
    ../src/model/gameobject.h
    ../src/model/gameobject.cpp
    ../src/model/coordinate.h
    ../src/model/coordinate.cpp
    ../src/model/board.h
    ../src/model/board.cpp
    ../src/model/direction.h
    ../src/model/type.h

)
target_include_directories(Tests PRIVATE
    ../src/model
)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.3.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)
#list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

target_link_libraries(Tests Catch2::Catch2WithMain)
