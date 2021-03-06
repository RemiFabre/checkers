#ifndef AGENTWALTER_H
#define AGENTWALTER_H

#include "checkersagent.h"
#include "tcphelper.h"
#include <limits>
#include <algorithm>

class AgentWalter : public CheckersAgent {
public:
  AgentWalter(PieceType self, int max_depth);
  virtual ~AgentWalter();
  virtual Word make_move(const CheckerBoard &board);

private:
  int score(const CheckerBoard &old_board, const CheckerBoard &board, int depth);

  int negamax(const CheckerBoard &old_board, const CheckerBoard &board, int depth, int alpha, int beta, int color);

  int maxi(const CheckerBoard &old_board, const CheckerBoard &board, int depth, int alpha, int beta);
  int mini(const CheckerBoard &old_board, const CheckerBoard &board, int depth, int alpha, int beta);

  PieceType self;
  PieceType enemy;

  int max_depth;

  TCPHelper control;
};

#endif // AGENTWALTER_H
