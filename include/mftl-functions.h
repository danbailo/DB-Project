/*=====================================================================================
 *
 *        Filename:  mftl-functions.h
 *
 *     Description:  This header file contains the declarations of the "general"
 *     functions of the library.
 *
 *         Version:  $Revision: 522 $
 *         Created:  Dec 26, 2009
 *
 *          Author:  Berend van Wachem (BvW), berend.van.wachem@gmail.com
 *       Copyright:  (c) Berend van Wachem.
 *
 *
 * MODIFICATIONS
 * File $Id: interpconveullag.c 522 2008-07-11 15:02:22Z berend $
 * Last modified by: $Author: berend $
 * On: $Date: 2008-07-11 16:02:22 +0100 (Fri, 11 Jul 2008) $
 *
 * =====================================================================================*/

#ifndef MFTLFUNCTIONS_H_
#define MFTLFUNCTIONS_H_

#include "mftl.h"
#include <stdio.h>
#include "mftl-constants.h"
#include <math.h>

// Structure for convex hull calculations
struct MFTL_GrahamSortPoint
{
	double x[3];
  int    id;
  int    delete;
};
typedef struct MFTL_GrahamSortPoint MFTL_GrahamSortPoint;


/* Set one value to an integer array */
int MFTL_IntArraySetValue(int *A, int size, int value);

/*************************************************************************/
/*  Intersection functions                                               */
/*************************************************************************/
int MFTL_BodyOverlap(MFTL_UnitBoundingBox *BigBB_A, MFTL_UnitBoundingBox *BigBB_B, MFTL_BoundingBox *SmlBB_A, MFTL_BoundingBox *SmlBB_B, MFTL_Object *Object_A, MFTL_Object *Object_B, MFTL_Object *AIntersectB, MFTL_Object *BIntersectA);
int MFTL_CalculateOverlap(MFTL_Object *AinB, MFTL_Object *BinA, struct MFTL_Overlap ** Output, double * VecAB);
int MFTL_FreeOverlap(struct MFTL_Overlap * ToFree);

/*************************************************************************/
/*  Parallel functions                                                   */
/*************************************************************************/
/* Return the processor of a vertex based on its position */
int MFTL_ProcOfVertex(struct MFTL_Object *Object, struct MFTL_Vertex *V);

/*************************************************************************/
/*  Memory management                                                    */
/*************************************************************************/
int MFTL_AllocateMemory(int size, void **NewPointer);
int MFTL_DynamicallyTriangleArrayGrow(MFTL_Object* Object, char **A, int oldsize, int increase);

/*************************************************************************/
/*  Finding the local number of items in the object                      */
/*************************************************************************/
int MFTL_NumberOfLocalTriangles(MFTL_Object *Object, int include_ghost);
int MFTL_NumberOfLocalEdges(MFTL_Object *Object, int include_ghost);
int MFTL_NumberOfLocalVertexes(MFTL_Object *Object, int include_ghost);

/*************************************************************************/
/*  HASH TABLE FUNCTIONS                                                 */
/*************************************************************************/
MFTL_Vertex *MFTL_AddVertex(MFTL_Object *Object, MFTL_Vertex *Vertex);
MFTL_Edge *MFTL_AddEdge(MFTL_Object *Object, MFTL_Edge *Edge);
MFTL_Triangle *MFTL_AddTriangle(MFTL_Object *Object, MFTL_Triangle *Triangle);

int MFTL_ArrayToTriangles(MFTL_Object *Object, char *Array, int NumofTriangles);
int MFTL_TriangleToArray(MFTL_Object *Object, MFTL_Triangle *Triangle, char* array);
int MFTL_VertexToArray(MFTL_Vertex *Vertex, char * array);
int MFTL_EdgeToArray(MFTL_Edge *Edge, char * array);
int MFTL_TriangleEdgeToArray(MFTL_Triangle *Triangle, char * array);
int MFTL_TriangleVertToArray(MFTL_Triangle *Triangle, char * array);

