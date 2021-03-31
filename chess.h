#include<stdio.h>
#include<string.h>
#include<sys/time.h>
#include<string.h>
#include<stdlib.h>
#define INFINITY 32766
#define MINUS_INFINITY -32766
#define KILLER_LENGTH 2
#define KILLER_EMPTY -1
struct killer{
	char loc[KILLER_LENGTH];
	short score[KILLER_LENGTH];
};
struct move{
	char piece;
	char from;
	char to;
	char dash;
	struct move * next;
};
struct board{
	char pieces_map[64];
    char uk_loc,lk_loc;
    unsigned char la_cst:1;
    unsigned char lh_cst:1;
    unsigned char ua_cst:1;
    unsigned char uh_cst:1;
};
#define EM 0
#define UR 1
#define UN 2
#define UB 3
#define UQ 4
#define UP 5
#define UK 6
#define LR 7
#define LN 8
#define LB 9
#define LQ 10
#define LP 11
#define LK 12
#define UWIN 13 
#define LWIN 14
#define DRAW 15
#define CANNOT_ENPASS 64
//whole board except king is 39 points. if all pawns have been promoted to queen, 103 points
//(103+300)x2=806
//2^15=32768
#define POINT_K 3000
#define OPEN_STEPS 30

//consts from consts.c
const short init_killer_score_lower[KILLER_LENGTH];
const short init_killer_score_upper[KILLER_LENGTH];
const char INIT_BOARD[64];
const short POINTS[13];
const char PIECES_NAME[13];
const char COLUMN_NAME[8];
const char N_MOVES[8][2];
const char K_MOVES[8][2];
const char K_MOVES_SUB_LP[6][2];
const char K_MOVES_SUB_UP[6][2];
const char UP_PROMOTION[4];
const char LP_PROMOTION[4];
const char OPENING_SUGGEST_LOWER[16];
const char OPENING_SUGGEST_UPPER[16];
const char PAWN_BONUS_UPPER[8];
const char PAWN_BONUS_LOWER[8];

//functions from chess.c 
void free_moves(struct move * pmove);
short count_control(struct board* pboard);
short score_board(struct board* pboard);
void calc_king_loc(struct board* pboard);
short alpha_beta_pruning_upper(struct board* pboard,char deep,short alpha,short beta
	,struct move** ppmove,unsigned int *pcases_count,char pjump_col,struct killer *pkiller,char *suggest,unsigned char sug_len);
short alpha_beta_pruning_lower(struct board* pboard,char deep,short alpha,short beta
	,struct move** ppmove,unsigned int *pcases_count,char pjump_col,struct killer *pkiller,char *suggest,unsigned char sug_len);
struct board *verify_move(struct board* pboard,char turn,char *pmove_str,char pjump_col);
char uk_being_checked(struct board * pboard);
char lk_being_checked(struct board * pboard);
char la_cstable(struct board * pboard);
char lh_cstable(struct board * pboard);
char ua_cstable(struct board * pboard);
char uh_cstable(struct board * pboard);
void prepare_init_board(struct board *pb);
void dump_board(struct board *pb);
char gen_jump_col(char *str);
void play_on_web();

//functions from interface.c
void print_board(struct board* pboard);
void dump_board(struct board *pb);
char *move_to_str(struct move *pmove);
char cmp_move_str(char *str_short,char *str_long);
void print_moves(struct move* pmove);
void print_killer(struct killer * pkiller);
char print_bell();
void prepare_init_board(struct board *pb);
char get_line(char *str);