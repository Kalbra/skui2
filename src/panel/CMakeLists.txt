qt_add_library(panel STATIC
<<<<<<< HEAD
    propertywindow.h propertywindow.cpp
=======
>>>>>>> f6f6ac898a1457f9f4378ef833cadc560b34b075
    resizeboundingbox.h resizeboundingbox.cpp
    panel.h panel.cpp
    visual_container.h visual_container.cpp
)

target_link_libraries(panel PRIVATE nodeeditor PRIVATE Qt6::Widgets)
target_include_directories(panel INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
