# Import packages
import cv2

# Lists to store the points
top_left_corner=[]
bottom_right_corner=[]

# Define drawRectangle function
def drawRectangle(action, x, y, flags, *userdata):
  # Referencing global variables 
  global top_left_corner, bottom_right_corner
  # Action to be taken when left mouse button is pressed
  if action == cv2.EVENT_LBUTTONDOWN:
    top_left_corner = [(x,y)]
    # Action to be taken when left mouse button is released
  elif action == cv2.EVENT_LBUTTONUP:
    bottom_right_corner = [(x,y)]    
    # Draw the rectangle
    cv2.rectangle(image, top_left_corner[0], bottom_right_corner[0], (0,255,0),2, 8)
    cv2.imshow("Window",image)


# Read Images
image = cv2.imread("../Input/sample.jpg")
# Make a dummy image, will be useful to clear the drawing
dummy = image.copy()
# Create a named window
cv2.namedWindow("Window")
# highgui function called when mouse events occur
cv2.setMouseCallback("Window", drawRectangle)

k=0
# Close the window when key q is pressed
while k!=113:
  # Display the image
  cv2.imshow("Window", image)
  k = cv2.waitKey(0)
  # Clear the window when c is presses
  if (k == 99):
    image= dummy.copy()
    cv2.imshow("Window", image)

cv2.destroyAllWindows()