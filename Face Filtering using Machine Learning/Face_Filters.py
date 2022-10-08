import cv2
import numpy as n

face_cascade=cv2.CascadeClassifier("haarcascade_frontalface_alt.xml")
eye_cascade=cv2.CascadeClassifier("haarcascade_eye.xml")
nose_cascade=cv2.CascadeClassifier("Nose18x15.xml")
img=cv2.imread("Before.png",-1)
glasses=cv2.imread("J.png",-1)
moustache=cv2.imread("mustache.png",-1)
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
face=face_cascade.detectMultiScale(gray)
for i in face:
    x,y,w,h=i
    #cv2.rectangle(img,(x,y),(x+w,y+h),(0,255,0),3)
    img_1=img[y:y+h,x:x+w]
    roi_gray = gray[y:y+h, x:x+w]
    eyes=eye_cascade.detectMultiScale(roi_gray)
    nose=nose_cascade.detectMultiScale(roi_gray)
    x2,y2,w2,h2=eyes[0]
    x1,y1,w1,h1=eyes[1]
    glasses=cv2.resize(glasses,(170,76))
    gh,gw,gc=glasses.shape
    #cv2.rectangle(img_1,(x1,y1),(x2+w2,y1+max(h2,h1)),(255,0,0),3)
    for l in range(gh):
        for w in range(gw):
            if glasses[l][w][3]!=0:
                img[y1+y+l][x1+x+w-5]=glasses[l][w]
    for i in nose:
        nx,ny,nw,nh=i
        moustache=cv2.resize(moustache,(140,70))
        #print(nx,ny,nw,nh)
        mh,mw,mc=moustache.shape
        #print(mh,mw)
        for l in range(mh):
            for w in range(mw):
                if moustache[l][w][3]!=0:
                    img[y+ny+int(1.1*mh)-nh+l][x+mw-int(2.3*nw)+w]=moustache[l][w]
        #cv2.rectangle(img_1,(nx,ny),(nx+nw,ny+nh),(0,0,255),3)
cv2.imshow("Frame",img)
cv2.imwrite("After.png",img)
cv2.waitKey(0)
cv2.destroyAllWindows()