int MFTL_EdgeFromVertex(MFTL_Object *Object, MFTL_Vertex *Vertex, MFTL_Edge *EdgeList);
int MFTL_TrianglesFromVertex(MFTL_Object *Object, MFTL_Vertex *Vertex, MFTL_GeneralList *List);
int MFTL_TriangleHashFromVertex(MFTL_Object *Object, MFTL_Vertex *Vertex, MFTL_Triangle **List);
int MFTL_NoTrianglesFromVertex(MFTL_Object *Object, MFTL_Vertex *Vertex);
void MFTL_GetTriangleVertexesAndEdges(MFTL_Object *Object, MFTL_Triangle *Triangle, MFTL_Vertex **Vertex0,
        MFTL_Vertex **Vertex1, MFTL_Vertex **Vertex2, MFTL_Edge **Edge0, MFTL_Edge **Edge1, MFTL_Edge **Edge2,
        MFTL_Edge **Edge);

/*************************************************************************/
/*  Functions to delete a whole element                                  */
/*************************************************************************/
int MFTL_RemoveObject(MFTL_Object *Object);
int MFTL_RemoveTriangle(MFTL_Object *Object, MFTL_Triangle *Triangle);
int MFTL_RemoveEdge(MFTL_Object *Object, MFTL_Edge *Edge);
int MFTL_RemoveVertex(MFTL_Object *Object, MFTL_Vertex *Vertex);
int MFTL_RemoveIntersection(MFTL_TrianglePair *Inter);

/*************************************************************************/
/*  Functions to clean-up the structure                                  */
/*************************************************************************/
int MFTL_FreeBoundingBoxMemory(MFTL_BoundingBox *BoundingBox);
int MFTL_RemoveOrphanVertexes(MFTL_Object *Object);
int MFTL_RemoveOrphanEdges(MFTL_Object *Object);
int MFTL_FreeMemory(void *Pointer);

/*************************************************************************/
/*  Looping functions                                                    */
/*************************************************************************/
int MFTL_ObjectForEachTriangle(MFTL_Object *Object, int (*LoopFunction)(MFTL_Triangle *T, void *data), void *data, int Operation);

/*************************************************************************/
/*  Linking object elements                                              */
/*************************************************************************/
int MFTL_FindTriangleEdgesandVertices(MFTL_Object *Object);

/*************************************************************************/
/*  Sphere generation functions                                          */
/*************************************************************************/
int MFTL_GenerateIsocahedron(MFTL_Object *Object);
int MFTL_TessalateSphere(MFTL_Object *Object);
MFTL_Edge * MFTL_GenerateEdge(MFTL_Vertex * V1, MFTL_Vertex *V2);
MFTL_Triangle * MFTL_GenerateTriangle(MFTL_Vertex * V1, MFTL_Vertex *V2, MFTL_Vertex *V3);

/*************************************************************************/
/*  Object intersection functions                                        */
/*************************************************************************/
int MFTL_AddToIntersectionList(double X1[3], MFTL_Point **Intersection);
int MFTL_IntersectingTrianges (MFTL_Object * Object1, MFTL_BoundingBox *BBox1, MFTL_Object *Object2, MFTL_BoundingBox *BBox2, MFTL_TrianglePair **IntersectionTriangles);
int MFTL_IntersectionPoints(MFTL_Object *Object1, MFTL_Object *Object2, MFTL_TrianglePair *IntersectionTriangles, MFTL_Point **Intersection);
int MFTL_TriangleSurfaceIntersectingTrianges (MFTL_Object * Object1, MFTL_BoundingBox *BBox1, MFTL_Triangle *Triangle, MFTL_BoundingBox *BBox2, MFTL_TrianglePair **IntersectionTriangles);
int MFTL_TriangleSurfaceIntersectionPoints(MFTL_Object *Object1, MFTL_Triangle *TriangleB, MFTL_TrianglePair *IntersectionTriangles, MFTL_Point **Intersection);

