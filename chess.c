#include"chess.h"

void free_moves(struct move * pmove){
    //printf("%ld\n",sizeof(struct move));
    struct move *pmove_now=pmove,*pmove_temp;
    while(pmove_now){
        //printf("get %ld\n",(unsigned long)pmove_now);
        pmove_temp=pmove_now->next;
        free(pmove_now);
        pmove_now=pmove_temp;
    }
}

/*#define UPPER_CONTROL(i) upper[i]=1;
#define LOWER_CONTROL(i) lower[i]=1;
char count_control(struct board* pboard){
    char upper[64],lower[64];
    memset(upper,0,64);
    memset(lower,0,64);
    char uc=0,lc=0;
    
    for(char row=7;row>=0;row--){
    for(char col=7;col>=0;col--){
        uc=0,lc=0;
        char i,neoi,neorow,neocol,piece;
        i=row*8+col;
        piece=pboard->pieces_map[i];
        switch(piece){
            case UR:        
                for(char j=1;j<=7-col;j++){
                    neoi=i+j;
                    UPPER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                for(char j=1;j<=col;j++){
                    neoi=i-j;
                    UPPER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                for(char j=8;j<=8*(7-row);j+=8){
                    neoi=i+j;
                    UPPER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                for(char j=8;j<=8*row;j+=8){
                    neoi=i-j;
                    UPPER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                break;
            case UN:
                for(char j=0;j<8;j++){
                    neorow=row+N_MOVES[j][0];
                    neocol=col+N_MOVES[j][1];
                    if(neorow<0 || neorow>=8 || neocol<0 || neocol>=8){
                        continue;
                    }
                    neoi=neorow*8+neocol;
                    UPPER_CONTROL(neoi)
                }
                break;
            case UB:{
                char maxj;
                maxj=row<col?row:col;
                for(char j=1;j<=maxj;j++){
                    neorow=row-j;
                    neocol=col-j;
                    neoi=neorow*8+neocol;
                    UPPER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                maxj=7-(row>col?row:col);
                for(char j=1;j<=maxj;j++){
                    neorow=row+j;
                    neocol=col+j;
                    neoi=neorow*8+neocol;
                    UPPER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                maxj=row<=(7-col)?row:7-col;
                for(char j=1;j<=maxj;j++){
                    neorow=row-j;
                    neocol=col+j;
                    neoi=neorow*8+neocol;
                    UPPER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                maxj=col<=(7-row)?col:7-row;
                for(char j=1;j<=maxj;j++){
                    neorow=row+j;
                    neocol=col-j;
                    neoi=neorow*8+neocol;
                    UPPER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                break;
            }
            case UQ:{
                char maxj;
                for(char j=1;j<=7-col;j++){
                    neoi=i+j;
                    UPPER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                for(char j=1;j<=col;j++){
                    neoi=i-j;
                    UPPER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                for(char j=8;j<=8*(7-row);j+=8){
                    neoi=i+j;
                    UPPER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                for(char j=8;j<=8*row;j+=8){
                    neoi=i-j;
                    UPPER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                maxj=row<col?row:col;
                for(char j=1;j<=maxj;j++){
                    neorow=row-j;
                    neocol=col-j;
                    neoi=neorow*8+neocol;
                    UPPER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                maxj=7-(row>col?row:col);
                for(char j=1;j<=maxj;j++){
                    neorow=row+j;
                    neocol=col+j;
                    neoi=neorow*8+neocol;
                    UPPER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                maxj=row<=(7-col)?row:7-col;
                for(char j=1;j<=maxj;j++){
                    neorow=row-j;
                    neocol=col+j;
                    neoi=neorow*8+neocol;
                    UPPER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                maxj=col<=(7-row)?col:7-row;
                for(char j=1;j<=maxj;j++){
                    neorow=row+j;
                    neocol=col-j;
                    neoi=neorow*8+neocol;
                    UPPER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                break;
            }
            case LR:        
                for(char j=1;j<=7-col;j++){
                    neoi=i+j;
                    LOWER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                for(char j=1;j<=col;j++){
                    neoi=i-j;
                    LOWER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                for(char j=8;j<=8*(7-row);j+=8){
                    neoi=i+j;
                    LOWER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                for(char j=8;j<=8*row;j+=8){
                    neoi=i-j;
                    LOWER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                break;
            case LN:
                for(char j=0;j<8;j++){
                    neorow=row+N_MOVES[j][0];
                    neocol=col+N_MOVES[j][1];
                    if(neorow<0 || neorow>=8 || neocol<0 || neocol>=8){
                        continue;
                    }
                    neoi=neorow*8+neocol;
                    LOWER_CONTROL(neoi)
                }
                break;
            case LB:{
                char maxj;
                maxj=row<col?row:col;
                for(char j=1;j<=maxj;j++){
                    neorow=row-j;
                    neocol=col-j;
                    neoi=neorow*8+neocol;
                    LOWER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                maxj=7-(row>col?row:col);
                for(char j=1;j<=maxj;j++){
                    neorow=row+j;
                    neocol=col+j;
                    neoi=neorow*8+neocol;
                    LOWER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                maxj=row<=(7-col)?row:7-col;
                for(char j=1;j<=maxj;j++){
                    neorow=row-j;
                    neocol=col+j;
                    neoi=neorow*8+neocol;
                    LOWER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                maxj=col<=(7-row)?col:7-row;
                for(char j=1;j<=maxj;j++){
                    neorow=row+j;
                    neocol=col-j;
                    neoi=neorow*8+neocol;
                    LOWER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                break;
            }
            case LQ:{
                char maxj;
                for(char j=1;j<=7-col;j++){
                    neoi=i+j;
                    LOWER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                for(char j=1;j<=col;j++){
                    neoi=i-j;
                    LOWER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                for(char j=8;j<=8*(7-row);j+=8){
                    neoi=i+j;
                    LOWER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                for(char j=8;j<=8*row;j+=8){
                    neoi=i-j;
                    LOWER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                maxj=row<col?row:col;
                for(char j=1;j<=maxj;j++){
                    neorow=row-j;
                    neocol=col-j;
                    neoi=neorow*8+neocol;
                    LOWER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                maxj=7-(row>col?row:col);
                for(char j=1;j<=maxj;j++){
                    neorow=row+j;
                    neocol=col+j;
                    neoi=neorow*8+neocol;
                    LOWER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                maxj=row<=(7-col)?row:7-col;
                for(char j=1;j<=maxj;j++){
                    neorow=row-j;
                    neocol=col+j;
                    neoi=neorow*8+neocol;
                    LOWER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                maxj=col<=(7-row)?col:7-row;
                for(char j=1;j<=maxj;j++){
                    neorow=row+j;
                    neocol=col-j;
                    neoi=neorow*8+neocol;
                    LOWER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                break;
            }
            case UP:
                neorow=row+1;
                neocol=col+1;
                if(neocol<8){
                    neoi=(neorow*8+neocol);
                    UPPER_CONTROL(neoi)
                }
                neocol=col-1;
                if(neocol>=0){
                    neoi=(neorow*8+neocol);
                    UPPER_CONTROL(neoi)
                }
                break;
            case LP:
                neorow=row-1;
                neocol=col+1;
                if(neocol<8){
                    neoi=(neorow*8+neocol);
                    LOWER_CONTROL(neoi)
                }
                neocol=col-1;
                if(neocol>=0){
                    neoi=(neorow*8+neocol);
                    LOWER_CONTROL(neoi)
                }
                break;
        }
    }}
    for(char i=0;i<64;i++){
        uc+=upper[i];
        lc+=lower[i];
    }
    //printf("uc,lc: %d,%d\n",uc,lc);
    return uc-lc;
}
#undef UPPER_CONTROL
#undef LOWER_CONTROL*/
#define UPPER_CONTROL(i) counter++;
#define LOWER_CONTROL(i) counter--;
short count_control(struct board* pboard){
    register short counter=0;
    for(char row=7;row>=0;row--){
    for(char col=7;col>=0;col--){
        char i,neoi,neorow,neocol,piece;
        i=row*8+col;
        piece=pboard->pieces_map[i];
        switch(piece){
            case UR:        
                for(char j=1;j<=7-col;j++){
                    neoi=i+j;
                    UPPER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                for(char j=1;j<=col;j++){
                    neoi=i-j;
                    UPPER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                for(char j=8;j<=8*(7-row);j+=8){
                    neoi=i+j;
                    UPPER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                for(char j=8;j<=8*row;j+=8){
                    neoi=i-j;
                    UPPER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                break;
            case UN:
                for(char j=0;j<8;j++){
                    neorow=row+N_MOVES[j][0];
                    neocol=col+N_MOVES[j][1];
                    if(neorow<0 || neorow>=8 || neocol<0 || neocol>=8){
                        continue;
                    }
                    neoi=neorow*8+neocol;
                    UPPER_CONTROL(neoi)
                }
                break;
            case UB:{
                char maxj;
                maxj=row<col?row:col;
                for(char j=1;j<=maxj;j++){
                    neorow=row-j;
                    neocol=col-j;
                    neoi=neorow*8+neocol;
                    UPPER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                maxj=7-(row>col?row:col);
                for(char j=1;j<=maxj;j++){
                    neorow=row+j;
                    neocol=col+j;
                    neoi=neorow*8+neocol;
                    UPPER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                maxj=row<=(7-col)?row:7-col;
                for(char j=1;j<=maxj;j++){
                    neorow=row-j;
                    neocol=col+j;
                    neoi=neorow*8+neocol;
                    UPPER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                maxj=col<=(7-row)?col:7-row;
                for(char j=1;j<=maxj;j++){
                    neorow=row+j;
                    neocol=col-j;
                    neoi=neorow*8+neocol;
                    UPPER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                break;
            }
            case UQ:{
                char maxj;
                for(char j=1;j<=7-col;j++){
                    neoi=i+j;
                    UPPER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                for(char j=1;j<=col;j++){
                    neoi=i-j;
                    UPPER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                for(char j=8;j<=8*(7-row);j+=8){
                    neoi=i+j;
                    UPPER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                for(char j=8;j<=8*row;j+=8){
                    neoi=i-j;
                    UPPER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                maxj=row<col?row:col;
                for(char j=1;j<=maxj;j++){
                    neorow=row-j;
                    neocol=col-j;
                    neoi=neorow*8+neocol;
                    UPPER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                maxj=7-(row>col?row:col);
                for(char j=1;j<=maxj;j++){
                    neorow=row+j;
                    neocol=col+j;
                    neoi=neorow*8+neocol;
                    UPPER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                maxj=row<=(7-col)?row:7-col;
                for(char j=1;j<=maxj;j++){
                    neorow=row-j;
                    neocol=col+j;
                    neoi=neorow*8+neocol;
                    UPPER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                maxj=col<=(7-row)?col:7-row;
                for(char j=1;j<=maxj;j++){
                    neorow=row+j;
                    neocol=col-j;
                    neoi=neorow*8+neocol;
                    UPPER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                break;
            }
            case LR:        
                for(char j=1;j<=7-col;j++){
                    neoi=i+j;
                    LOWER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                for(char j=1;j<=col;j++){
                    neoi=i-j;
                    LOWER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                for(char j=8;j<=8*(7-row);j+=8){
                    neoi=i+j;
                    LOWER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                for(char j=8;j<=8*row;j+=8){
                    neoi=i-j;
                    LOWER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                break;
            case LN:
                for(char j=0;j<8;j++){
                    neorow=row+N_MOVES[j][0];
                    neocol=col+N_MOVES[j][1];
                    if(neorow<0 || neorow>=8 || neocol<0 || neocol>=8){
                        continue;
                    }
                    neoi=neorow*8+neocol;
                    LOWER_CONTROL(neoi)
                }
                break;
            case LB:{
                char maxj;
                maxj=row<col?row:col;
                for(char j=1;j<=maxj;j++){
                    neorow=row-j;
                    neocol=col-j;
                    neoi=neorow*8+neocol;
                    LOWER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                maxj=7-(row>col?row:col);
                for(char j=1;j<=maxj;j++){
                    neorow=row+j;
                    neocol=col+j;
                    neoi=neorow*8+neocol;
                    LOWER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                maxj=row<=(7-col)?row:7-col;
                for(char j=1;j<=maxj;j++){
                    neorow=row-j;
                    neocol=col+j;
                    neoi=neorow*8+neocol;
                    LOWER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                maxj=col<=(7-row)?col:7-row;
                for(char j=1;j<=maxj;j++){
                    neorow=row+j;
                    neocol=col-j;
                    neoi=neorow*8+neocol;
                    LOWER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                break;
            }
            case LQ:{
                char maxj;
                for(char j=1;j<=7-col;j++){
                    neoi=i+j;
                    LOWER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                for(char j=1;j<=col;j++){
                    neoi=i-j;
                    LOWER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                for(char j=8;j<=8*(7-row);j+=8){
                    neoi=i+j;
                    LOWER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                for(char j=8;j<=8*row;j+=8){
                    neoi=i-j;
                    LOWER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                maxj=row<col?row:col;
                for(char j=1;j<=maxj;j++){
                    neorow=row-j;
                    neocol=col-j;
                    neoi=neorow*8+neocol;
                    LOWER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                maxj=7-(row>col?row:col);
                for(char j=1;j<=maxj;j++){
                    neorow=row+j;
                    neocol=col+j;
                    neoi=neorow*8+neocol;
                    LOWER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                maxj=row<=(7-col)?row:7-col;
                for(char j=1;j<=maxj;j++){
                    neorow=row-j;
                    neocol=col+j;
                    neoi=neorow*8+neocol;
                    LOWER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                maxj=col<=(7-row)?col:7-row;
                for(char j=1;j<=maxj;j++){
                    neorow=row+j;
                    neocol=col-j;
                    neoi=neorow*8+neocol;
                    LOWER_CONTROL(neoi)
                    if(pboard->pieces_map[neoi]!=EM){break;}
                }
                break;
            }
            case UP:
                neorow=row+1;
                neocol=col+1;
                if(neocol<8){
                    neoi=(neorow*8+neocol);
                    UPPER_CONTROL(neoi)
                }
                neocol=col-1;
                if(neocol>=0){
                    neoi=(neorow*8+neocol);
                    UPPER_CONTROL(neoi)
                }
                break;
            case LP:
                neorow=row-1;
                neocol=col+1;
                if(neocol<8){
                    neoi=(neorow*8+neocol);
                    LOWER_CONTROL(neoi)
                }
                neocol=col-1;
                if(neocol>=0){
                    neoi=(neorow*8+neocol);
                    LOWER_CONTROL(neoi)
                }
                break;
        }
    }}
    return counter;
}
#undef UPPER_CONTROL
#undef LOWER_CONTROL
short score_board(struct board* pboard){
	short s=0;
	for(char i=0;i<64;i++){
        char piece=pboard->pieces_map[i];
		s+=POINTS[piece];
        if(piece==UP){
            s+=PAWN_BONUS_UPPER[i/8];
        }else if(piece==LP){
            s-=PAWN_BONUS_LOWER[i/8];
        }
	}
    s+=(count_control(pboard)/6);
	return s;
}
void calc_king_loc(struct board* pboard){
    char flag_uk=0,flag_lk=0;
    for(char i=0;i<64;i++){
    	if(pboard->pieces_map[i]==LK){
    		if(flag_lk){
                printf("have found %d lower kings!\n",flag_lk);
            }
            pboard->lk_loc=i;
            flag_lk++;
    	}else if(pboard->pieces_map[i]==UK){
            if(flag_uk){
                printf("have found %d upper kings!\n",flag_uk);
            }
    		pboard->uk_loc=i;
            flag_uk++;
    	}
    }
    if(flag_lk==0){
        printf("have not found any lower king!\n");
    }
    if(flag_uk==0){
        printf("have not found any upper king!\n");
    }
}

#define PLUSCOUNT (*pcases_count)++;
#define PREPARE_KILLER_FOR_LOWER(killer) {\
    memset(killer.loc,KILLER_EMPTY,KILLER_LENGTH);\
    memcpy(killer.score,init_killer_score_lower,KILLER_LENGTH*sizeof(short));\
}
#define PREPARE_KILLER_FOR_UPPER(killer) {\
    memset(killer.loc,KILLER_EMPTY,KILLER_LENGTH);\
    memcpy(killer.score,init_killer_score_upper,KILLER_LENGTH*sizeof(short));\
}
#define UPDATE_KILLER_UPPER() {\
    if(eval>(pkiller->score[0])){\
        if(i!=(pkiller->loc[0])){\
            pkiller->loc[1]=pkiller->loc[0];\
            pkiller->score[1]=pkiller->score[0];\
            pkiller->loc[0]=i;\
            pkiller->score[0]=eval;\
        }\
    }else if(eval>(pkiller->score[1])  && eval!=(pkiller->score[0])){\
        if(i!=(pkiller->loc[0]) && i!=(pkiller->loc[1])){\
            pkiller->loc[1]=i;\
            pkiller->score[1]=eval;\
        }\
    }\
}
#define CMP_RETURN_UPPER() {\
    UPDATE_KILLER_UPPER()\
    alpha=alpha>eval?alpha:eval;\
    if(beta<=alpha) return maxeval;\
}
#define EVAL_CHILD_UPPER() {\
    eval=alpha_beta_pruning_lower(&neoboard,deep-1,alpha,beta,&pmove_next,pcases_count,CANNOT_ENPASS,&killer_for_decs,NULL,0);\
    PLUSCOUNT\
    if(maxeval<eval){\
        maxeval=eval;\
        (*ppmove)->piece=piece;\
        (*ppmove)->from=i;\
        (*ppmove)->to=neoi;\
        (*ppmove)->dash=(pboard->pieces_map[neoi]==EM)?'-':'x';\
        free_moves((*ppmove)->next);\
        (*ppmove)->next=pmove_next;\
    }else{\
        free_moves(pmove_next);\
    }\
    CMP_RETURN_UPPER()\
}
#define MOVE_PIECE_UPPER(piece) {\
    memcpy(&neoboard,pboard,sizeof(struct board));\
    neoboard.pieces_map[i]=EM;\
    neoboard.pieces_map[neoi]=piece;\
    if(!uk_being_checked(&neoboard)){\
        EVAL_CHILD_UPPER()\
    }\
}
#define MOVE_ROCK_UPPER {\
    memcpy(&neoboard,pboard,sizeof(struct board));\
    neoboard.pieces_map[i]=EM;\
    neoboard.pieces_map[neoi]=piece;\
    if(!uk_being_checked(&neoboard)){\
        if(i==0 && neoboard.ua_cst==1){neoboard.ua_cst=0;}\
        if(i==7 && neoboard.uh_cst==1){neoboard.uh_cst=0;}\
        EVAL_CHILD_UPPER()\
    }\
}
#define PROMOTION_UPPER(piece2) {\
    memcpy(&neoboard,pboard,sizeof(struct board));\
    neoboard.pieces_map[i]=EM;\
    neoboard.pieces_map[neoi]=piece2;\
    if(!uk_being_checked(&neoboard)){\
        PLUSCOUNT\
        eval=alpha_beta_pruning_lower(&neoboard,deep-1,alpha,beta,&pmove_next,pcases_count,CANNOT_ENPASS,&killer_for_decs,NULL,0);\
        if(maxeval<eval){\
            maxeval=eval;\
            (*ppmove)->piece=UP;\
            (*ppmove)->from=i;\
            (*ppmove)->to=neoi;\
            (*ppmove)->dash=PIECES_NAME[piece2];\
            free_moves((*ppmove)->next);\
            (*ppmove)->next=pmove_next;\
        }else{\
            free_moves(pmove_next);\
        }\
        CMP_RETURN_UPPER()\
    }\
}
#define JUMP_UPPER() {\
    memcpy(&neoboard,pboard,sizeof(struct board));\
    neoboard.pieces_map[i]=EM;\
    neoboard.pieces_map[neoi]=UP;\
    if(!uk_being_checked(&neoboard)){\
        eval=alpha_beta_pruning_lower(&neoboard,deep-1,alpha,beta,&pmove_next,pcases_count,col,&killer_for_decs,NULL,0);\
        PLUSCOUNT\
        if(maxeval<eval){\
            maxeval=eval;\
            (*ppmove)->piece=UP;\
            (*ppmove)->from=i;\
            (*ppmove)->to=neoi;\
            (*ppmove)->dash=(pboard->pieces_map[neoi]==EM)?'-':'x';\
            free_moves((*ppmove)->next);\
            (*ppmove)->next=pmove_next;\
        }else{\
            free_moves(pmove_next);\
        }\
        CMP_RETURN_UPPER()\
    }\
}
#define ENPASS_UPPER() {\
    memcpy(&neoboard,pboard,sizeof(struct board));\
    neoboard.pieces_map[i]=EM;\
    neoboard.pieces_map[neoi]=UP;\
    neoboard.pieces_map[neoi-8]=EM;\
    if(!uk_being_checked(&neoboard)){\
        PLUSCOUNT\
        eval=alpha_beta_pruning_lower(&neoboard,deep-1,alpha,beta,&pmove_next,pcases_count,CANNOT_ENPASS,&killer_for_decs,NULL,0);\
        if(maxeval<eval){\
            maxeval=eval;\
            (*ppmove)->piece=UP;\
            (*ppmove)->from=i;\
            (*ppmove)->to=neoi;\
            (*ppmove)->dash='x';\
            free_moves((*ppmove)->next);\
            (*ppmove)->next=pmove_next;\
        }else{\
            free_moves(pmove_next);\
        }\
        CMP_RETURN_UPPER()\
    }\
}
short alpha_beta_pruning_upper(struct board* pboard,char deep,short alpha,short beta,struct move** ppmove,unsigned int *pcases_count
    ,char pjump_col,struct killer *pkiller,char *suggest,unsigned char sug_len){
	if(deep==0){
        /*getchar();
        printf("\n");
        dump_board(pboard);*/
		return score_board(pboard);
	}
    short maxeval=MINUS_INFINITY;
    unsigned int cases_count_old=*(pcases_count);
    char done_map[64];
    memset(done_map,0,64);
    struct killer killer_for_decs;
    PREPARE_KILLER_FOR_LOWER(killer_for_decs);
	struct move *pmove_next=NULL;
    (*ppmove)=calloc(1,sizeof(struct move));
    //unsigned int cc_for_test;
    char i,neoi,piece,piece2,neorow,neocol;
    short eval;
    struct board neoboard;
    /*backup and prepare pkiller*/
    //printf("at deep %d: ",deep);
    //print_killer(pkiller);
    char killer_loc[KILLER_LENGTH];
    memcpy(killer_loc,pkiller->loc,KILLER_LENGTH);
    PREPARE_KILLER_FOR_UPPER((*pkiller));
    for(char k=0;k<KILLER_LENGTH;k++){
        if(killer_loc[k]>=0){
            i=killer_loc[k];
            piece=pboard->pieces_map[i];
            char row=i/8;
            char col=i%8;
            switch(piece){
                case UR:        
                    for(char j=1;j<=7-col;j++){
                        neoi=i+j;
                        piece2=pboard->pieces_map[neoi];
                        if(0<piece2 && piece2<=6){
                            break;
                        }else{
                            MOVE_ROCK_UPPER
                            if(piece2>=7){
                                break;
                            }
                        }
                    }
                    for(char j=1;j<=col;j++){
                        neoi=i-j;
                        piece2=pboard->pieces_map[neoi];
                        if(0<piece2 && piece2<=6){
                            break;
                        }else{
                            MOVE_ROCK_UPPER
                            if(piece2>=7){
                                break;
                            }
                        }
                    }
                    for(char j=8;j<=8*(7-row);j+=8){
                        neoi=i+j;
                        piece2=pboard->pieces_map[neoi];
                        if(0<piece2 && piece2<=6){
                            break;
                        }else{
                            MOVE_ROCK_UPPER
                            if(piece2>=7){
                                break;
                            }
                        }
                    }
                    for(char j=8;j<=8*row;j+=8){
                        neoi=i-j;
                        piece2=pboard->pieces_map[neoi];
                        if(0<piece2 && piece2<=6){
                            break;
                        }else{
                            MOVE_ROCK_UPPER
                            if(piece2>=7){
                                break;
                            }
                        }
                    }
                    break;
                case UN:
                    //printf("get N at (%d,%d). ",row,col);cases_ax_old=cases_ax;
                    for(char j=0;j<8;j++){
                        neorow=row+N_MOVES[j][0];
                        neocol=col+N_MOVES[j][1];
                        if(neorow<0 || neorow>=8 || neocol<0 || neocol>=8){
                            continue;
                        }
                        neoi=neorow*8+neocol;
                        piece2=pboard->pieces_map[neoi];
                        if(piece2==EM || piece2>=LR){
                            MOVE_PIECE_UPPER(UN)
                        }
                    }
                    //printf("totally %d cases\n",cases_ax-cases_ax_old);
                    break;
                case UB:{
                    char maxj;
                    maxj=row<col?row:col;
                    for(char j=1;j<=maxj;j++){
                        neorow=row-j;
                        neocol=col-j;
                        if(neorow<0 || neocol<0){
                            printf("error2\n");
                            exit(1);
                        }
                        neoi=neorow*8+neocol;
                        piece2=pboard->pieces_map[neoi];
                        if(piece2<=UK && piece2!=EM)break;
                        else{
                            MOVE_PIECE_UPPER(UB)
                            if(piece2!=EM){
                                break;
                            }
                        }
                    }
                    maxj=7-(row>col?row:col);
                    for(char j=1;j<=maxj;j++){
                        neorow=row+j;
                        neocol=col+j;
                        neoi=neorow*8+neocol;
                        if(neorow>=8 || neocol>=8){
                            printf("error1\n");
                            exit(1);
                        }
                        piece2=pboard->pieces_map[neoi];
                        if(piece2<=UK && piece2!=EM)break;
                        else{
                            MOVE_PIECE_UPPER(UB)
                            if(piece2!=EM){
                                break;
                            }
                        }
                    }
                    maxj=row<=(7-col)?row:7-col;
                    for(char j=1;j<=maxj;j++){
                        neorow=row-j;
                        neocol=col+j;
                        if(neorow<0 || neocol>=8){
                            printf("error4\n");
                            exit(1);
                        }
                        neoi=neorow*8+neocol;
                        piece2=pboard->pieces_map[neoi];
                        if(piece2<=UK && piece2!=EM) break;
                        else{
                            MOVE_PIECE_UPPER(UB)
                            if(piece2!=EM){
                                break;
                            }
                        }
                    }
                    maxj=col<=(7-row)?col:7-row;
                    for(char j=1;j<=maxj;j++){
                        neorow=row+j;
                        neocol=col-j;
                        if(neorow>=8 || neocol<0){
                            printf("error3\n");
                            exit(1);
                        }
                        neoi=neorow*8+neocol;
                        piece2=pboard->pieces_map[neoi];
                        if(piece2<=UK && piece2!=EM) break;
                        else{
                            MOVE_PIECE_UPPER(UB)
                            if(piece2!=EM){
                                break;
                            }
                        }
                    }
                    break;
                }
                case UQ:{
                    char maxj;
                    for(char j=1;j<=7-col;j++){
                        neoi=i+j;
                        piece2=pboard->pieces_map[neoi];
                        if(0<piece2 && piece2<=6){
                            break;
                        }else{
                            MOVE_PIECE_UPPER(UQ)
                            if(piece2>=7){
                                break;
                            }
                        }
                    }
                    for(char j=1;j<=col;j++){
                        neoi=i-j;
                        piece2=pboard->pieces_map[neoi];
                        if(0<piece2 && piece2<=6){
                            break;
                        }else{
                            MOVE_PIECE_UPPER(UQ)
                            if(piece2>=7){
                                break;
                            }
                        }
                    }
                    for(char j=8;j<=8*(7-row);j+=8){
                        neoi=i+j;
                        piece2=pboard->pieces_map[neoi];
                        if(0<piece2 && piece2<=6){
                            break;
                        }else{
                            MOVE_PIECE_UPPER(UQ)
                            if(piece2>=7){
                                break;
                            }
                        }
                    }
                    for(char j=8;j<=8*row;j+=8){
                        neoi=i-j;
                        piece2=pboard->pieces_map[neoi];
                        if(0<piece2 && piece2<=6){
                            break;
                        }else{
                            MOVE_PIECE_UPPER(UQ)
                            if(piece2>=7){
                                break;
                            }
                        }
                    }
                    maxj=7-(row>col?row:col);
                    for(char j=1;j<=maxj;j++){
                        neorow=row+j;
                        neocol=col+j;
                        neoi=neorow*8+neocol;
                        piece2=pboard->pieces_map[neoi];
                        if(piece2<=UK && piece2!=EM) break;
                        else{
                            MOVE_PIECE_UPPER(UQ)
                            if(piece2!=EM){
                                break;
                            }
                        }
                    }
                    maxj=row<col?row:col;
                    for(char j=1;j<=maxj;j++){
                        neorow=row-j;
                        neocol=col-j;
                        neoi=neorow*8+neocol;
                        piece2=pboard->pieces_map[neoi];
                        if(piece2<=UK && piece2!=EM) break;
                        else{
                            MOVE_PIECE_UPPER(UQ)
                            if(piece2!=EM){
                                break;
                            }
                        }
                    }
                    maxj=col<(7-row)?col:(7-row);
                    for(char j=1;j<=maxj;j++){
                        neorow=row+j;
                        neocol=col-j;
                        neoi=neorow*8+neocol;
                        piece2=pboard->pieces_map[neoi];
                        if(piece2<=UK && piece2!=EM) break;
                        else{
                            MOVE_PIECE_UPPER(UQ)
                            if(piece2!=EM){
                                break;
                            }
                        }
                    }
                    maxj=row<(7-col)?row:(7-col);
                    for(char j=1;j<=maxj;j++){
                        neorow=row-j;
                        neocol=col+j;
                        neoi=neorow*8+neocol;
                        piece2=pboard->pieces_map[neoi];
                        if(piece2<=UK && piece2!=EM) break;
                        else{
                            MOVE_PIECE_UPPER(UQ)
                            if(piece2!=EM){
                                break;
                            }
                        }
                    }
                    break;
                }
                case UP:
                    if(pjump_col<8 && row==4 && abs(col-pjump_col)==1){
                        neoi=40+pjump_col;
                        ENPASS_UPPER()
                    }
                    if(pboard->pieces_map[neoi=(i+8)]==EM){
                        if(row==1 && pboard->pieces_map[neoi=(i+16)]==EM){
                            JUMP_UPPER()
                        }
                        neoi=i+8;
                        if(row==6){
                            for(char j=0;j<4;j++){
                                PROMOTION_UPPER(UP_PROMOTION[j])
                            }
                        }else{
                            MOVE_PIECE_UPPER(UP)
                        }
                    }
                    neorow=row+1;
                    neocol=col+1;
                    if(neocol<8 && pboard->pieces_map[neoi=(neorow*8+neocol)]>=LR){
                        if(row==6){
                            for(char j=0;j<4;j++){
                                PROMOTION_UPPER(UP_PROMOTION[j])
                            }
                        }else{
                            MOVE_PIECE_UPPER(UP)
                        }
                    }
                    neocol=col-1;
                    if(neocol>=0 && pboard->pieces_map[neoi=(neorow*8+neocol)]>=LR){
                        if(row==6){
                            for(char j=0;j<4;j++){
                                PROMOTION_UPPER(UP_PROMOTION[j])
                            }
                        }else{
                            MOVE_PIECE_UPPER(UP)
                        }
                    }
                    break;
                case UK:
                    for(char j=0;j<8;j++){
                        neorow=row+K_MOVES[j][0];
                        neocol=col+K_MOVES[j][1];
                        if(neorow<0 || neorow>=8 || neocol<0 || neocol>=8){
                            continue;
                        }
                        neoi=neorow*8+neocol;
                        piece2=pboard->pieces_map[neoi];
                        if(piece2==EM || piece2>=LR){
                            memcpy(&neoboard,pboard,sizeof(struct board));
                            neoboard.pieces_map[i]=EM;
                            neoboard.pieces_map[neoi]=UK;
                            neoboard.uk_loc=neoi;
                            neoboard.ua_cst=0;
                            neoboard.uh_cst=0;
                            if(uk_being_checked(&neoboard)) continue;
                            EVAL_CHILD_UPPER()
                        }
                    }
                    if(pboard->ua_cst &&\
                       pboard->pieces_map[1]==EM && pboard->pieces_map[2]==EM && pboard->pieces_map[3]==EM &&\
                       ua_cstable(pboard)){
                        if(pboard->pieces_map[0]!=UR){
                            pboard->ua_cst=0;
                        }else{
                            neoi=2;
                            memcpy(&neoboard,pboard,sizeof(struct board));
                            neoboard.pieces_map[i]=EM;
                            neoboard.pieces_map[neoi]=UK;
                            neoboard.pieces_map[0]=EM;
                            neoboard.pieces_map[3]=UR;
                            neoboard.uk_loc=neoi;
                            neoboard.ua_cst=0;
                            neoboard.uh_cst=0;
                            EVAL_CHILD_UPPER()
                        }
                    }
                    if(pboard->uh_cst &&\
                       pboard->pieces_map[5]==EM && pboard->pieces_map[6]==EM &&\
                       uh_cstable(pboard)){
                        if(pboard->pieces_map[7]!=UR){
                            pboard->uh_cst=0;
                        }else{
                            neoi=6;
                            memcpy(&neoboard,pboard,sizeof(struct board));
                            neoboard.pieces_map[i]=EM;
                            neoboard.pieces_map[neoi]=UK;
                            neoboard.pieces_map[7]=EM;
                            neoboard.pieces_map[5]=UR;
                            neoboard.uk_loc=neoi;
                            neoboard.ua_cst=0;
                            neoboard.uh_cst=0;
                            EVAL_CHILD_UPPER()
                        }
                    }
                    break;
            }
            done_map[i]=1;
        }
    }

    if(sug_len>0){
        printf("considering suggestions.. at deep =%d\n",deep);
    }
    for(unsigned char s=0;s<sug_len;s++){
        i=suggest[s];
        piece=pboard->pieces_map[i];
        char row=i/8;
        char col=i%8;
        //if(piece<=UK && piece!=EM){
        //    printf("get %c at (%d,%d).\n",PIECES_NAME[piece],row,col);
        //}
        switch(piece){
            case UR:        
                for(char j=1;j<=7-col;j++){
                    neoi=i+j;
                    piece2=pboard->pieces_map[neoi];
                    if(0<piece2 && piece2<=6){
                        break;
                    }else{
                        MOVE_ROCK_UPPER
                        if(piece2>=7){
                            break;
                        }
                    }
                }
                for(char j=1;j<=col;j++){
                    neoi=i-j;
                    piece2=pboard->pieces_map[neoi];
                    if(0<piece2 && piece2<=6){
                        break;
                    }else{
                        MOVE_ROCK_UPPER
                        if(piece2>=7){
                            break;
                        }
                    }
                }
                for(char j=8;j<=8*(7-row);j+=8){
                    neoi=i+j;
                    piece2=pboard->pieces_map[neoi];
                    if(0<piece2 && piece2<=6){
                        break;
                    }else{
                        MOVE_ROCK_UPPER
                        if(piece2>=7){
                            break;
                        }
                    }
                }
                for(char j=8;j<=8*row;j+=8){
                    neoi=i-j;
                    piece2=pboard->pieces_map[neoi];
                    if(0<piece2 && piece2<=6){
                        break;
                    }else{
                        MOVE_ROCK_UPPER
                        if(piece2>=7){
                            break;
                        }
                    }
                }
                break;
            case UN:
                //printf("get N at (%d,%d). ",row,col);cases_ax_old=cases_ax;
                for(char j=0;j<8;j++){
                    neorow=row+N_MOVES[j][0];
                    neocol=col+N_MOVES[j][1];
                    if(neorow<0 || neorow>=8 || neocol<0 || neocol>=8){
                        continue;
                    }
                    neoi=neorow*8+neocol;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2==EM || piece2>=LR){
                        MOVE_PIECE_UPPER(UN)
                    }
                }
                //printf("totally %d cases\n",cases_ax-cases_ax_old);
                break;
            case UB:{
                char maxj;
                maxj=row<col?row:col;
                for(char j=1;j<=maxj;j++){
                    neorow=row-j;
                    neocol=col-j;
                    if(neorow<0 || neocol<0){
                        printf("error2\n");
                        exit(1);
                    }
                    neoi=neorow*8+neocol;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2<=UK && piece2!=EM)break;
                    else{
                        MOVE_PIECE_UPPER(UB)
                        if(piece2!=EM){
                            break;
                        }
                    }
                }
                maxj=7-(row>col?row:col);
                for(char j=1;j<=maxj;j++){
                    neorow=row+j;
                    neocol=col+j;
                    neoi=neorow*8+neocol;
                    if(neorow>=8 || neocol>=8){
                        printf("error1\n");
                        exit(1);
                    }
                    piece2=pboard->pieces_map[neoi];
                    if(piece2<=UK && piece2!=EM)break;
                    else{
                        MOVE_PIECE_UPPER(UB)
                        if(piece2!=EM){
                            break;
                        }
                    }
                }
                maxj=row<=(7-col)?row:7-col;
                for(char j=1;j<=maxj;j++){
                    neorow=row-j;
                    neocol=col+j;
                    if(neorow<0 || neocol>=8){
                        printf("error4\n");
                        exit(1);
                    }
                    neoi=neorow*8+neocol;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2<=UK && piece2!=EM) break;
                    else{
                        MOVE_PIECE_UPPER(UB)
                        if(piece2!=EM){
                            break;
                        }
                    }
                }
                maxj=col<=(7-row)?col:7-row;
                for(char j=1;j<=maxj;j++){
                    neorow=row+j;
                    neocol=col-j;
                    if(neorow>=8 || neocol<0){
                        printf("error3\n");
                        exit(1);
                    }
                    neoi=neorow*8+neocol;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2<=UK && piece2!=EM) break;
                    else{
                        MOVE_PIECE_UPPER(UB)
                        if(piece2!=EM){
                            break;
                        }
                    }
                }
                break;
            }
            case UQ:{
                char maxj;
                for(char j=1;j<=7-col;j++){
                    neoi=i+j;
                    piece2=pboard->pieces_map[neoi];
                    if(0<piece2 && piece2<=6){
                        break;
                    }else{
                        MOVE_PIECE_UPPER(UQ)
                        if(piece2>=7){
                            break;
                        }
                    }
                }
                for(char j=1;j<=col;j++){
                    neoi=i-j;
                    piece2=pboard->pieces_map[neoi];
                    if(0<piece2 && piece2<=6){
                        break;
                    }else{
                        MOVE_PIECE_UPPER(UQ)
                        if(piece2>=7){
                            break;
                        }
                    }
                }
                for(char j=8;j<=8*(7-row);j+=8){
                    neoi=i+j;
                    piece2=pboard->pieces_map[neoi];
                    if(0<piece2 && piece2<=6){
                        break;
                    }else{
                        MOVE_PIECE_UPPER(UQ)
                        if(piece2>=7){
                            break;
                        }
                    }
                }
                for(char j=8;j<=8*row;j+=8){
                    neoi=i-j;
                    piece2=pboard->pieces_map[neoi];
                    if(0<piece2 && piece2<=6){
                        break;
                    }else{
                        MOVE_PIECE_UPPER(UQ)
                        if(piece2>=7){
                            break;
                        }
                    }
                }
                maxj=7-(row>col?row:col);
                for(char j=1;j<=maxj;j++){
                    neorow=row+j;
                    neocol=col+j;
                    neoi=neorow*8+neocol;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2<=UK && piece2!=EM) break;
                    else{
                        MOVE_PIECE_UPPER(UQ)
                        if(piece2!=EM){
                            break;
                        }
                    }
                }
                maxj=row<col?row:col;
                for(char j=1;j<=maxj;j++){
                    neorow=row-j;
                    neocol=col-j;
                    neoi=neorow*8+neocol;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2<=UK && piece2!=EM) break;
                    else{
                        MOVE_PIECE_UPPER(UQ)
                        if(piece2!=EM){
                            break;
                        }
                    }
                }
                maxj=col<(7-row)?col:(7-row);
                for(char j=1;j<=maxj;j++){
                    neorow=row+j;
                    neocol=col-j;
                    neoi=neorow*8+neocol;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2<=UK && piece2!=EM) break;
                    else{
                        MOVE_PIECE_UPPER(UQ)
                        if(piece2!=EM){
                            break;
                        }
                    }
                }
                maxj=row<(7-col)?row:(7-col);
                for(char j=1;j<=maxj;j++){
                    neorow=row-j;
                    neocol=col+j;
                    neoi=neorow*8+neocol;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2<=UK && piece2!=EM) break;
                    else{
                        MOVE_PIECE_UPPER(UQ)
                        if(piece2!=EM){
                            break;
                        }
                    }
                }
                break;
            }
            case UP:
                if(pjump_col<8 && row==4 && abs(col-pjump_col)==1){
                    neoi=40+pjump_col;
                    ENPASS_UPPER()
                }
                if(pboard->pieces_map[neoi=(i+8)]==EM){
                    if(row==1 && pboard->pieces_map[neoi=(i+16)]==EM){
                        JUMP_UPPER()
                    }
                    neoi=i+8;
                    if(row==6){
                        for(char j=0;j<4;j++){
                            PROMOTION_UPPER(UP_PROMOTION[j])
                        }
                    }else{
                        MOVE_PIECE_UPPER(UP)
                    }
                }
                neorow=row+1;
                neocol=col+1;
                if(neocol<8 && pboard->pieces_map[neoi=(neorow*8+neocol)]>=LR){
                    if(row==6){
                        for(char j=0;j<4;j++){
                            PROMOTION_UPPER(UP_PROMOTION[j])
                        }
                    }else{
                        MOVE_PIECE_UPPER(UP)
                    }
                }
                neocol=col-1;
                if(neocol>=0 && pboard->pieces_map[neoi=(neorow*8+neocol)]>=LR){
                    if(row==6){
                        for(char j=0;j<4;j++){
                            PROMOTION_UPPER(UP_PROMOTION[j])
                        }
                    }else{
                        MOVE_PIECE_UPPER(UP)
                    }
                }
                break;
            case UK:
                for(char j=0;j<8;j++){
                    neorow=row+K_MOVES[j][0];
                    neocol=col+K_MOVES[j][1];
                    if(neorow<0 || neorow>=8 || neocol<0 || neocol>=8){
                        continue;
                    }
                    neoi=neorow*8+neocol;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2==EM || piece2>=LR){
                        memcpy(&neoboard,pboard,sizeof(struct board));
                        neoboard.pieces_map[i]=EM;
                        neoboard.pieces_map[neoi]=UK;
                        neoboard.uk_loc=neoi;
                        neoboard.ua_cst=0;
                        neoboard.uh_cst=0;
                        if(uk_being_checked(&neoboard)) continue;
                        EVAL_CHILD_UPPER()
                    }
                }
                if(pboard->ua_cst &&\
                   pboard->pieces_map[1]==EM && pboard->pieces_map[2]==EM && pboard->pieces_map[3]==EM &&\
                   ua_cstable(pboard)){
                    if(pboard->pieces_map[0]!=UR){
                        pboard->ua_cst=0;
                    }else{
                        neoi=2;
                        memcpy(&neoboard,pboard,sizeof(struct board));
                        neoboard.pieces_map[i]=EM;
                        neoboard.pieces_map[neoi]=UK;
                        neoboard.pieces_map[0]=EM;
                        neoboard.pieces_map[3]=UR;
                        neoboard.uk_loc=neoi;
                        neoboard.ua_cst=0;
                        neoboard.uh_cst=0;
                        EVAL_CHILD_UPPER()
                    }
                }
                if(pboard->uh_cst &&\
                   pboard->pieces_map[5]==EM && pboard->pieces_map[6]==EM &&\
                   uh_cstable(pboard)){
                    if(pboard->pieces_map[7]!=UR){
                        pboard->uh_cst=0;
                    }else{
                        neoi=6;
                        memcpy(&neoboard,pboard,sizeof(struct board));
                        neoboard.pieces_map[i]=EM;
                        neoboard.pieces_map[neoi]=UK;
                        neoboard.pieces_map[7]=EM;
                        neoboard.pieces_map[5]=UR;
                        neoboard.uk_loc=neoi;
                        neoboard.ua_cst=0;
                        neoboard.uh_cst=0;
                        EVAL_CHILD_UPPER()
                    }
                }
                break;
        }
        done_map[i]=1;
        
    }
    for(char row=7;row>=0;row--){
    for(char col=7;col>=0;col--){
    	i=row*8+col;
        if(done_map[i]) continue;
        piece=pboard->pieces_map[i];
        //cc_for_test=*pcases_count;
        switch(piece){
        	case UR:        
        	    for(char j=1;j<=7-col;j++){
        	    	neoi=i+j;
        	    	piece2=pboard->pieces_map[neoi];
        	    	if(0<piece2 && piece2<=6){
        	    		break;
        	    	}else{
                        MOVE_ROCK_UPPER
                        if(piece2>=7){
                        	break;
                        }
        	    	}
        	    }
        	    for(char j=1;j<=col;j++){
        	    	neoi=i-j;
        	    	piece2=pboard->pieces_map[neoi];
        	    	if(0<piece2 && piece2<=6){
        	    		break;
        	    	}else{
                        MOVE_ROCK_UPPER
                        if(piece2>=7){
                        	break;
                        }
        	    	}
        	    }
        	    for(char j=8;j<=8*(7-row);j+=8){
        	    	neoi=i+j;
        	    	piece2=pboard->pieces_map[neoi];
        	    	if(0<piece2 && piece2<=6){
        	    		break;
        	    	}else{
                        MOVE_ROCK_UPPER
                        if(piece2>=7){
                        	break;
                        }
        	    	}
        	    }
        	    for(char j=8;j<=8*row;j+=8){
        	    	neoi=i-j;
        	    	piece2=pboard->pieces_map[neoi];
        	    	if(0<piece2 && piece2<=6){
        	    		break;
                	}else{
                        MOVE_ROCK_UPPER
                        if(piece2>=7){
                        	break;
                        }
        	    	}
        	    }
        	    break;
        	case UN:
        	    //printf("get N at (%d,%d). ",row,col);cases_ax_old=cases_ax;
                for(char j=0;j<8;j++){
                	neorow=row+N_MOVES[j][0];
                	neocol=col+N_MOVES[j][1];
                	if(neorow<0 || neorow>=8 || neocol<0 || neocol>=8){
                    	continue;
                    }
                    neoi=neorow*8+neocol;
                	piece2=pboard->pieces_map[neoi];
                	if(piece2==EM || piece2>=LR){
                		MOVE_PIECE_UPPER(UN)
                	}
                }
                //printf("totally %d cases\n",cases_ax-cases_ax_old);
        	    break;
        	case UB:{
        	    char maxj;
                maxj=row<col?row:col;
                for(char j=1;j<=maxj;j++){
                    neorow=row-j;
                    neocol=col-j;
                    if(neorow<0 || neocol<0){
                        printf("error2\n");
                        exit(1);
                    }
                    neoi=neorow*8+neocol;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2<=UK && piece2!=EM)break;
                    else{
                        MOVE_PIECE_UPPER(UB)
                        if(piece2!=EM){
                            break;
                        }
                    }
                }
                maxj=7-(row>col?row:col);
        	    for(char j=1;j<=maxj;j++){
        	    	neorow=row+j;
        	    	neocol=col+j;
        	    	neoi=neorow*8+neocol;
                    if(neorow>=8 || neocol>=8){
                        printf("error1\n");
                        exit(1);
                    }
        	    	piece2=pboard->pieces_map[neoi];
        	    	if(piece2<=UK && piece2!=EM)break;
        	    	else{
        	    		MOVE_PIECE_UPPER(UB)
                        if(piece2!=EM){
                        	break;
                        }
        	    	}
        	    }
                maxj=row<=(7-col)?row:7-col;
                for(char j=1;j<=maxj;j++){
                    neorow=row-j;
                    neocol=col+j;
                    if(neorow<0 || neocol>=8){
                        printf("error4\n");
                        exit(1);
                    }
                    neoi=neorow*8+neocol;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2<=UK && piece2!=EM) break;
                    else{
                        MOVE_PIECE_UPPER(UB)
                        if(piece2!=EM){
                            break;
                        }
                    }
                }
        	    maxj=col<=(7-row)?col:7-row;
        	    for(char j=1;j<=maxj;j++){
        	    	neorow=row+j;
        	    	neocol=col-j;
                    if(neorow>=8 || neocol<0){
                        printf("error3\n");
                        exit(1);
                    }
        	    	neoi=neorow*8+neocol;
        	    	piece2=pboard->pieces_map[neoi];
        	    	if(piece2<=UK && piece2!=EM) break;
        	    	else{
        	    		MOVE_PIECE_UPPER(UB)
                        if(piece2!=EM){
                        	break;
                        }
        	    	}
        	    }
        	    break;
        	}
        	case UQ:{
                char maxj;
        	    for(char j=1;j<=7-col;j++){
        	    	neoi=i+j;
        	    	piece2=pboard->pieces_map[neoi];
        	    	if(0<piece2 && piece2<=6){
        	    		break;
        	    	}else{
                        MOVE_PIECE_UPPER(UQ)
                        if(piece2>=7){
                        	break;
                        }
        	    	}
        	    }
        	    for(char j=1;j<=col;j++){
        	    	neoi=i-j;
        	    	piece2=pboard->pieces_map[neoi];
        	    	if(0<piece2 && piece2<=6){
        	    		break;
        	    	}else{
                        MOVE_PIECE_UPPER(UQ)
                        if(piece2>=7){
                        	break;
                        }
        	    	}
        	    }
        	    for(char j=8;j<=8*(7-row);j+=8){
        	    	neoi=i+j;
        	    	piece2=pboard->pieces_map[neoi];
        	    	if(0<piece2 && piece2<=6){
        	    		break;
        	    	}else{
                        MOVE_PIECE_UPPER(UQ)
                        if(piece2>=7){
                        	break;
                        }
        	    	}
        	    }
        	    for(char j=8;j<=8*row;j+=8){
        	    	neoi=i-j;
        	    	piece2=pboard->pieces_map[neoi];
        	    	if(0<piece2 && piece2<=6){
        	    		break;
                	}else{
                        MOVE_PIECE_UPPER(UQ)
                        if(piece2>=7){
                        	break;
                        }
        	    	}
        	    }
                maxj=7-(row>col?row:col);
        	    for(char j=1;j<=maxj;j++){
        	    	neorow=row+j;
        	    	neocol=col+j;
        	    	neoi=neorow*8+neocol;
        	    	piece2=pboard->pieces_map[neoi];
        	    	if(piece2<=UK && piece2!=EM) break;
        	    	else{
        	    		MOVE_PIECE_UPPER(UQ)
                        if(piece2!=EM){
                        	break;
                        }
        	    	}
        	    }
                maxj=row<col?row:col;
        	    for(char j=1;j<=maxj;j++){
        	    	neorow=row-j;
        	    	neocol=col-j;
        	    	neoi=neorow*8+neocol;
        	    	piece2=pboard->pieces_map[neoi];
        	    	if(piece2<=UK && piece2!=EM) break;
        	    	else{
        	    		MOVE_PIECE_UPPER(UQ)
                        if(piece2!=EM){
                        	break;
                        }
        	    	}
        	    }
                maxj=col<(7-row)?col:(7-row);
        	    for(char j=1;j<=maxj;j++){
        	    	neorow=row+j;
        	    	neocol=col-j;
        	    	neoi=neorow*8+neocol;
        	    	piece2=pboard->pieces_map[neoi];
        	    	if(piece2<=UK && piece2!=EM) break;
        	    	else{
        	    		MOVE_PIECE_UPPER(UQ)
                        if(piece2!=EM){
                        	break;
                        }
        	    	}
        	    }
                maxj=row<(7-col)?row:(7-col);
        	    for(char j=1;j<=maxj;j++){
        	    	neorow=row-j;
        	    	neocol=col+j;
        	    	neoi=neorow*8+neocol;
        	    	piece2=pboard->pieces_map[neoi];
        	    	if(piece2<=UK && piece2!=EM) break;
        	    	else{
        	    		MOVE_PIECE_UPPER(UQ)
                        if(piece2!=EM){
                        	break;
                        }
        	    	}
        	    }
        	    break;
            }
        	case UP:
        	    if(pjump_col<8 && row==4 && abs(col-pjump_col)==1){
                    neoi=40+pjump_col;
                    ENPASS_UPPER()
                }
                if(pboard->pieces_map[neoi=(i+8)]==EM){
                    if(row==1 && pboard->pieces_map[neoi=(i+16)]==EM){
                        JUMP_UPPER()
                    }
                    neoi=i+8;
                    if(row==6){
                        for(char j=0;j<4;j++){
                    	    PROMOTION_UPPER(UP_PROMOTION[j])
                        }
                    }else{
                	    MOVE_PIECE_UPPER(UP)
                    }
                }
                neorow=row+1;
                neocol=col+1;
                if(neocol<8 && pboard->pieces_map[neoi=(neorow*8+neocol)]>=LR){
                    if(row==6){
                        for(char j=0;j<4;j++){
                    	    PROMOTION_UPPER(UP_PROMOTION[j])
                        }
                    }else{
                	    MOVE_PIECE_UPPER(UP)
                    }
                }
                neocol=col-1;
                if(neocol>=0 && pboard->pieces_map[neoi=(neorow*8+neocol)]>=LR){
                    if(row==6){
                        for(char j=0;j<4;j++){
                    	    PROMOTION_UPPER(UP_PROMOTION[j])
                        }
                    }else{
                	    MOVE_PIECE_UPPER(UP)
                    }
                }
        	    break;
            case UK:
                for(char j=0;j<8;j++){
                    neorow=row+K_MOVES[j][0];
                    neocol=col+K_MOVES[j][1];
                    if(neorow<0 || neorow>=8 || neocol<0 || neocol>=8){
                        continue;
                    }
                    neoi=neorow*8+neocol;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2==EM || piece2>=LR){
                        memcpy(&neoboard,pboard,sizeof(struct board));
                        neoboard.pieces_map[i]=EM;
                        neoboard.pieces_map[neoi]=UK;
                        neoboard.uk_loc=neoi;
                        neoboard.ua_cst=0;
                        neoboard.uh_cst=0;
                        if(uk_being_checked(&neoboard)) continue;
                        EVAL_CHILD_UPPER()
                    }
                }
                if(pboard->ua_cst &&\
                   pboard->pieces_map[1]==EM && pboard->pieces_map[2]==EM && pboard->pieces_map[3]==EM &&\
                   ua_cstable(pboard)){
                    if(pboard->pieces_map[0]!=UR){
                        pboard->ua_cst=0;
                    }else{
                        neoi=2;
                        memcpy(&neoboard,pboard,sizeof(struct board));
                        neoboard.pieces_map[i]=EM;
                        neoboard.pieces_map[neoi]=UK;
                        neoboard.pieces_map[0]=EM;
                        neoboard.pieces_map[3]=UR;
                        neoboard.uk_loc=neoi;
                        neoboard.ua_cst=0;
                        neoboard.uh_cst=0;
                        EVAL_CHILD_UPPER()
                    }
                }
                if(pboard->uh_cst &&\
                   pboard->pieces_map[5]==EM && pboard->pieces_map[6]==EM &&\
                   uh_cstable(pboard)){
                    if(pboard->pieces_map[7]!=UR){
                        pboard->uh_cst=0;
                    }else{
                        neoi=6;
                        memcpy(&neoboard,pboard,sizeof(struct board));
                        neoboard.pieces_map[i]=EM;
                        neoboard.pieces_map[neoi]=UK;
                        neoboard.pieces_map[7]=EM;
                        neoboard.pieces_map[5]=UR;
                        neoboard.uk_loc=neoi;
                        neoboard.ua_cst=0;
                        neoboard.uh_cst=0;
                        EVAL_CHILD_UPPER()
                    }
                }
                break;
        }
        /*if(piece<=UK && piece!=EM){
            printf("get %c at (%d,%d). ",PIECES_NAME[piece],row,col);
            printf("totally %d cases\n",*pcases_count-cc_for_test);
        }*/
    }}
    if(cases_count_old<(*pcases_count))return maxeval;
    else if(cases_count_old==(*pcases_count)){
    	if(uk_being_checked(pboard)){
            (*ppmove)->piece=LWIN;
            return score_board(pboard)-POINT_K;
        }else{
            (*ppmove)->piece=DRAW;
            return 0;
        }
    }else{
        printf("sth wired\n");
        exit(914);
    }
}
#undef UPDATE_KILLER_UPPER
#undef CMP_RETURN_UPPER
#undef EVAL_CHILD_UPPER
#undef MOVE_PIECE_UPPER
#undef MOVE_ROCK_UPPER
#undef PROMOTION_UPPER
#undef JUMP_UPPER
#undef ENPASS_UPPER

#define UPDATE_KILLER_LOWER() {\
    if(eval<(pkiller->score[0])){\
        if(i!=(pkiller->loc[0])){\
            pkiller->loc[1]=pkiller->loc[0];\
            pkiller->score[1]=pkiller->score[0];\
            pkiller->loc[0]=i;\
            pkiller->score[0]=eval;\
        }\
    }else if(eval<(pkiller->score[1])  && eval!=(pkiller->score[0])){\
        if(i!=(pkiller->loc[0])){\
            pkiller->loc[1]=i;\
            pkiller->score[1]=eval;\
        }\
    }\
}
#define CMP_RETURN_LOWER() {\
    UPDATE_KILLER_LOWER()\
    beta=beta<eval?beta:eval;\
    if(beta<=alpha){\
        return mineval;\
    }\
}
#define EVAL_CHILD_LOWER() {\
    PLUSCOUNT\
    eval=alpha_beta_pruning_upper(&neoboard,deep-1,alpha,beta,&pmove_next,pcases_count,CANNOT_ENPASS,&killer_for_decs,NULL,0);\
    if(mineval>eval){\
        mineval=eval;\
        (*ppmove)->piece=piece;\
        (*ppmove)->from=i;\
        (*ppmove)->to=neoi;\
        (*ppmove)->dash=(pboard->pieces_map[neoi]==EM)?'-':'x';\
        free_moves((*ppmove)->next);\
        (*ppmove)->next=pmove_next;\
    }else{\
        free_moves(pmove_next);\
    }\
    CMP_RETURN_LOWER()\
}
#define MOVE_PIECE_LOWER(piece) {\
    memcpy(&neoboard,pboard,sizeof(struct board));\
    neoboard.pieces_map[i]=EM;\
    neoboard.pieces_map[neoi]=piece;\
    if(!lk_being_checked(&neoboard)){\
        EVAL_CHILD_LOWER()\
    }\
}
#define MOVE_ROCK_LOWER {\
    memcpy(&neoboard,pboard,sizeof(struct board));\
    neoboard.pieces_map[i]=EM;\
    neoboard.pieces_map[neoi]=piece;\
    if(!lk_being_checked(&neoboard)){\
        if(i==56 && neoboard.la_cst==1){neoboard.la_cst=0;}\
        if(i==63 && neoboard.lh_cst==1){neoboard.lh_cst=0;}\
        EVAL_CHILD_LOWER()\
    }\
}
#define PROMOTION_LOWER(piece2) {\
    memcpy(&neoboard,pboard,sizeof(struct board));\
    neoboard.pieces_map[i]=EM;\
    neoboard.pieces_map[neoi]=piece2;\
    if(!lk_being_checked(&neoboard)){\
        PLUSCOUNT\
        eval=alpha_beta_pruning_upper(&neoboard,deep-1,alpha,beta,&pmove_next,pcases_count,CANNOT_ENPASS,&killer_for_decs,NULL,0);\
        if(mineval>eval){\
            mineval=eval;\
            (*ppmove)->piece=LP;\
            (*ppmove)->from=i;\
            (*ppmove)->to=neoi;\
            (*ppmove)->dash=PIECES_NAME[piece2];\
            free_moves((*ppmove)->next);\
            (*ppmove)->next=pmove_next;\
        }else{\
            free_moves(pmove_next);\
        }\
        CMP_RETURN_LOWER()\
    }\
}
#define JUMP_LOWER() {\
    memcpy(&neoboard,pboard,sizeof(struct board));\
    neoboard.pieces_map[i]=EM;\
    neoboard.pieces_map[neoi]=LP;\
    if(!lk_being_checked(&neoboard)){\
        eval=alpha_beta_pruning_upper(&neoboard,deep-1,alpha,beta,&pmove_next,pcases_count,col,&killer_for_decs,NULL,0);\
        PLUSCOUNT\
        if(mineval>eval){\
            mineval=eval;\
            (*ppmove)->piece=LP;\
            (*ppmove)->from=i;\
            (*ppmove)->to=neoi;\
            (*ppmove)->dash='-';\
            free_moves((*ppmove)->next);\
            (*ppmove)->next=pmove_next;\
        }else{\
            free_moves(pmove_next);\
        }\
        CMP_RETURN_LOWER()\
    }\
}
#define ENPASS_LOWER() {\
    memcpy(&neoboard,pboard,sizeof(struct board));\
    neoboard.pieces_map[i]=EM;\
    neoboard.pieces_map[neoi]=LP;\
    neoboard.pieces_map[neoi+8]=EM;\
    if(!lk_being_checked(&neoboard)){\
        PLUSCOUNT\
        eval=alpha_beta_pruning_upper(&neoboard,deep-1,alpha,beta,&pmove_next,pcases_count,CANNOT_ENPASS,&killer_for_decs,NULL,0);\
        if(mineval>eval){\
            mineval=eval;\
            (*ppmove)->piece=LP;\
            (*ppmove)->from=i;\
            (*ppmove)->to=neoi;\
            (*ppmove)->dash='x';\
            free_moves((*ppmove)->next);\
            (*ppmove)->next=pmove_next;\
        }else{\
            free_moves(pmove_next);\
        }\
        CMP_RETURN_LOWER()\
    }\
}
/*test new features in this function*/
short alpha_beta_pruning_lower(struct board* pboard,char deep,short alpha,short beta,struct move** ppmove,unsigned int *pcases_count
    ,char pjump_col,struct killer *pkiller,char *suggest,unsigned char sug_len){
    /*  
        pboard: passing a pointer to save memory copy time
        deep,alpha,beta: cannot pass a pointer because programme may change it, and need not to pass a pointer
        ppmove: a pointer to a pointer to a move, 
                where the pointer to a move is also declared in its father function 
                and calloc in its father function 
                and need to free after use in its father function
        pcases_count: a pointer to a unsigned int which counts how many cases have be tested
    */  
    if(deep==0){
        /*getchar();
        printf("\n");
        dump_board(pboard);*/
        return score_board(pboard);
    }
    short mineval=INFINITY;
    unsigned int cases_count_old=*(pcases_count);
    char done_map[64];
    memset(done_map,0,64);
    struct killer killer_for_decs;
    PREPARE_KILLER_FOR_UPPER(killer_for_decs);
    struct move *pmove_next=NULL;
    (*ppmove)=calloc(1,sizeof(struct move));
    //unsigned int cc_for_test;
    char i,neoi,piece,piece2,neorow,neocol;
    short eval;
    struct board neoboard;
    /*backup and prepare pkiller*/
    //printf("at deep %d: ",deep);
    //print_killer(pkiller);
    char killer_loc[KILLER_LENGTH];
    memcpy(killer_loc,pkiller->loc,KILLER_LENGTH);
    PREPARE_KILLER_FOR_LOWER((*pkiller));
    

    for(char k=0;k<KILLER_LENGTH;k++){
        //continue;
        //cc_for_test=*pcases_count;
        if(killer_loc[k]>=0){
            i=killer_loc[k];
            piece=pboard->pieces_map[i];
            char row=i/8;
            char col=i%8;
            //printf("trying killer %d: \n",i);
            switch(piece){
                case LR:
                    for(char j=1;j<=7-col;j++){
                        neoi=i+j;
                        piece2=pboard->pieces_map[neoi];
                        if(piece2>=LR){break;}
                        else{
                            MOVE_ROCK_LOWER
                            if(piece2!=EM){break;}
                        }
                    }
                    for(char j=1;j<=col;j++){
                        neoi=i-j;
                        piece2=pboard->pieces_map[neoi];
                        if(piece2>=LR){break;}
                        else{
                            MOVE_ROCK_LOWER
                            if(piece2!=EM){break;}
                        }
                    }
                    for(char j=8;j<=8*(7-row);j+=8){
                        neoi=i+j;
                        piece2=pboard->pieces_map[neoi];
                        if(piece2>=LR){break;}
                        else{
                            MOVE_ROCK_LOWER
                            if(piece2!=EM){break;}
                        }
                    }
                    for(char j=8;j<=8*row;j+=8){
                        neoi=i-j;
                        piece2=pboard->pieces_map[neoi];
                        if(piece2>=LR){break;}
                        else{
                            MOVE_ROCK_LOWER
                            if(piece2!=EM){break;}
                        }
                    }
                    break;
                case LN:
                    for(char j=0;j<8;j++){
                        neorow=row+N_MOVES[j][0];
                        neocol=col+N_MOVES[j][1];
                        if(neorow<0 || neorow>=8 || neocol<0 || neocol>=8){
                            continue;
                        }
                        neoi=neorow*8+neocol;
                        piece2=pboard->pieces_map[neoi];
                        if(piece2<=UK){
                            MOVE_PIECE_LOWER(LN)
                        }
                    }
                    break;
                case LB:{
                    char maxj=7-(row>col?row:col);
                    for(char j=1;j<=maxj;j++){
                        neorow=row+j;
                        neocol=col+j;
                        neoi=neorow*8+neocol;
                        piece2=pboard->pieces_map[neoi];
                        if(piece2>=LR) break;
                        else{
                            MOVE_PIECE_LOWER(LB)
                            if(piece2!=EM){break;}
                        }
                    }
                    maxj=row<col?row:col;
                    for(char j=1;j<=maxj;j++){
                        neorow=row-j;
                        neocol=col-j;
                        neoi=neorow*8+neocol;
                        piece2=pboard->pieces_map[neoi];
                        if(piece2>=LR) break;
                        else{
                            MOVE_PIECE_LOWER(LB)
                            if(piece2!=EM){break;}
                        }
                    }
                    maxj=col<=(7-row)?col:(7-row);
                    for(char j=1;j<=maxj;j++){
                        neorow=row+j;
                        neocol=col-j;
                        neoi=neorow*8+neocol;
                        piece2=pboard->pieces_map[neoi];
                        if(piece2>=LR) break;
                        else{
                            MOVE_PIECE_LOWER(LB)
                            if(piece2!=EM){break;}
                        }
                    }
                    maxj=row<=(7-col)?row:(7-col);
                    for(char j=1;j<=maxj;j++){
                        neorow=row-j;
                        neocol=col+j;
                        neoi=neorow*8+neocol;
                        piece2=pboard->pieces_map[neoi];
                        if(piece2>=LR) break;
                        else{
                            MOVE_PIECE_LOWER(LB)
                            if(piece2!=EM){break;}
                        }
                    }
                    break;
                }
                case LQ:{
                    char maxj;
                    for(char j=1;j<=7-col;j++){
                        neoi=i+j;
                        piece2=pboard->pieces_map[neoi];
                        if(piece2>=LR){break;}
                        else{
                            MOVE_PIECE_LOWER(LQ)
                            if(piece2!=EM){break;}
                        }
                    }
                    for(char j=1;j<=col;j++){
                        neoi=i-j;
                        piece2=pboard->pieces_map[neoi];
                        if(piece2>=LR){break;}
                        else{
                            MOVE_PIECE_LOWER(LQ)
                            if(piece2!=EM){break;}
                        }
                    }
                    for(char j=8;j<=8*(7-row);j+=8){
                        neoi=i+j;
                        piece2=pboard->pieces_map[neoi];
                        if(piece2>=LR){break;}
                        else{
                            MOVE_PIECE_LOWER(LQ)
                            if(piece2!=EM){break;}
                        }
                    }
                    for(char j=8;j<=8*row;j+=8){
                        neoi=i-j;
                        piece2=pboard->pieces_map[neoi];
                        if(piece2>=LR){break;}
                        else{
                            MOVE_PIECE_LOWER(LQ)
                            if(piece2!=EM){break;}
                        }
                    }
                    maxj=7-(row>col?row:col);
                    for(char j=1;j<=maxj;j++){
                        neorow=row+j;
                        neocol=col+j;
                        neoi=neorow*8+neocol;
                        piece2=pboard->pieces_map[neoi];
                        if(piece2>=LR) break;
                        else{
                            MOVE_PIECE_LOWER(LQ)
                            if(piece2!=EM){break;}
                        }
                    }
                    maxj=row<col?row:col;
                    for(char j=1;j<=maxj;j++){
                        neorow=row-j;
                        neocol=col-j;
                        neoi=neorow*8+neocol;
                        piece2=pboard->pieces_map[neoi];
                        if(piece2>=LR) break;
                        else{
                            MOVE_PIECE_LOWER(LQ)
                            if(piece2!=EM){break;}
                        }
                    }
                    maxj=col<(7-row)?col:(7-row);
                    for(char j=1;j<=maxj;j++){
                        neorow=row+j;
                        neocol=col-j;
                        neoi=neorow*8+neocol;
                        piece2=pboard->pieces_map[neoi];
                        if(piece2>=LR) break;
                        else{
                            MOVE_PIECE_LOWER(LQ)
                            if(piece2!=EM){break;}
                        }
                    }
                    maxj=row<(7-col)?row:(7-col);
                    for(char j=1;j<=maxj;j++){
                        neorow=row-j;
                        neocol=col+j;
                        neoi=neorow*8+neocol;
                        piece2=pboard->pieces_map[neoi];
                        if(piece2>=LR) break;
                        else{
                            MOVE_PIECE_LOWER(LQ)
                            if(piece2!=EM){break;}
                        }
                    }
                    break;
                }
                case LP:
                    if(pjump_col<8 && row==3 && abs(col-pjump_col)==1){
                        neoi=16+pjump_col;
                        ENPASS_LOWER()
                    }
                    if(pboard->pieces_map[neoi=(i-8)]==EM){
                        if(row==6 && pboard->pieces_map[neoi=(i-16)]==EM){
                            JUMP_LOWER()
                        }
                        neoi=i-8;
                        if(row==1){
                            for(char j=0;j<4;j++){
                                PROMOTION_LOWER(LP_PROMOTION[j])
                            }
                        }else{
                            MOVE_PIECE_LOWER(LP)
                        }  
                    }
                    neorow=row-1;
                    neocol=col+1;
                    neoi=(neorow*8+neocol);
                    if(neocol<8 && pboard->pieces_map[neoi]<=UK && pboard->pieces_map[neoi]!=EM){
                        if(row==1){
                            for(char j=0;j<4;j++){
                                PROMOTION_LOWER(LP_PROMOTION[j])
                            }
                        }else{
                            MOVE_PIECE_LOWER(LP)
                        }
                    }
                    neocol=col-1;
                    neoi=(neorow*8+neocol);
                    if(neocol>=0 && pboard->pieces_map[neoi]<=UK && pboard->pieces_map[neoi]!=EM){
                        if(row==1){
                            for(char j=0;j<4;j++){
                                PROMOTION_LOWER(LP_PROMOTION[j])
                            }
                        }else{
                            MOVE_PIECE_LOWER(LP)
                        }
                    }
                    break;
                case LK:
                    for(char j=0;j<8;j++){
                        neorow=row+K_MOVES[j][0];
                        neocol=col+K_MOVES[j][1];
                        if(neorow<0 || neorow>=8 || neocol<0 || neocol>=8){
                            continue;
                        }
                        neoi=neorow*8+neocol;
                        piece2=pboard->pieces_map[neoi];
                        if(piece2<=UK){
                            memcpy(&neoboard,pboard,sizeof(struct board));
                            neoboard.pieces_map[i]=EM;
                            neoboard.pieces_map[neoi]=LK;
                            neoboard.lk_loc=neoi;
                            neoboard.la_cst=0;
                            neoboard.lh_cst=0;
                            if(lk_being_checked(&neoboard)) continue;
                            EVAL_CHILD_LOWER()
                        }
                    }
                    if(pboard->la_cst &&\
                       pboard->pieces_map[57]==EM && pboard->pieces_map[58]==EM && pboard->pieces_map[59]==EM &&\
                       la_cstable(pboard)){
                        if(pboard->pieces_map[56]!=LR){
                            pboard->la_cst=0;
                        }else{
                            neoi=58;
                            memcpy(&neoboard,pboard,sizeof(struct board));
                            neoboard.pieces_map[i]=EM;
                            neoboard.pieces_map[neoi]=LK;
                            neoboard.pieces_map[56]=EM;
                            neoboard.pieces_map[59]=LR;
                            neoboard.lk_loc=neoi;
                            neoboard.la_cst=0;
                            neoboard.lh_cst=0;
                            EVAL_CHILD_LOWER()
                        }
                    }
                    if(pboard->lh_cst &&\
                       pboard->pieces_map[61]==EM && pboard->pieces_map[62]==EM &&\
                       lh_cstable(pboard)){
                        if(pboard->pieces_map[63]!=LR){
                            pboard->lh_cst=0;
                        }else{
                            neoi=62;
                            memcpy(&neoboard,pboard,sizeof(struct board));
                            neoboard.pieces_map[i]=EM;
                            neoboard.pieces_map[neoi]=LK;
                            neoboard.pieces_map[63]=EM;
                            neoboard.pieces_map[61]=LR;
                            neoboard.lk_loc=neoi;
                            neoboard.la_cst=0;
                            neoboard.lh_cst=0;
                            EVAL_CHILD_LOWER()
                        }
                    }
                    break;
            }
            /*printf("get %c at (%d,%d) at deep=%d. best move: %s, ",PIECES_NAME[piece],row,col,deep,move_to_str(*ppmove));
            printf("totally %d cases\n",*pcases_count-cc_for_test);*/
            done_map[i]=1;
        }
    }

    if(sug_len>0){
        printf("considering suggestions..\n");
    }
    for(unsigned char s=0;s<sug_len;s++){
        i=suggest[s];
        piece=pboard->pieces_map[i];
        char row=i/8;
        char col=i%8;
        switch(piece){
            case LR:
                for(char j=1;j<=7-col;j++){
                    neoi=i+j;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2>=LR){break;}
                    else{
                        MOVE_ROCK_LOWER
                        if(piece2!=EM){break;}
                    }
                }
                for(char j=1;j<=col;j++){
                    neoi=i-j;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2>=LR){break;}
                    else{
                        MOVE_ROCK_LOWER
                        if(piece2!=EM){break;}
                    }
                }
                for(char j=8;j<=8*(7-row);j+=8){
                    neoi=i+j;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2>=LR){break;}
                    else{
                        MOVE_ROCK_LOWER
                        if(piece2!=EM){break;}
                    }
                }
                for(char j=8;j<=8*row;j+=8){
                    neoi=i-j;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2>=LR){break;}
                    else{
                        MOVE_ROCK_LOWER
                        if(piece2!=EM){break;}
                    }
                }
                break;
            case LN:
                for(char j=0;j<8;j++){
                    neorow=row+N_MOVES[j][0];
                    neocol=col+N_MOVES[j][1];
                    if(neorow<0 || neorow>=8 || neocol<0 || neocol>=8){
                        continue;
                    }
                    neoi=neorow*8+neocol;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2<=UK){
                        MOVE_PIECE_LOWER(LN)
                    }
                }
                break;
            case LB:{
                char maxj=7-(row>col?row:col);
                for(char j=1;j<=maxj;j++){
                    neorow=row+j;
                    neocol=col+j;
                    neoi=neorow*8+neocol;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2>=LR) break;
                    else{
                        MOVE_PIECE_LOWER(LB)
                        if(piece2!=EM){break;}
                    }
                }
                maxj=row<col?row:col;
                for(char j=1;j<=maxj;j++){
                    neorow=row-j;
                    neocol=col-j;
                    neoi=neorow*8+neocol;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2>=LR) break;
                    else{
                        MOVE_PIECE_LOWER(LB)
                        if(piece2!=EM){break;}
                    }
                }
                maxj=col<=(7-row)?col:(7-row);
                for(char j=1;j<=maxj;j++){
                    neorow=row+j;
                    neocol=col-j;
                    neoi=neorow*8+neocol;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2>=LR) break;
                    else{
                        MOVE_PIECE_LOWER(LB)
                        if(piece2!=EM){break;}
                    }
                }
                maxj=row<=(7-col)?row:(7-col);
                for(char j=1;j<=maxj;j++){
                    neorow=row-j;
                    neocol=col+j;
                    neoi=neorow*8+neocol;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2>=LR) break;
                    else{
                        MOVE_PIECE_LOWER(LB)
                        if(piece2!=EM){break;}
                    }
                }
                break;
            }
            case LQ:{
                char maxj;
                for(char j=1;j<=7-col;j++){
                    neoi=i+j;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2>=LR){break;}
                    else{
                        MOVE_PIECE_LOWER(LQ)
                        if(piece2!=EM){break;}
                    }
                }
                for(char j=1;j<=col;j++){
                    neoi=i-j;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2>=LR){break;}
                    else{
                        MOVE_PIECE_LOWER(LQ)
                        if(piece2!=EM){break;}
                    }
                }
                for(char j=8;j<=8*(7-row);j+=8){
                    neoi=i+j;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2>=LR){break;}
                    else{
                        MOVE_PIECE_LOWER(LQ)
                        if(piece2!=EM){break;}
                    }
                }
                for(char j=8;j<=8*row;j+=8){
                    neoi=i-j;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2>=LR){break;}
                    else{
                        MOVE_PIECE_LOWER(LQ)
                        if(piece2!=EM){break;}
                    }
                }
                maxj=7-(row>col?row:col);
                for(char j=1;j<=maxj;j++){
                    neorow=row+j;
                    neocol=col+j;
                    neoi=neorow*8+neocol;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2>=LR) break;
                    else{
                        MOVE_PIECE_LOWER(LQ)
                        if(piece2!=EM){break;}
                    }
                }
                maxj=row<col?row:col;
                for(char j=1;j<=maxj;j++){
                    neorow=row-j;
                    neocol=col-j;
                    neoi=neorow*8+neocol;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2>=LR) break;
                    else{
                        MOVE_PIECE_LOWER(LQ)
                        if(piece2!=EM){break;}
                    }
                }
                maxj=col<(7-row)?col:(7-row);
                for(char j=1;j<=maxj;j++){
                    neorow=row+j;
                    neocol=col-j;
                    neoi=neorow*8+neocol;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2>=LR) break;
                    else{
                        MOVE_PIECE_LOWER(LQ)
                        if(piece2!=EM){break;}
                    }
                }
                maxj=row<(7-col)?row:(7-col);
                for(char j=1;j<=maxj;j++){
                    neorow=row-j;
                    neocol=col+j;
                    neoi=neorow*8+neocol;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2>=LR) break;
                    else{
                        MOVE_PIECE_LOWER(LQ)
                        if(piece2!=EM){break;}
                    }
                }
                break;
            }
            case LP:
                if(pjump_col<8 && row==3 && abs(col-pjump_col)==1){
                    neoi=16+pjump_col;
                    ENPASS_LOWER()
                }
                if(pboard->pieces_map[neoi=(i-8)]==EM){
                    if(row==6 && pboard->pieces_map[neoi=(i-16)]==EM){
                        JUMP_LOWER()
                    }
                    neoi=i-8;
                    if(row==1){
                        for(char j=0;j<4;j++){
                            PROMOTION_LOWER(LP_PROMOTION[j])
                        }
                    }else{
                        MOVE_PIECE_LOWER(LP)
                    }  
                }
                neorow=row-1;
                neocol=col+1;
                neoi=(neorow*8+neocol);
                if(neocol<8 && pboard->pieces_map[neoi]<=UK && pboard->pieces_map[neoi]!=EM){
                    if(row==1){
                        for(char j=0;j<4;j++){
                            PROMOTION_LOWER(LP_PROMOTION[j])
                        }
                    }else{
                        MOVE_PIECE_LOWER(LP)
                    }
                }
                neocol=col-1;
                neoi=(neorow*8+neocol);
                if(neocol>=0 && pboard->pieces_map[neoi]<=UK && pboard->pieces_map[neoi]!=EM){
                    if(row==1){
                        for(char j=0;j<4;j++){
                            PROMOTION_LOWER(LP_PROMOTION[j])
                        }
                    }else{
                        MOVE_PIECE_LOWER(LP)
                    }
                }
                break;
            case LK:
                for(char j=0;j<8;j++){
                    neorow=row+K_MOVES[j][0];
                    neocol=col+K_MOVES[j][1];
                    if(neorow<0 || neorow>=8 || neocol<0 || neocol>=8){
                        continue;
                    }
                    neoi=neorow*8+neocol;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2<=UK){
                        memcpy(&neoboard,pboard,sizeof(struct board));
                        neoboard.pieces_map[i]=EM;
                        neoboard.pieces_map[neoi]=LK;
                        neoboard.lk_loc=neoi;
                        neoboard.la_cst=0;
                        neoboard.lh_cst=0;
                        if(lk_being_checked(&neoboard)) continue;
                        EVAL_CHILD_LOWER()
                    }
                }
                if(pboard->la_cst &&\
                   pboard->pieces_map[57]==EM && pboard->pieces_map[58]==EM && pboard->pieces_map[59]==EM &&\
                   la_cstable(pboard)){
                    if(pboard->pieces_map[56]!=LR){
                        pboard->la_cst=0;
                    }else{
                        neoi=58;
                        memcpy(&neoboard,pboard,sizeof(struct board));
                        neoboard.pieces_map[i]=EM;
                        neoboard.pieces_map[neoi]=LK;
                        neoboard.pieces_map[56]=EM;
                        neoboard.pieces_map[59]=LR;
                        neoboard.lk_loc=neoi;
                        neoboard.la_cst=0;
                        neoboard.lh_cst=0;
                        EVAL_CHILD_LOWER()
                    }
                }
                if(pboard->lh_cst &&\
                   pboard->pieces_map[61]==EM && pboard->pieces_map[62]==EM &&\
                   lh_cstable(pboard)){
                    if(pboard->pieces_map[63]!=LR){
                        pboard->lh_cst=0;
                    }else{
                        neoi=62;
                        memcpy(&neoboard,pboard,sizeof(struct board));
                        neoboard.pieces_map[i]=EM;
                        neoboard.pieces_map[neoi]=LK;
                        neoboard.pieces_map[63]=EM;
                        neoboard.pieces_map[61]=LR;
                        neoboard.lk_loc=neoi;
                        neoboard.la_cst=0;
                        neoboard.lh_cst=0;
                        EVAL_CHILD_LOWER()
                    }
                }
                break;
        }
        done_map[i]=1;
    }
    
    for(char row=0;row<8;row++){
    for(char col=0;col<8;col++){
        i=row*8+col;
        if(done_map[i]){
            //printf("pass %d\n",i);
            continue;
        }
        piece=pboard->pieces_map[i];
        //cc_for_test=*pcases_count;
        switch(piece){
            case LR:
                for(char j=1;j<=7-col;j++){
                    neoi=i+j;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2>=LR){break;}
                    else{
                        MOVE_ROCK_LOWER
                        if(piece2!=EM){break;}
                    }
                }
                for(char j=1;j<=col;j++){
                    neoi=i-j;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2>=LR){break;}
                    else{
                        MOVE_ROCK_LOWER
                        if(piece2!=EM){break;}
                    }
                }
                for(char j=8;j<=8*(7-row);j+=8){
                    neoi=i+j;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2>=LR){break;}
                    else{
                        MOVE_ROCK_LOWER
                        if(piece2!=EM){break;}
                    }
                }
                for(char j=8;j<=8*row;j+=8){
                    neoi=i-j;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2>=LR){break;}
                    else{
                        MOVE_ROCK_LOWER
                        if(piece2!=EM){break;}
                    }
                }
                break;
            case LN:
                for(char j=0;j<8;j++){
                    neorow=row+N_MOVES[j][0];
                    neocol=col+N_MOVES[j][1];
                    if(neorow<0 || neorow>=8 || neocol<0 || neocol>=8){
                        continue;
                    }
                    neoi=neorow*8+neocol;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2<=UK){
                        MOVE_PIECE_LOWER(LN)
                    }
                }
                break;
            case LB:{
                char maxj=7-(row>col?row:col);
                for(char j=1;j<=maxj;j++){
                    neorow=row+j;
                    neocol=col+j;
                    neoi=neorow*8+neocol;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2>=LR) break;
                    else{
                        MOVE_PIECE_LOWER(LB)
                        if(piece2!=EM){break;}
                    }
                }
                maxj=row<col?row:col;
                for(char j=1;j<=maxj;j++){
                    neorow=row-j;
                    neocol=col-j;
                    neoi=neorow*8+neocol;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2>=LR) break;
                    else{
                        MOVE_PIECE_LOWER(LB)
                        if(piece2!=EM){break;}
                    }
                }
                maxj=col<=(7-row)?col:(7-row);
                for(char j=1;j<=maxj;j++){
                    neorow=row+j;
                    neocol=col-j;
                    neoi=neorow*8+neocol;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2>=LR) break;
                    else{
                        MOVE_PIECE_LOWER(LB)
                        if(piece2!=EM){break;}
                    }
                }
                maxj=row<=(7-col)?row:(7-col);
                for(char j=1;j<=maxj;j++){
                    neorow=row-j;
                    neocol=col+j;
                    neoi=neorow*8+neocol;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2>=LR) break;
                    else{
                        MOVE_PIECE_LOWER(LB)
                        if(piece2!=EM){break;}
                    }
                }
                break;
            }
            case LQ:{
                char maxj;
                for(char j=1;j<=7-col;j++){
                    neoi=i+j;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2>=LR){break;}
                    else{
                        MOVE_PIECE_LOWER(LQ)
                        if(piece2!=EM){break;}
                    }
                }
                for(char j=1;j<=col;j++){
                    neoi=i-j;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2>=LR){break;}
                    else{
                        MOVE_PIECE_LOWER(LQ)
                        if(piece2!=EM){break;}
                    }
                }
                for(char j=8;j<=8*(7-row);j+=8){
                    neoi=i+j;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2>=LR){break;}
                    else{
                        MOVE_PIECE_LOWER(LQ)
                        if(piece2!=EM){break;}
                    }
                }
                for(char j=8;j<=8*row;j+=8){
                    neoi=i-j;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2>=LR){break;}
                    else{
                        MOVE_PIECE_LOWER(LQ)
                        if(piece2!=EM){break;}
                    }
                }
                maxj=7-(row>col?row:col);
                for(char j=1;j<=maxj;j++){
                    neorow=row+j;
                    neocol=col+j;
                    neoi=neorow*8+neocol;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2>=LR) break;
                    else{
                        MOVE_PIECE_LOWER(LQ)
                        if(piece2!=EM){break;}
                    }
                }
                maxj=row<col?row:col;
                for(char j=1;j<=maxj;j++){
                    neorow=row-j;
                    neocol=col-j;
                    neoi=neorow*8+neocol;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2>=LR) break;
                    else{
                        MOVE_PIECE_LOWER(LQ)
                        if(piece2!=EM){break;}
                    }
                }
                maxj=col<(7-row)?col:(7-row);
                for(char j=1;j<=maxj;j++){
                    neorow=row+j;
                    neocol=col-j;
                    neoi=neorow*8+neocol;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2>=LR) break;
                    else{
                        MOVE_PIECE_LOWER(LQ)
                        if(piece2!=EM){break;}
                    }
                }
                maxj=row<(7-col)?row:(7-col);
                for(char j=1;j<=maxj;j++){
                    neorow=row-j;
                    neocol=col+j;
                    neoi=neorow*8+neocol;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2>=LR) break;
                    else{
                        MOVE_PIECE_LOWER(LQ)
                        if(piece2!=EM){break;}
                    }
                }
                break;
            }
            case LP:
                if(pjump_col<8 && row==3 && abs(col-pjump_col)==1){
                    neoi=16+pjump_col;
                    ENPASS_LOWER()
                }
                if(pboard->pieces_map[neoi=(i-8)]==EM){
                    if(row==6 && pboard->pieces_map[neoi=(i-16)]==EM){
                        JUMP_LOWER()
                    }
                    neoi=i-8;
                    if(row==1){
                        for(char j=0;j<4;j++){
                            PROMOTION_LOWER(LP_PROMOTION[j])
                        }
                    }else{
                        MOVE_PIECE_LOWER(LP)
                    }  
                }
                neorow=row-1;
                neocol=col+1;
                neoi=(neorow*8+neocol);
                if(neocol<8 && pboard->pieces_map[neoi]<=UK && pboard->pieces_map[neoi]!=EM){
                    if(row==1){
                        for(char j=0;j<4;j++){
                            PROMOTION_LOWER(LP_PROMOTION[j])
                        }
                    }else{
                        MOVE_PIECE_LOWER(LP)
                    }
                }
                neocol=col-1;
                neoi=(neorow*8+neocol);
                if(neocol>=0 && pboard->pieces_map[neoi]<=UK && pboard->pieces_map[neoi]!=EM){
                    if(row==1){
                        for(char j=0;j<4;j++){
                            PROMOTION_LOWER(LP_PROMOTION[j])
                        }
                    }else{
                        MOVE_PIECE_LOWER(LP)
                    }
                }
                break;
            case LK:
                for(char j=0;j<8;j++){
                    neorow=row+K_MOVES[j][0];
                    neocol=col+K_MOVES[j][1];
                    if(neorow<0 || neorow>=8 || neocol<0 || neocol>=8){
                        continue;
                    }
                    neoi=neorow*8+neocol;
                    piece2=pboard->pieces_map[neoi];
                    if(piece2<=UK){
                        memcpy(&neoboard,pboard,sizeof(struct board));
                        neoboard.pieces_map[i]=EM;
                        neoboard.pieces_map[neoi]=LK;
                        neoboard.lk_loc=neoi;
                        neoboard.la_cst=0;
                        neoboard.lh_cst=0;
                        if(lk_being_checked(&neoboard)) continue;
                        EVAL_CHILD_LOWER()
                    }
                }
                if(pboard->la_cst &&\
                   pboard->pieces_map[57]==EM && pboard->pieces_map[58]==EM && pboard->pieces_map[59]==EM &&\
                   la_cstable(pboard)){
                    if(pboard->pieces_map[56]!=LR){
                        pboard->la_cst=0;
                    }else{
                        neoi=58;
                        memcpy(&neoboard,pboard,sizeof(struct board));
                        neoboard.pieces_map[i]=EM;
                        neoboard.pieces_map[neoi]=LK;
                        neoboard.pieces_map[56]=EM;
                        neoboard.pieces_map[59]=LR;
                        neoboard.lk_loc=neoi;
                        neoboard.la_cst=0;
                        neoboard.lh_cst=0;
                        EVAL_CHILD_LOWER()
                    }
                }
                if(pboard->lh_cst &&\
                   pboard->pieces_map[61]==EM && pboard->pieces_map[62]==EM &&\
                   lh_cstable(pboard)){
                    if(pboard->pieces_map[63]!=LR){
                        pboard->lh_cst=0;
                    }else{
                        neoi=62;
                        memcpy(&neoboard,pboard,sizeof(struct board));
                        neoboard.pieces_map[i]=EM;
                        neoboard.pieces_map[neoi]=LK;
                        neoboard.pieces_map[63]=EM;
                        neoboard.pieces_map[61]=LR;
                        neoboard.lk_loc=neoi;
                        neoboard.la_cst=0;
                        neoboard.lh_cst=0;
                        EVAL_CHILD_LOWER()
                    }
                }
                break;
        }
        /*if(piece>=LR){
            printf("get %c at (%d,%d) at deep=%d. best move: %s, ",PIECES_NAME[piece],row,col,deep,move_to_str(*ppmove));
            printf("totally %d cases\n",*pcases_count-cc_for_test);
        }*/
    }}
    if(cases_count_old<(*pcases_count)){
        return mineval;
    }else if(cases_count_old==(*pcases_count)){
        if(lk_being_checked(pboard)){
            (*ppmove)->piece=UWIN;
            //printf("searched %d cases at deep=%d str(**ppmove)=%s\n",(*pcases_count)-cases_count_old,deep,move_to_str(*ppmove));
            return score_board(pboard)+POINT_K;
        }else{
            (*ppmove)->piece=DRAW;
            //printf("searched %d cases at deep=%d str(**ppmove)=%s\n",(*pcases_count)-cases_count_old,deep,move_to_str(*ppmove));
            return 0;
        }
    }else{
        printf("sth wired happened\n");
        exit(1350);
    }
}
#undef PLUSCOUNT
#undef UPDATE_KILLER_LOWER
#undef CMP_RETURN_LOWER
#undef EVAL_CHILD_LOWER
#undef MOVE_PIECE_LOWER
#undef MOVE_ROCK_LOWER
#undef PROMOTION_LOWER
#undef JUMP_LOWER
#undef ENPASS_LOWER

