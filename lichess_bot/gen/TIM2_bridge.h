/*----------------------------------------------------------------------------
 * File:  TIM2_bridge.h
 *
 * Description:
 * Methods for bridging to an external entity.
 *
 * External Entity:  LongTime (TIM2)
 * The Time external entity provides date, timestamp, and timer related operations.
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#ifndef TIM2_BRIDGE_H
#define TIM2_BRIDGE_H
#ifdef	__cplusplus
extern	"C"	{
#endif

#include "lichess_bot_sys_types.h"
Escher_Timer_t TIM2_timer_start( Escher_xtUMLEvent_t *, const i_t );

#ifdef	__cplusplus
}
#endif
#endif   /* TIM2_BRIDGE_H */
