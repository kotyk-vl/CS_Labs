/*****************************************************************************
 * Filename : stage2.h                                                 
 *   
 * Description : The is the implementation file for the stage2 module. 
 *
 * Original Author : Amit Rao (arao@synopsys.com)
 *
 *****************************************************************************/

#include "systemc.h"
#include "stage2.h"

//definition of multdiv method
void stage2::mult()
{
  double _a;
  double _b;

  _a = a.read();
  _b = b.read();
 
  
  r1.write(_a*_b);
  r2.write(6);

} // end of mult