#define GEN_AMOVE_AND_CMP() {\
    amove.piece=piece;\
    amove.from=i;\
    amove.to=neoi;\
    amove.dash=(pboard->pieces_map[neoi]==EM)?'-':'x';\
    pamove_str=move_to_str(&amove);\
    if(cmp_move_str(pmove_str,pamove_str)==0){\
        free(pamove_str);\
        return pneoboard;\
    }else{\
        free(pamove_str);\
    }\
}
#define MOVE_PIECE_STR_LOWER(piece) {\
    memcpy(pneoboard,pboard,sizeof(struct board));\
    pneoboard->pieces_map[i]=EM;\
    pneoboard->pieces_map[neoi]=piece;\
    if(!lk_being_checked(pneoboard)){\
        GEN_AMOVE_AND_CMP()\
    }\
}
#define MOVE_PIECE_STR_UPPER(piece) {\
    memcpy(pneoboard,pboard,sizeof(struct board));\
    pneoboard->pieces_map[i]=EM;\
    pneoboard->pieces_map[neoi]=piece;\
    if(!uk_being_checked(pneoboard)){\
        GEN_AMOVE_AND_CMP()\
    }\
}
#define MOVE_ROCK_STR_LOWER() {\
    memcpy(pneoboard,pboard,sizeof(struct board));\
    pneoboard->pieces_map[i]=EM;\
    pneoboard->pieces_map[neoi]=LR;\
    if(!lk_being_checked(pneoboard)){\
        if(i==56 && pneoboard->la_cst==1){pneoboard->la_cst=0;}\
        if(i==63 && pneoboard->lh_cst==1){pneoboard->lh_cst=0;}\
        GEN_AMOVE_AND_CMP()\
    }\
}
#define MOVE_ROCK_STR_UPPER() {\
    memcpy(pneoboard,pboard,sizeof(struct board));\
    pneoboard->pieces_map[i]=EM;\
    pneoboard->pieces_map[neoi]=UR;\
    if(!uk_being_checked(pneoboard)){\
        if(i==0 && pneoboard->ua_cst==1){pneoboard->ua_cst=0;}\
        if(i==7 && pneoboard->uh_cst==1){pneoboard->uh_cst=0;}\
        GEN_AMOVE_AND_CMP()\
    }\
}
#define PROMOTION_STR_LOWER(piece2) {\
    memcpy(pneoboard,pboard,sizeof(struct board));\
    pneoboard->pieces_map[i]=EM;\
    pneoboard->pieces_map[neoi]=piece2;\
    if(!lk_being_checked(pneoboard)){\
        amove.piece=LP;\
        amove.from=i;\
        amove.to=neoi;\
        amove.dash=PIECES_NAME[piece2];\
        pamove_str=move_to_str(&amove);\
        if(cmp_move_str(pmove_str,pamove_str)==0){\
            free(pamove_str);\
            return pneoboard;\
        }else{\
            free(pamove_str);\
        }\
    }\
}
#define PROMOTION_STR_UPPER(piece2) {\
    memcpy(pneoboard,pboard,sizeof(struct board));\
    pneoboard->pieces_map[i]=EM;\
    pneoboard->pieces_map[neoi]=piece2;\
    if(!uk_being_checked(pneoboard)){\
        amove.piece=UP;\
        amove.from=i;\
        amove.to=neoi;\
        amove.dash=PIECES_NAME[piece2];\
        pamove_str=move_to_str(&amove);\
        if(cmp_move_str(pmove_str,pamove_str)==0){\
            free(pamove_str);\
            return pneoboard;\
        }else{\
            free(pamove_str);\
        }\
    }\
}
struct board *verify_move(struct board* pboard,char turn,char *pmove_str,char pjump_col){
    struct move amove;
    struct board *pneoboard=malloc(sizeof(struct board));
    char *pamove_str;
    char piece,piece2,i,neoi,neorow,neocol;
    switch(turn){
        case 1:{
            for(char row=7;row>=0;row--){
            for(char col=7;col>=0;col--){
                i=row*8+col;
                piece=pboard->pieces_map[i];
                switch(piece){
                    case UR:        
                        for(char j=1;j<=7-col;j++){
                            neoi=i+j;
                            piece2=pboard->pieces_map[neoi];
                            if(0<piece2 && piece2<=6){
                                break;
                            }else{
                                MOVE_ROCK_STR_UPPER()
                                if(piece2>=7){
                                    break;
                                }
                            }
                        }
                        for(char j=1;j<=col;j++){
                            neoi=i-j;
                            piece2=pboard->pieces_map[neoi];
                            if(0<piece2 && piece2<=6){
                                break;
                            }else{
                                MOVE_ROCK_STR_UPPER()
                                if(piece2>=7){
                                    break;
                                }
                            }
                        }
                        for(char j=8;j<=8*(7-row);j+=8){
                            neoi=i+j;
                            piece2=pboard->pieces_map[neoi];
                            if(0<piece2 && piece2<=6){
                                break;
                            }else{
                                MOVE_ROCK_STR_UPPER()
                                if(piece2>=7){
                                    break;
                                }
                            }
                        }
                        for(char j=8;j<=8*row;j+=8){
                            neoi=i-j;
                            piece2=pboard->pieces_map[neoi];
                            if(0<piece2 && piece2<=6){
                                break;
                            }else{
                                MOVE_ROCK_STR_UPPER()
                                if(piece2>=7){
                                    break;
                                }
                            }
                        }
                        break;
                    case UN:
                        for(char j=0;j<8;j++){
                            neorow=row+N_MOVES[j][0];
                            neocol=col+N_MOVES[j][1];
                            if(neorow<0 || neorow>=8 || neocol<0 || neocol>=8){
                                continue;
                            }
                            neoi=neorow*8+neocol;
                            piece2=pboard->pieces_map[neoi];
                            if(piece2==EM || piece2>=LR){
                                MOVE_PIECE_STR_UPPER(UN)
                            }
                        }
                        break;
                    case UB:{
                        char maxj;
                        maxj=row<col?row:col;
                        for(char j=1;j<=maxj;j++){
                            neorow=row-j;
                            neocol=col-j;
                            neoi=neorow*8+neocol;
                            piece2=pboard->pieces_map[neoi];
                            if(piece2<=UK && piece2!=EM)break;
                            else{
                                MOVE_PIECE_STR_UPPER(UB)
                                if(piece2!=EM){
                                    break;
                                }
                            }
                        }
                        maxj=7-(row>col?row:col);
                        for(char j=1;j<=maxj;j++){
                            neorow=row+j;
                            neocol=col+j;
                            neoi=neorow*8+neocol;
                            piece2=pboard->pieces_map[neoi];
                            if(piece2<=UK && piece2!=EM)break;
                            else{
                                MOVE_PIECE_STR_UPPER(UB)
                                if(piece2!=EM){
                                    break;
                                }
                            }
                        }
                        maxj=row<=(7-col)?row:7-col;
                        for(char j=1;j<=maxj;j++){
                            neorow=row-j;
                            neocol=col+j;
                            neoi=neorow*8+neocol;
                            piece2=pboard->pieces_map[neoi];
                            if(piece2<=UK && piece2!=EM) break;
                            else{
                                MOVE_PIECE_STR_UPPER(UB)
                                if(piece2!=EM){
                                    break;
                                }
                            }
                        }
                        maxj=col<=(7-row)?col:7-row;
                        for(char j=1;j<=maxj;j++){
                            neorow=row+j;
                            neocol=col-j;
                            neoi=neorow*8+neocol;
                            piece2=pboard->pieces_map[neoi];
                            if(piece2<=UK && piece2!=EM) break;
                            else{
                                MOVE_PIECE_STR_UPPER(UB)
                                if(piece2!=EM){
                                    break;
                                }
                            }
                        }
                        break;
                    }
                    case UQ:{
                        char maxj;
                        for(char j=1;j<=7-col;j++){
                            neoi=i+j;
                            piece2=pboard->pieces_map[neoi];
                            if(0<piece2 && piece2<=6){
                                break;
                            }else{
                                MOVE_PIECE_STR_UPPER(UQ)
                                if(piece2>=7){
                                    break;
                                }
                            }
                        }
                        for(char j=1;j<=col;j++){
                            neoi=i-j;
                            piece2=pboard->pieces_map[neoi];
                            if(0<piece2 && piece2<=6){
                                break;
                            }else{
                                MOVE_PIECE_STR_UPPER(UQ)
                                if(piece2>=7){
                                    break;
                                }
                            }
                        }
                        for(char j=8;j<=8*(7-row);j+=8){
                            neoi=i+j;
                            piece2=pboard->pieces_map[neoi];
                            if(0<piece2 && piece2<=6){
                                break;
                            }else{
                                MOVE_PIECE_STR_UPPER(UQ)
                                if(piece2>=7){
                                    break;
                                }
                            }
                        }
                        for(char j=8;j<=8*row;j+=8){
                            neoi=i-j;
                            piece2=pboard->pieces_map[neoi];
                            if(0<piece2 && piece2<=6){
                                break;
                            }else{
                                MOVE_PIECE_STR_UPPER(UQ)
                                if(piece2>=7){
                                    break;
                                }
                            }
                        }
                        maxj=7-(row>col?row:col);
                        for(char j=1;j<=maxj;j++){
                            neorow=row+j;
                            neocol=col+j;
                            neoi=neorow*8+neocol;
                            piece2=pboard->pieces_map[neoi];
                            if(piece2<=UK && piece2!=EM) break;
                            else{
                                MOVE_PIECE_STR_UPPER(UQ)
                                if(piece2!=EM){
                                    break;
                                }
                            }
                        }
                        maxj=row<col?row:col;
                        for(char j=1;j<=maxj;j++){
                            neorow=row-j;
                            neocol=col-j;
                            neoi=neorow*8+neocol;
                            piece2=pboard->pieces_map[neoi];
                            if(piece2<=UK && piece2!=EM) break;
                            else{
                                MOVE_PIECE_STR_UPPER(UQ)
                                if(piece2!=EM){
                                    break;
                                }
                            }
                        }
                        maxj=col<(7-row)?col:(7-row);
                        for(char j=1;j<=maxj;j++){
                            neorow=row+j;
                            neocol=col-j;
                            neoi=neorow*8+neocol;
                            piece2=pboard->pieces_map[neoi];
                            if(piece2<=UK && piece2!=EM) break;
                            else{
                                MOVE_PIECE_STR_UPPER(UQ)
                                if(piece2!=EM){
                                    break;
                                }
                            }
                        }
                        maxj=row<(7-col)?row:(7-col);
                        for(char j=1;j<=maxj;j++){
                            neorow=row-j;
                            neocol=col+j;
                            neoi=neorow*8+neocol;
                            piece2=pboard->pieces_map[neoi];
                            if(piece2<=UK && piece2!=EM) break;
                            else{
                                MOVE_PIECE_STR_UPPER(UQ)
                                if(piece2!=EM){
                                    break;
                                }
                            }
                        }
                        break;
                    }
                    case UK:
                        for(char j=0;j<8;j++){
                            neorow=row+K_MOVES[j][0];
                            neocol=col+K_MOVES[j][1];
                            if(neorow<0 || neorow>=8 || neocol<0 || neocol>=8){
                                continue;
                            }
                            neoi=neorow*8+neocol;
                            piece2=pboard->pieces_map[neoi];
                            if(piece2==EM || piece2>=LR){
                                memcpy(pneoboard,pboard,sizeof(struct board));
                                pneoboard->pieces_map[i]=EM;
                                pneoboard->pieces_map[neoi]=UK;
                                pneoboard->uk_loc=neoi;
                                pneoboard->ua_cst=0;
                                pneoboard->uh_cst=0;
                                if(uk_being_checked(pneoboard)) continue;
                                GEN_AMOVE_AND_CMP()
                            }
                        }
                        if(pboard->ua_cst &&\
                           pboard->pieces_map[1]==EM && pboard->pieces_map[2]==EM && pboard->pieces_map[3]==EM &&\
                           ua_cstable(pboard)){
                            neoi=2;
                            memcpy(pneoboard,pboard,sizeof(struct board));
                            pneoboard->pieces_map[i]=EM;
                            pneoboard->pieces_map[neoi]=UK;
                            pneoboard->pieces_map[0]=EM;
                            pneoboard->pieces_map[3]=UR;
                            pneoboard->uk_loc=neoi;
                            pneoboard->ua_cst=0;
                            pneoboard->uh_cst=0;
                            GEN_AMOVE_AND_CMP()
                        }
                        if(pboard->uh_cst &&\
                           pboard->pieces_map[5]==EM && pboard->pieces_map[6]==EM &&\
                           uh_cstable(pboard)){
                            neoi=6;
                            memcpy(pneoboard,pboard,sizeof(struct board));
                            pneoboard->pieces_map[i]=EM;
                            pneoboard->pieces_map[neoi]=UK;
                            pneoboard->pieces_map[7]=EM;
                            pneoboard->pieces_map[5]=UR;
                            pneoboard->uk_loc=neoi;
                            pneoboard->ua_cst=0;
                            pneoboard->uh_cst=0;
                            GEN_AMOVE_AND_CMP()
                        }
                        break;
                    case UP:
                        if(pjump_col<8 && row==4 && abs(col-pjump_col)==1){
                            neoi=40+pjump_col;
                            memcpy(pneoboard,pboard,sizeof(struct board));\
                            pneoboard->pieces_map[i]=EM;
                            pneoboard->pieces_map[neoi]=UP;
                            pneoboard->pieces_map[neoi-8]=EM;
                            if(!uk_being_checked(pneoboard)){
                                amove.piece=UP;
                                amove.from=i;
                                amove.to=neoi;
                                amove.dash='x';
                                pamove_str=move_to_str(&amove);
                                if(strcmp(pmove_str,pamove_str)==0){
                                    free(pamove_str);
                                    return pneoboard;
                                }else{
                                    free(pamove_str);
                                }
                            }
                        }
                        if(pboard->pieces_map[neoi=(i+8)]==EM){
                            if(row==1 && pboard->pieces_map[neoi=(i+16)]==EM){
                                MOVE_PIECE_STR_UPPER(UP)
                            }
                            neoi=i+8;
                            if(row==6){
                                for(char j=0;j<4;j++){
                                    PROMOTION_STR_UPPER(UP_PROMOTION[j])
                                }
                            }else{
                                MOVE_PIECE_STR_UPPER(UP)
                            }
                        }
                        neorow=row+1;
                        neocol=col+1;
                        if(neocol<8 && pboard->pieces_map[neoi=(neorow*8+neocol)]>=LR){
                            if(row==6){
                                for(char j=0;j<4;j++){
                                    PROMOTION_STR_UPPER(UP_PROMOTION[j])
                                }
                            }else{
                                MOVE_PIECE_STR_UPPER(UP)
                            }
                        }
                        neocol=col-1;
                        if(neocol>=0 && pboard->pieces_map[neoi=(neorow*8+neocol)]>=LR){
                            if(row==6){
                                for(char j=0;j<4;j++){
                                    PROMOTION_STR_UPPER(UP_PROMOTION[j])
                                }
                            }else{
                                MOVE_PIECE_STR_UPPER(UP)
                            }
                        }
                        break;
                }
            }}
            free(pneoboard);
            return NULL;
        }
        case 0:{
            for(char row=0;row<8;row++){
            for(char col=0;col<8;col++){
                i=row*8+col;
                piece=pboard->pieces_map[i];
                switch(piece){
                    case LR:
                        for(char j=1;j<=7-col;j++){
                            neoi=i+j;
                            piece2=pboard->pieces_map[neoi];
                            if(piece2>=LR){break;}
                            else{
                                MOVE_ROCK_STR_LOWER()
                                if(piece2!=EM){break;}
                            }
                        }
                        for(char j=1;j<=col;j++){
                            neoi=i-j;
                            piece2=pboard->pieces_map[neoi];
                            if(piece2>=LR){break;}
                            else{
                                MOVE_ROCK_STR_LOWER()
                                if(piece2!=EM){break;}
                            }
                        }
                        for(char j=8;j<=8*(7-row);j+=8){
                            neoi=i+j;
                            piece2=pboard->pieces_map[neoi];
                            if(piece2>=LR){break;}
                            else{
                                MOVE_ROCK_STR_LOWER()
                                if(piece2!=EM){break;}
                            }
                        }
                        for(char j=8;j<=8*row;j+=8){
                            neoi=i-j;
                            piece2=pboard->pieces_map[neoi];
                            if(piece2>=LR){break;}
                            else{
                                MOVE_ROCK_STR_LOWER()
                                if(piece2!=EM){break;}
                            }
                        }
                        break;
                    case LN:
                        for(char j=0;j<8;j++){
                            neorow=row+N_MOVES[j][0];
                            neocol=col+N_MOVES[j][1];
                            if(neorow<0 || neorow>=8 || neocol<0 || neocol>=8){
                                continue;
                            }
                            neoi=neorow*8+neocol;
                            piece2=pboard->pieces_map[neoi];
                            if(piece2<=UK){
                                MOVE_PIECE_STR_LOWER(LN)
                            }
                        }
                        break;
                    case LB:{
                        char maxj=7-(row>col?row:col);
                        for(char j=1;j<=maxj;j++){
                            neorow=row+j;
                            neocol=col+j;
                            neoi=neorow*8+neocol;
                            piece2=pboard->pieces_map[neoi];
                            if(piece2>=LR) break;
                            else{
                                MOVE_PIECE_STR_LOWER(LB)
                                if(piece2!=EM){break;}
                            }
                        }
                        maxj=row<col?row:col;
                        for(char j=1;j<=maxj;j++){
                            neorow=row-j;
                            neocol=col-j;
                            neoi=neorow*8+neocol;
                            piece2=pboard->pieces_map[neoi];
                            if(piece2>=LR) break;
                            else{
                                MOVE_PIECE_STR_LOWER(LB)
                                if(piece2!=EM){break;}
                            }
                        }
                        maxj=col<=(7-row)?col:(7-row);
                        for(char j=1;j<=maxj;j++){
                            neorow=row+j;
                            neocol=col-j;
                            neoi=neorow*8+neocol;
                            piece2=pboard->pieces_map[neoi];
                            if(piece2>=LR) break;
                            else{
                                MOVE_PIECE_STR_LOWER(LB)
                                if(piece2!=EM){break;}
                            }
                        }
                        maxj=row<=(7-col)?row:(7-col);
                        for(char j=1;j<=maxj;j++){
                            neorow=row-j;
                            neocol=col+j;
                            neoi=neorow*8+neocol;
                            piece2=pboard->pieces_map[neoi];
                            if(piece2>=LR) break;
                            else{
                                MOVE_PIECE_STR_LOWER(LB)
                                if(piece2!=EM){break;}
                            }
                        }
                        break;
                    }
                    case LQ:{
                        char maxj;
                        for(char j=1;j<=7-col;j++){
                            neoi=i+j;
                            piece2=pboard->pieces_map[neoi];
                            if(piece2>=LR){break;}
                            else{
                                MOVE_PIECE_STR_LOWER(LQ)
                                if(piece2!=EM){break;}
                            }
                        }
                        for(char j=1;j<=col;j++){
                            neoi=i-j;
                            piece2=pboard->pieces_map[neoi];
                            if(piece2>=LR){break;}
                            else{
                                MOVE_PIECE_STR_LOWER(LQ)
                                if(piece2!=EM){break;}
                            }
                        }
                        for(char j=8;j<=8*(7-row);j+=8){
                            neoi=i+j;
                            piece2=pboard->pieces_map[neoi];
                            if(piece2>=LR){break;}
                            else{
                                MOVE_PIECE_STR_LOWER(LQ)
                                if(piece2!=EM){break;}
                            }
                        }
                        for(char j=8;j<=8*row;j+=8){
                            neoi=i-j;
                            piece2=pboard->pieces_map[neoi];
                            if(piece2>=LR){break;}
                            else{
                                MOVE_PIECE_STR_LOWER(LQ)
                                if(piece2!=EM){break;}
                            }
                        }
                        maxj=7-(row>col?row:col);
                        for(char j=1;j<=maxj;j++){
                            neorow=row+j;
                            neocol=col+j;
                            neoi=neorow*8+neocol;
                            piece2=pboard->pieces_map[neoi];
                            if(piece2>=LR) break;
                            else{
                                MOVE_PIECE_STR_LOWER(LQ)
                                if(piece2!=EM){break;}
                            }
                        }
                        maxj=row<col?row:col;
                        for(char j=1;j<=maxj;j++){
                            neorow=row-j;
                            neocol=col-j;
                            neoi=neorow*8+neocol;
                            piece2=pboard->pieces_map[neoi];
                            if(piece2>=LR) break;
                            else{
                                MOVE_PIECE_STR_LOWER(LQ)
                                if(piece2!=EM){break;}
                            }
                        }
                        maxj=col<(7-row)?col:(7-row);
                        for(char j=1;j<=maxj;j++){
                            neorow=row+j;
                            neocol=col-j;
                            neoi=neorow*8+neocol;
                            piece2=pboard->pieces_map[neoi];
                            if(piece2>=LR) break;
                            else{
                                MOVE_PIECE_STR_LOWER(LQ)
                                if(piece2!=EM){break;}
                            }
                        }
                        maxj=row<(7-col)?row:(7-col);
                        for(char j=1;j<=maxj;j++){
                            neorow=row-j;
                            neocol=col+j;
                            neoi=neorow*8+neocol;
                            piece2=pboard->pieces_map[neoi];
                            if(piece2>=LR) break;
                            else{
                                MOVE_PIECE_STR_LOWER(LQ)
                                if(piece2!=EM){break;}
                            }
                        }
                        break;
                    }
                    case LK:
                        for(char j=0;j<8;j++){
                            neorow=row+K_MOVES[j][0];
                            neocol=col+K_MOVES[j][1];
                            if(neorow<0 || neorow>=8 || neocol<0 || neocol>=8){
                                continue;
                            }
                            neoi=neorow*8+neocol;
                            piece2=pboard->pieces_map[neoi];
                            if(piece2<=UK){
                                memcpy(pneoboard,pboard,sizeof(struct board));
                                pneoboard->pieces_map[i]=EM;
                                pneoboard->pieces_map[neoi]=LK;
                                pneoboard->lk_loc=neoi;
                                pneoboard->la_cst=0;
                                pneoboard->lh_cst=0;
                                if(!lk_being_checked(pneoboard)){
                                    GEN_AMOVE_AND_CMP()
                                }
                            }
                        }
                        if(pboard->la_cst &&\
                           pboard->pieces_map[57]==EM && pboard->pieces_map[58]==EM && pboard->pieces_map[59]==EM &&\
                           la_cstable(pboard)){
                            neoi=58;
                            memcpy(pneoboard,pboard,sizeof(struct board));
                            pneoboard->pieces_map[i]=EM;
                            pneoboard->pieces_map[neoi]=LK;
                            pneoboard->pieces_map[56]=EM;
                            pneoboard->pieces_map[59]=LR;
                            pneoboard->lk_loc=neoi;
                            pneoboard->la_cst=0;
                            pneoboard->lh_cst=0;
                            GEN_AMOVE_AND_CMP()
                        }
                        if(pboard->lh_cst &&\
                           pboard->pieces_map[61]==EM && pboard->pieces_map[62]==EM &&\
                           lh_cstable(pboard)){
                            neoi=62;
                            memcpy(pneoboard,pboard,sizeof(struct board));
                            pneoboard->pieces_map[i]=EM;
                            pneoboard->pieces_map[neoi]=LK;
                            pneoboard->pieces_map[63]=EM;
                            pneoboard->pieces_map[61]=LR;
                            pneoboard->lk_loc=neoi;
                            pneoboard->la_cst=0;
                            pneoboard->lh_cst=0;
                            GEN_AMOVE_AND_CMP()
                        }
                        break;
                    case LP:
                        if(pjump_col<8 && row==3 && abs(col-pjump_col)==1){
                            neoi=16+pjump_col;
                            memcpy(pneoboard,pboard,sizeof(struct board));\
                            pneoboard->pieces_map[i]=EM;
                            pneoboard->pieces_map[neoi]=LP;
                            pneoboard->pieces_map[neoi+8]=EM;
                            if(!lk_being_checked(pneoboard)){
                                amove.piece=LP;\
                                amove.from=i;
                                amove.to=neoi;
                                amove.dash='x';
                                pamove_str=move_to_str(&amove);
                                if(strcmp(pmove_str,pamove_str)==0){
                                    free(pamove_str);
                                    return pneoboard;
                                }else{
                                    free(pamove_str);
                                }
                            }
                        }
                        if(pboard->pieces_map[neoi=(i-8)]==EM){
                            if(row==6 && pboard->pieces_map[neoi=(i-16)]==EM){
                                memcpy(pneoboard,pboard,sizeof(struct board));
                                pneoboard->pieces_map[i]=EM;
                                pneoboard->pieces_map[neoi]=LP;
                                if(!lk_being_checked(pneoboard)){
                                    GEN_AMOVE_AND_CMP()
                                }
                            }
                            neoi=i-8;
                            if(row==1){
                                for(char j=0;j<4;j++){
                                    PROMOTION_STR_LOWER(LP_PROMOTION[j])
                                }
                            }else{
                                memcpy(pneoboard,pboard,sizeof(struct board));
                                pneoboard->pieces_map[i]=EM;
                                pneoboard->pieces_map[neoi]=LP;
                                if(!lk_being_checked(pneoboard)){
                                    GEN_AMOVE_AND_CMP()
                                }
                            }  
                        }
                        neorow=row-1;
                        neocol=col+1;
                        neoi=(neorow*8+neocol);
                        if(neocol<8 && pboard->pieces_map[neoi]<=UK && pboard->pieces_map[neoi]!=EM){
                            if(row==1){
                                for(char j=0;j<4;j++){
                                    PROMOTION_STR_LOWER(LP_PROMOTION[j])
                                }
                            }else{
                                memcpy(pneoboard,pboard,sizeof(struct board));
                                pneoboard->pieces_map[i]=EM;
                                pneoboard->pieces_map[neoi]=LP;
                                if(!lk_being_checked(pneoboard)){
                                    GEN_AMOVE_AND_CMP()
                                }
                            }
                        }
                        neocol=col-1;
                        neoi=(neorow*8+neocol);
                        if(neocol>=0 && pboard->pieces_map[neoi]<=UK && pboard->pieces_map[neoi]!=EM){
                            if(row==1){
                                for(char j=0;j<4;j++){
                                    PROMOTION_STR_LOWER(LP_PROMOTION[j])
                                }
                            }else{
                                memcpy(pneoboard,pboard,sizeof(struct board));
                                pneoboard->pieces_map[i]=EM;
                                pneoboard->pieces_map[neoi]=LP;
                                if(!lk_being_checked(pneoboard)){
                                    GEN_AMOVE_AND_CMP()
                                }
                            }
                        }
                        break;
                }
            }}
            free(pneoboard);
            return NULL;
        }
    }
}
#undef GEN_AMOVE_AND_CMP
#undef MOVE_PIECE_STR_LOWER
#undef MOVE_PIECE_STR_UPPER
#undef MOVE_ROCK_STR_LOWER
#undef MOVE_ROCK_STR_UPPER
#undef PROMOTION_STR_LOWER
#undef PROMOTION_STR_UPPER

