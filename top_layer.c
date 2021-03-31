#include"chess.h"
#define PREPARE_KILLER_FOR_LOWER(killer) {\
    memset(killer.loc,KILLER_EMPTY,KILLER_LENGTH);\
    memcpy(killer.score,init_killer_score_lower,KILLER_LENGTH*sizeof(short));\
}
#define PREPARE_KILLER_FOR_UPPER(killer) {\
    memset(killer.loc,KILLER_EMPTY,KILLER_LENGTH);\
    memcpy(killer.score,init_killer_score_upper,KILLER_LENGTH*sizeof(short));\
}
struct player{
	struct board record[1024];
	char jump_col[1024];
	short move_count;
};
char move(struct player * pplayer){
    ;
}
void play_on_web(){
    char deep=7;
    struct board *pneob;
    pneob=malloc(sizeof(struct board));
    prepare_init_board(pneob);
    
    struct board *record[1024];
    char jump_col[1024];
    short move_count=0;
    record[move_count]=pneob;
    jump_col[move_count]=CANNOT_ENPASS;
    
    char input[128];
    double t_upper=15;
    char autohelp_flag=-1,help_flag=0;
    while(1){
        print_board(record[move_count]);
        do{
            if(move_count%2==autohelp_flag){
                help_flag=1;
            }else{
label2:
                help_flag=0;
                printf("move(%d): ",move_count);
                get_line(input);
            }
            if(strcmp(input,"back")==0){
                move_count-=1;
                move_count=move_count<0?0:move_count;
                print_board(record[move_count]);
                goto label2;
            }if(strcmp(input,"board")==0){
                print_board(record[move_count]);
                goto label2;
            }else if(strcmp(input,"dump")==0){
                printf("jump_col: %d, turn: %d\n",jump_col[move_count],move_count%2);
                dump_board(record[move_count]);
                printf("autohelp_flag: %d,help_flag: %d\n",autohelp_flag,help_flag);
                printf("deep: %d, t_upper: %f\n",deep,t_upper);
                goto label2;
            }else if(strncmp(input,"sett",4)==0){
                float tempf=atof(input+4);
                if(tempf>0){
                    t_upper=tempf;
                    printf("set t_upper to %f\n",t_upper);
                }else{
                    printf("parse number failed\n");
                }
                goto label2;
            }else if(strncmp(input,"setdeep",7)==0){
                char tempd=atoi(input+7);
                if(tempd>0){
                    deep=tempd;
                    printf("set deep to %d\n",deep);
                }else{
                    printf("parse number failed\n");
                }
                goto label2;
            }else if(strncmp(input,"ah",2)==0){
                if(input[3]=='0'){
                    autohelp_flag=0;
                }else if(input[3]=='1'){
                    autohelp_flag=1;
                }else{
                    autohelp_flag=-1;
                }
                printf("set autohelp_flag to %d\n",autohelp_flag);
                goto label2;
            }else if(input[0]=='h' || help_flag){
                help_flag=0;
                printf("got, calcing with deep=%d...\n",deep);
                unsigned int cases_count=0;
                unsigned long ut1,ut2;
                double delta_t;
                struct timeval tv1,tv2;
                struct move *pmove;
                short ans;
                struct killer killer_for_dec;
                if(move_count%2){
                    PREPARE_KILLER_FOR_UPPER(&killer_for_dec)
                }else{
                    PREPARE_KILLER_FOR_LOWER(&killer_for_dec)
                }
                gettimeofday(&tv1,NULL); 
                if(move_count%2){ 
                    if(move_count<OPEN_STEPS){
                        //printf("is opening\n");
                        ans=alpha_beta_pruning_upper(record[move_count],deep,-500,500,&pmove,&cases_count,jump_col[move_count],
                            &killer_for_dec,(char *)OPENING_SUGGEST_UPPER,sizeof(OPENING_SUGGEST_UPPER));
                    }else{
                        ans=alpha_beta_pruning_upper(record[move_count],deep,-500,500,&pmove,&cases_count,jump_col[move_count],
                            &killer_for_dec,NULL,0);
                    }
                }else{
                    if(move_count<OPEN_STEPS){
                        //printf("is opening\n");
                        ans=alpha_beta_pruning_lower(record[move_count],deep,-500,500,&pmove,&cases_count,jump_col[move_count],
                            &killer_for_dec,(char *)OPENING_SUGGEST_LOWER,sizeof(OPENING_SUGGEST_LOWER));
                    }else{
                        ans=alpha_beta_pruning_lower(record[move_count],deep,-500,500,&pmove,&cases_count,jump_col[move_count],
                            &killer_for_dec,NULL,0);
                    }
                }
                gettimeofday(&tv2,NULL);
                ut1=tv1.tv_sec*1000000+tv1.tv_usec;
                ut2=tv2.tv_sec*1000000+tv2.tv_usec;
                delta_t=(ut2-ut1)/1000.0;
                printf("searched %u cases in %.3lf ms at deep %d, avg %.3lf us/case\n",cases_count,delta_t,deep,delta_t/cases_count*1000.0);
                printf("minmax_value: %d\n",ans);
                print_killer(&killer_for_dec);
                print_moves(pmove);
                
                
                if(delta_t<t_upper*100){
                    deep++;
                    printf("delta t<%f, increment deep to %d\n",t_upper/10,deep);
                }else if(delta_t>t_upper*1000){
                    deep--;
                    printf("delta t>%f, decrease deep to %d\n",t_upper,deep);
                }
                
                char *pmove_str=move_to_str(pmove);
                strcpy(input,pmove_str);
                free(pmove_str);
                print_bell();
            }
            //printf("get input: %s\n",input);
            pneob=verify_move(record[move_count],move_count%2,input,jump_col[move_count]);
            if(!pneob){
                printf("illegal\n");
            }
        }while(pneob==NULL);
        move_count++;
        record[move_count]=pneob;
        jump_col[move_count]=gen_jump_col(input);
    }
}
char main(){
    //printf("%ld\n",sizeof(OPENING_SUGGEST_LOWER));
    print_bell();
    /*struct move amove;
    memset(&amove,0,sizeof(struct move));
    //amove.piece=UWIN;
    printf("%s\n",move_to_str(&amove));*/
    //printf("%d\n",(unsigned int)sizeof(struct board));
    //play();
    play_on_web();
    //test_verify_move();
    //test_pruning();
	//test_cstable();
    //test_being_checked();
    //test_rules();
	//test_gen_jump_col();
    //test_moves();
    //test_cmp_move_str();
    //test_count_control();
    //test_score_board();
	return 0;
}