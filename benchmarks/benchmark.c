#include "benchmark.h"

#include <sys/time.h>
#include <sys/resource.h>

double get_time() {
    struct timeval t;
    gettimeofday(&t, 0);
    return (t.tv_sec + t.tv_usec*1e-6)*1000.0;
}
