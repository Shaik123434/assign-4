#include <stdio.h>

#define PI 3.14159265358979323846

union shape {
    float radius;
    struct {
        float length;
        float width;
    } rectangle;
};

int main() {
    union shape s;
    char shape_type;
    printf("Enter shape type (c for circle, r for rectangle): ");
    scanf("%c", &shape_type);
    if (shape_type == 'c') {
        printf("Enter circle radius: ");
        scanf("%f", &s.radius);
        printf("Circle area: %f\n", PI * s.radius * s.radius);
    } else if (shape_type == 'r') {
        printf("Enter rectangle length: ");
        scanf("%f", &s.rectangle.length);
        printf("Enter rectangle width: ");
        scanf("%f", &s.rectangle.width);
        printf("Rectangle area: %f\n", s.rectangle.length * s.rectangle.width);
    } else {
        printf("Invalid shape type.\n");
    }
    return 0;
}

