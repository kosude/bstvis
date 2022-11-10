set(SOURCES
    "testfn.c"
)

add_library("${PROJECT_NAME}" SHARED ${SOURCES})
target_include_directories("${PROJECT_NAME}"
    PUBLIC
    "${BSTVIS_INCLUDE_DIR}"
)
