/*=====================================================================================
 *
 *        Filename:  mftl.h
 *
 *     Description:  Triangulization Library Header file with Data structure and external functions.
 *
 *         Version:  $Revision: 522 $
 *         Created:  Oct 13, 2009
 *
 *          Author:  Berend van Wachem (BvW), berend.van.wachem@gmail.com
 *                   M�rcio Ricardo Pivello, pivello@gmail.com
 *
 * =====================================================================================*/

#ifndef MFTL_H_
#define MFTL_H_

#include <mpi.h>
#include <stdio.h>
#include "uthash.h"
#include "mftl-constants.h"
#include "devcompileoptions.h"

//#define DEBUGPRINT

/*************************************************************************/
/*  Data structures                                                      */
/*************************************************************************/
extern double MFTL_TOLERANCE;

struct MFTL_Object_size
{
  long unsigned int MFTL_arrayindex[3];
  long unsigned int MFTL_sizeofobject;
};

/* define a point in space */
struct MFTL_Point
{
  double x[3];
  int processor;
  int body;
  int address;
  int addresslocal;
  int i,j,k,l; // block number

  /* For hashtable */
  int id;
  UT_hash_handle hh;
};

/* Define the structure for a vertex; a point in space */
struct MFTL_Vertex
{
  double x[3];

  int processor;
  short move;

  /* For hashtable */
  int id;
  UT_hash_handle hh;

};

/* Define the structure for an Edge: a connection between two vertices. An edge is also the barrier between two
 * triangles and contains two pointers to the triangles
 */
struct MFTL_Edge
{
  struct MFTL_Vertex *Vertex[2];
  int VertexID[2];
  struct MFTL_Triangle *Triangle[2];
  int TriangleID[2];

  /* The processor which has the original copy of this vertex */
  int processor;
  /* Processor number of triangles' processors of which the edge belong to */
#ifdef MFTL_DEV
  int procNo;
#endif

  /* For hashtable */
  int id;
  UT_hash_handle hh;
};

struct AuxPointFluidData
{
  double x[7][3];       // position of surrounding cells
  double v[7][3];       // velocity of surrounding cells
  double p[7];          // pressure of surrounding cells
  int IIB[7];           // IIB tags of surrounding cells
};


/* Structure that stores some of the triangle properties e.g. auxiliary points */
struct MFTL_TriangleProperties
{
  //  Auxiliary points
  struct MFTL_Point AuxPoints[3];
  double *AuxPress;

  // Data of surrounding points (for interpolation)
  struct AuxPointFluidData *AuxPointFluidData;

  /* force components of the triangle */
  double fmu[3];
  double fforcing[3];
  double fcoll[3];
  double fsigma[3];

  /* pressure velocity & velocity gradients at the triangle centre */
  double pressure;
  double velocity[3];
  double gradV[9];

#ifdef MFTL_DEV
  int closestPointID;
#endif
};

/* Defines the structure of a triangle. A triangle consists of 3 edges. Moreover, a triangle has 3 vertices */
struct MFTL_Triangle
{
  struct MFTL_Edge *Edge[3];
  struct MFTL_Vertex *Vertex[3];

  struct MFTL_TriangleProperties *Properties;
  /* The processor which has dominance over this triangle */
  int mainprocessor;

  double center[3];
  double normal[3];
  double area;

  // The data of the cell containing centre
  int I, J, K, blk, centerproc;

  /* For hashtable */
  int id;
  UT_hash_handle hh;
};

/* An object contains a number of triangles and also has pointers to the edges and vertices */
struct MFTL_Object
{
  /* Communicator on object */
  MPI_Comm OBJECT_COMM_WORLD;

  /* Sizes of one part in the object */
  struct MFTL_Object_size Size;

  struct MFTL_Triangle *Triangles;
  struct MFTL_Edge *Edges;
  struct MFTL_Vertex *Vertexes;

  /* Current processor */
  int rank;

  /* Total number of processors */
  int nproc;

  /* Min, Max location of object. The global domain limits. */
  double globalxmin[3], globalxmax[3];

  /* Number of "cuts" in each direction */
  int Xcut, Ycut, Zcut;

  double *ownershiprangemin[3], *ownershiprangemax[3];

  /* For hashtable */
  int id;
  UT_hash_handle hh;
};

