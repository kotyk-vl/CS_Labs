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

    sc_fixed.h - 

    Original Author: Martin Janssen. Synopsys, Inc. (mjanssen@synopsys.com)

******************************************************************************/

/******************************************************************************

    MODIFICATION LOG - modifiers, enter your name, affliation and
    changes you are making here:

    Modifier Name & Affiliation:
    Description of Modification:
    

******************************************************************************/


#ifndef SC_FIXED_H
#define SC_FIXED_H


#ifndef   SC_FIX_H
#include "sc_fix.h"
#endif


// ----------------------------------------------------------------------------
//  TEMPLATE CLASS : sc_fixed
//
//  "Constrained" signed fixed-point class; arbitrary precision.
// ----------------------------------------------------------------------------

template <int W, int I,
	  sc_q_mode Q = _SC_DEFAULT_Q_MODE,
	  sc_o_mode O = _SC_DEFAULT_O_MODE, int N = _SC_DEFAULT_N_BITS>
class sc_fixed : public sc_fix
{

public:

    // constructors

    sc_fixed( sc_fxnum_observer* = 0 );
    sc_fixed( const sc_fxcast_switch&, sc_fxnum_observer* = 0 );

#define DECL_CTORS_T(tp)                                                      \
    sc_fixed( tp, sc_fxnum_observer* = 0 );                                   \
    sc_fixed( tp, const sc_fxcast_switch&, sc_fxnum_observer* = 0 );

    DECL_CTORS_T(short)
    DECL_CTORS_T(unsigned short)
    DECL_CTORS_T(int)
    DECL_CTORS_T(unsigned int)
    DECL_CTORS_T(long)
    DECL_CTORS_T(unsigned long)
    DECL_CTORS_T(float)
    DECL_CTORS_T(double)
    DECL_CTORS_T(const char*)
    DECL_CTORS_T(int64)
    DECL_CTORS_T(uint64)
    DECL_CTORS_T(const sc_int_base&)
    DECL_CTORS_T(const sc_uint_base&)
    DECL_CTORS_T(const sc_signed&)
    DECL_CTORS_T(const sc_unsigned&)
    DECL_CTORS_T(const sc_fxval&)
    DECL_CTORS_T(const sc_fxval_fast&)
    DECL_CTORS_T(const sc_fxnum&)
    DECL_CTORS_T(const sc_fxnum_fast&)

#undef DECL_CTORS_T


    // assignment operators

#define DECL_ASN_OP_T(op,tp)                                                  \
    sc_fixed& operator op ( tp );

#define DECL_ASN_OP(op)                                                       \
    DECL_ASN_OP_T(op,short)                                                   \
    DECL_ASN_OP_T(op,unsigned short)                                          \
    DECL_ASN_OP_T(op,int)                                                     \
    DECL_ASN_OP_T(op,unsigned int)                                            \
    DECL_ASN_OP_T(op,long)                                                    \
    DECL_ASN_OP_T(op,unsigned long)                                           \
    DECL_ASN_OP_T(op,float)                                                   \
    DECL_ASN_OP_T(op,double)                                                  \
    DECL_ASN_OP_T(op,const char*)                                             \
    DECL_ASN_OP_T(op,int64)                                                   \
    DECL_ASN_OP_T(op,uint64)                                                  \
    DECL_ASN_OP_T(op,const sc_int_base&)                                      \
    DECL_ASN_OP_T(op,const sc_uint_base&)                                     \
    DECL_ASN_OP_T(op,const sc_signed&)                                        \
    DECL_ASN_OP_T(op,const sc_unsigned&)                                      \
    DECL_ASN_OP_T(op,const sc_fxval&)                                         \
    DECL_ASN_OP_T(op,const sc_fxval_fast&)                                    \
    DECL_ASN_OP_T(op,const sc_fxnum&)                                         \
    DECL_ASN_OP_T(op,const sc_fxnum_fast&)

    DECL_ASN_OP(=)

    DECL_ASN_OP(*=)
    DECL_ASN_OP(/=)
    DECL_ASN_OP(+=)
    DECL_ASN_OP(-=)

    DECL_ASN_OP_T(<<=,int)
    DECL_ASN_OP_T(>>=,int)

