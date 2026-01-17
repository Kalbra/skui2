qt_add_library(node STATIC
    node.h node.cpp
    interface.h interface.cpp
    nodes/label.h nodes/label.cpp
    nodes/slider.h nodes/slider.cpp
)

target_link_libraries(node PRIVATE Qt6::Widgets)
target_include_directories(node INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})