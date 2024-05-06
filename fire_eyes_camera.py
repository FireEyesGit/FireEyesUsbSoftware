# FireEyes@2024
import cv2
cap = cv2.VideoCapture(1,cv2.CAP_DSHOW)
cap.set(cv2.CAP_PROP_FPS, 30)
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 2560)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 720)
cap.set(cv2.CAP_PROP_FOURCC, cv2.VideoWriter_fourcc('M', 'J', 'P', 'G'))
while True:
    ''
    flag, frame0 = cap.read()
    cv2.imshow('FireEyes', frame0)
    cv2.waitKey(30)
