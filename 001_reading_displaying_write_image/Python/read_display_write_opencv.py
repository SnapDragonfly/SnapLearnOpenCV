# The python libraries numpy and cv2 need to be imported before reading an image.
import numpy as np
import cv2

# The function cv2.imread() is used to read an image.
img_color = cv2.imread('test.jpg',1)
img_grayscale = cv2.imread('test.jpg',0)
img_unchanged = cv2.imread('test.jpg',-1)


# The function cv2.imshow() is used to display an image in a window.
cv2.imshow('color image',img_color)
cv2.imshow('grayscale image',img_grayscale)
cv2.imshow('unchanged image',img_unchanged)

#Printing the image type and shape for Color Image
print(type(img_color))
print(img_color.shape)

# waitKey() waits for a key press to close the window and 0 specifies indefinite loop
cv2.waitKey(0)

# cv2.destroyAllWindows() simply destroys all the windows we created.
cv2.destroyAllWindows()

# The function cv2.imwrite() is used to write an image.
cv2.imwrite('grayscale.jpg',img_grayscale)
