project(lesson_1)

add_executable(lesson_1 src/main.cpp)

target_link_libraries(lesson_1 ${SDL2_LIBRARIES})