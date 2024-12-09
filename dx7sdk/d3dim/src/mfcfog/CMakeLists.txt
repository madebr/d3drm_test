add_executable(mfcfog WIN32
    d3dapp.cpp
    d3dapp.h
    fog.cpp
    stdafx.cpp
    stdafx.h
    resource.h

    d3dapp.rc
    directx.ico
)
target_link_libraries(mfcfog PRIVATE d3dframe)
