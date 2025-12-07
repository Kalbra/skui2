qt_add_library(panel STATIC
    visual.h visual.cpp
    visuals/test.h visuals/test.cpp
    visuals/slider.h visuals/slider.cpp
    resizeboundingbox.h resizeboundingbox.cpp
    panel.h panel.cpp
)

target_link_libraries(panel PRIVATE nodeeditor PRIVATE Qt6::Widgets)
target_include_directories(panel INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
