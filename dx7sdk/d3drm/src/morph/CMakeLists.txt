add_executable(morph WIN32
    morph.cpp
    rmmain.cpp
    resource.h

    rmmain.rc
    morph.def
    d3d.ico
)
target_link_libraries(morph PRIVATE d3dim d3drm ddraw)
