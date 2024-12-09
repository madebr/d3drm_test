add_executable(tentacle WIN32
    tentacle.cpp
    cframetimer.cpp
    cframetimer.hpp
    clensflare.cpp
    clensflare.hpp
    ctentacle.cpp
    ctentacle.hpp
    pch.cpp
    pch.hpp
    resource.h

    tentacle.rc
    directx.ico
)
target_link_libraries(tentacle PRIVATE d3dx ddraw winmm)
