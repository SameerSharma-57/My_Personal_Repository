import pygame
from random import randint
x=pygame.init()

#creating game window
game_window=pygame.display.set_mode((900,500))
pygame.display.set_caption("SNAKE'S GAME BY SAMEER SHARMA")
pygame.display.update()
clock=pygame.time.Clock()

font=pygame.font.SysFont(None,55)
def text_screen(text,color,x,y):
    s=font.render(text,True,color)
    game_window.blit(s,[x,y])

def plot_snake(sn_list,color,size):
    for x,y in sn_list:
        pygame.draw.rect(game_window,color,(x,y,size,size))




def welcome():
    game_window.fill((255,255,255))
    text_screen("welcome to my snake game",((0,0,0)),210,200)
    text_screen("Press Enter to continue",(0,255,0),250,270)
    exit_game=False
    while not exit_game:
        for event in pygame.event.get():
            if event.type==pygame.QUIT:
                exit_game=True
            if event.type==pygame.KEYDOWN:
                
                if event.key==pygame.K_RETURN:
                    gameloop()
        pygame.display.update()
         
        clock.tick(20)


def gameover():
    game_window.fill((200,135,80))
    text_screen("GAME OVER!\npress space to continue",(255,0,0),150,210)
    exit_game=False
    while not exit_game:
        for event in pygame.event.get():
            if event.type==pygame.QUIT:
                exit_game=True
            if event.type==pygame.KEYDOWN:
                if event.key==pygame.K_SPACE:
                    welcome()

        pygame.display.update()
        clock.tick(20)





def gameloop():
    #game variables
    white=(255,255,255)
    red=(255,0,0)
    black=(0,0,0)
    exit_game=False
    snake_x=randint(300,800)
    snake_y=randint(200,450)
    food_x=20
    food_y=20
    velocity_x=0
    velocity_y=0
    size=15
    score=0
    sn_len=1
    sn_list=[]
    gameover=False
    
    while not exit_game:
        if not gameover:
            for event in pygame.event.get():
                if event.type==pygame.QUIT:
                    exit_game=True

                if event.type==pygame.KEYDOWN:
                    if event.key==pygame.K_DOWN:
                        velocity_y=5
                        velocity_x=0
                    elif event.key==pygame.K_UP:
                        velocity_y=-5
                        velocity_x=0
                    elif event.key==pygame.K_RIGHT:
                        velocity_x=5
                        velocity_y=0
                    elif event.key==pygame.K_LEFT:
                        velocity_x=-5
                        velocity_y=0
                

            snake_x+=velocity_x
            snake_y+=velocity_y
            if abs(snake_x-food_x)<6 and (snake_y-food_y)<6:
                food_x=randint(100,800)
                food_y=randint(50,450)
                score+=1
                sn_len+=1

            

            head=[snake_x,snake_y]
            if head in sn_list[:-1]:
                gameover=True
            if snake_x<0 or snake_x>900 or snake_y<0 or snake_y>500:
                gameover=True
            sn_list.append(head)

            if len(sn_list)>sn_len:
                del sn_list[0]
            game_window.fill(white)
            plot_snake(sn_list,black,size)
            pygame.draw.rect(game_window,red,(food_x,food_y,size,size))
            text_screen("Score :"+str(score),red,10,10)
            pygame.display.update()
        else:
            game_window.fill((80,255,80))
            text_screen("GAME OVER!",(255,0,0),300,210)
            text_screen("PRESS SPACE TO CONTINUE",(255,0,0),190,270)
            pygame.display.update()
            for event in pygame.event.get():
                if event.type==pygame.QUIT:
                    exit_game=True
                if event.type==pygame.KEYDOWN:
                    if event.key==pygame.K_SPACE:
                        welcome()

        

        clock.tick(20)
welcome()         
pygame.quit()
quit()