    DECL_ASN_OP_T(&=,const sc_fix&)
    DECL_ASN_OP_T(&=,const sc_fix_fast&)
    DECL_ASN_OP_T(|=,const sc_fix&)
    DECL_ASN_OP_T(|=,const sc_fix_fast&)
    DECL_ASN_OP_T(^=,const sc_fix&)
    DECL_ASN_OP_T(^=,const sc_fix_fast&)

#undef DECL_ASN_OP_T
#undef DECL_ASN_OP


    // auto-increment and auto-decrement

    const sc_fxval operator ++ ( int );
    const sc_fxval operator -- ( int );

    sc_fixed& operator ++ ();
    sc_fixed& operator -- ();

};


// ----------------------------------------------------------------------------
//  TEMPLATE CLASS : sc_fixed_fast
//
//  "Constrained" signed fixed-point class; limited precision.
// ----------------------------------------------------------------------------

template <int W, int I,
	  sc_q_mode Q = _SC_DEFAULT_Q_MODE,
	  sc_o_mode O = _SC_DEFAULT_O_MODE, int N = _SC_DEFAULT_N_BITS>
class sc_fixed_fast : public sc_fix_fast
{

public:

    // constructors

    sc_fixed_fast( sc_fxnum_fast_observer* = 0 );
    sc_fixed_fast( const sc_fxcast_switch&, sc_fxnum_fast_observer* = 0 );

#define DECL_CTORS_T(tp)                                                      \
    sc_fixed_fast( tp, sc_fxnum_fast_observer* = 0 );                         \
    sc_fixed_fast( tp, const sc_fxcast_switch&, sc_fxnum_fast_observer* = 0 );

    DECL_CTORS_T(short)
    DECL_CTORS_T(unsigned short)
    DECL_CTORS_T(int)
    DECL_CTORS_T(unsigned int)
    DECL_CTORS_T(long)
    DECL_CTORS_T(unsigned long)
    DECL_CTORS_T(float)
    DECL_CTORS_T(double)
    DECL_CTORS_T(const char*)
    DECL_CTORS_T(int64)
    DECL_CTORS_T(uint64)
    DECL_CTORS_T(const sc_int_base&)
    DECL_CTORS_T(const sc_uint_base&)
    DECL_CTORS_T(const sc_signed&)
    DECL_CTORS_T(const sc_unsigned&)
    DECL_CTORS_T(const sc_fxval&)
    DECL_CTORS_T(const sc_fxval_fast&)
    DECL_CTORS_T(const sc_fxnum&)
    DECL_CTORS_T(const sc_fxnum_fast&)

#undef DECL_CTORS_T


    // assignment operators

#define DECL_ASN_OP_T(op,tp)                                                  \
    sc_fixed_fast& operator op ( tp );

#define DECL_ASN_OP(op)                                                       \
    DECL_ASN_OP_T(op,short)                                                   \
    DECL_ASN_OP_T(op,unsigned short)                                          \
    DECL_ASN_OP_T(op,int)                                                     \
    DECL_ASN_OP_T(op,unsigned int)                                            \
    DECL_ASN_OP_T(op,long)                                                    \
    DECL_ASN_OP_T(op,unsigned long)                                           \
    DECL_ASN_OP_T(op,float)                                                   \
    DECL_ASN_OP_T(op,double)                                                  \
    DECL_ASN_OP_T(op,const char*)                                             \
    DECL_ASN_OP_T(op,int64)                                                   \
    DECL_ASN_OP_T(op,uint64)                                                  \
    DECL_ASN_OP_T(op,const sc_int_base&)                                      \
    DECL_ASN_OP_T(op,const sc_uint_base&)                                     \
    DECL_ASN_OP_T(op,const sc_signed&)                                        \
    DECL_ASN_OP_T(op,const sc_unsigned&)                                      \
    DECL_ASN_OP_T(op,const sc_fxval&)                                         \
    DECL_ASN_OP_T(op,const sc_fxval_fast&)                                    \
    DECL_ASN_OP_T(op,const sc_fxnum&)                                         \
    DECL_ASN_OP_T(op,const sc_fxnum_fast&)

    DECL_ASN_OP(=)

    DECL_ASN_OP(*=)
    DECL_ASN_OP(/=)
    DECL_ASN_OP(+=)
    DECL_ASN_OP(-=)

    DECL_ASN_OP_T(<<=,int)
    DECL_ASN_OP_T(>>=,int)

    DECL_ASN_OP_T(&=,const sc_fix&)
    DECL_ASN_OP_T(&=,const sc_fix_fast&)
    DECL_ASN_OP_T(|=,const sc_fix&)
    DECL_ASN_OP_T(|=,const sc_fix_fast&)
    DECL_ASN_OP_T(^=,const sc_fix&)
    DECL_ASN_OP_T(^=,const sc_fix_fast&)

#undef DECL_ASN_OP_T
#undef DECL_ASN_OP


