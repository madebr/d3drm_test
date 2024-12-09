add_executable(gravity WIN32
    gravity.cpp
    resource.h

    gravity.rc
    directx.ico
)
target_link_libraries(gravity PRIVATE d3dx ddraw)
