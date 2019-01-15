#include <time.h>
#include <sys/time.h>

double wall_clock()
{
        struct timeval timeval;
        (void) gettimeofday (&timeval,NULL);
        return (timeval.tv_sec + (timeval.tv_usec / 1000000.0));
}