    // auto-increment and auto-decrement

    const sc_fxval_fast operator ++ ( int );
    const sc_fxval_fast operator -- ( int );

    sc_fixed_fast& operator ++ ();
    sc_fixed_fast& operator -- ();

};


// IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII

// ----------------------------------------------------------------------------
//  TEMPLATE CLASS : sc_fixed
//
//  "Constrained" signed fixed-point class; arbitrary precision.
// ----------------------------------------------------------------------------

template<int W, int I, sc_q_mode Q, sc_o_mode O, int N>
inline
sc_fixed<W,I,Q,O,N>::sc_fixed( sc_fxnum_observer* observer_ )
: sc_fix( W, I, Q, O, N, observer_ )
{}

template<int W, int I, sc_q_mode Q, sc_o_mode O, int N>
inline
sc_fixed<W,I,Q,O,N>::sc_fixed( const sc_fxcast_switch& cast_sw,
			       sc_fxnum_observer* observer_ )
: sc_fix( W, I, Q, O, N, cast_sw, observer_ )
{}

#define DEFN_CTORS_T(tp)                                                      \
template<int W, int I, sc_q_mode Q, sc_o_mode O, int N>                       \
inline                                                                        \
sc_fixed<W,I,Q,O,N>::sc_fixed( tp a,                                          \
			       sc_fxnum_observer* observer_ )                 \
: sc_fix( a, W, I, Q, O, N, observer_ )                                       \
{}                                                                            \
                                                                              \
template<int W, int I, sc_q_mode Q, sc_o_mode O, int N>                       \
inline                                                                        \
sc_fixed<W,I,Q,O,N>::sc_fixed( tp a,                                          \
			       const sc_fxcast_switch& cast_sw,               \
			       sc_fxnum_observer* observer_ )                 \
: sc_fix( a, W, I, Q, O, N, cast_sw, observer_ )                              \
{}

DEFN_CTORS_T(short)
DEFN_CTORS_T(unsigned short)
DEFN_CTORS_T(int)
DEFN_CTORS_T(unsigned int)
DEFN_CTORS_T(long)
DEFN_CTORS_T(unsigned long)
DEFN_CTORS_T(float)
DEFN_CTORS_T(double)
DEFN_CTORS_T(const char*)
DEFN_CTORS_T(int64)
DEFN_CTORS_T(uint64)
DEFN_CTORS_T(const sc_int_base&)
DEFN_CTORS_T(const sc_uint_base&)
DEFN_CTORS_T(const sc_signed&)
DEFN_CTORS_T(const sc_unsigned&)
DEFN_CTORS_T(const sc_fxval&)
DEFN_CTORS_T(const sc_fxval_fast&)
DEFN_CTORS_T(const sc_fxnum&)
DEFN_CTORS_T(const sc_fxnum_fast&)

#undef DEFN_CTORS_T


// assignment operators

#define DEFN_ASN_OP_T(op,tp)                                                  \
template<int W, int I, sc_q_mode Q, sc_o_mode O, int N>                       \
inline                                                                        \
sc_fixed<W,I,Q,O,N>&                                                          \
sc_fixed<W,I,Q,O,N>::operator op ( tp a )                                     \
{                                                                             \
    sc_fix::operator op ( a );                                                \
    return *this;                                                             \
}

#define DEFN_ASN_OP(op)                                                       \
DEFN_ASN_OP_T(op,short)                                                       \
DEFN_ASN_OP_T(op,unsigned short)                                              \
DEFN_ASN_OP_T(op,int)                                                         \
DEFN_ASN_OP_T(op,unsigned int)                                                \
DEFN_ASN_OP_T(op,long)                                                        \
DEFN_ASN_OP_T(op,unsigned long)                                               \
DEFN_ASN_OP_T(op,float)                                                       \
DEFN_ASN_OP_T(op,double)                                                      \
DEFN_ASN_OP_T(op,const char*)                                                 \
DEFN_ASN_OP_T(op,int64)                                                       \
DEFN_ASN_OP_T(op,uint64)                                                      \
DEFN_ASN_OP_T(op,const sc_int_base&)                                          \
DEFN_ASN_OP_T(op,const sc_uint_base&)                                         \
DEFN_ASN_OP_T(op,const sc_signed&)                                            \
DEFN_ASN_OP_T(op,const sc_unsigned&)                                          \
DEFN_ASN_OP_T(op,const sc_fxval&)                                             \
DEFN_ASN_OP_T(op,const sc_fxval_fast&)                                        \
DEFN_ASN_OP_T(op,const sc_fxnum&)                                             \
DEFN_ASN_OP_T(op,const sc_fxnum_fast&)

