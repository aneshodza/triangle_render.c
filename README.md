# triangle_render.c
This is a simple C Program that renders a triangle from complete scratch and transforms it.  
Everything is written completely from scratch (except the drawing of pixels).  
Following things have been manually implemented:
- Bresenham's algorithm for rasterization
- Span filling to color the inside of the triangle white
- Translation
- Transformation
    - Rotation around the centroid of the triangle

For further information look at the source-code.

## Running the program
### For macos & homebrew users
You can compile using:
```
make
```
And then execute using:
```
./out/executable
```

### For everyone else
You have to overwrite the SDL flag to properly include it:
```
make SDL="SDL path here"
```
And then execute using:
```
./out/executable
```
