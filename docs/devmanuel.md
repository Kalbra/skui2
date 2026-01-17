# Developer manuel

## Debug Mode
The application has a few more tools if build as debug. The Macro `QT_DEBUG` is used to specify if the application builds as debug.

### Additional Shortcuts
- `Esc`: Quit the application


## Panels
The *Panel* is a fundamental concept of Skui.
It is organised the following way:
```mermaid
classDiagram
MainWindow *-- Document : Stores
Document : QList~VisualContainer~ visuals
Document : createVisual(VisualType) Visual

MainWindow *-- Panel : Shows / Handles

Panel *-- Visual : Parent
Visual : ~slot~ changeGeometryByDelta(QPointF delta, ...)
Visual : setGeometry(QRect)

Panel *-- ResizeBoundBox : Parent
ResizeBoundBox : setBoxGeometry(QRect)
ResizeBoundBox : ~signal~ chagnedDelta(QPointF delta, ...) 

ResizeBoundBox <-- Visual : Change in geometry
ResizeBoundBox --> Visual : Change in mouse Delta

Visual <|-- Test
Test *-- QLabel : Parent

Visual <|-- Slider
Slider *-- QSlider : Parent
```

## CoreNode vs. UINode 
A *Visual* 