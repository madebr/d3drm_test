add_executable(rmenum WIN32
    rmenum.cpp
    rmenum.h
    rmerror.c
    rmerror.h

    rmenum.rc
    d3d.ico
)
target_link_libraries(rmenum PRIVATE d3drm ddraw)
