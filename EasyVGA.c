#include <dos.h>
#include <conio.h>
#include <math.h>

// Function to initialize the VGA mode
void EasyVGA_Init() {
    union REGS regs;
    regs.h.ah = 0x00; // Function to set video mode
    regs.h.al = 0x13; // VGA mode 320x200, 256 colors
    int86(0x10, &regs, &regs); // Call BIOS interrupt 10h
}

// Function to create a 2D vector with x and y coordinates
typedef struct {
    float x;
    float y;
} Vector2;

Vector2 EasyVGA_Vector2(float x, float y) {
    Vector2 vector;
    vector.x = x;
    vector.y = y;
    return vector;
}

// Function to create a point with a 2D vector position
typedef struct {
    Vector2 pos;
} Point;

Point EasyVGA_CreatePoint(Vector2 pos) {
    Point point;
    point.pos = pos;
    return point;
}

// Function to convert RGB values to a VGA 256 color index
typedef int EasyVGA_Color;

EasyVGA_Color EasyVGA_RGBColor(int r, int g, int b) {
    // Simplified conversion; actual implementation would depend on the color palette
    return (r * 31 / 255) + (g * 63 / 255) * 32 + (b * 31 / 255) * 32 * 64;
}

// Function to draw a line between two points with a specified color
typedef struct {
    Point point1;
    Point point2;
    EasyVGA_Color color;
    float thickness; // Note: This parameter is not used in the current implementation
} Line;

void EasyVGA_CreateLine(Line line) {
    int x1 = line.point1.pos.x;
    int y1 = line.point1.pos.y;
    int x2 = line.point2.pos.x;
    int y2 = line.point2.pos.y;

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        unsigned char *video_memory = (unsigned char *)0xA0000;
        int index = (y1 * 320 + x1) * 4; // Assuming 32-bit color mode
        video_memory[index] = line.color & 0xFF; // Blue
        video_memory[index + 1] = (line.color >> 8) & 0xFF; // Green
        video_memory[index + 2] = (line.color >> 16) & 0xFF; // Red
        video_memory[index + 3] = 0xFF; // Alpha (ignored in this implementation)

        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x1 += sx; }
        if (e2 < dx) { err += dx; y1 += sy; }
    }
}

// To compile this code for DOS, you can use a DOS compiler like Turbo C or Borland C++.
// Here's a basic example of how you might compile the code using Turbo C:
// 1. Open Turbo C.
// 2. Load the EasyVGA.c file.
// 3. Compile the code by selecting the appropriate options for your DOS environment.
// 4. If successful, you will get an executable file that you can run in DOS.

// To use this code like a DLL or dynamic library in DOS, you would typically compile it into an object file (.obj)
// and then use a tool like LIB.EXE (included with Turbo C) to create a library file (.lib) that can be linked into your DOS applications.
// For example, you might use a command like "LIB.EXE /OUT:EasyVGA.lib EasyVGA.obj" to create the library file.
// Then, when compiling your DOS application, you would link against this library file.

// Made in Phind-34B by the help of a user DismissD64.
// You can send feedback to dismissd64@gmail.com.
// Message from DismissD64: Thanks Phind-34B for helping to make DOS more useful!
