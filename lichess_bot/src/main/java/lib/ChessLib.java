package lib;

import java.util.List;
import java.util.stream.Collectors;

import com.github.bhlangonijr.chesslib.Board;
import com.github.bhlangonijr.chesslib.move.Move;
import com.github.bhlangonijr.chesslib.move.MoveList;

public class ChessLib {

	public static final String STARTPOS = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

	public static List<String> legalMoves(String fen) {
		final var board = new Board();
		board.loadFromFen(fen);
		return board.legalMoves().stream().map(Move::toString).collect(Collectors.toList());
	}

	public static String movesToFEN(String initialFen, List<String> moves) {
		final var fen = initialFen == null || initialFen.isEmpty() || initialFen.equals("startpos") ? STARTPOS
				: initialFen;
		if (moves.size() > 0) {
			final var moveList = new MoveList(fen);
			moveList.loadFromSan(moves.stream().collect(Collectors.joining(" ")));
			return moveList.getFen();
		}
		return fen;
	}

}