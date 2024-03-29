import cv2

# Create a video capture object
# vid_capture = cv2.VideoCapture(0) will work fine, but generates a warning.
# A bug, Direct show flag solves it.
#vid_capture = cv2.VideoCapture(0, cv2.CAP_DSHOW)
vid_capture = cv2.VideoCapture(0)

if(vid_capture.isOpened() == False):
	print("Error opening video stream")

# Get height and width of the frame
#CAP_PROP_FRAME_WIDTH =3, CAP_PROP_FRAME_HEIGHT =4
frame_width = int(vid_capture.get(3))
frame_height = int(vid_capture.get(4))
frame_size = (frame_width,frame_height)
fps = 20

# Create a video writer object
output = cv2.VideoWriter('Resources/output_video_from_web_cam.avi', cv2.VideoWriter_fourcc('M','J','P','G'), fps, frame_size)

while(vid_capture.isOpened()):
	# vCapture.read() methods returns a tuple, first element is a bool 
	# and the second is frame
	ret, frame = vid_capture.read()

	if ret == True:
		output.write(frame)

		cv2.imshow("Frame",frame)
		# k == 113 is ASCII code for q key. You can try to replace that 
		# with any key with its corresponding ASCII code, try 27 which is for ESCAPE
		key = cv2.waitKey(20)
		if key == ord('q'):
			break
	else:
		print('Web camera is disconnected')
		break
# Release the video capture and output objects.
vid_capture.release()
output.release()
cv2.destroyAllWindows()