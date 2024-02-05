# Import necessary packages
import cv2 

# Create a video capture object, in this case we are reading from image sequence
# Note the name of the files. 
# For Cars0000.jpg  >> Cars%04d.jpg
# For Cars000.jpg  >> Cars%03d.jpg
# For Cars_00.jpg  >> Cars_%02.jpg

vid_capture = cv2.VideoCapture('Resources/Image_sequence/Cars%04d.jpg')


if (vid_capture.isOpened() == False):
	print("Error processing the image sequence")

while(vid_capture.isOpened()):
	# vCapture.read() methods returns a tuple, first element is a bool and the second is frame
	ret, frame = vid_capture.read()
	if ret == True:
		cv2.imshow('Frame',frame)
		# 20 is in milliseconds, try to increase the value, say 50 and observe
		k = cv2.waitKey(20)
		# k == 113 is ASCII code for q key. You can try to replace that 
		# with any key with its corresponding ASCII code, try 27 which is for ESCAPE key
		if k == 113:
			break
	else:
		break
# Release the video capture object
vid_capture.release()
cv2.destroyAllWindows()