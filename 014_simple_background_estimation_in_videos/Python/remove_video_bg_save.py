import numpy as np
import cv2

# Open Video
cap = cv2.VideoCapture('../input/video.mp4')

# Randomly select 25 frames
frameIds = cap.get(cv2.CAP_PROP_FRAME_COUNT) * np.random.uniform(size=25)

# Store selected frames in an array
frames = []
for fid in frameIds:
    cap.set(cv2.CAP_PROP_POS_FRAMES, fid)
    ret, frame = cap.read()
    frames.append(frame)

# Calculate the median along the time axis
medianFrame = np.median(frames, axis=0).astype(dtype=np.uint8)    

# Display median frame
cv2.imshow('frame', medianFrame)
cv2.waitKey(0)

# Reset frame number to 0
cap.set(cv2.CAP_PROP_POS_FRAMES, 0)

# Convert background to grayscale
grayMedianFrame = cv2.cvtColor(medianFrame, cv2.COLOR_BGR2GRAY)

# Define the codec and create VideoWriter object
fourcc = cv2.VideoWriter_fourcc(*'mp4v')
out = cv2.VideoWriter('output_video.mp4', fourcc, 25.0, (medianFrame.shape[1], medianFrame.shape[0]))

# Loop over all frames
ret = True
while(ret):

  # Read frame
  ret, frame = cap.read()
  if ret:
      # Convert current frame to grayscale
      grayFrame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
      # Calculate absolute difference of current frame and 
      # the median frame
      dframe = cv2.absdiff(grayFrame, grayMedianFrame)
      # Threshold to binarize
      th, dframe = cv2.threshold(dframe, 30, 255, cv2.THRESH_BINARY)
      # Write processed frame to output video
      out.write(cv2.cvtColor(dframe, cv2.COLOR_GRAY2BGR))
      # Display processed frame
      cv2.imshow('frame', dframe)
      if cv2.waitKey(1) & 0xFF == ord('q'):
          break
  else:
      break

# Release video objects
cap.release()
out.release()

# Destroy all windows
cv2.destroyAllWindows()