/*************************************************************************/
/*  Point inside the Surface supplementary functions                     */
/*************************************************************************/
int MFTL_RayPlaneIntersection(MFTL_Triangle *Triangle, MFTL_Point *P, double *RayEnd, double *InterPoint);
int MFTL_RayCrossingBoxTest(MFTL_BoundingBox *Box, MFTL_Point *P, double *RayEnd);
int MFTL_RayTracing(MFTL_Object *Object, MFTL_BoundingBox *Box, MFTL_Point *P, int *DegenerateCaseFlag, double *RayEnd);
int MFTL_RandomRay(MFTL_Object *Object, double RayDirection[3]);
int MFTL_RandomRayLocal(MFTL_Object *Object, double RayDirection[3]);
int MFTL_StabbedTriangles(MFTL_Object *Object, MFTL_BoundingBox *Box, MFTL_Point *P, int *DegenerateCaseFlag, double *RayEnd);
int MFTL_StabbedTriangle(MFTL_Object *Object, MFTL_BoundingBox *Box, MFTL_Point *P, int *DegenerateCaseFlag, double *RayEnd);
int MFTL_PointInTriangle(MFTL_Point *p, MFTL_Triangle *Triangle, int *DegenerateCaseFlag);
int MFTL_SameSide(double *p1, double *p2, double *a, double *b);
double MFTL_RandomNumber01(void);

/*************************************************************************/
/*  Sorting functions                                                    */
/*************************************************************************/
int MFTL_PointAddressSort(MFTL_Point *a, MFTL_Point *b);
int MFTL_VertIdSort(MFTL_Vertex *a, MFTL_Vertex *b);
int MFTL_EdgeIdSort(MFTL_Edge *a, MFTL_Edge *b);
int MFTL_CompareAngles(const void *tpi, const void *tpj);

/*************************************************************************/
/*  Convex hull supplementary functions                                  */
/*************************************************************************/
MFTL_GrahamSortPoint * MFTL_AlignPointsXY(MFTL_Point *PointList, int n);
MFTL_Vertex * MFTL_PointListToVertexList(MFTL_Point * PointList);
MFTL_Point * MFTL_ConvexPolygonVertexes(MFTL_Point *PointList);
int MFTL_FindLowest(MFTL_GrahamSortPoint * GSP, int n);
int MFTL_AreaSign(double x1[3], double x2[3], double x3[3]);
int MFTL_GrahamScan(int n);

/*************************************************************************/
/*  Output functions                                                     */
/*************************************************************************/
int MFTL_WriteObjectToVTK_1Proc(MFTL_Object *Object, char fname[]);
int MFTL_WriteTriangleToVTK(MFTL_Triangle *Triangle, char name[]);
int MFTL_WritePointsToVTK(MFTL_Point *Points, char name[]);
int MFTL_SaveBBoxToVTK(MFTL_Object * Object, MFTL_BoundingBox * BoundingBox);
int MFTL_PrintTreeToFile(MFTL_BoundingBox * BoundingBox, char fname[]);

int MFTLWritePVTUOutput(struct MFTL_Object *Object, char* base_name);
int MFTLWritePVTUFile(struct MFTL_Object *Object, char* base_name);
int MFTLWriteVTUFile(struct MFTL_Object *Object, FILE *fp);
void MFTL_ParserShowSummary(FILE *fp, MFTL_Parser *Parser, const char *msg);
void MFTL_PrintArrayDouble(FILE *fp, double x[], int size, int skip, char *msg);
void MFTL_PrintArrayInt(FILE *fp, int x[], int size, int skip, char *msg);

int MFTL_ParserInitialize(MFTL_Parser *parser, char *fname);
int MFTL_ParserFinalize(MFTL_Parser *parser);

/*************************************************************************/
/*  I/O functions (input/restart/debug, not post-processing)                   */
/*************************************************************************/

