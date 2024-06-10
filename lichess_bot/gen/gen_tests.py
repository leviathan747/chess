import chess
import chess.pgn
import sys

parent_package_name = 'lichess_bot::components::Engine::test'
package_name = 'do_move_test_cases'

# parse all the games
test_games = []
with open(sys.argv[1]) as pgn:
    game = chess.pgn.read_game(pgn)
    while game is not None:
        test_game = {'moves': [], 'fens': [], 'initial_fen': game.headers.get('FEN', 'rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1')}
        board = game.board()
        for move in game.mainline_moves():
            board.push(move)
            test_game['moves'].append(str(move))
            test_game['fens'].append(board.fen(en_passant='fen'))
        if len(test_game['moves']) > 0:
            test_games.append(test_game)
        game = chess.pgn.read_game(pgn)

# output file header
print('// BP 7.1.6 content: Package syschar: 3 persistence-version: 7.1.6')
print()
print(f'within {parent_package_name} is')
print()
print(f'\tpackage {package_name} is')
print()

# output test functions
for test_num, test_game in enumerate(test_games):
    print('\t\t@dialect("oal");')
    print(f'\t\tfunction test{test_num + 1}() return boolean is')
    print('\t\t\t@noparse')
    print(f'\t\t\tLOG::LogInfo(message: "test{test_num + 1}: start");')
    print('\t\t\tt0 = TIM::current_clock();')
    print()
    print(f'\t\t\tinitial_fen = "{test_game["initial_fen"]}";')
    print(f'\t\t\tmove_text = "{" ".join(test_game["moves"])}";')
    for i in reversed(range(len(test_game['fens']))):
        print(f'\t\t\tfens[{i}] = "{test_game["fens"][i]}";')
    print()
    print(f'\t\t\tresult = ::test_do_move(name: "test{test_num + 1}", initial_fen: initial_fen, move_text: move_text, fens: fens);')
    print()
    print('\t\t\tt1 = TIM::current_clock();')
    print(f'\t\t\tLOG::LogInfo(message: "test{test_num + 1}: done " + STRING::itoa(i: (t1 - t0) / 1000) + "ms");')
    print()
    print('\t\t\treturn result;')
    print('\t\t\t@endnoparse')
    print('\t\tend function;')
    print()

# output test_all function
print('\t\t@dialect("oal");')
print('\t\tfunction test_all() is')
print('\t\t\t@noparse')
print('\t\t\tfailures = 0;')
print('\t\t\tt0 = TIM::current_clock();')
print()
for test_num, test_game in enumerate(test_games):
    print(f'\t\t\tif not ::test{test_num + 1}() then failures = failures + 1; end if;')
print()
print('\t\t\tt1 = TIM::current_clock();')
print(f'\t\t\tLOG::LogInfo(message: "{len(test_games)} tests run in " + STRING::itoa(i: (t1 - t0) / 1000) + "ms");')
print('\t\t\tLOG::LogInfo(message: "Tests ran with " + STRING::itoa(i: failures) + " failures");')
print('\t\t\tARCH::shutdown();')
print('\t\t\t@endnoparse')
print('\t\tend function;')
print()

# ouptut file footer
print('\tend package;')
print()
print('end;')