/* An light version of object structure containing local surface with triangle egdes and vertexes */
struct MFTL_Surface
{
  struct MFTL_Triangle *Triangles;
  struct MFTL_Edge *Edges;
  struct MFTL_Vertex *Vertexes;

  /* Current processor */
  int rank;
};
// General linked list
struct MFTL_GeneralList
{
  /* data in list */
  void *Data;

  /* For hashtable */
  int id;
  UT_hash_handle hh;
};

/* Moment of a triangle/set of triangles */
struct MFTL_Moment {
    double Area;
    double Center[3];
    double s[3][3];
};

// Bounding box
struct MFTL_obb {
  // Bounding box parameters
  double Rotation[3][3];
  double Displacement[3];
  double Dimensions[3];

  /* Hash list of triangle numbers */
  int *TriangleHashes;

  /* Number of triangles in Bounding Box */
  int NumTriangles;

  /* Tree functionality */
  struct MFTL_obb *left;
  struct MFTL_obb *right;
};

// Unit/Orthogonal bounding box
struct MFTL_obb_UO {
  // Bounding box parameters
  double Displacement[3];
  double Dimensions[3];
};

// List of overlapping triangles
struct MFTL_TrianglePair
{
  /* Data in list */
  int triangle[2];

  /* For hashtable */
  int id;
  UT_hash_handle hh;
};

struct MFTL_Overlap {
	/* Size of overlap */
	double Volume;
	double AreaTriA;
	double AreaTriB;

	/* real space */
	double AverageSurfaceNorm[3]; /*(Normal A - Normal B)/2*/
	double RealCentreOfVolume[3];
	double EffectiveRadiusOfCurvature;

	/* Tags of the triangles that overlap to create it */
	int ID_A;
	int ID_B;

	/* list handleing */
	int id;
	UT_hash_handle hh;
};

struct MFTL_Stats
{
  double min, max, sum, sum2, mean, stddev;
  int n;
};

struct MFTL_Parser
{
    int nproc, nfiles;
    int M[3];
    double global_xL[3], global_xU[3];
    double **local_xL, **local_xU;
    char **geo_file, topology[MFTL_STRINGLENGTH], case_name[MFTL_STRINGLENGTH];
};


/* Typedefs, to use optionally */
typedef struct MFTL_GeneralList  MFTL_GeneralList;
typedef struct MFTL_Object MFTL_Object;
typedef struct MFTL_Surface MFTL_Surface;
typedef struct MFTL_Triangle MFTL_Triangle;
typedef struct MFTL_Vertex MFTL_Vertex;
typedef struct MFTL_Point MFTL_Point;
typedef struct MFTL_Edge MFTL_Edge;
typedef struct MFTL_obb MFTL_BoundingBox;
typedef struct MFTL_obb_UO MFTL_UnitBoundingBox;
typedef struct MFTL_Moment MFTL_Moment;
typedef struct MFTL_TrianglePair MFTL_TrianglePair;
typedef struct MFTL_TriangleProperties MFTL_TriangleProperties;
typedef struct MFTL_Stats MFTL_Stats;
typedef struct MFTL_Parser MFTL_Parser;

/*************************************************************************/
/*  External MFTL functions                                              */
/*************************************************************************/
/*  Initialise/Finalise  Object */
int MFTLInitializeObject(MFTL_Object *Object, int M[3], double xmin[3], double xmax[3]);
int MFTLInitializeObjectWithComm(MFTL_Object *Object, int M[3], double xmin[3], double xmax[3], MPI_Comm ObjectComm);
int MFTLFinalizeObject(MFTL_Object *Object);
int MFTLCleanupObject(MFTL_Object *Object);
int MFTLRedefineDomainTopology(MFTL_Object* Object, double** proc_x_min, double** proc_x_max);
int MFTLInitializeObject2(MFTL_Object* Object, int nproc,
                          double global_xmin[3], double global_xmax[3],
                          double** proc_x_min, double** proc_x_max);
int MFTLInitializeObject3(MFTL_Object *Object, MPI_Fint *comm, int nproc,
                          double global_xmin[3], double global_xmax[3],
                          double* proc_x_min, double* proc_x_max);


/* General IO */
int MFTLThrowError(int i, char * string);
int MFTLGTSFileRead(MFTL_Object *Object, char filename[]);
int MFTLGTSFileCheck(MFTL_Object *Object );
int MFTLShowSummary(MFTL_Object *Object);
int MFTLWriteObjectToVTK(MFTL_Object *Object, char fname[]);
int MFTLWriteObjectToGTS(MFTL_Object *Object, char fname[]);
double MFTLSetTolerance (MFTL_Object *Object);

