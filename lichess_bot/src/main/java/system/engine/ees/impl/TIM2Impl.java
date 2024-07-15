package system.engine.ees.impl;

import io.ciera.runtime.summit.components.IComponent;
import io.ciera.runtime.summit.statemachine.EventHandle;
import io.ciera.runtime.summit.time.Timer;
import io.ciera.runtime.summit.time.TimerHandle;
import io.ciera.runtime.summit.util.Utility;
import system.engine.ees.TIM2;

public class TIM2Impl<C extends IComponent<C>> extends Utility<C> implements TIM2 {

	public TIM2Impl(C context) {
		super(context);
	}

	public TimerHandle timer_start(final EventHandle event_inst, final int seconds) {
		Timer timer = new Timer(context().getId(), event_inst, seconds * 1000000L, false);
		timer.reset(getRunContext().time());
		return getRunContext().addTimer(timer);
	}

}
