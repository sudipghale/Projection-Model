// Ghale, Sudip
// sxg7881
// 2020-04-20
//----------------------------------------------------------
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "projection.h"

//----------------------------------------------------------
Projection *allocProjection()
{
  Projection *ptrProjection;
  ptrProjection = (Projection*)calloc(1,sizeof(Projection));
  if ( ptrProjection == NULL ) {
  fprintf( stderr, "allocModel: Unable to allocate Projection.\n" );
  exit( 0 );
  }

}

//----------------------------------------------------------
Projection *computeProjection( View *v )
{
  Projection *p = allocProjection();
  p->m_fx = - v->m_worldXMin;
  p->m_fy = - v->m_worldYMin;
  p->m_gx = v->m_width * v->m_viewportXMin;
  p->m_gy = v->m_height * v->m_viewportYMin;
  p->m_sx = v->m_width * (v->m_viewportXMax - v->m_viewportXMin) / (v->m_worldXMax - v->m_worldXMin);
  p->m_sy = v->m_height * (v->m_viewportYMax - v->m_viewportYMin) / (v->m_worldYMax - v->m_worldYMin);
  p->m_ax = p->m_fx * p->m_sx + p->m_gx;
  p->m_ay = p->m_fy * p->m_sy + p->m_gy;
  p->m_cameraDistance = v->m_cameraDistance;

  return p;
}

//----------------------------------------------------------
void dumpProjection( Projection *p )
{
  printf( "#- Projection parameters ---------------\n" );
  printf( "# (fx, fy) : ( %13.6f, %13.6f )\n", p->m_fx, p->m_fy );
  printf( "# (gx, gy) : ( %13.6f, %13.6f )\n", p->m_gx, p->m_gy );
  printf( "# (sx, sy) : ( %13.6f, %13.6f )\n", p->m_sx, p->m_sy );
  printf( "# (ax, ay) : ( %13.6f, %13.6f )\n", p->m_ax, p->m_ay );
  printf( "# Camera distance : %13.6f\n", p->m_cameraDistance );
  printf( "#---------------------------------------\n" );
}

//----------------------------------------------------------
void freeProjection( Projection *p )
{
  if (p != NULL) free(p);
}

//----------------------------------------------------------
void projectVertex( Projection *p, Vertex *v1, Vertex *v2 )
{
  if(p->m_cameraDistance == 0) // parallel projection
  {
    v2->x = v1->x * p->m_sx + p->m_ax;
    v2->y = v1->y * p->m_sy + p->m_ay;
    v2->z = 0;

  }

 else if (p->m_cameraDistance != 0)
 {
   if(v1->z >= p->m_cameraDistance) // parallel projection
   {
     fprintf(stderr, "Warning v->z >= camera distance\n" );
     v2->x = v1->x * p->m_sx + p->m_ax;
     v2->y = v1->y * p->m_sy + p->m_ay;
     v2->z = 0;
   }
   else { // perspective projection
     v2->x = (p->m_sx * ( v1->x / (1- (v1->z/p->m_cameraDistance))) + p->m_ax);
     v2->y = (p->m_sy * ( v1->y / (1- (v1->z/p->m_cameraDistance))) + p->m_ay);
     v2->z = 0;
   }


 }


}

void projectVertexList( Projection *p, Vertex *v, int numVertices )
{

  if(numVertices >0) 
  {
    for(int i=0; i < numVertices; i++)
    {
      projectVertex(p,&v[i], &v[i]);
    }
  }
  
}

//----------------------------------------------------------

