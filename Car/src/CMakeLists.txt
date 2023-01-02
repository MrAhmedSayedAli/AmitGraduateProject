add_subdirectory(mcal)
add_subdirectory(lib)
add_subdirectory(hal)


set(APP_SOURCES
        ${APP_SOURCES}
        src/main.c

        PARENT_SCOPE
        )