#define CHECK_RETURN return piece2;
char uk_being_checked(struct board * pboard){
    char row,col,neorow,neocol,i,neoi,piece2;
    i=pboard->uk_loc;
    row=i/8;
    col=i%8;
    //Rock
    for(char j=1;j<=7-col;j++){
        neoi=i+j;
        piece2=pboard->pieces_map[neoi];
        if(piece2==LR || piece2==LQ){
            CHECK_RETURN
        }else{
            if(piece2!=EM){break;}
        }
    }
    for(char j=1;j<=col;j++){
        neoi=i-j;
        piece2=pboard->pieces_map[neoi];
        if(piece2==LR || piece2==LQ){
            CHECK_RETURN
        }else{
            if(piece2!=EM){break;}
        }
    }
    for(char j=8;j<=8*(7-row);j+=8){
        neoi=i+j;
        piece2=pboard->pieces_map[neoi];
        if(piece2==LR || piece2==LQ){
            CHECK_RETURN
        }else{
            if(piece2!=EM){break;}
        }
    }
    for(char j=8;j<=8*row;j+=8){
        neoi=i-j;
        piece2=pboard->pieces_map[neoi];
        if(piece2==LR || piece2==LQ){
            CHECK_RETURN
        }else{
            if(piece2!=EM){break;}
        }
    }
    //Bishop
    char maxj;
    maxj=row<col?row:col;
    for(char j=1;j<=maxj;j++){
        neorow=row-j;
        neocol=col-j;
        neoi=neorow*8+neocol;
        piece2=pboard->pieces_map[neoi];
        if(piece2==LB || piece2==LQ) CHECK_RETURN
        else if(piece2!=EM) break;
    }
    maxj=7-(row>col?row:col);
    for(char j=1;j<=maxj;j++){
        neorow=row+j;
        neocol=col+j;
        neoi=neorow*8+neocol;
        piece2=pboard->pieces_map[neoi];
        if(piece2==LB || piece2==LQ) CHECK_RETURN
        else if(piece2!=EM) break;
    }
    maxj=row<=(7-col)?row:7-col;
    for(char j=1;j<=maxj;j++){
        neorow=row-j;
        neocol=col+j;
        neoi=neorow*8+neocol;
        piece2=pboard->pieces_map[neoi];
        if(piece2==LB || piece2==LQ) CHECK_RETURN
        else if(piece2!=EM) break;
    }
    maxj=col<=(7-row)?col:7-row;
    for(char j=1;j<=maxj;j++){
        neorow=row+j;
        neocol=col-j;
        neoi=neorow*8+neocol;
        piece2=pboard->pieces_map[neoi];
        if(piece2==LB || piece2==LQ) CHECK_RETURN
        else if(piece2!=EM) break;
    }
    //Knight
    for(char j=0;j<8;j++){
        neorow=row+N_MOVES[j][0];
        neocol=col+N_MOVES[j][1];
        if(neorow<0 || neorow>=8 || neocol<0 || neocol>=8){
            continue;
        }
        neoi=neorow*8+neocol;
        piece2=pboard->pieces_map[neoi];
        if(piece2==LN){CHECK_RETURN}
    }
    //Pawn
    neorow=row+1;
    neocol=col+1;
    if(neorow<8 && neocol<8){
        piece2=pboard->pieces_map[neorow*8+neocol];
        if(piece2==LP || piece2==LK) CHECK_RETURN
    }
    neocol=col-1;
    if(neorow<8 && neocol>=0){
        piece2=pboard->pieces_map[neorow*8+neocol];
        if(piece2==LP || piece2==LK) CHECK_RETURN
    }
    //King
    for(char j=0;j<6;j++){
        neorow=row+K_MOVES_SUB_LP[j][0];
        neocol=col+K_MOVES_SUB_LP[j][1];
        if(neorow<0 || neorow>=8 || neocol<0 || neocol>=8){
            continue;
        }
        neoi=neorow*8+neocol;
        piece2=pboard->pieces_map[neoi];
        if(piece2==LK) CHECK_RETURN
    }
    return 0;
}
char lk_being_checked(struct board * pboard){
    char row,col,neorow,neocol,i,neoi,piece2;
    i=pboard->lk_loc;
    row=i/8;
    col=i%8;
    //Rock
    for(char j=1;j<=7-col;j++){
        neoi=i+j;
        piece2=pboard->pieces_map[neoi];
        if(piece2==UR || piece2==UQ){
            CHECK_RETURN
        }else{
            if(piece2!=EM){
                break;
            }
        }
    }
    for(char j=1;j<=col;j++){
        neoi=i-j;
        piece2=pboard->pieces_map[neoi];
        if(piece2==UR || piece2==UQ){
            CHECK_RETURN
        }else{
            if(piece2!=EM){
                break;
            }
        }
    }
    for(char j=8;j<=8*(7-row);j+=8){
        neoi=i+j;
        piece2=pboard->pieces_map[neoi];
        if(piece2==UR || piece2==UQ){
            CHECK_RETURN
        }else{
            if(piece2!=EM){
                break;
            }
        }
    }
    for(char j=8;j<=8*row;j+=8){
        neoi=i-j;
        piece2=pboard->pieces_map[neoi];
        if(piece2==UR || piece2==UQ){
            CHECK_RETURN
        }else{
            if(piece2!=EM){
                break;
            }
        }
    }
    //Bishop
    char maxj;
    maxj=row<col?row:col;
    for(char j=1;j<=maxj;j++){
        neorow=row-j;
        neocol=col-j;
        neoi=neorow*8+neocol;
        piece2=pboard->pieces_map[neoi];
        if(piece2==UB || piece2==UQ) CHECK_RETURN
        else if(piece2!=EM) break;
    }
    maxj=7-(row>col?row:col);
    for(char j=1;j<=maxj;j++){
        neorow=row+j;
        neocol=col+j;
        neoi=neorow*8+neocol;
        piece2=pboard->pieces_map[neoi];
        if(piece2==UB || piece2==UQ) CHECK_RETURN
        else if(piece2!=EM) break;
    }
    maxj=row<=(7-col)?row:7-col;
    for(char j=1;j<=maxj;j++){
        neorow=row-j;
        neocol=col+j;
        neoi=neorow*8+neocol;
        piece2=pboard->pieces_map[neoi];
        if(piece2==UB || piece2==UQ) CHECK_RETURN
        else if(piece2!=EM) break;
    }
    maxj=col<=(7-row)?col:7-row;
    for(char j=1;j<=maxj;j++){
        neorow=row+j;
        neocol=col-j;
        neoi=neorow*8+neocol;
        piece2=pboard->pieces_map[neoi];
        if(piece2==UB || piece2==UQ) CHECK_RETURN
        else if(piece2!=EM) break;
    }
    //Knight
    for(char j=0;j<8;j++){
        neorow=row+N_MOVES[j][0];
        neocol=col+N_MOVES[j][1];
        if(neorow<0 || neorow>=8 || neocol<0 || neocol>=8){
            continue;
        }
        neoi=neorow*8+neocol;
        piece2=pboard->pieces_map[neoi];
        if(piece2==UN){
            CHECK_RETURN
        }
    }
    //Pawn
    neorow=row-1;
    neocol=col+1;
    if(neorow>=0 && neocol<8){
        piece2=pboard->pieces_map[neorow*8+neocol];
        if(piece2==UP || piece2==UK) CHECK_RETURN
    }
    neocol=col-1;
    if(neorow>=0 && neocol>=0){
        piece2=pboard->pieces_map[neorow*8+neocol];
        if(piece2==UP || piece2==UK) CHECK_RETURN
    }
    //King
    for(char j=0;j<6;j++){
        neorow=row+K_MOVES_SUB_UP[j][0];
        neocol=col+K_MOVES_SUB_UP[j][1];
        if(neorow<0 || neorow>=8 || neocol<0 || neocol>=8){
            continue;
        }
        neoi=neorow*8+neocol;
        piece2=pboard->pieces_map[neoi];
        if(piece2==UK) CHECK_RETURN
    }
    return 0;
}
#undef CHECK_RETURN
#define CHECK_RETURN return 0;
char la_cstable(struct board * pboard){
    char piece2;
    //Rock
    for(char j=61;j<=63;j++){
        piece2=pboard->pieces_map[j];
        if(piece2==UR || piece2==UQ){
            CHECK_RETURN
        }else{
            if(piece2!=EM){
                break;
            }
        }
    }
    for(char i=56;i<=60;i++){
        for(char j=(i-8);j>=(i-56);j-=8){
            piece2=pboard->pieces_map[j];
            if(piece2==UR || piece2==UQ){
                CHECK_RETURN
            }else{
                if(piece2!=EM){
                    break;
                }
            }
        }
    }
    //Knight
    for(char j=40;j<=45;j++){
        piece2=pboard->pieces_map[j];
        if(piece2==UN){
            CHECK_RETURN
        }
    }
    for(char j=48;j<=54;j++){
        piece2=pboard->pieces_map[j];
        if(piece2==UN){
            CHECK_RETURN
        }
    }
    //Pawn and King
    for(char j=48;j<=53;j++){
        piece2=pboard->pieces_map[j];
        if(piece2==UP || piece2==UK){
            CHECK_RETURN
        }
    }
    //Bishop
    char neorow,neocol,neoi;
    const char row=7;
    for(char col=0;col<=4;col++){
        char maxj;
        maxj=row<col?row:col;
        for(char j=1;j<=maxj;j++){
            neorow=row-j;
            neocol=col-j;
            neoi=neorow*8+neocol;
            piece2=pboard->pieces_map[neoi];
            if(piece2==UB || piece2==UQ) CHECK_RETURN
            else if(piece2!=EM) break;
        }
        
        maxj=row<=(7-col)?row:7-col;
        for(char j=1;j<=maxj;j++){
            neorow=row-j;
            neocol=col+j;
            neoi=neorow*8+neocol;
            piece2=pboard->pieces_map[neoi];
            if(piece2==UB || piece2==UQ) CHECK_RETURN
            else if(piece2!=EM) break;
        }
    }
    return 1;
}
char lh_cstable(struct board * pboard){
    char piece2;
    //Rock
    for(char j=59;j>=56;j--){
        piece2=pboard->pieces_map[j];
        if(piece2==UR || piece2==UQ){
            CHECK_RETURN
        }else{
            if(piece2!=EM){
                break;
            }
        }
    }
    for(char i=60;i<=63;i++){
        for(char j=(i-8);j>=(i-56);j-=8){
            piece2=pboard->pieces_map[j];
            if(piece2==UR || piece2==UQ){
                CHECK_RETURN
            }else{
                if(piece2!=EM){
                    break;
                }
            }
        }
    }
    //Knight
    for(char j=43;j<=47;j++){
        piece2=pboard->pieces_map[j];
        if(piece2==UN){
            CHECK_RETURN
        }
    }
    for(char j=50;j<=55;j++){
        piece2=pboard->pieces_map[j];
        if(piece2==UN){
            CHECK_RETURN
        }
    }
    //Pawn and King
    for(char j=51;j<=55;j++){
        piece2=pboard->pieces_map[j];
        if(piece2==UP || piece2==UK){
            CHECK_RETURN
        }
    }
    //Bishop
    char neorow,neocol,neoi;
    const char row=7;
    for(char col=4;col<=7;col++){
        char maxj;
        maxj=row<col?row:col;
        for(char j=1;j<=maxj;j++){
            neorow=row-j;
            neocol=col-j;
            neoi=neorow*8+neocol;
            piece2=pboard->pieces_map[neoi];
            if(piece2==UB || piece2==UQ) CHECK_RETURN
            else if(piece2!=EM) break;
        }
        maxj=row<=(7-col)?row:7-col;
        for(char j=1;j<=maxj;j++){
            neorow=row-j;
            neocol=col+j;
            neoi=neorow*8+neocol;
            piece2=pboard->pieces_map[neoi];
            if(piece2==UB || piece2==UQ) CHECK_RETURN
            else if(piece2!=EM) break;
        }
    }
    return 1;
}
char ua_cstable(struct board * pboard){
    char piece2;
    //Rock
    for(char j=5;j<=7;j++){
        piece2=pboard->pieces_map[j];
        if(piece2==LR || piece2==LQ){
            CHECK_RETURN
        }else{
            if(piece2!=EM){
                break;
            }
        }
    }
    for(char i=0;i<=4;i++){
        for(char j=(i+8);j<=(i+56);j+=8){
            piece2=pboard->pieces_map[j];
            if(piece2==LR || piece2==LQ){
                CHECK_RETURN
            }else{
                if(piece2!=EM){
                    break;
                }
            }
        }
    }
    //Knight
    for(char j=8;j<=14;j++){
        piece2=pboard->pieces_map[j];
        if(piece2==LN){
            CHECK_RETURN
        }
    }
    for(char j=16;j<=21;j++){
        piece2=pboard->pieces_map[j];
        if(piece2==LN){
            CHECK_RETURN
        }
    }
    //Pawn and King
    for(char j=8;j<=13;j++){
        piece2=pboard->pieces_map[j];
        if(piece2==LP || piece2==LK){
            CHECK_RETURN
        }
    }
    //Bishop
    char maxj,neorow,neocol,neoi;
    const char row=0;
    for(char col=0;col<=4;col++){
        maxj=7-(row>col?row:col);
        for(char j=1;j<=maxj;j++){
            neorow=row+j;
            neocol=col+j;
            neoi=neorow*8+neocol;
            piece2=pboard->pieces_map[neoi];
            if(piece2==LB || piece2==LQ) CHECK_RETURN
            else if(piece2!=EM) break;
        }
        maxj=col<=(7-row)?col:7-row;
        for(char j=1;j<=maxj;j++){
            neorow=row+j;
            neocol=col-j;
            neoi=neorow*8+neocol;
            piece2=pboard->pieces_map[neoi];
            if(piece2==LB || piece2==LQ) CHECK_RETURN
            else if(piece2!=EM) break;
        }
    }
    return 1;
}
char uh_cstable(struct board * pboard){
    char piece2;
    //Rock
    for(char j=4;j>=0;j--){
        piece2=pboard->pieces_map[j];
        if(piece2==LR || piece2==LQ){
            CHECK_RETURN
        }else{
            if(piece2!=EM){
                break;
            }
        }
    }
    for(char i=4;i<=7;i++){
        for(char j=(i+8);j<=(i+56);j+=8){
            piece2=pboard->pieces_map[j];
            if(piece2==LR || piece2==LQ){
                CHECK_RETURN
            }else{
                if(piece2!=EM){
                    break;
                }
            }
        }
    }
    //Knight
    for(char j=10;j<=15;j++){
        piece2=pboard->pieces_map[j];
        if(piece2==LN){
            CHECK_RETURN
        }
    }
    for(char j=19;j<=23;j++){
        piece2=pboard->pieces_map[j];
        if(piece2==LN){
            CHECK_RETURN
        }
    }
    //Pawn and King
    for(char j=3;j<=15;j++){
        piece2=pboard->pieces_map[j];
        if(piece2==LP || piece2==LK){
            CHECK_RETURN
        }
    }
    //Bishop
    char maxj,neorow,neocol,neoi;
    const char row=0;
    for(char col=4;col<=7;col++){
        maxj=7-(row>col?row:col);
        for(char j=1;j<=maxj;j++){
            neorow=row+j;
            neocol=col+j;
            neoi=neorow*8+neocol;
            piece2=pboard->pieces_map[neoi];
            if(piece2==LB || piece2==LQ) CHECK_RETURN
            else if(piece2!=EM) break;
        }
        maxj=col<=(7-row)?col:7-row;
        for(char j=1;j<=maxj;j++){
            neorow=row+j;
            neocol=col-j;
            neoi=neorow*8+neocol;
            piece2=pboard->pieces_map[neoi];
            if(piece2==LB || piece2==LQ) CHECK_RETURN
            else if(piece2!=EM) break;
        }
    }
    return 1;
}
#undef CHECK_RETURN


