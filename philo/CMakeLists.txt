cmake_minimum_required(VERSION 3.25)
project(philo)

set(CMAKE_CXX_STANDARD 17)

add_executable(philo src/utils.c src/main.c src/threads.c)
