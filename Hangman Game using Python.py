#Importing all the required modules
import random
import turtle 
import sys
import time

#Declaring all the variables
flagW=False
flagL=False
flafA=False
flagWr=False
gameFlag=True
wrongCount=0
hmTC=(0,0)
hm=turtle.Turtle()
hm.speed(0)
state=turtle.Turtle()
state.ht()


#Defining functions
def correct():
        state.clear()
        state.color("green")
        state.write("Correct!!",font=("Arial",50,"bold"))
def lose():
        state.clear()
        state.color("white")
        state.write("YOU LOSE!!", font=("Arial",50,"bold"))
        cordxy=letter[0].pos()
        temp=turtle.Turtle()
        temp.ht()
        temp.speed(0)
        temp.color("white")
        temp.penup()
        temp.setpos(cordxy[0],cordxy[1]+40)
        temp.pendown()
        temp.write("This was the movie:",align="left", font=("Arial", 30, "bold"))
        
        for i in range(len(movie)):
                if(movie[i] not in user_list_correct):
                        letter[i].color("red")
                        letter[i].write(movie[i],align="left", font=("Arial", 20, "bold"))
        
def win():
	state.clear()
	state.color("white")
	state.write("YOU WIN!!", font=("Arial",50,"bold"))
def already():
	
		
	state.clear()
	state.color("green")
	state.write("YOU Already pressed that key!!", font=("Arial",50,"bold"))
	
def wrong():
	state.clear()
	state.color("red")
	state.write("wrong", font=("Arial",50,"bold"))

#Evaluating individual letters
def A():
			evaluate(movie,"A")
def B():
			evaluate(movie,"B")
def C():
			evaluate(movie,"C")
def D():
			evaluate(movie,"D")
def E():
			evaluate(movie,"E")
def F():
			evaluate(movie,"F")
def G():
			evaluate(movie,"G")
def H():
			evaluate(movie,"H")
def I():
			evaluate(movie,"I")
def J():
			evaluate(movie,"J")
def K():
			evaluate(movie,"K")
def L():
			evaluate(movie,"L")
def M():
			evaluate(movie,"M")
def N():
			evaluate(movie,"N")
def O():
			evaluate(movie,"O")
def P():
			evaluate(movie,"P")
def Q():
			evaluate(movie,"Q")
def R():
			evaluate(movie,"R")
def S():
			evaluate(movie,"S")
def T():
			evaluate(movie,"T")
def U():
			evaluate(movie,"U")
def V():
			evaluate(movie,"V")
def W():
			evaluate(movie,"W")
def X():
			evaluate(movie,"X")
def Y():
			evaluate(movie,"Y")
def Z():
			evaluate(movie,"Z")

#Designing and controlling the hangman
def Hangman(num):
    global hmTC
    if(num==0):
            
            hm.penup()
            hm.setpos(-670,-340)
            hm.pendown()
            hm.ht()
            hm.begin_fill()
            hm.fd(400)
            hm.lt(90)
            hm.fd(50)
            hm.lt(90)
            hm.fd(390)
    
            hm.rt(90)
            hm.fd(600)
            hm.rt(90)
            hm.fd(400)
            hm.rt(90)
            hm.fd(20)
            hm.lt(90)
            hm.fd(10)
            
            
            # print(hmTC[0])
            hm.lt(90)
            hmTC=hm.pos()
            hm.fd(30)
            
            hm.lt(90)
            hm.fd(420)
            hm.lt(90)
            hm.fd(550)
            hm.end_fill()
            #hm.end_fill()
            hm.pensize(5)
    elif(num==1):
            hm.penup()
            hm.setpos(hmTC[0],hmTC[1])
            hm.rt(90)
            hm.pendown()
            hm.circle(40)
            #print(hm.pos())
    elif(num==2):
            hm.penup()
            hm.setpos(hmTC[0],hmTC[1]-80)
            hm.lt(90)
            hm.pendown()
            hm.fd(140)
            hmTC=hm.pos()
    elif(num==3):
            hm.penup()
            hm.rt(30)
            hm.pendown()
            hm.fd(100)
            hm.rt(60)
            hm.fd(10)
            hm.penup()
            hm.rt(180)
            hm.fd(10)
            hm.rt(30)
            hm.fd(100)
            hm.rt(90)
            hm.pendown()
    elif(num==4):
            hm.penup()
            hm.setpos(hmTC[0],hmTC[1])
            
            hm.pendown()
            hm.lt(60)
            hm.fd(100)
            hm.lt(60)
            hm.fd(10)
            #hm.rt(90)
            
            
           
    elif(num==5):
            hm.penup()
            hm.setpos(hmTC[0],hmTC[1])
            hm.lt(90)
            hm.fd(90)
            hm.lt(180)
            hm.rt(30)
            hm.pendown()
            hm.fd(80)
            hm.rt(60)
            
            
            
    elif(num==6):
            hm.penup()
            hm.setpos(hmTC[0],hmTC[1])
            hm.rt(90)
            hm.fd(90)
            hm.lt(180)
            hm.lt(30)
            hm.pendown()
            hm.fd(80)
            
    elif(num==7):
            hm.penup()
            hm.setpos(-235.00,265.00)
            hm.rt(90)
            hm.pendown()
            hm.circle(4)
    elif(num==8):
            hm.penup()
            hm.setpos(-265,265.00)
            hm.rt(90)
            hm.pendown()
            hm.circle(4)
    
    else:
        hm.penup()
        hm.setpos(hm.pos()[0]+25,hm.pos()[1]-35)
        hm.pendown()
        hm.rt(30)
        hm.circle(10,180)

