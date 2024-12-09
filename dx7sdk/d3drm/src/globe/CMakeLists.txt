add_executable(globe WIN32
    globe.cpp
    rmmain.cpp
    resource.h

    rmmain.rc
    globe.def
    d3d.ico
)
target_link_libraries(globe PRIVATE d3drm ddraw)
