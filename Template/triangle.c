// Ghale, Sudip
// sxg7881
// 2020-04-20
//----------------------------------------------------------
#include <stdio.h>

#include "triangle.h"
#include "vertex.h"

//----------------------------------------------------------
void dumpTriangle( Vertex *v1, Vertex *v2, Vertex *v3 )
{
  printf("l %8.1f %8.1f %8.1f %8.1f\n" ,v1->x, v1->y,v2->x,v2->y);
  printf("l %8.1f %8.1f %8.1f %8.1f\n" ,v2->x, v2->y,v3->x,v3->y);
  printf("l %8.1f %8.1f %8.1f %8.1f\n" ,v3->x, v3->y,v1->x,v1->y);

}

//----------------------------------------------------------

