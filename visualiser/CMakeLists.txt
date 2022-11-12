set(SOURCES
    "main.c"

    "io/mode.c"
    "io/user_query.c"
    "control/control.c"
    "tree/tree.c"
)

add_executable("${PROJECT_NAME}exec" ${SOURCES})
target_link_libraries("${PROJECT_NAME}exec" "${PROJECT_NAME}")