DEFN_ASN_OP(=)

DEFN_ASN_OP(*=)
DEFN_ASN_OP(/=)
DEFN_ASN_OP(+=)
DEFN_ASN_OP(-=)

DEFN_ASN_OP_T(<<=,int)
DEFN_ASN_OP_T(>>=,int)

DEFN_ASN_OP_T(&=,const sc_fix&)
DEFN_ASN_OP_T(&=,const sc_fix_fast&)
DEFN_ASN_OP_T(|=,const sc_fix&)
DEFN_ASN_OP_T(|=,const sc_fix_fast&)
DEFN_ASN_OP_T(^=,const sc_fix&)
DEFN_ASN_OP_T(^=,const sc_fix_fast&)

#undef DEFN_ASN_OP_T
#undef DEFN_ASN_OP


// auto-increment and auto-decrement

template<int W, int I, sc_q_mode Q, sc_o_mode O, int N>
inline
const sc_fxval
sc_fixed<W,I,Q,O,N>::operator ++ ( int )
{
    return sc_fxval( sc_fix::operator ++ ( 0 ) );
}

template<int W, int I, sc_q_mode Q, sc_o_mode O, int N>
inline
const sc_fxval
sc_fixed<W,I,Q,O,N>::operator -- ( int )
{
    return sc_fxval( sc_fix::operator -- ( 0 ) );
}

template<int W, int I, sc_q_mode Q, sc_o_mode O, int N>
inline
sc_fixed<W,I,Q,O,N>&
sc_fixed<W,I,Q,O,N>::operator ++ ()
{
    sc_fix::operator ++ ();
    return *this;
}

template<int W, int I, sc_q_mode Q, sc_o_mode O, int N>
inline
sc_fixed<W,I,Q,O,N>&
sc_fixed<W,I,Q,O,N>::operator -- ()
{
    sc_fix::operator -- ();
    return *this;
}


// ----------------------------------------------------------------------------
//  TEMPLATE CLASS : sc_fixed_fast
//
//  "Constrained" signed fixed-point class; limited precision.
// ----------------------------------------------------------------------------

template<int W, int I, sc_q_mode Q, sc_o_mode O, int N>
inline
sc_fixed_fast<W,I,Q,O,N>::sc_fixed_fast( sc_fxnum_fast_observer* observer_ )
: sc_fix_fast( W, I, Q, O, N, observer_ )
{}

template<int W, int I, sc_q_mode Q, sc_o_mode O, int N>
inline
sc_fixed_fast<W,I,Q,O,N>::sc_fixed_fast( const sc_fxcast_switch& cast_sw,
					 sc_fxnum_fast_observer* observer_ )
: sc_fix_fast( W, I, Q, O, N, cast_sw, observer_ )
{}

#define DEFN_CTORS_T(tp)                                                      \
template<int W, int I, sc_q_mode Q, sc_o_mode O, int N>                       \
inline                                                                        \
sc_fixed_fast<W,I,Q,O,N>::sc_fixed_fast( tp a,                                \
					 sc_fxnum_fast_observer* observer_ )  \
: sc_fix_fast( a, W, I, Q, O, N, observer_ )                                  \
{}                                                                            \
                                                                              \
template<int W, int I, sc_q_mode Q, sc_o_mode O, int N>                       \
inline                                                                        \
sc_fixed_fast<W,I,Q,O,N>::sc_fixed_fast( tp a,                                \
					 const sc_fxcast_switch& cast_sw,     \
					 sc_fxnum_fast_observer* observer_ )  \
: sc_fix_fast( a, W, I, Q, O, N, cast_sw, observer_ )                         \
{}

