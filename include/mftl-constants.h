/*=====================================================================================
 *
 *        Filename:  MFTL-constants.h
 *
 *     Description: Constants used.
 *
 *         Version:  $Revision: 522 $
 *         Created:  Dec 24, 2009
 *
 *          Author:  Berend van Wachem (BvW), berend.van.wachem@gmail.com
 *       Copyright:  (c) Berend van Wachem.
 *
 *
 *
 *
 * MODIFICATIONS
 * File $Id: interpconveullag.c 522 2008-07-11 15:02:22Z berend $
 * Last modified by: $Author: berend $
 * On: $Date: 2008-07-11 16:02:22 +0100 (Fri, 11 Jul 2008) $
 *
 *
 *
 * =====================================================================================*/

#ifndef MFTLCONSTANTS_H_
#define MFTLCONSTANTS_H_

#define MFTL_STRINGLENGTH (600)

#define MF_NULL (NULL)

#define MFTL_YES (1)
#define MFTL_NO (0)

#define MFTL_PREALLOCATION (100)


/* Maximum number of vertices per processor */
#define MF_PROC_JUMP (1000000)

/* Some "general" sizes */
#define MF_SMALL (1.0e-7)
#define MFTL_VERYSMALL (1.0e-15)
#define MF_VERYVERYSMALL (1.0e-60)
#define MF_LARGE (1.0e+10)
#define MF_VERYLARGE (1.0e+13)
#define MF_LARGE_INT (10000000)
#define MFTL_ONETHIRD (0.33333333333333333333333333333333333333333333)
#define MFTL_ONESIXTH (0.16666666666666666666666666666666666666666667)

/* Generic definitions */
#define MF_MAX(a,b) ((a)>(b)?(a):(b))
#define MF_MIN(a,b) ((a)<(b)?(a):(b))
#define MF_SQ(x) ( (x) * (x) )
#define MFTL_ABS(x) (((x) < 0) ? -(x) : (x))

/*Value of PI added by M.R. Pivello at 31/07/2012. */
#define MF_PI (3.1415926535897932384626e0)
#define MF_TWO_PI (6.28318530717958647693e0)
#define MF_HALF_PI (1.57079632679489661923e0)


#endif /* MFTLCONSTANTS_H_ */
