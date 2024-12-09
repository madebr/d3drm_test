add_executable(modetest WIN32
    modetest.cpp
    resource.h

    modetest.rc
    modetest.ico
)
target_link_libraries(modetest PRIVATE ddraw dxguid)

if(MINGW)
    target_compile_definitions(modetest PRIVATE
        DDEM_MODEPASSED=0x0000001L
        DDEM_MODEFAILED=0x0000002L
        DDSMT_ISTESTREQUIRED=0x0000001L
    )
endif()

