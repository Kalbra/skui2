cmake_minimum_required(VERSION 3.19)
project(skui2 LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(CMAKE_AUTORCC ON)

qt_standard_project_setup()

qt_add_executable(skui2
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    document.h document.cpp

    visual.h visual.cpp
    outbound.h outbound.cpp
    visuals/test.h visuals/test.cpp
    resizeboundingbox.h resizeboundingbox.cpp
    panel.h panel.cpp
    assets.qrc
    interfacehandler.h interfacehandler.cpp
    visuals/slider.h visuals/slider.cpp
    skuievent.h
    skui.h skui.cpp

)

target_link_libraries(skui2
    PRIVATE
        Qt::Core
        Qt::Widgets
)
target_link_libraries(skui2 PRIVATE Qt6::Widgets)

include(GNUInstallDirs)

install(TARGETS skui2
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET skui2
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