void test_cstable(){
    struct move amove;
    amove.piece=LK;
    amove.from=60;
    amove.to=62;
    amove.dash='-';
    printf("%s\n",move_to_str(&amove));


    struct board b;
    prepare_init_board(&b);
    b.pieces_map[61]=EM;
    b.pieces_map[62]=EM;
    dump_board(&b);

    struct board *pneob=verify_move(&b,0,"O-O",CANNOT_ENPASS);
    if(pneob){
        dump_board(pneob);
        free(pneob);
    }else{
        printf("pneob=NULL\n");
    }
}
void test_being_checked(){
    struct board b;
    //memset(&(b.pieces_map),(char)EM,64);
    //b.pieces_map[9]=LK;
    //b.pieces_map[16]=UK;
    memcpy(&(b.pieces_map),&INIT_BOARD,64);
    calc_king_loc(&b);
    
    print_board(&b);
    char ans=uk_being_checked(&b);
    printf("test uk_being_checked: %d\n",ans);
    ans=lk_being_checked(&b);
    printf("test lk_being_checked: %d\n",ans);
}
void test_moves(){
    struct move *pm1,*pm2,*pm3;
    pm1=(struct move *)malloc(sizeof(struct move));
    pm1->piece=UK;
    pm1->from=0;
    pm1->to=1;
    pm1->dash='x';
    pm1->next=(struct move *)(pm2=(struct move *)malloc(sizeof(struct move)));
    pm2->piece=LK;
    pm2->from=63;
    pm2->to=62;
    pm2->dash='y';
    pm2->next=(struct move *)(pm3=(struct move *)malloc(sizeof(struct move)));
    pm3->piece=UK;
    pm3->from=1;
    pm3->to=2;
    pm3->dash='-';
    pm3->next=NULL;
    printf("gen %ld\n",(unsigned long)pm1);
    printf("gen %ld\n",(unsigned long)pm2);
    printf("gen %ld\n",(unsigned long)pm3);
    print_moves(pm1);
    free_moves(pm1);
}
void test_cmp_move_str(){
    printf("%d\n",cmp_move_str("pb4","pc5-b4=q"));
}
void test_gen_jump_col(){
    printf("%d\n",gen_jump_col("Pe7-e6"));
}
void test_count_control(){
    struct board b;
    //memset(&(b.pieces_map),(char)EM,64);
    memcpy(&(b.pieces_map),&INIT_BOARD,64);
    //b.pieces_map[8]=UR;
    print_board(&b);
    printf("%d\n",count_control(&b));
}
void test_score_board(){
	struct board b;
    memset(&(b.pieces_map),(char)EM,64);
    b.pieces_map[15]=LP;
    print_board(&b);
    short score=score_board(&b);
    printf("get score: %d\n",score);
}
/*void test_rules(){
    /*tested: R,N
	const char deep=1;
	struct board b;
	struct move *pmove=NULL;
	unsigned int cases_count=0;

    memset(&(b.pieces_map),(char)EM,64);
    b.pieces_map[9]=UK;
    b.pieces_map[63]=LK;
    b.pieces_map[24]=LP;
    b.pieces_map[8]=UP;
    calc_king_loc(&b);
    /*prepare_init_board(&b);
    b.pieces_map[52]=EM;
    b.pieces_map[36]=LP;

    dump_board(&b);
    short ans=alpha_beta_pruning_upper(&b,deep,-500,500,&pmove,&cases_count,2);
    printf("searched %u cases\n",cases_count);
}*/
/*void test_pruning(){
	const char deep=7;
	struct board b;
	struct move *pmove=NULL;
	unsigned int cases_count=0;
	prepare_init_board(&b);
    struct killer killer_for_decs;
    PREPARE_KILLER_FOR_LOWER(killer_for_decs)
    /*memset(&b,EM,sizeof(struct board));
    b.pieces_map[7]=LK;
    b.pieces_map[24]=UR;
    b.pieces_map[33]=UK;
    calc_king_loc(&b);

    unsigned long ut1,ut2;
    struct timeval tv1,tv2;
    double delta_t;
    gettimeofday(&tv1,NULL);  
    short ans=alpha_beta_pruning_lower(&b,deep,-500,500,&pmove,&cases_count,CANNOT_ENPASS,&killer_for_decs);
    gettimeofday(&tv2,NULL);  
    ut1=tv1.tv_sec*1000000+tv1.tv_usec;
    ut2=tv2.tv_sec*1000000+tv2.tv_usec;
    delta_t=(ut2-ut1)/1000.0;
    dump_board(&b);
    printf("get minmax_value: %d\n",ans);
    print_moves(pmove);
    print_killer(&killer_for_decs);
    printf("searched %u cases in %.3f ms at deep %d, avg %.3f us/case\n",\
           cases_count,delta_t,deep,delta_t/cases_count*1000.0);
}*/
void test_verify_move(){
    struct move amove;
    amove.piece=LP;
    amove.from=8;
    amove.to=1;
    amove.dash='q';
    char *str=move_to_str(&amove);
    printf("%s\n",str);
    
    struct board b;
    prepare_init_board(&b);
    b.pieces_map[25]=UP;
    b.pieces_map[26]=LP;
    dump_board(&b);
    
    struct board *pneob=verify_move(&b,0,"pc5xb6",CANNOT_ENPASS);
    if(pneob){
        dump_board(pneob);
        free(pneob);
    }else{
        printf("pneob=NULL\n");
    }
}
char gen_jump_col(char *str){
    char piece=str[0];
    if(piece=='p' || piece=='P'){
        char row1,col1,row2,col2;
        row1=str[2];
        col1=str[1]-'a';
        row2=str[5];
        col2=str[4]-'a';
        if(abs(row1-row2)==2){
            return col1;
        }    
    }
    return CANNOT_ENPASS;
}
/*void play(){
    const char deep=7;
    struct board *pneob;
    pneob=malloc(sizeof(struct board));
    prepare_init_board(pneob);
    struct board *record[1024];
    char move_count=0;
    record[0]=pneob;
    char jump_col=CANNOT_ENPASS;
    char input[128];
    while(1){
        label1:
        dump_board(record[move_count]);
        printf("jump_col: %d\n",jump_col);

        do{
            printf("your move(%d): ",move_count);
            get_line(input);
            //printf("get \"%s\"\n",input);
            if(strcmp(input,"back")==0){
                printf("you son of a bitch\n");
                move_count-=2;
                move_count=move_count<0?0:move_count;
                goto label1;
            }else{
                pneob=verify_move(record[move_count],0,input,jump_col);
                if(!pneob){
                    printf("illegal\n");
                }
            }
        }while(pneob==NULL);
        jump_col=gen_jump_col(input);
        record[++move_count]=pneob;
        //dump_board(&b);
        printf("jump_col: %d\n",jump_col);
        printf("got calcing...\n");
        

        unsigned int cases_count=0;
        unsigned long ut1,ut2;
        struct timeval tv1,tv2;
        struct move *pmove;
        gettimeofday(&tv1,NULL);  
        short ans=alpha_beta_pruning_upper(record[move_count],deep,-500,500,&pmove,&cases_count,jump_col);
        gettimeofday(&tv2,NULL);
        ut1=tv1.tv_sec*1000000+tv1.tv_usec;
        ut2=tv2.tv_sec*1000000+tv2.tv_usec;

        printf("searched %u cases in %.3f ms at deep %d\n",cases_count,(ut2-ut1)/1000.0,deep);
        printf("minmax_value: %d\n",ans);
        print_moves(pmove);
        
        char *pmove_str=move_to_str(pmove);
        pneob=verify_move(record[move_count],1,pmove_str,jump_col);
        if(pneob){
            jump_col=gen_jump_col(pmove_str);
            record[++move_count]=pneob;
        }else{
            printf("some error happened\n");
        }
    }
}*/
