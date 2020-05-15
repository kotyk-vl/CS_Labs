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
 

/******************************************************************************
 
    paging.h -- Instruction Paging Unit 
 
    Original Author: Martin Wang. Synopsys, Inc. (mwang@synopsys.com)
 
******************************************************************************/
 
/******************************************************************************
 
    MODIFICATION LOG - modifiers, enter your name, affliation and
    changes you are making here:
 
    Modifier Name & Affiliation:
    Description of Modification:
 
 
******************************************************************************/

 


struct paging : sc_module {
        sc_in<unsigned >   paging_din; 	// input data       
        sc_in<bool>           paging_csin;    	// chip select        
        sc_in<bool>           paging_wein;    	// write enable       
        sc_in<unsigned >   logical_address; 	// logical address  
        sc_in<unsigned >   icache_din;      	// data from BIOS/icache
        sc_in<bool>           icache_validin;   // data valid bit 
        sc_in<bool>           icache_stall;     // stall IFU if busy

        sc_out<unsigned >  paging_dout;            // output data
        sc_out<bool>  	      paging_csout;           // output cs to cache/BIOS
        sc_out<bool>  	      paging_weout;           // write enable to cache/BIOS
        sc_out<unsigned >  physical_address;       // physical address 
        sc_out<unsigned >  dataout;        	      // dataout from memory
        sc_out<bool>  	      data_valid;             // data valid
        sc_out<bool>  	      stall_ifu;              // stall IFU if busy
	sc_in_clk 	      CLK;

        signed int pid_reg;             //CPU process ID register      

  SC_CTOR(paging) {
      SC_CTHREAD(entry, CLK.pos());
      pid_reg = 0;
  }
  
  void entry();
};

// EOF