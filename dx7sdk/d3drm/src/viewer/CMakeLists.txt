add_executable(viewer WIN32
    viewer.cpp
    color.cpp
    file.cpp
    rodcone.cpp
    rodcone.h
    sel.cpp
    sel.h
    viewer.cpp
    viewer.h

    viewer.rc
    viewer.def
    viewer.ico
)
target_link_libraries(viewer PRIVATE d3drm ddraw dxguid)
