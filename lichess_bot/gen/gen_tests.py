import chess
import chess.pgn

# parse all the games
test_games = []
with open('/Users/levi/Downloads/lichess_leviathan747_2024-06-10.pgn') as pgn:
    game = chess.pgn.read_game(pgn)
    while game is not None:
        test_game = {'moves': [], 'fens': []}
        board = game.board()
        for move in game.mainline_moves():
            board.push(move)
            test_game['moves'].append(str(move))
            test_game['fens'].append(board.fen(en_passant='fen'))
        if len(test_game['moves']) > 0:
            test_games.append(test_game)
        game = chess.pgn.read_game(pgn)

# output test operations
for test_num, test_game in enumerate(test_games):
    print('\t\t@dialect("oal");')
    print(f'\t\tfunction test{test_num + 1}() return boolean is')
    print('\t\t\t@noparse')
    print(f'\t\t\tLOG::LogInfo(message: "test{test_num + 1}: start");')
    print('\t\t\tt0 = TIM::current_clock();')
    print()
    print('\t\t\tinitial_fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";')
    print(f'\t\t\tmove_text = "{" ".join(test_game["moves"])}";')
    for i in reversed(range(len(test_game['fens']))):
        print(f'\t\t\tfens[{i}] = "{test_game["fens"][i]}";')
    print()
    print(f'\t\t\tresult = ::test_do_move(name: "test{test_num}", initial_fen: initial_fen, move_text: move_text, fens: fens);')
    print()
    print('\t\t\tt1 = TIM::current_clock();')
    print(f'\t\t\tLOG::LogInfo(message: "test{test_num + 1}: done " + STRING::itoa(i: (t1 - t0) / 1000) + "ms");')
    print()
    print('\t\t\treturn result;')
    print('\t\t\t@endnoparse')
    print('\t\tend function;')