DEFN_CTORS_T(short)
DEFN_CTORS_T(unsigned short)
DEFN_CTORS_T(int)
DEFN_CTORS_T(unsigned int)
DEFN_CTORS_T(long)
DEFN_CTORS_T(unsigned long)
DEFN_CTORS_T(float)
DEFN_CTORS_T(double)
DEFN_CTORS_T(const char*)
DEFN_CTORS_T(int64)
DEFN_CTORS_T(uint64)
DEFN_CTORS_T(const sc_int_base&)
DEFN_CTORS_T(const sc_uint_base&)
DEFN_CTORS_T(const sc_signed&)
DEFN_CTORS_T(const sc_unsigned&)
DEFN_CTORS_T(const sc_fxval&)
DEFN_CTORS_T(const sc_fxval_fast&)
DEFN_CTORS_T(const sc_fxnum&)
DEFN_CTORS_T(const sc_fxnum_fast&)

#undef DEFN_CTORS_T


// assignment operators

#define DEFN_ASN_OP_T(op,tp)                                                  \
template<int W, int I, sc_q_mode Q, sc_o_mode O, int N>                       \
inline                                                                        \
sc_fixed_fast<W,I,Q,O,N>&                                                     \
sc_fixed_fast<W,I,Q,O,N>::operator op ( tp a )                                \
{                                                                             \
    sc_fix_fast::operator op ( a );                                           \
    return *this;                                                             \
}

#define DEFN_ASN_OP(op)                                                       \
DEFN_ASN_OP_T(op,short)                                                       \
DEFN_ASN_OP_T(op,unsigned short)                                              \
DEFN_ASN_OP_T(op,int)                                                         \
DEFN_ASN_OP_T(op,unsigned int)                                                \
DEFN_ASN_OP_T(op,long)                                                        \
DEFN_ASN_OP_T(op,unsigned long)                                               \
DEFN_ASN_OP_T(op,float)                                                       \
DEFN_ASN_OP_T(op,double)                                                      \
DEFN_ASN_OP_T(op,const char*)                                                 \
DEFN_ASN_OP_T(op,int64)                                                       \
DEFN_ASN_OP_T(op,uint64)                                                      \
DEFN_ASN_OP_T(op,const sc_int_base&)                                          \
DEFN_ASN_OP_T(op,const sc_uint_base&)                                         \
DEFN_ASN_OP_T(op,const sc_signed&)                                            \
DEFN_ASN_OP_T(op,const sc_unsigned&)                                          \
DEFN_ASN_OP_T(op,const sc_fxval&)                                             \
DEFN_ASN_OP_T(op,const sc_fxval_fast&)                                        \
DEFN_ASN_OP_T(op,const sc_fxnum&)                                             \
DEFN_ASN_OP_T(op,const sc_fxnum_fast&)

DEFN_ASN_OP(=)

DEFN_ASN_OP(*=)
DEFN_ASN_OP(/=)
DEFN_ASN_OP(+=)
DEFN_ASN_OP(-=)

DEFN_ASN_OP_T(<<=,int)
DEFN_ASN_OP_T(>>=,int)

DEFN_ASN_OP_T(&=,const sc_fix&)
DEFN_ASN_OP_T(&=,const sc_fix_fast&)
DEFN_ASN_OP_T(|=,const sc_fix&)
DEFN_ASN_OP_T(|=,const sc_fix_fast&)
DEFN_ASN_OP_T(^=,const sc_fix&)
DEFN_ASN_OP_T(^=,const sc_fix_fast&)

#undef DEFN_ASN_OP_T
#undef DEFN_ASN_OP


// auto-increment and auto-decrement

template<int W, int I, sc_q_mode Q, sc_o_mode O, int N>
inline
const sc_fxval_fast
sc_fixed_fast<W,I,Q,O,N>::operator ++ ( int )
{
    return sc_fxval_fast( sc_fix_fast::operator ++ ( 0 ) );
}

template<int W, int I, sc_q_mode Q, sc_o_mode O, int N>
inline
const sc_fxval_fast
sc_fixed_fast<W,I,Q,O,N>::operator -- ( int )
{
    return sc_fxval_fast( sc_fix_fast::operator -- ( 0 ) );
}

template<int W, int I, sc_q_mode Q, sc_o_mode O, int N>
inline
sc_fixed_fast<W,I,Q,O,N>&
sc_fixed_fast<W,I,Q,O,N>::operator ++ ()
{
    sc_fix_fast::operator ++ ();
    return *this;
}

template<int W, int I, sc_q_mode Q, sc_o_mode O, int N>
inline
sc_fixed_fast<W,I,Q,O,N>&
sc_fixed_fast<W,I,Q,O,N>::operator -- ()
{
    sc_fix_fast::operator -- ();
    return *this;
}


#endif

// Taf!
