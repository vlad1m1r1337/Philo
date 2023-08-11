cmake_minimum_required(VERSION 3.26)
project(philo_project C)

set(CMAKE_C_STANDARD 11)

add_executable(philo_project
        philo/src/main.c
        philo/src/utils.c
        philo/src/validation.c
        philo/src/init.c
        philo/src/checker.c
        philo/src/meal.c
        philo/src/meal.c
        philo/src/meal.c
        philo/src/take.c
        philo/src/sleep.c
)
