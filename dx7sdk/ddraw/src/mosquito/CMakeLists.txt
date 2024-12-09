add_executable(mosquito WIN32
    mosquito.cpp
    resource.h

    mosquito.def
    mosquito.rc
    mosquito.ico
    mosquit1.bmp
    mosquit2.bmp
    mosquit3.bmp
)
target_link_libraries(mosquito PRIVATE ddraw dxguid)
