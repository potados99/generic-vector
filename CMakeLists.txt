cmake_minimum_required(VERSION 3.17)
project(generic_vector C)

set(CMAKE_C_STANDARD 99)

include_directories(include)

add_executable(
        demo
        main.c
        include/list.h
        include/types.h
        include/poison.h
        include/tests.h
        include/vector.h
        test/vector.test.c
        src/vector.c)