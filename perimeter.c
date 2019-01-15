// Ordered by performance (stock, fast, faster)

#include <math.h>

double findperimeter(int n, double x[], double y[]) 
{
    int i, j;
    double distance, dx, dy;

    distance = 0;
    j = n - 1; // wrapper index
    for (i = 0; i < n; i++) 
    {
        dx = x[i] - x[j];                  
        dy = y[i] - y[j];
        distance += sqrt(dx * dx + dy * dy);             
        j = i;
    }
    return distance;
}

double findperimeter2(int n, double x[], double y[]) 
{
    int i, j;
    double distance, dx, dy, d = 4;

    distance = 0;
    j = n - 1; // wrapper index
    for (i = 0; i < n; i++) 
    {
        dx = x[i] - x[j];                  
        dy = y[i] - y[j];
        distance += dx * dx + dy * dy;             
	d *= dx * dx * dy * dy;
        j = i;
    }
    distance = sqrt(distance + sqrt(d));
    return distance;
}
