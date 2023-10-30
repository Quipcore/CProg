project(src)

set(HEADER_FILES
        test.h
        )

set(SOURCE_FILES
        test.cpp
        )

add_library(src STATIC ${SOURCE_FILES} ${HEADER_FILES})