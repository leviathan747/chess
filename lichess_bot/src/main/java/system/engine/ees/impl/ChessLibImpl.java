package system.engine.ees.impl;

import java.util.List;

import io.ciera.runtime.summit.components.IComponent;
import io.ciera.runtime.summit.util.Utility;
import system.engine.ees.ChessLib;

public class ChessLibImpl<C extends IComponent<C>> extends Utility<C> implements ChessLib {

	public ChessLibImpl(C context) {
		super(context);
	}

	public String[] legalMoves(final String fen) {
		return lib.ChessLib.legalMoves(fen).toArray(new String[0]);
	}

	public String movesToFEN(final String initialFen, final String[] moves) {
		return lib.ChessLib.movesToFEN(initialFen, List.of(moves));
	}

}
