# EasyVGA-ForDOS

EasyVGA-ForDOS is a simple library designed to facilitate VGA graphics programming in DOS environments. It provides a set of functions to initialize VGA modes, create and manipulate 2D vectors and points, convert RGB values to VGA color indices, and draw lines between points with specified colors.

## Features

- **VGA Mode Initialization**: EasyVGA-ForDOS allows you to initialize VGA modes directly from your DOS applications.
- **2D Vector and Point Manipulation**: Create and manipulate 2D vectors and points with ease.
- **Color Conversion**: Convert RGB values to VGA color indices for drawing.
- **Line Drawing**: Draw lines between points with specified colors.

## Usage

### Initialization

To initialize the VGA mode, call the `EasyVGA_Init` function. This sets the VGA mode to 320x200 with 256 colors.

```c
EasyVGA_Init();
```

### Creating Points

Create a point with a 2D vector position using the `EasyVGA_CreatePoint` function.

```c
Vector2 pos = EasyVGA_Vector2(100.0f, 100.0f);
Point point = EasyVGA_CreatePoint(pos);
```

### Drawing Lines

Draw a line between two points with a specified color using the `EasyVGA_CreateLine` function.

```c
Vector2 pos1 = EasyVGA_Vector2(50.0f, 50.0f);
Vector2 pos2 = EasyVGA_Vector2(200.0f, 200.0f);
Point point1 = EasyVGA_CreatePoint(pos1);
Point point2 = EasyVGA_CreatePoint(pos2);
EasyVGA_Color color = EasyVGA_RGBColor(255, 0, 0); // Red color
Line line = {point1, point2, color, 1.0f};
EasyVGA_CreateLine(line);
```

## Compilation

To compile this code for DOS, you can use a DOS compiler like Turbo C or Borland C++. Here's a basic example of how you might compile the code using Turbo C:

1. Open Turbo C.
2. Load the `EasyVGA.c` file.
3. Compile the code by selecting the appropriate options for your DOS environment.
4. If successful, you will get an executable file that you can run in DOS.

## Contributing

Contributions are welcome! If you have any feedback or suggestions for improvements, please feel free to contact the maintainer at dismissd64@gmail.com.

## License

EasyVGA-ForDOS is open-source software licensed under the MIT License. See the `LICENSE` file for more details.

<!MakeEdit index="0" startLine="1" endLine="2" file="file:///home/user/Documents/EasyVGA%28ForDOS%29/README.md" type="replace" title="Update README.md" />