set(SOURCES
    "main.c"
)

add_executable("${PROJECT_NAME}exec" ${SOURCES})
target_link_libraries("${PROJECT_NAME}exec" "${PROJECT_NAME}")
