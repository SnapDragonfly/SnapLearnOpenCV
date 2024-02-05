import cv2 

#Create a video capture object, in this case we are reading the webcam
#To  read  from  multiple  webcam  we  can  pass  1 , 2 , 3  and so on

# vid_capture = cv2.VideoCapture(0) will also work, but generates a warning
# A bug.
# Passing direct show flag resolves the issue

#vid_capture = cv2.VideoCapture(0, cv2.CAP_DSHOW)
vid_capture = cv2.VideoCapture(0)


if (vid_capture.isOpened() == False):
	print("Error opening the video stream")

while(vid_capture.isOpened()):
	# vCapture.read() methods returns a tuple, first element is a bool 
	# and the second is frame
	ret, frame = vid_capture.read()
	if ret == True:
		cv2.imshow('Frame',frame)
		# 20  is  in milliseconds, try to increase the value, say 50 and observe
		k = cv2.waitKey(20)
		# k == 113 is ASCII code for q key. You can try to replace that 
		# with any key with its corresponding ASCII code, try 27 which is for ESCAPE key
		if k == 113:
			break
	else:
		break
# Release the video capture object.
vid_capture.release()
cv2.destroyAllWindows()