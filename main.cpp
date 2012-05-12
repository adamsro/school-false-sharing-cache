#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <omp.h>

#if !defined (NUMT)
#define NUMT 4
#endif
#if !defined (NUM)
#define NUM 0
#endif
#define PADDING 0

struct s {
    float value;
    int pad[NUM];
} Array[4];

int main() {
#ifndef _OPENMP
    fprintf( stderr, "OpenMP is not available\n" );
    return 1;
#endif
    long some_big_number = 1000000000;
//    float isize = sizeof (int);
//    float fsize = sizeof (float);
//    printf("sizeof int %f\t\t sizeof float %f\n\n", isize, fsize);

    //    int numProcessors = omp_get_num_procs( );
    //    fprintf( stderr, "Have %d processors.\n", numProcessors );
    omp_set_num_threads( NUMT );

    double time0 = omp_get_wtime( );
    if(PADDING == 1) {
#pragma omp parallel for 
        for( int i = 0; i < 4; i++ ) {
            for( int j = 0; j < some_big_number; j++ ) {
                Array[ i ].value = Array[ i ].value + 2.;
            }
        }
    } else {
#pragma omp parallel for 
        for( int i = 0; i < 4; i++ ) {
            float tmp = Array[ i ].value;
            for( int j = 0; j < some_big_number; j++ ) {
                tmp = tmp + 2.;
            }
            Array[ i ].value = tmp;
        }
    }

    double time1 = omp_get_wtime( );
    //printf("%f\t%ld\n\n", time, some_big_number* 4); 
    float mflops = ((float) (some_big_number * 4) / (float)(time1-time0)) / 1000000.f;
    printf("%d\t%8.3f\n", NUM, mflops);

    return 0;
}
