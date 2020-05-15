/******************************************************************************
    Copyright (c) 1996-2000 Synopsys, Inc.    ALL RIGHTS RESERVED

  The contents of this file are subject to the restrictions and limitations
  set forth in the SystemC(TM) Open Community License Software Download and
  Use License Version 1.1 (the "License"); you may not use this file except
  in compliance with such restrictions and limitations. You may obtain
  instructions on how to receive a copy of the License at
  http://www.systemc.org/. Software distributed by Original Contributor
  under the License is distributed on an "AS IS" basis, WITHOUT WARRANTY OF
  ANY KIND, either express or implied. See the License for the specific
  language governing rights and limitations under the License.

******************************************************************************/

/*****************************************************************************
 * Filename : stage1.h                                                     
 *   
 * Description : The is the interface file for the stage1 module. 
 *
 * Original Author : Amit Rao (arao@synopsys.com)
 *
 *****************************************************************************/
/******************************************************************************

    MODIFICATION LOG - modifiers, enter your name, affliation and
    changes you are making here:

    Modifier Name & Affiliation:
    Description of Modification:
    

******************************************************************************/

#ifndef STAGE1_H
#define STAGE1_H

struct stage1 : sc_module {

    sc_in<double> x;   //input 1
    sc_in<double> y;   //input 2
    sc_out<double> o1;  //output 1
    sc_out<double> o2; //output 2
    sc_in<bool>    clk;  //clock

    void sub();       //method implementing functionality

    //Counstructor
    SC_CTOR( stage1 ) {
        SC_METHOD( sub );   //Declare sub as SC_METHOD and  
		sensitive<<x<<y;
        sensitive_pos << clk;  //make it sensitive to positive clock edge
    }

	public:

};

#endif