int MFTL_Init(MFTL_Object *Object, MFTL_Parser *Parser);
int MFTL_BeginWithComm(MFTL_Object *Object, MFTL_Parser *Parser, char fname[MFTL_STRINGLENGTH], MPI_Comm Comm);
int MFTL_ObjectReadGeometry(MFTL_Object *Object, char fname[MFTL_STRINGLENGTH]);
int MFTL_ObjectReadMeshForeach(MFTL_Object *Object, char fname[MFTL_STRINGLENGTH]);
int MFTL_ObjectSaveState(MFTL_Object *Object, char case_name[MFTL_STRINGLENGTH], char topology_kind[MFTL_STRINGLENGTH],
		int *version);
int MFTL_ObjectWriteMainRestartFile(MFTL_Object *Object, char case_name[MFTL_STRINGLENGTH], char topology_kind[MFTL_STRINGLENGTH],
		char root_name[MFTL_STRINGLENGTH]);
int MFTL_ObjectWriteMeshForeach(MFTL_Object *Object, char fname[]);
void MFTLTopologyShowSummary(MFTL_Object *Object);
void MFTL_VertexShowSummary(MFTL_Vertex *V, FILE *fp, const char* msg);
void MFTL_EdgeShowSummary(MFTL_Edge *E, FILE *fp, const char* msg);
void MFTL_TriangleShowSummary(MFTL_Triangle *T, FILE *fp, const char *msg);
/*************************************************************************/
/*  Vertex-Related functions (mostly remeshing-related)                  */
/*************************************************************************/

void MFTL_VertexNormal(MFTL_Object *Object, MFTL_Vertex *V, double *normal);
void MFTL_VertexLaplacianSmoothing(MFTL_Object *Object, MFTL_Vertex *V);
void MFTL_VertexWASmoothing(MFTL_Object *Object, MFTL_Vertex *V);
double MFTL_VertexReferenceVolume(MFTL_Object *Object, MFTL_Vertex *V);
void MFTL_VertexVolumeRecovery(MFTL_Object *Object, MFTL_Vertex *V, double reference_vol, double reference[3]);

/*************************************************************************/
/*  Edge-Related functions (mostly remeshing-related)                    */
/*************************************************************************/
int MFTL_EdgeSmooth(MFTL_Object *Object, MFTL_Edge *Edge);
void MFTL_EdgeMidVertex(MFTL_Edge *Edge, MFTL_Vertex *MidVertex);
double MFTL_EdgeLength(MFTL_Edge* Edge);
void MFTL_EdgeNormal(MFTL_Object *Object, MFTL_Edge *edge, double normal[3]);
double MFTL_EdgePointDistance(MFTL_Edge *Edge, MFTL_Point *P);

/*************************************************************************/
/*  Mesh topology functions                                              */
/*************************************************************************/
int MFTL_EdgeIsBoundary(MFTL_Object *Object, MFTL_Edge *E);
void MFTL_EdgeBoundaryTriangle(MFTL_Object *Object, MFTL_Edge *E, int *tri_id);
int MFTL_EdgeIsGhost(MFTL_Edge *E);
int MFTL_EdgeOppositeID(MFTL_Triangle *T, MFTL_Vertex *V);
int MFTL_EdgeHashFromVertex(MFTL_Object *Object, MFTL_Vertex *Vertex, MFTL_Edge **List);
int MFTL_TriangleHasGhostVertices(MFTL_Triangle *t);
int MFTL_TriangleIsGhost(MFTL_Object *Object, MFTL_Triangle *t);
int MFTL_TriangleIsBoundary(MFTL_Object *Object, MFTL_Triangle *t);
void MFTL_ProcessorConnectivity(MFTL_Object *Object, int **Connect);


void MFTL_EdgeLengthStats(MFTL_Object *Object, MFTL_Stats *s);

#endif /* MFTLFUNCTIONS_H_ */
