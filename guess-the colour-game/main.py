from tkinter import *
import random
from tkinter import messagebox


colours = ['Red','Blue','Green','Pink','White', 
           'Yellow','Orange','Purple','Brown']

score  = 0


time = 30


def startGame(event):

    if time==30:

        
        countdown()

        
    nextcolor()

def nextcolor():

    global score
    global time

    
    if time > 0:

        
        colour_entry.focus_set()

        if colour_entry.get().lower() == colours[1].lower():

            score += 1

        
        colour_entry.delete(0, END)

        random.shuffle(colours) 

        
        colour.config(fg= str(colours[1]) , text = str(colours[0]))

        
        scoreLabel.config(text = "Score: " + str(score))

def GameEnd():
   messagebox.showinfo("System", "Game Over")
   
def countdown():

    global time

   
    if time > 0 :

        
        time -= 1

        
        timeLabel.config(text = "Time left: "+ str(time))

        
        timeLabel.after(1000, countdown)

    else:
        GameEnd()
if __name__=='__main__':

    root = Tk()

    
    root.title('Guess the Color Game') 

    
    root.geometry('375x200')
    root.config(bg='black')
    
    instructions = Label(root, text = 'What color? Enter your Guess!', font = ('Helvetica', 12), bg='black', fg='white') 
    instructions.pack()

    
    scoreLabel = Label(root, text = 'Score :'+str(score), fg='white', bg='black', font=('Helvetica' , 12))
    scoreLabel.pack()

    
    timeLabel = Label(root, text = 'Time Left : '+str(time), fg='white', bg='black', font=('Helvetica' , 12))
    timeLabel.pack()

    
    colour = Label(root, font=('Helevetica',20), fg='white', bg='black',)
    colour.pack()

    
    colour_entry = Entry(root, font=('Arial',16))


    colour_entry.focus_set()
    root.bind('<Return>',startGame)

    colour_entry.pack()

    root.mainloop()

