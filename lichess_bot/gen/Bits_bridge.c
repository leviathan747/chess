/*----------------------------------------------------------------------------
 * Description:   Methods for bridging to an external entity.
 *
 * External Entity:  Bits (Bits)
 * 
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#include "lichess_bot_sys_types.h"
#include "ARCH_bridge.h"
#include "Bits_bridge.h"
#include "ChessLib_bridge.h"
#include "LOG_bridge.h"
#include "TIM2_bridge.h"
#include "PROP_bridge.h"
#include "TIM_bridge.h"
#include "STRING_bridge.h"

/*
 * Bridge:  bitwise_and
 */
Escher_TimeStamp_t
Bits_bitwise_and( const Escher_TimeStamp_t p_a, const Escher_TimeStamp_t p_b )
{
  return p_a & p_b;
}


/*
 * Bridge:  bitwise_not
 */
Escher_TimeStamp_t
Bits_bitwise_not( const Escher_TimeStamp_t p_a )
{
  return ~p_a;
}


/*
 * Bridge:  bitwise_or
 */
Escher_TimeStamp_t
Bits_bitwise_or( const Escher_TimeStamp_t p_a, const Escher_TimeStamp_t p_b )
{
  return p_a | p_b;
}


/*
 * Bridge:  bitwise_xor
 */
Escher_TimeStamp_t
Bits_bitwise_xor( const Escher_TimeStamp_t p_a, const Escher_TimeStamp_t p_b )
{
  return p_a ^ p_b;
}


/*
 * Bridge:  left_shift
 */
Escher_TimeStamp_t
Bits_left_shift( const Escher_TimeStamp_t p_a, const i_t p_n )
{
  return p_a << p_n;
}


/*
 * Bridge:  right_shift
 */
Escher_TimeStamp_t
Bits_right_shift( const Escher_TimeStamp_t p_a, const i_t p_n )
{
  return p_a >> p_n;
}


/*
 * Bridge:  to_binary_string
 */
c_t *
Bits_to_binary_string( c_t A0xtumlsret[ESCHER_SYS_MAX_STRING_LEN], const Escher_TimeStamp_t p_a )
{
  // Initialize the binary string with "0b"
  A0xtumlsret[0] = '0';
  A0xtumlsret[1] = 'b';

  // Convert the unsigned long to a 64-bit binary string
  for (int i = 0; i < 64 && i < ESCHER_SYS_MAX_STRING_LEN - 3; i++) {
    A0xtumlsret[2 + i] = (p_a & (1UL << (63 - i))) ? '1' : '0';
  }

  // Null-terminate the string
  A0xtumlsret[ESCHER_SYS_MAX_STRING_LEN] = '\0';
  if (ESCHER_SYS_MAX_STRING_LEN > 67) {
    A0xtumlsret[66] = '\0';
  }
}


/*
 * Bridge:  unsigned_right_shift
 */
Escher_TimeStamp_t
Bits_unsigned_right_shift( const Escher_TimeStamp_t p_a, const i_t p_n )
{
  return p_a >> p_n;
}


/*
 * Bridge:  zero
 */
Escher_TimeStamp_t
Bits_zero()
{
  return 0l;
}

