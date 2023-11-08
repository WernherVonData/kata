project(bowling-kata)

enable_testing()

set(HEADERS
"game.hpp"
)

set(SRC
"game.cpp"
"bowling_game_test.cpp"
)

add_executable(${PROJECT_NAME} ${HEADERS} ${SRC})

target_link_libraries(${PROJECT_NAME} gtest_main)

add_subdirectory(googletest)
include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})