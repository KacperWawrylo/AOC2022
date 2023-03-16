#include <stdio.h>
#include <math.h>

typedef struct {
    char can_build_triangle; // 't' if it can, 'n' if it can't
    int smallest_triangle_index; // index of smallest triangle or -1 if no triangle can be built
    double smallest_triangle_area; // area of smallest triangle or -1 if no triangle can be built
} TriangleInfo;

TriangleInfo check_triangles(double arr[][3], int n) {
    TriangleInfo info = { 'n', -1, -1 }; // initialize info struct with default values

    double a, b, c, p, area;
    double smallest_area = INFINITY;

    for (int i = 0; i < n; i++) {
        a = arr[i][0];
        b = arr[i][1];
        c = arr[i][2];

        if (a <= 0 || b <= 0 || c <= 0) {
            continue; // skip negative or zero values
        }

        if (a + b > c && a + c > b && b + c > a) { // check triangle inequality
            p = (a + b + c) / 2; // calculate semi-perimeter
            area = sqrt(p * (p - a) * (p - b) * (p - c)); // calculate area using Heron's formula

            if (area < smallest_area) { // update smallest area and index if applicable
                smallest_area = area;
                info.smallest_triangle_index = i;
                info.smallest_triangle_area = area;
            }

            info.can_build_triangle = 't'; // at least one triangle can be built
        }
    }

    return info;
}

int main() {
    int n = 3;
    printf("Enter number of triangles: ");
    

    double triangles[3][3];

    printf("Enter triangle side lengths:\n");
    for (int i = 0; i < n; i++) {
        scanf_s("%lf %lf %lf", &triangles[i][0], &triangles[i][1], &triangles[i][2]);
    }

    TriangleInfo info = check_triangles(triangles, n);

    if (info.can_build_triangle == 'n') {
        printf("No triangles can be built.\n");
    }
    else {
        printf("Triangles:\n");

        for (int i = 0; i < n; i++) {
            printf("Triangle %d: %lf %lf %lf\n", i + 1, triangles[i][0], triangles[i][1], triangles[i][2]);
        }

        if (info.smallest_triangle_index != -1) {
            printf("Smallest triangle:\n");
            printf("Index: %d\n", info.smallest_triangle_index + 1);
            printf("Side lengths: %lf %lf %lf\n", triangles[info.smallest_triangle_index][0], triangles[info.smallest_triangle_index][1], triangles[info.smallest_triangle_index][2]);
            printf("Area: %lf\n", info.smallest_triangle_area);
        }
    }

    return 0;
}
