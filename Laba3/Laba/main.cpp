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
 * Filename: main.cpp                                                  
 *   
 * Description : The is the top level file instantiating the modules and
 *               binding ports to signals 
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

#include "systemc.h"
#include "stage1.h"
#include "stage2.h"
#include "stage3.h"
#include "display.h"
#include "numgen.h"

#define NS * 1e-9

int sc_main(int ac, char *av[])
{
  //Signals
  sc_signal<double> in1;
  sc_signal<double> in2;
  sc_signal<double> sum;
  sc_signal<double> diff;
  sc_signal<double> prod;
  sc_signal<double> quot;
  sc_signal<double> powr;  
  //Clock
 // sc_signal<bool>   clk;
    //Clock
  sc_clock clk("Mod", 2.0, 0.5, 0.2, false);
  
  numgen N("numgen");               //instance of `numgen' module
  N(in1, in2, clk );                //Positional port binding

  
  stage1 S1("stage1");              //instance of `stage1' module
  //Named port binding
  S1.in1(in1);
  S1.in2(in2);
  S1.sum(sum);
  S1.diff(diff);
  S1.clk(clk);

  stage2 S2("stage2");              //instance of `stage2' module
  S2(sum, diff, prod, quot, clk );  //Positional port binding


  stage3 S3("stage3");              //instance of `stage3' module
  S3( prod, quot, powr, clk);       //Positional port binding

  
  display D("display");             //instance of `display' module
  D(powr,clk,diff);                     //Positional port binding 

  // Open VCD file
  sc_trace_file* wf = sc_create_vcd_trace_file("MainMod");
  // Dump the desired signals
  sc_trace(wf, in1, "in1");
  sc_trace(wf, in2, "in2");
  //sc_trace(wf, sum, "sum");
  sc_trace(wf, diff, "diff");
  sc_trace(wf, prod, "prod");
  sc_trace(wf, quot, "quot");
  sc_trace(wf, powr, "powr");
  sc_trace(wf, clk, "clk");

  sc_initialize();                  //Initialize simulation
  sc_start(clk, 20);
  sc_close_vcd_trace_file(wf);

  return 0;
}

