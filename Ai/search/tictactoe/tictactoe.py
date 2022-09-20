"""
Tic Tac Toe Player
"""

import math
import copy
X = "X"
O = "O"
EMPTY = None


def initial_state():
    """
    Returns starting state of the board.
    """
    return [[EMPTY, EMPTY, EMPTY],
            [EMPTY, EMPTY, EMPTY],
            [EMPTY, EMPTY, EMPTY]]


def player(board):
    """
    Returns player who has the next turn on a board.
    """
    # raise NotImplementedError
    countx = 0
    counto = 0
    for row in board:
        for pos in row:
            if pos == X:
                countx += 1
            elif pos == O:
                counto += 1
    if countx > counto:
        return O
    return X


def actions(board):
    """
    Returns set of all possible actions (i, j) available on the board.
    """
    # raise NotImplementedError
    possible = []
    if(terminal(board)):
        return None
    i = 0
    j = 0
    for i in range(0, 3):
        for j in range(0, 3):
            if (board[i][j] == EMPTY):
                # #print(board[i][j])
                possible.append((i, j))
    # #print(possible)
    return possible


def result(board, action):
    """
    Returns the board that results from making move (i, j) on the board.
    """
    # raise NotImplementedError
    newboard = copy.deepcopy(board)

    if newboard[action[0]][action[1]] != EMPTY:
        raise "ACTION NOT VALID"
    newboard[action[0]][action[1]] = player(newboard)
    # print(newboard)
    return newboard


def winner(board):
    """
    Returns the winner of the game, if there is one.
    """
    # raise NotImplementedError
    for ind in range(3):
        if board[0][ind] == board[1][ind] and board[1][ind] == board[2][ind]:
            return board[1][ind]
        if board[ind][0] == board[ind][1] and board[ind][1] == board[ind][2]:
            return board[ind][0]

    if board[0][0] == board[1][1] and board[1][1] == board[2][2]:
        return board[1][1]
    elif board[0][2] == board[1][1] and board[1][1] == board[2][0]:
        return board[1][1]

    return None


def terminal(board):
    """
    Returns True if game is over, False otherwise.
    """
   # raise NotImplementedError

    if (winner(board) is None):
        for row in board:
            for pos in row:
                if pos == None:
                    return False

    return True


def utility(board):
    """
    Returns 1 if X has won the game, -1 if O has won, 0 otherwise.
    """
    # raise NotImplementedError
    if winner(board) is O:
        return -1
    elif winner(board) is X:
        return 1
    else:
        return 0


def minimax(board):
    """
    Returns the optimal action for the current player on the board.
    """
    # raise NotImplementedError
    if terminal(board):
        return None
    else:
        if player(board) == X:
            move = Max(board)
            return move[1]
        else:
            move = Min(board)
            return move[1]


def Max(board):
    if terminal(board):
        return [utility(board), None]

    best = [float('-inf'), None]
    for action in actions(board):
        res = result(board, action)
        v = Min(res)
        if v[0] > best[0]:
            best[0] = v[0]
            best[1] = action
            if best[0] == 1:
                return best
    return best


def Min(board):
    if terminal(board):
        return [utility(board), None]

    best = [float('inf'), None]
    for action in actions(board):
        res = result(board, action)
        v = Max(res)
        if v[0] < best[0]:
            best[0] = v[0]
            best[1] = action
            if best[0] == -1:
                return best
    return best
