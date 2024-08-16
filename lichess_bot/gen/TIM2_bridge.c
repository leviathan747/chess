/*----------------------------------------------------------------------------
 * Description:   Methods for bridging to an external entity.
 *
 * External Entity:  LongTime (TIM2)
 * The Time external entity provides date, timestamp, and timer related operations.
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
 * Bridge:  timer_start
 */
Escher_Timer_t
TIM2_timer_start( Escher_xtUMLEvent_t * p_event_inst, const i_t p_seconds )
{
  /* Replace/Insert the following instructions with your implementation code.  */
  /* RETURN TIM::timer_start(event_inst:PARAM.event_inst, microseconds:( PARAM.seconds * 1000000 )) */
  {Escher_Timer_t xtumlOALrv = TIM_timer_start( (Escher_xtUMLEvent_t *)p_event_inst, ( p_seconds * 1000000 ) );
  return xtumlOALrv;}
}

