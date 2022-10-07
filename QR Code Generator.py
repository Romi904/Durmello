import tkinter as tk
from tkinter import ttk
from tkinter import filedialog

def create_qr():
    import qrcode
    from PIL import Image
    from qrcode.image.pil import PilImage
    k=entry1.get()
    img=qrcode.make(k)
    img.save("q.jpg")
    p=Image.open("q.jpg")
    p.show()

def read_img():
    import cv2
    from pyzbar.pyzbar import decode
    file_path = filedialog.askopenfilename()
    img1=cv2.imread(file_path)
    for code in decode(img1):
       label3.config(text = "Output: " + code.data.decode('utf-8'))

def read_cam():
    import cv2
    from pyzbar.pyzbar import decode
    cap=cv2.VideoCapture(0)
    i=0
    while i<1:
       _,frame=cap.read()
       for code in decode(frame):
          label4.config(text = "Output: " + code.data.decode('utf-8'))
          i=i+1
       cv2.imshow("Screen",frame)
       cv2.waitKey(5)
    cv2.destroyAllWindows()

window = tk.Tk()
window.geometry('400x300')
greeting = tk.Label(text="Welcome to the QR Code Program")
label1 = tk.Label(text="Enter Text to generate code")
entry1 = tk.Entry()
button1 = tk.Button(text="Generate QR Code", command=create_qr)
label2 = tk.Label(text="Select QR Image File to read:")
button2 = tk.Button(text="Select Image", command=read_img)
label3 = tk.Label(text="Output: ")
button3 = tk.Button(text="Read QR Code from Camera", command=read_cam)
label4 = tk.Label(text="Output: ")
greeting.pack()
label1.pack()
entry1.pack()
button1.pack()
separator1 = ttk.Separator(window, orient='horizontal')
separator1.pack(fill='x')
label2.pack()
button2.pack()
label3.pack()
separator2 = ttk.Separator(window, orient='horizontal')
separator2.pack(fill='x')
button3.pack()
label4.pack()
window.mainloop()