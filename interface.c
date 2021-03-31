#include"chess.h"
void print_board(struct board* pboard){
	for(char row=0;row<8;row++){
		printf("   ------------------------\n");
		printf(" %d ",8-row);
	    for(char col=0;col<8;col++){
            printf(" %c ",PIECES_NAME[pboard->pieces_map[row*8+col]]);
	    }
	    printf("\n");
	}
	printf("   ------------------------\n");
    printf("    a  b  c  d  e  f  g  h \n");
    //printf("    0  1  2  3  4  5  6  7 \n");
}
void dump_board(struct board *pb){
    //print_board(pb);
    printf("score: %d\n",score_board(pb));
    printf("lk_loc,uk_loc: %d,%d\n",pb->lk_loc,pb->uk_loc);
    printf("la,lh,ua,uh: %d,%d,%d,%d\n",pb->la_cst,pb->lh_cst,pb->ua_cst,pb->uh_cst);
}
char *move_to_str(struct move *pmove){
    char *str=(char *)malloc(16);
    if(pmove->piece==UWIN){
        sprintf(str,"black win");
        return str;
    }else if(pmove->piece==LWIN){
        sprintf(str,"white win");
        return str;
    }else if(pmove->piece==DRAW){
        sprintf(str,"draw");
        return str;
    }
    char name,row1,row2,col1,col2,dash;
    name=PIECES_NAME[pmove->piece];
    row1=8-pmove->from/8;
    col1=COLUMN_NAME[pmove->from%8];
    row2=8-pmove->to/8;
    col2=COLUMN_NAME[pmove->to%8];
    dash=pmove->dash;
    if((name==PIECES_NAME[UK] || name==PIECES_NAME[LK])&&abs(col2-col1)>1){
        if(col2=='g'){
            sprintf(str,"O-O");
        }else if(col2=='c'){
            sprintf(str,"O-O-O");
        }else{
            sprintf(str,"castling error");
        }
    }else if((name==PIECES_NAME[UP] && row2==1)||(name==PIECES_NAME[LP] && row2==8)){
        if((col1-col2)==0){
            dash='-';
        }else{
            dash='x';
        }
        sprintf(str,"%c%c%d%c%c%d=%c",name,col1,row1,dash,col2,row2,pmove->dash);
    }else{
        sprintf(str,"%c%c%d%c%c%d",name,col1,row1,dash,col2,row2);
    }
    return str;
}
char cmp_move_str(char *str_short,char *str_long){
    char lens=strlen(str_short);
    char lenl=strlen(str_long);
    if(lens==lenl){
    	return strcmp(str_short,str_long);
    }
    char p1=(*str_short);
    char p2=(*str_long);
    if(p1!=p2){
    	return 2;
    }
    if(p1=='b' || p1=='k' || (p1=='p' && *(str_long+3)=='-') || p1=='B' || p1=='K' || (p1=='P' && *(str_long+3)=='-')){
    	return strcmp(str_short+1,str_long+4);
    }
    return 3;
}
void print_moves(struct move* pmove){
    struct move * pmove_now=pmove;
    char *str;
    do{
        str=move_to_str(pmove_now);
		printf("%s,",str);
        free(str);
        pmove_now=pmove_now->next;
	}while(pmove_now);
	printf("\n");
}
void print_killer(struct killer * pkiller){
    for(char i=0;i<KILLER_LENGTH;i++){
	    printf("%d:%d,",pkiller->loc[i],pkiller->score[i]);
	}
	printf("\n");
}
char print_bell(){
	char r=system("./bell.py 1>/dev/null");
	return r;
}
void prepare_init_board(struct board *pb){
    memcpy(pb->pieces_map,&(INIT_BOARD),64);
    calc_king_loc(pb);
    pb->la_cst=pb->lh_cst=pb->ua_cst=pb->uh_cst=1;
}
char get_line(char *str){
    char i;
    for(i=0;i<127;i++){
        char char_got;
        if((char_got=getchar())=='\n'){
            break;
        }else{
            str[i]=char_got;
        }
    }
    str[i]=0;
    return i;
}