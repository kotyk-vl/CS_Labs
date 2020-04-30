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

#define NS * 1e-9

int sc_main(int ac, char *av[])
{
  //Signals
	sc_signal<int>x;
	sc_signal<int>y;
	sc_signal<int>o1;
  sc_signal<int>o2;
  sc_signal<int> r1;
  sc_signal<int> r2;
  //Clock

  sc_clock clk ("clk",20 );

  stage1 S1("stage1");              //instance of `stage1' module
  //Named port binding
  S1.x(x=6);
  S1.y(y=161);
  S1.o1(o1);
  S1.o2(o2);
  S1.clk(clk);

  
  stage2 S2("stage2");              //instance of `stage2' module
  S2(o1, o2, r1, r2, clk );  //Positional port binding

  sc_initialize();                  //Initialize simulation

   sc_start(1000);

   	std::cout << "x: " << x.read() << std::endl;
    std::cout << "y: " << y.read() << std::endl;

    std::cout << "r1: " << r1.read() << std::endl;
    std::cout << "r2: " << r2.read() << std::endl;


  return 0;
}

