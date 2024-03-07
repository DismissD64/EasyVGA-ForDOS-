```markdown
# EasyVGA Library for DOS

EasyVGA is a simple library designed to facilitate VGA graphics programming in DOS environments. It provides basic functionality for initializing VGA mode, creating 2D vectors, converting RGB values to VGA color indices, and drawing lines between points with specified colors.

## Features

- **VGA Mode Initialization**: EasyVGA can set the VGA mode to 320x200 with 256 colors.
- **2D Vector Creation**: Create 2D vectors with x and y coordinates.
- **Color Conversion**: Convert RGB values to a VGA 256 color index.
- **Line Drawing**: Draw lines between two points with a specified color.

## Usage

### Initialization

To initialize VGA mode, call `EasyVGA_Init()`.

```c
EasyVGA_Init();
```

### Creating Vectors

To create a 2D vector, use `EasyVGA_Vector2(x, y)`.

```c
Vector2 vector = EasyVGA_Vector2(10.0f, 20.0f);
```

### Color Conversion

To convert RGB values to a VGA color index, use `EasyVGA_RGBColor(r, g, b)`.

```c
EasyVGA_Color color = EasyVGA_RGBColor(255, 0, 0); // Red
```

### Drawing Lines

To draw a line between two points with a specified color, use `EasyVGA_CreateLine(line)`.

```c
EasyVGA_Line line;
line.point1 = EasyVGA_Vector2(10.0f, 20.0f);
line.point2 = EasyVGA_Vector2(30.0f, 40.0f);
line.color = EasyVGA_RGBColor(255, 0, 0); // Red
line.thickness = 1.0f; // Note: This parameter is not used in the current implementation
EasyVGA_CreateLine(line);
```

## Compilation

This code is designed to be compiled for DOS using a DOS compiler like Turbo C or Borland C++. For detailed compilation instructions, refer to the comments within the source code.

## Contributing

Feedback and contributions are welcome. Please send your feedback to dismissd64@gmail.com.

## License

This project is licensed under the MIT License.
```