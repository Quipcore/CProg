# Vector2

## Description
Represents a 2D vector with the origin at the lower left corner of the screen.

## Constructors
| Name           | Description |
|----------------|---|
| `Vector2()`    |Creates a new `Vector2` with the values (0, 0).|
| `Vector2(x, y)` |Creates a new `Vector2` with the values (x, y).|

## Methods

| Type      | Name                               | Description                                            |
|-----------|------------------------------------|--------------------------------------------------------|
| `double`  | `getX()`                           | Returns the x component of the vector.                 |
| `double`  | `getY()`                           | Returns the y component of the vector.                 |
| `double`  | `magnitude()`                      | Returns the magnitude (length) of the vector.          |
| `Vector2` | `normalize()`                      | Normalizes current vector.                             |
| `Vector2` | `dot(Vector2 &rhs)`                | Returns the dot product of current vector and argument |
| `double`  | `distance(const Vector2 &rhs)`     | Returns the distance between current vector and argument |
| `double`  | `angleBetween(const Vector2 &rhs)` | Returns the angle between current vector and argument  |


## Operators

## Properties

| Type     | Name | Description |
|----------|------|-------------|
| `double` | `x`  | The x component of the vector. |
| `double` | `y`  | The y component of the vector. |

## Static Methods

## Static Properties