#Creating empty boxes
def createDash(num):
    dash=[]
    letter=[]
    for i in range(num):
        #print(movie_space_position)
        dash.append(turtle.Turtle())
        dash[i].color("#800000","white")
        dash[i].pensize(4)
        letter.append(turtle.Turtle())      
        dash[i].ht()
        dash[i].speed(0)
        letter[i].ht()      
        dash[i].penup()
        letter[i].penup()       
        dash[i].setpos(-600+i*50,-200)
        letter[i].setpos(-595+i*50,-200)        
        dash[i].pendown()
        letter[i].pendown()
        if(i in movie_space_position):
                    dash[i].penup()
                    continue
        dash[i].begin_fill()
        dash[i].fd(30)
        dash[i].lt(90)
        dash[i].fd(30)
        dash[i].lt(90)
        dash[i].fd(30)
        dash[i].lt(90)
        dash[i].fd(30)
        dash[i].end_fill()
    return letter
		
#Working logic of the game
def evaluate(movie,user_input):
    global wrongCount
    global gameFlag
    if(gameFlag==True):
        if(user_input in movie and user_input not in user_list_correct):
            tempPositionList=[]
            for i in range(len(movie)):
                if(movie[i]==user_input):
                    letter[i].write(user_input,align="left", font=("Arial", 20, "bold"))
                    user_list_correct.append(user_input)
                    tempPositionList.append(i)
                    correct()                    
                    if(len(user_list_correct)==len(movie)):
                        win()
                        gameFlag=False
            
        else:
            if(user_input in user_list_correct):
                already()
                
            else:
                wrong()
                user_list_wrong.append(user_input)
                wrongCount+=1
                if(wrongCount>=9):
                    lose()
                    gameFlag=False
                
                
                Hangman(wrongCount)
    
f = open("movies.txt")
movie_list=[]
for line in f:
    line = line.strip()
    movie_list.append(line)

movie = random.choice(movie_list)
movie=movie.upper()
l = len(movie)
movie = list(movie)
movie_space_count=0
movie_space_position=[]
user_list_correct  = []
user_list_wrong = []
user_input=[]
for c in range(len(movie)):
    if(movie[c]==' '):
        movie_space_count+=1
        movie_space_position.append(c)
        user_list_correct.append(' ')

    
##Adding a screen 
wn = turtle.Screen()
wn.setup (width=1920, height=1080, startx=0, starty=0)
wn.bgpic("imain.gif")
wn.tracer(2)
Hangman(0)
letter = createDash(len(movie))
wn.tracer(1)

#Tracing keys and handling user input  
wn.onkey(A,"a")
wn.onkey(B,"b")
wn.onkey(A,"a")
wn.onkey(A,"A")
wn.onkey(B,"b")
wn.onkey(B,"B")
wn.onkey(C,"c")
wn.onkey(C,"C")
wn.onkey(D,"d")
wn.onkey(D,"D")
wn.onkey(E,"e")
wn.onkey(E,"E")
wn.onkey(F,"f")
wn.onkey(F,"F")
wn.onkey(G,"g")
wn.onkey(G,"G")
wn.onkey(H,"h")
wn.onkey(H,"H")
wn.onkey(I,"i")
wn.onkey(I,"I")
wn.onkey(J,"j")
wn.onkey(J,"J")
wn.onkey(K,"k")
wn.onkey(K,"K")
wn.onkey(L,"l")
wn.onkey(L,"L")
wn.onkey(M,"m")
wn.onkey(M,"M")
wn.onkey(N,"n")
wn.onkey(N,"N")
wn.onkey(O,"o")
wn.onkey(O,"O")
wn.onkey(P,"p")
wn.onkey(P,"P")
wn.onkey(Q,"q")
wn.onkey(Q,"Q")
wn.onkey(R,"r")
wn.onkey(R,"R")
wn.onkey(S,"s")
wn.onkey(S,"S")
wn.onkey(T,"t")
wn.onkey(T,"T")
wn.onkey(U,"u")
wn.onkey(U,"U")
wn.onkey(V,"v")
wn.onkey(V,"V")
wn.onkey(W,"w")
wn.onkey(W,"W")
wn.onkey(X,"x")
wn.onkey(X,"X")
wn.onkey(Y,"y")
wn.onkey(Y,"Y")
wn.onkey(Z,"z")
wn.onkey(Z,"Z")
if(gameFlag==True):
	wn.listen()

turtle.mainloop()