/* Generate Objects with MFTL */
int MFTLGenerateSphere(MFTL_Object *Object, int refine);
int MFTLGenerateFace( MFTL_Object *Object, MFTL_Vertex *Vertex[]);
int MFTLGenerateBox( MFTL_Object *Object, MFTL_Vertex *Vertex[]);
int MFTLGenerateCube( MFTL_Object *Object, int refine);

/* Redistributes an object in the parallel space */
int MFTLRedistributeObject(MFTL_Object *Object);
int MFTLSendTrianglesToProcWCenter(MFTL_Object *Object);
MFTL_Point * MFTLGatherPoints( MFTL_Object *Object, MFTL_Point *SendPoints);

/* Geometric operations */
double MFTLSurfaceCenter (MFTL_Object *Object, double cm[]);
double MFTLObjectVolume(MFTL_Object *Object);
int MFTLMomentOfInertia(MFTL_Object *Object, double MomentOfInetria[3][3], double *ObjectCenter, double density);

int MFTLScaleSurface(MFTL_Object *Object, double radius[3]);
int MFTLMoveBody(MFTL_Object *Object, double move[3]);
int MFTLRotateBody(MFTL_Object *Object, double angle[3], double centre[3]);

int MFTLFindTriagleCentres(MFTL_Object *Object);
int MFTLFindTriagleNormals(MFTL_Object *Object);
int MFTLFindTriagleAreas(MFTL_Object *Object);

/* Point functions  */
int MFTLPointInsideObjectBox (MFTL_UnitBoundingBox *BigBox, MFTL_Point *P);
int MFTLPointInsideObject (MFTL_Object *Object, MFTL_BoundingBox *Box, MFTL_Point *P);
int MFTLPointInsideObjectLocal (MFTL_Object *Object, MFTL_BoundingBox *Box, MFTL_Point *P);
double MFTLPointTriangleDistance (MFTL_Triangle *Triangle, MFTL_Point *P);
int MFTLAddUniquePointToList(MFTL_Point * P, MFTL_Point **List);

/* Surface intersection */
MFTL_Point * MFTLSurfaceIntersection (MFTL_Object * Object1, MFTL_BoundingBox *BBox1, MFTL_Object *Object2, MFTL_BoundingBox *BBox2);
MFTL_Point * MFTLSurfaceTriangleIntersection (MFTL_Object * Object1, MFTL_BoundingBox *BBox1, MFTL_Triangle *Triangle, MFTL_BoundingBox *BBox2);
int MFTLTriangleSurfaceIntersectionTest (MFTL_Object * Object1, MFTL_BoundingBox *BBox1, MFTL_Triangle *Triangle, MFTL_BoundingBox *BBox2);

/* Convex hull operations */
MFTL_Point * MFTLConvexPolygonVertexesSort(MFTL_Point *PointList, int * ISConvex);
double MFTLCentroidFromPoints(MFTL_Point * PointList, double * Center);
double MFTLPolygonAreaFromPoints (MFTL_Point * PointList);
MFTL_Surface * MFTLConvexHull(MFTL_Point *PointList);

/*  Bounding box generation */
MFTL_UnitBoundingBox * MFTLGenerateBigBoundingBox(MFTL_Object *Object, MFTL_BoundingBox *OrthoBox);
MFTL_BoundingBox * MFTLGenerateBoundingBox(MFTL_Object *Object, int aligned);
MFTL_BoundingBox MFTLTriangleBoundingBox(MFTL_Triangle *Triangle, int aligned);

/* Cleanup Functions */
int MFTLClearUnitBoundingBox(MFTL_UnitBoundingBox *BoundingBox);
int MFTLClearBoundingBox(MFTL_BoundingBox *BoundingBox);
int MFTLClearTriangleBoundingBox(MFTL_BoundingBox *BoundingBox);
int MFTLRemovePoints(MFTL_Point *Points);
int MFTLRemoveSurface(MFTL_Surface *Surface);


/*************************************************************************/
/* Constants definitions for functions                                  */
/*************************************************************************/
#define MFTL_ALIGNED (1)
#define MFTL_ORTHOGONAL (0)
#define MFTL_CLOSED (1)
#define MFTL_OPEN (0)

#endif /* MFTL_H_ */
