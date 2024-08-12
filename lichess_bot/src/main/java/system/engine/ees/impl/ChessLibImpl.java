package system.engine.ees.impl;

import java.util.ArrayList;
import java.util.List;

import io.ciera.runtime.summit.components.IComponent;
import io.ciera.runtime.summit.util.Utility;
import system.engine.ees.ChessLib;

public class ChessLibImpl<C extends IComponent<C>> extends Utility<C> implements ChessLib {

	public ChessLibImpl(C context) {
		super(context);
	}

	public int legalMoves(final String fen, String[] legalMoves) {
		final List<String> legalMovesList = new ArrayList<>();
		final int legalMoveCount = lib.ChessLib.legalMoves(fen, legalMovesList);
		for (int i = 0; i < legalMovesList.size() && i < legalMoves.length; i++) {
			legalMoves[i] = legalMovesList.get(i);
		}
		return legalMoveCount;
	}

	public String movesToFEN(final String initialFen, final String[] moves) {
		return lib.ChessLib.movesToFEN(initialFen, List.of(moves));
	}

}
