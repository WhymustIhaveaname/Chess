#include"chess.h"
const short init_killer_score_lower[KILLER_LENGTH]={32766,32766};
const short init_killer_score_upper[KILLER_LENGTH]={-32766,-32766};
const char INIT_BOARD[64]={UR,UN,UB,UQ,UK,UB,UN,UR,\
                           UP,UP,UP,UP,UP,UP,UP,UP,\
                           EM,EM,EM,EM,EM,EM,EM,EM,\
                           EM,EM,EM,EM,EM,EM,EM,EM,\
                           EM,EM,EM,EM,EM,EM,EM,EM,\
                           EM,EM,EM,EM,EM,EM,EM,EM,\
                           LP,LP,LP,LP,LP,LP,LP,LP,\
                           LR,LN,LB,LQ,LK,LB,LN,LR,};
const short POINTS[13]={0,50,30,30,90,10,POINT_K,-50,-30,-30,-90,-10,-1*POINT_K};
const char PIECES_NAME[13]={' ','R','N','B','Q','P','K','r','n','b','q','p','k'};
const char COLUMN_NAME[8]={'a','b','c','d','e','f','g','h'};
const char N_MOVES[8][2]={{2,1},{1,2},{2,-1},{-1,2},{-2,1},{1,-2},{-1,-2},{-2,-1}};
const char K_MOVES[8][2]={{1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1}};
const char K_MOVES_SUB_LP[6][2]={{1,0},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1}};
const char K_MOVES_SUB_UP[6][2]={{1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,0}};
const char UP_PROMOTION[4]={UR,UN,UB,UQ};
const char LP_PROMOTION[4]={LR,LN,LB,LQ};
const char OPENING_SUGGEST_LOWER[]={52,
	                                57,58,61,62,
	                                50,53,51,
	                                34,35,36,37,
                                    42,43,44,45,};
/**                                      34,35,36,37,
                                         42,43,44,45,
                                         50,51,52,53,
                                      57,58      ,61,62};*/
const char OPENING_SUGGEST_UPPER[]={12,//two pawns
	                                1,2,5,6,//knights and bishops
	                                10,13,11,
	                                18,19,20,21,26,27,28,29};//other pawns
/*	                                  1, 2      , 5, 6,
                                         10,11,12,13,
                                         18,19,20,21,
                                         26,27,28,29,};*/
const char PAWN_BONUS_UPPER[8]={0,0,0,1,2,4,8,80};
const char PAWN_BONUS_LOWER[8]={80,8,4,2,1,0,0,0};