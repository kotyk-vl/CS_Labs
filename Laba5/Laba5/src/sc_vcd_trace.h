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

     sc_vcd_trace.h - implementation of VCD tracing.

     Original Author - Abhijit Ghosh. Synopsys, Inc. (ghosh@synopsys.com)

******************************************************************************/


/******************************************************************************

    MODIFICATION LOG - modifiers, enter your name, affliation and
    changes you are making here:

    Modifier Name & Affiliation:
    Description of Modification:
    

******************************************************************************/


/*******************************************************************

   Acknowledgement: The tracing mechanism is based on the tracing
   mechanism developed at Infineon (formerly Siemens HL). Though this
   code is somewhat different, and significantly enhanced, the basics
   are identical to what was originally contributed by Infineon.  The
   contribution of Infineon in the development of this tracing
   technology is hereby acknowledged.

********************************************************************/

#ifndef SC_VCD_TRACE_H
#define SC_VCD_TRACE_H

#include <stdio.h>
#include "sc_trace.h"
#include "sc_vector.h"

class vcd_trace;  // defined in vcd_trace.cc


class vcd_trace_file : public sc_trace_file {
public:
    void sc_set_vcd_time_unit(int exponent10_seconds); // -7 -> 100ns

    // Create a Vcd trace file.
    // `Name' forms the base of the name to which `.vcd' is added.
    vcd_trace_file(const char *name);

    // Flush results and close file.
    ~vcd_trace_file();

protected:
    // These are all virtual functions in sc_trace_file and
    // they need to be defined here.

    // Trace a boolean object (single bit)
     void trace(const bool& object, const sc_string& name);

    // Trace a sc_logic object (single bit)
     void trace(const sc_logic& object, const sc_string& name);

    // Trace a sc_bool_vector
     void trace(const sc_bool_vector& object, const sc_string& name);

    // Trace a sc_logic_vector
     void trace(const sc_logic_vector& object, const sc_string& name);
    
    // Trace an unsigned char with the given width
     void trace(const unsigned char& object, const sc_string& name, int width);

    // Trace an unsigned short with the given width
     void trace(const unsigned short& object, const sc_string& name, int width);

    // Trace an unsigned int with the given width
     void trace(const unsigned int& object, const sc_string& name, int width);

    // Trace an unsigned long with the given width
     void trace(const unsigned long& object, const sc_string& name, int width);

    // Trace a signed char with the given width
     void trace(const char& object, const sc_string& name, int width);

    // Trace a signed short with the given width
     void trace(const short& object, const sc_string& name, int width);

    // Trace a signed int with the given width
     void trace(const int& object, const sc_string& name, int width);

    // Trace a signed long with the given width
     void trace(const long& object, const sc_string& name, int width);
    
    // Trace a float
     void trace(const float& object, const sc_string& name);

    // Trace a double
     void trace(const double& object, const sc_string& name);

    // Trace sc_signal<sc_bool_vector>
     void trace(const sc_signal_bool_vector& object, const sc_string& name);

    // Trace sc_signal<sc_logic_vector>
     void trace(const sc_signal_logic_vector& object, const sc_string& name);

    // Trace sc_uint_base
     void trace (const sc_uint_base& object, const sc_string& name);

    // Trace sc_int_base
     void trace (const sc_int_base& object, const sc_string& name);

    // Trace sc_unsigned
     void trace (const sc_unsigned& object, const sc_string& name);

    // Trace sc_signed
     void trace (const sc_signed& object, const sc_string& name);

#ifdef SC_INCLUDE_FX
    // Trace sc_fxval
    void trace( const sc_fxval& object, const sc_string& name );

    // Trace sc_fxval_fast
    void trace( const sc_fxval_fast& object, const sc_string& name );

    // Trace sc_fxnum
    void trace( const sc_fxnum& object, const sc_string& name );

    // Trace sc_fxnum_fast
    void trace( const sc_fxnum_fast& object, const sc_string& name );
#endif

    // Trace resolved signal
     void trace (const sc_signal_resolved& object, const sc_string& name);

    // Trace resolved signal vector
     void trace (const sc_signal_resolved_vector& object, const sc_string& name);
  
    // Trace an enumerated object - where possible output the enumeration literals
    // in the trace file. Enum literals is a null terminated array of null
    // terminated char* literal strings.
     void trace(const unsigned& object, const sc_string& name, const char** enum_literals);

    // Output a comment to the trace file
     void write_comment(const sc_string& comment);

    // Also trace transitions between delta cycles if flag is true.
     void delta_cycles(bool flag);

    // Write trace info for cycle.
     void cycle(bool delta_cycle);
    
private:
    // Initialize the tracing
    void initialize();
    // Create VCD names for each variable
    void create_vcd_name(sc_string* p_destination);
    
    // Array to store the variables traced
    sc_pvector<vcd_trace*> traces;
    // Pointer to the file that needs to be written
    FILE* fp;

    double timescale_unit;      // in seconds
    bool timescale_set_by_user; // = 1 means set by user
    bool trace_delta_cycles;    // = 1 means trace the delta cycles
    bool initialized;           // = 1 means initialized

    unsigned vcd_name_index;    // Number of variables traced

    unsigned previous_time_units_low, previous_time_units_high; // Previous time unit as 64-bit integer
};

// Create VCD file
extern sc_trace_file *sc_create_vcd_trace_file(const char* name);
extern void sc_close_vcd_trace_file( sc_trace_file* tf );

#endif
