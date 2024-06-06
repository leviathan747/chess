package system.engine.ees.impl;

import io.ciera.runtime.summit.components.IComponent;
import io.ciera.runtime.summit.util.Utility;
import system.engine.ees.Bits;

public class BitsImpl<C extends IComponent<C>> extends Utility<C> implements Bits {

	public BitsImpl(C context) {
		super(context);
	}

	public long bitwise_and(final long a, final long b) {
		return a & b;
	}

	public long bitwise_not(final long a) {
		return ~a;
	}

	public long bitwise_or(final long a, final long b) {
		return a | b;
	}

	public long bitwise_xor(final long a, final long b) {
		return a ^ b;
	}

	public long left_shift(final long a, final int n) {
		return a << n;
	}

	public long right_shift(final long a, final int n) {
		return a >> n;
	}

	public long zero() {
		return 0L;
	}

}