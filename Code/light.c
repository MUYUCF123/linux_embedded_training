#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


typedef enum {
    IDLE,
    PLAYING,
    PAUSED,
    SETTING
} State;

typedef enum {
    EV_NONE,
    EV_PLAY_TOGGLE, 
    EV_SET_TOGGLE,  
    EV_KEY_UP,      
    EV_KEY_DOWN           
} Event;

typedef struct {
    State state;
    int position;
    int setting_val;
} Player;

static void print_state(const Player *p){
    const char* name = "?";
    switch (p->state)
    {
    case IDLE: name = "IDLE"; break;
    case PLAYING: name = "PLAYING"; break;
    case PAUSED: name = "PAUSED"; break;
    case SETTING: name = "SETTING"; break;
    }
    printf("状态:%s \n",name);
}

static void handle_event(Player *p, Event ev){
    switch (p->state)
    {
    case IDLE:
        if(ev == EV_PLAY_TOGGLE){
            p->position = 0;
            p->state = PLAYING;
            printf("由空闲开始播放\n");
        }else if (ev == EV_SET_TOGGLE)
        {
            p->state = SETTING;
            printf("进入设置\n");
        }
        
        break;
    
    case PLAYING:
        if (ev == EV_PLAY_TOGGLE)
        {
            p->state = PAUSED;
            printf("播放暂停");
        }else if (ev == EV_SET_TOGGLE)
        {
            p->state = SETTING;
            printf("进入设置\n");
        }else if(ev == EV_KEY_UP){
            printf("发送上一曲指令");
        }else if(ev == EV_KEY_DOWN){
            printf("发送下一曲指令");
        }
        break;
    case PAUSED:
        if (ev == EV_PLAY_TOGGLE)
        {
            p->state = PLAYING;
            printf("播放重新开始");
        }else if (ev == EV_SET_TOGGLE)
        {
            p->state = SETTING;
            printf("进入设置\n");
        }else if(ev == EV_KEY_UP){
            printf("发送上一曲指令");
        }else if(ev == EV_KEY_DOWN){
            printf("发送下一曲指令");
        }
        break;

    case SETTING:
        if (ev == EV_SET_TOGGLE) {
            p->state = IDLE;
            printf("退出设置\n");
        } else if (ev == EV_KEY_UP) {
            if (p->setting_val < 100) p->setting_val += 1;
            printf("动作: 设置值增加 -> %d\n", p->setting_val);
        } else if (ev == EV_KEY_DOWN) {
            if (p->setting_val > 0) p->setting_val -= 1;
            printf("动作: 设置值减少 -> %d\n", p->setting_val);
        }
        break;

    default:
        p->state = IDLE;
        printf("遇到未知状态\n");
    }
}

Event KeyToEvent(int KeyNum){
    KeyNum = tolower(KeyNum);
    switch(KeyNum){
        case 'p': return EV_PLAY_TOGGLE;
        case 's': return EV_SET_TOGGLE;
        case 'a': return EV_KEY_DOWN;
        case 'd': return EV_KEY_UP;
        default: return EV_NONE;
    }
}

int main(){
    int keynum;
    Player player = { .state = IDLE, .position = 0, .setting_val = 50 };

    while (1)
    {
        keynum = getchar();
        if(keynum == '\n'|| keynum == '\r') continue;

        Event ev = KeyToEvent(keynum);
        if (ev == EV_NONE)
        {
            printf("未知命令");
        }
        
        handle_event(&player, ev);
        print_state(&player);
        
    }
    

}



